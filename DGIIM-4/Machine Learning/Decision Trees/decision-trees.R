
# Exrcise A7 --------------------------------------------------------------
# Pablo Olivares Martinez -------------------------------------------------
library(rattle)
library(caTools)
library(rpart)

# Read dataset and clean it for its analysis
data <- read.csv("bank_data.csv")
data <- data[-1]  # Remove IDs

for (col in 1:ncol(data)) {
  if (is.character(data[,col])) {
    data[col] <- as.factor(data[,col])  # Convert to factor non-numeric data
  }
}

set.seed(0) # For replication

# Split data in training set and test set
split <- sample.split(data$y, SplitRatio = 0.7)
training_set <- subset(data, split == TRUE)
test_set <- subset(data, split == FALSE)

# Check if the distribution of data is good enough
prop.table(table(data$y))
prop.table(table(training_set$y))
prop.table(table(test_set$y))

# Tree 1: Pruned tree.
model <- rpart(formula = y ~ ., data = training_set) # Default control
model
fancyRpartPlot(model)   # Plot the tree

asRules(model)  # Set of rules equivalent to the model
y_pred <- predict(model, newdata = test_set, type = 'class')  # Try to predict the output using the model
table(test_set$y, y_pred) # See the results of the test set compared to the real ones
# Comparing the prediction with the real data of the test set, we can see that the model classifies really well
# the negative results. However, it fails predicting 2/3 of the affirmative results.

# Tree 2: No pruning.
control <- rpart.control(cp=0, minbucket=0) # Complexity parameter to 0, minimum size of terminal nodes to 0
model.full <- rpart(y ~ .,data = training_set,control=control)
model.full
fancyRpartPlot(model.full)

model.full.pred<-predict(model.full , test_set ,type = "class")
table(test_set$y,model.full.pred)
# In the full model, we can see that this is a bit worse predicting negative results but better classifying
# affirmative ones. Nevertheless, it is important to appreciate the fact that most of the values have a 
# negative output so we will have to compare the accuracy to see which one is better.

# Compare the two models using only the ACC ratio.
acc<-function(y1,y2){
  sum(y1==y2)/length(y1)
}

acc(test_set$y,y_pred)  # ACC Ratio: 0.900612
acc(test_set$y,model.full.pred) # ACC Ratio: 0.8729632

# According to the accuracy ratio, The pruned tree is a better option, as the accuracy is higher. 
# This could be because the not pruned model is overfiting so it gets worse results for the 
# prediction.
