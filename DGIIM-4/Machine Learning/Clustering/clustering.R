
# Author: Pablo Olivares Martinez -----------------------------------------
# Exercise A5: For the Country-data.csv collection, apply the partitionig clustering method. 
# Describe the resulting clusters (as a comment in the script).

library(cluster)
library(factoextra)
library(dplyr)

# STEP 1: Data Preparation.
# First, we have to remove non numeric values and scale all data to the same 
# interval of reference, as they have different units.
df=read.csv("Country-data.csv")
df.scaled <- scale(df[-1])
row.names(df.scaled) <- df$country
summary(df)


# STEP 2: Assessing clustering tendency.
# Now, we have to evaluate if our data set is valid for clustering. To do this,
# I will use Hopkins statistic and the dissimilarity heat map.
res <- get_clust_tendency(df.scaled, 40, graph = TRUE)
res$hopkins_stat
res$plot
# As we can see Hopkins statistic is next to 1, so our data set is highly clustered.
# Also the heat map shows as that there are several possible valid clusterizations.
# Let's see which is the best option for k.


# STEP 3:-Defining the optimal number of cluster.
# Now we will set a max value for k, as we are not interested in getting more than
# 15 clusters in this case. Using the gap statistic method and the silhouette 
# method I will set 2 different values for k.
k.max <- 15 
wss <- sapply(1:k.max, function(k){kmeans(df.scaled , k, nstart = 50)$tot.withinss})

# Elbow method -> k = ? Here I can't see clearly where the elbow is.
plot(1:k.max, wss, type = "b", pch = 19, 
     xlab = "number of clusters - k", 
     ylab = "Sum of squares of distances within a cluster")

# Silhouette method -> k = 5
fviz_nbclust(df.scaled, kmeans, method = "silhouette")+
  labs(subtitle = "Silhouette method")

# Gap Statistic method -> k = 3
fviz_nbclust(df.scaled, kmeans, nstart = 25, method = "gap_stat", nboot = 50)+
  labs(subtitle = "Gap")


# STEP 4:-Computing cluster analysis K Means clustering for k = 3 & k = 5
km3 <- kmeans(df.scaled , 3, nstart = 50)
km5 <- kmeans(df.scaled , 5, nstart = 50)

# Now we visualize both clusterizations
fviz_cluster(km3, data = df.scaled, geom = c("point", "text"), main = "Clusters in Country (3 clusters)")
fviz_cluster(km5, data = df.scaled, geom = c("point", "text"), main = "Clusters in Country (5 clusters)")


# STEP 5:-Validating clustering analysis
# To validate and evaluate our clusterizations, we have to obtain the silhouette 
# measures (SiSi). SiSi close to 1 implies the object is well clustered. SiSi 
# close to -1 implies the object is poorly clustered.
# First we get the silhouette measures
km3.sil <- silhouette(km3$cluster, dist(df.scaled))
km5.sil <- silhouette(km5$cluster, dist(df.scaled))
# Stablish the name of the countries to its values
rownames(km3.sil) <- df$country
rownames(km5.sil) <- df$country
# Print the output
km3.sil
km5.sil
# See which countries are poorly clustered
neg_km3.sil_index <- which(km3.sil[, "sil_width"] < 0)
neg_km5.sil_index <- which(km5.sil[, "sil_width"] < 0)
km3.sil[neg_km3.sil_index, , drop = FALSE]
km5.sil[neg_km5.sil_index, , drop = FALSE]
# Obviously, if we have more and more clusters, the SiSi will be lower every time.
# However, this is why we tried to figure out the optimal number of clusters 
# previously. In my case, I consider that 7 countries with negative silhouette 
# values is enough to be considered (the difference between both). So from now, 
# I will continue with k = 5.


# FINAL STEP: Conclusions about the clustered data.
# First let's see graphically some of the relationships
fviz_cluster(km5, data = df.scaled, choose.vars = c("life_expec", "income"), geom = c("point", "text"))
# Here we can see that countries with high income tend to have more life expectancy, 
# where groups 1 and 2 have the best results.
fviz_cluster(km5, data = df.scaled, choose.vars = c("life_expec", "health"), geom = c("point", "text"))
# What is more, countries with low health do also have low life expectancy. We can 
# see that countries from group 4 are the ones who struggle more with this situation.
fviz_cluster(km5, data = df.scaled, choose.vars = c("child_mort", "income"), geom = c("point", "text"))
# Here we appreciate that countries with higher income have less child mortality rate.
# Again, countries of groups 1 and 2 are the ones with both income and children mortality
# ratio and group 4 the ones who are in the worst situation.

# Finally, let's take a look to the summarized data to make the conclusions
countries<-cbind(df.scaled,km5$cluster)
aggregate(countries, by=list(cluster = km5$cluster), mean)

# CONCLUSIONS: Then we can make the conclusion that countries from groups 1 and 2
# have very good health, income and life expectancy while having a moderate
# inflation and very low children mortality. On the other hand, countries from groups 3 and 4
# have really high children mortality, very low life expectancy and the lowest income, so they would
# not be in a very good situation. The main reason why they are in different clusters is
# because even they share many similarities, there are some attributes which are quite 
# different one from another. In 1 and 2, the imports and exports are quite different while
# in 3 and 4 the inflation is the main differentiator. About cluster 5, we can say that there are countries
# which are not very good in any attribute but also not very bad in anyone.

