# Exercises A4 ------------------------------------------------------------
# Name: Pablo Olivares Martinez -------------------------------------------

library(arules)
library(dplyr)

# 1. From the datasets in the Data folder, select one dataset and find 
# association rules in it (minimum 30 rules). Give an interpretation of the 
# rule with the highest support value.

med.tr <- read.transactions(file="Data/medication.csv", format=c("basket"),
                            sep = ",", header = T, cols = NULL, 
                            rm.duplicates = FALSE, skip = 0,
                            encoding = "unknown")

parameters = list(
  support = 0.0025,
  confidence = 0.5,
  minlen = 2, # Minimal number of items per item set
  maxlen = 5 # Maximal number of items per item set
)

freq.items <- apriori(med.tr, parameter = parameters)
summary(freq.items)
freq.items.sort <- sort (freq.items, by="support", decreasing=TRUE)
inspect(freq.items.sort[1]) # Rule with the highest support value

# INTERPRETATION: Here we can see that more than 50% of people who need cefazolin ivpb uh,
# also need hydrocodone acetaminophen 5mg 325mg according to our transactions. According to
# US National Library of Medicine, cefazolin ivpb uh is a drug used to fight bacterial infections
# while hydrocodone acetaminophen 5mg 325mg is used to reduce pain. From this analysis we can
# say that some people who suffer infections are also having pain. However, we have to be
# careful with our assumptions as support=0.112 => only 11.2% of our transactions (50 aprox)
# affirm this with a 54.63% of confidence. 


# 2. Select one item from the collection and find the rules in which the selected
# item is rhs. Give an interpretation of the rule with the highest confidence value.

item = "hydrocodone acetaminophen 5mg 325mg"

# We get all the rules whose unique right-hand side is our item
rules.rhs.hydro <- apriori(med.tr,
                           parameter = list(support=0.0, confidence=0.0),
                           appearance = list(rhs = c(item), default="lhs"))

highest.conf.hydro <- sort(rules.rhs.hydro, by="confidence", decreasing=TRUE)[1]
inspect(highest.conf.hydro) # Item with highest confidence

# INTERPRETATION: Our rule has confidence = 1. This means that every time someone needs 
# aprepitant, he or she will need hydrocodone acetaminophen 5mg 325mg too. Aprepitant
# is a drug only used to reduce some side effects of cancer chemotherapy treatment. This could
# mean that cancer chemotherapy treatment is a painful treatment or aprepitant side effects
# are painful. However, our support (0.0019) implies that ONLY 1 TRANSACTION supports this, 
# which obviously is not enough to take such precipitated conclusions. Maybe we would need 
# more transactions related to these two drugs to study this case.


# 3. Select one of the items from the set (different from the item in subsection 
# 2) and find the rules in which the selected item is lhs. Write the resulting 
# rules into the data frame.
item2 = "cefazolin ivpb uh"
rules.lhs.cefazolin <- apriori(med.tr,
                               parameter = list(support=0.0, confidence=0.0, minlen = 2),
                               appearance = list(lhs = item2, default="rhs"))

inspect(rules.lhs.cefazolin)
rules.lhs.cefazolin.df = data.frame(
  lhs = labels(lhs(rules.lhs.cefazolin)),
  rhs = labels(rhs(rules.lhs.cefazolin)), 
  rules.lhs.cefazolin@quality
  )

# Giving the dataframe head ordered by lift
head(rules.lhs.cefazolin.df[order(rules.lhs.cefazolin.df$lift, decreasing = TRUE),])


# 4. Find the frequentist sets in the selected dataset.

# The frequentist set of the dataset is the one with the biggest support, as 
# support denotates the quotient between the times a set appears in the different
# transactions over the number of transactions.
parameters <- list(support = 0.001,confidence = 0.0,minlen = 1, maxlen = 5)
freq.items <- apriori(med.tr, parameter = parameters)
freq.items.sort <- sort (freq.items, by="support", decreasing=TRUE)
supp <- select(inspect(freq.items.sort[1]), support) # We take the highest support

supp <- max(supp)

parameters2 <- list(
  support = supp, # Take the rules with max support (frequentist sets)
  confidence = 0.0, # We don't want confidence to affect our selection
  minlen = 1, # Minimal number of items per item set (a set can have 1 element)
  maxlen = 5 # Maximal number of items per item set
)

# Now we take only the sets with max support
freq.items <- apriori(med.tr, parameter = parameters2)
inspect(freq.items)

# This means that {fentanyl injection} uh is the most common subset in the dataset with a
# rate of appearance of 39.96%. 
# However, if we wanted to only consider sets with 2 or more elements, we would just have
# to set minlen = 2 in parameters. In this case, the frequentiest set would be
# {cefazolin ivpb uh, hydrocodone acetaminophen 5mg 325mg} with a rate of appearance of 11.17%.