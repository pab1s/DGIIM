# Pablo Olivares Martinez -------------------------------------------------
# Exercise A6 -------------------------------------------------------------

# Load libraries
library(tidyverse)
library(dplyr)
library(cluster)
library(factoextra)
library(pheatmap)

# Read in data
coll <- read_csv("college.csv")

# Clean up data and factorize relevant data to analize
coll$city <- as.factor(coll$city)
coll$state <- as.factor(coll$state)
coll$region <- as.factor(coll$region)
coll$highest_degree <- as.factor(coll$highest_degree)
coll$control <- as.factor(coll$control)
coll$gender <- as.factor(coll$gender)
coll$loan_default_rate <- as.factor(coll$loan_default_rate)

data = coll[-1]
gower_dist <- daisy(data[, -1],metric = "gower")


# Stablish matrix of gower distances 
gower_mat <- as.matrix(gower_dist)

# The most similar values. Here we can see some interesting things. First of all, we can see that
# the similarity in our data is quite influenced by the geographical situation. This is because there
# are many columns which talk about this (city, state, lon, lat). Wjhat is more, we can say that both
# universities have students with a really similar economical and social profile, which could indicate
# that the universities are rivals because both are private and compete for the same population profile.
data[ which(gower_mat == min(gower_mat[gower_mat != min(gower_mat)]), arr.ind = TRUE)[1, ], ]

# The most dissimilar values. Here, again, we can see a strong influence of the location of the universities.
# However, we can identify more interesting things. First of all, I would like to highlight the fact that one
# is public and the other one is private and how this is reflected in other data. We can see that in general,
# more wealthy people go to the private one, where students have less debt. We can also see that Wellesley 
# College seems to be more exclusive as they have a very low admission rate, small number of students and they
# have a really high SAT score.
data[which(gower_mat == max(gower_mat[gower_mat != max(gower_mat)]), arr.ind = TRUE)[1, ], ]

# Creation of the hierarchical cluster and its respective tree
tree.coll <- hclust(gower_dist)
dist.coph <- cophenetic(tree.coll)
cor(gower_dist, dist.coph )
# We can see that the correlation of the cophenetic distances is 0.64. We can see then that 
# this data has not a really good correlation in order to get a nice clusterization. It would be
# much better if it was above 0.75. However, let's try to find relationships between data.

# Seeing the dendogram and the heatmap,  we can see that an acceptable number of clusters could be 8.  
fviz_dend(tree.coll, cex = 0.5, main = "College tree ")
pheatmap(gower_dist, clustering_method="complete", cutree_rows = 8)
heatmap(gower_mat, scale = "none")

# Now let's see the dendogram cutting the tree for k=8
fviz_dend(tree.coll, cex = 0.5, k=8, main = "College tree ")
clust.coll <- cutree(tree.coll, 8)

# Representation in 2D of the clusters.
fviz_cluster(list(data = gower_mat, cluster = clust.coll),
             ellipse.type = "convex",
             repel = TRUE,
             main = "Clusters in College",
             show.clust.cent = FALSE, ggtheme = theme_minimal())

# Set the clusters to the data
data.cl=cbind(data, clust.coll)
# Mutate private/public to bool to make it easier to count
data.cl <- data.cl %>%
  mutate(control = (control == "Private"))
colnames(data.cl)[6] <- "private"

# Description of clusters
data.cl %>% 
  group_by(clust.coll) %>%
  summarise(
    number.of.obs= n(),
    average.threshold.of.admission=mean(admission_rate),
    av.region=mean(as.numeric(region)),
    sat_avg=mean(sat_avg),
    private.coll=sum(private),
    state.coll=n()-private.coll
  )
# Let's analyze this summary. Here we can see a clusterization very influenced by location. From all the
# clusters, we can identify a relative small cluster (cluster 5) characterized by its high SAT average, 
# mainly private colleges and really small rate of admission. This seems to be a very exclusive group of
# universities which are in the elite of colleges. About the other clusters, we can see that they are quite
# related by proximity of the region and if they are private or public. Maybe it could have been more interesting
# to exlude some parameters of location in order to see how are they related. However, the correlation of the
# cophenetic distances is even worse than the one we are using, so it would be more difficult to characterize
# the clusters.

# Cluster validation
clust.coll.eclust<- eclust(gower_mat, "hclust", k = 8, stand = TRUE, nstart = 25, graph = FALSE)

fviz_cluster(clust.coll.eclust, gower_mat, geom = "point", repel = FALSE, 
             ggtheme = theme_classic())

fviz_silhouette(clust.coll.eclust, palette = "jco", ggtheme = theme_classic())
# observations in the wrong cluster 
silinfo <- clust.coll.eclust$silinfo
silinfo
sil <- clust.coll.eclust$silinfo$widths
neg <- which(sil$sil_width < 0)
sil[neg, , drop = FALSE]
rn<-rownames(sil[neg, , drop = FALSE] )
data[rn,]

# Now, interpreting the SiSi coefficient we see that SiSi = 0.35. This means that our clusterization is not very
# good however it is not that bad. We have more than 100 values with negative silhouette coefficient, which is less
# than 10% of our data. However, maybe we should consider this and try to see if there is a better clusterization 
# without having to cluster too much our data.
