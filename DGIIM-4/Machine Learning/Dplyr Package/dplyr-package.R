# Author: Pablo Olivares Martinez
# Exercise A2
# Create a random vector v of 30 integers numbers from the interval [-100,100]
v = sample(-100:100, 30, replace=TRUE)

# 1 - check if zero has been drawn in v
0 %in% v

# 2 - how many positive and negative numbers were drawn?
neg.v = v[v < 0]
pos.v = v[v >= 0]
print(paste("Number of negative elements of v:", length(neg.v)))
print(paste("Number of positive elements of v:", length(pos.v)))

# 3 - for the negative values of v find the minimum and maximum, and their location
min.neg.v = min(neg.v)
max.neg.v = max(neg.v)
min.neg.v.index = which(v == min.neg.v)
max.neg.v.index = which(v == max.neg.v)
print(paste("Minimum of the negative elements of v is", min.neg.v, "at position", min.neg.v.index))
print(paste("Maximum of the negative elements of v is", max.neg.v, "at position", max.neg.v.index))

# 4 - at position 5,10,22 generate missing values
v[c(5,10,22)] = NA
print(v)

# 5 - find the sum and median for the negative values of v
neg.v.sum = sum(neg.v)
neg.v.median = median(neg.v)
print(paste("Sum of the negative elements of v:", neg.v.sum))
print(paste("Median of the negative elements of v:", neg.v.median))

# 6 - find the product of v
# Here we ignore the NA values to compute the product, if not, it would return 'NA'
v.prod = prod(v, na.rm = TRUE)
print(paste("Product of the elements of v:", v.prod))

