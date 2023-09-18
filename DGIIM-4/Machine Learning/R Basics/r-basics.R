# Author: Pablo Olivares Martinez
# This script contains the first exercise of the A1 homework
# We create the vectors which contains the number of muffins sold per day and person
kate.muffins = c(22,18,23,20,16,20)
lucy.muffins = c(32,18,24,18,20,16)

# Then we calculate the amount of money obtained by each one each day and both together
kate.donations = 12*kate.muffins
lucy.donations = 15*lucy.muffins
donations = kate.donations + lucy.donations

# Next we print the total amount of money per day using a for loop
# I do it in this way to show explicitly the day
for (i in 1:6) {
  print(paste("Total donations that they collected for day", i, ":", donations[i]))
}

# Here we obtain the total amount of money obtained individually
kate.total = sum(kate.donations)
lucy.total = sum(lucy.donations)

# Finally we print this quantity
print(paste("Total profit of Kate: ", kate.total))
print(paste("Total profit of Lucy: ", lucy.total))