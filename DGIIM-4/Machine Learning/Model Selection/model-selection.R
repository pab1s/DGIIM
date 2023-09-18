# Exercise A9 -------------------------------------------------------------
# Pablo Olivares Martinez -------------------------------------------------

# Dataset Libraries
library(kernlab)

# Utility libraries
library(caTools)
library(Matrix)
library(ROCR)
library(pROC)

# ML algorithms libraries
library(rpart)          # Decision Tree
library(randomForest)   # Random Forest
library(ipred)          # Bagging
library(adabag)         # Ada Boost
library(gbm)            # Gradient Boosting
library(xgboost)        # XGBoost

# Visualization libraries
library(rpart.plot)     # Decision Tree
library(ggplot2)        # Plots


# Function definitions ----------------------------------------------------

# Accuracy function
acc <- function(y.true, y.pred) { sum(y.pred==y.true)/length(y.true) }

# ROC function
roc.function<-function(y_pred,testY){
  pred <- prediction(as.numeric(y_pred), as.numeric(testY))
  perf.auc <- performance(pred, measure = "auc")
  auc<-round(unlist(perf.auc@y.values),2)
  perf <- performance(pred,"tpr","fpr")
  plot(perf,main=paste("ROC curve and AUC=",auc),colorize=TRUE, lwd = 3)
  abline(a = 0, b = 1, lwd = 2, lty = 2) 
}


# Preparing Dataset -------------------------------------------------------

set.seed(123)

# Importing the dataset
data("spam")

# Dataset splitting into Training set and Test set
split = sample.split(spam$type, SplitRatio = 0.7)
training_set = subset(spam, split == TRUE)
test_set = subset(spam, split == FALSE)

# Dummy dataset for GBM and XGBoost
dummy.spam = dummyVars("~ .", spam[-58], fullRank = F)
dummy.spam = as.data.frame(predict(dummy.spam, newdata = spam[-58]))
dummy.spam = cbind(dummy.spam, spam[58])
dummy.spam$type = ifelse(dummy.spam$type == "spam", 1, 0)

dummy_split = sample.split(dummy.spam$type, SplitRatio = 0.7)
dummy_training_set = subset(dummy.spam, split == TRUE)
dummy_test_set = subset(dummy.spam, split == FALSE)

# Matricial form for XGBoost
mat_training_set = as.matrix(dummy_training_set[,-58])
m.train = as(mat_training_set, "dgCMatrix")
mat_test_set = as.matrix(dummy_test_set[,-58])
m.test = as(mat_test_set, "dgCMatrix")


# Models ------------------------------------------------------------------

# MODEL 1: DECISION TREE
decision.tree = rpart(formula = type ~ ., data = training_set)
rpart.plot(decision.tree)
dt.pred = predict(decision.tree, newdata = test_set, type="class")

# MODEL 2: BAGGING (BOOTSTRAP AGGREGATING)
spam.bagging = bagging(formula = type ~ ., data =training_set, coob=FALSE, nbagg=80, keepX=TRUE)
rpart.plot(spam.bagging$trees[[1]])
bagging.pred = predict(spam.bagging, newdata = test_set, type="class")

# MODEL 3: RANDOM FOREST
random.forest = randomForest(type ~ .,data = training_set)
plot(random.forest, log="y")
varImpPlot(random.forest)
rf.pred = predict(random.forest, newdata = test_set, type="class")

# MODEL 4: BOOSTING (ADA BOOST)
ada.boosting = boosting(type ~ ., training_set, mfinal=50)
ada.boosting$importance
ada.pred = predict(ada.boosting, newdata = test_set, type="class")

# MODEL 5: GRADIENT BOOSTING METHOD (GBM)
gbm.bernouilli = gbm(type ~ .,distribution = "bernoulli", data = dummy_training_set,
                n.trees=500,shrinkage = 0.05)
gbm.n.trees = gbm.perf(gbm.bernouilli)
gbm.pred = predict(gbm.bernouilli, dummy_test_set, n.trees = gbm.n.trees)

# Find the threshold
gbm.roc = roc(dummy_test_set$type, gbm.pred)
x=plot(gbm.roc)
x
coords(gbm.roc, "best")
threshold = -0.8432333
gbm.pred.class = ifelse(gbm.pred > threshold, 1, 0)

# MODEL 6: XGBOOST MODEL
gc.xgb = xgboost(data=m.train,label=dummy_training_set$type,
                  nrounds = 500,objective="binary:logistic",
                  eval_metric = "logloss")
xgb.pred = predict(gc.xgb, m.test)
xgb.pred.class = ifelse(xgb.pred > 0.5, 1, 0)


# Comparison of the Models' Performance -----------------------------------

# Accuracy Comparison
model = c('DT', 'BAGGING', 'RF', 'ADA', 'GBM', 'XGBOOST')
accuracy = c(acc(test_set$type, dt.pred),acc(test_set$type, bagging.pred$class),
           acc(test_set$type, rf.pred),acc(test_set$type, ada.pred$class),
           acc(dummy_test_set$type, gbm.pred.class),acc(dummy_test_set$type,xgb.pred.class))


data = cbind(model, accuracy)
data = as.data.frame(data)

ggplot(data, aes(x = model, y = accuracy)) + 
  geom_point() + 
  geom_segment(aes(x = model, xend = model, y = 0, yend = accuracy))

# ROC and AUC Comparison
roc.function(dt.pred, test_set$type)                # DT AUC = 0.88
roc.function(bagging.pred$prob[,2], test_set$type)  # BAGGING AUC = 0.95
roc.function(rf.pred, test_set$type)                # RF AUC = 0.94
roc.function(ada.pred$prob[,2], test_set$type)      # ADA Boosting AUC = 0.99
roc.function(gbm.pred.class, dummy_test_set$type)   # GBM AUC = 0.93
roc.function(xgb.pred.class, dummy_test_set$type)   # XGBOOST AUC = 0.95


# Conclusions -------------------------------------------------------------

# After obtaining accuracy and AUC, we can see that both indicators agree in that
# the ADA Boosting model has been the best one in predicting the results.
# Not only that, but also all the models we created to improve the performance of
# a decision tree have done better as we wanted to. We can also see that Bagging
# and XGBoost have an Area Under the Curve of 0.95, the 2nd best, however, XGBoost
# shows a higher accuracy of the predictions.

# We should be careful when using the accuracy as an indicator of the goodness of 
# our model. Accuracy is more reliable when the data is balanced. In our case:
n.spam = length(spam$type[spam$type == 'spam']) # 1813
n.nospam = length(spam$type) - n.spam           # 2788
# This means that 1813/2788 = 0.65 is not as near to 1 as we would want and our 
# data is imbalanced, so AUC would be a better and more reliable indicator to 
# consider in this case.

# Finally, for this problem, I would choose the models in the following order 
# according to its performance:
# ADA <- XGBOOST <- BAGGING <- RANDOM FOREST <- GBM <- DECISION TREE
