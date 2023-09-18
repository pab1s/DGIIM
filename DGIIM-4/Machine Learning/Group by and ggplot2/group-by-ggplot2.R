
# Exercise A3 -------------------------------------------------------------
## Pablo Olivares Martinez ------------------------------------------------

library(ggplot2)
library(dplyr)

# First we import the needed libraries
pets = read.csv("http://imul.math.uni.lodz.pl/~bartkiew/ml/data/pets.csv")

# 1. Group the data by pet species (pet). Determine the average age, average 
#    weight, and highest grade in each group of pets.
pets |>
  group_by(pet) |>
  summarise(
    age.average = mean(age),
    weight.average = mean(weight),
    grade.max = max(score)
  )

# 2. Give the number of animals in each group, according to country of residence.
pets |>
  group_by(pet, country) |>
  summarise(
    num.animals = n()
  )

# 3. Draw a graph of the relationship of the variable age to weight, by species.
ggplot(pets) +
  aes(x = weight, y = age, col = pet) +
  geom_point() +
  ggtitle("Relationship of age to weight") +
  xlab("Weight (kg)") +
  ylab("Age (years)")


