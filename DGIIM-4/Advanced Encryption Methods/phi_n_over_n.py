# Author: Pablo Olivares
# Date: 05-06-2023

import matplotlib.pyplot as plt

# Function to calculate the greatest common divisor using the Euclidean algorithm
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Function to calculate Euler's totient function (phi) for a given number (n)
def euler_phi(n):
    print("Calculating Euler's totient function (phi) for n = " + str(n))
    count = 0
    # Iterate over the range of numbers from 1 to n
    for i in range(1, n + 1):
        # Check if i is coprime with n by checking if their gcd is 1
        if gcd(n, i) == 1:
            count += 1
    return count

# Efficient implementation of Euler's totient function (phi) for a given number (n)
def euler_phi_efficient(n):
    print("Calculating Efficient Euler's totient function (phi) for n = " + str(n))
    phi = n  # Initialize phi as n
    
    # Iterate through prime numbers up to the square root of n
    p = 2
    while p * p <= n:
        if n % p == 0:
            # p is a prime factor of n
            while n % p == 0:
                n //= p
            phi -= phi // p  # Update phi using Euler's product formula
        p += 1
    
    # If n has a prime factor greater than sqrt(n)
    if n > 1:
        phi -= phi // n
    
    return phi


# Generate the x-axis values as a list from 1 to 300,000
x = list(range(1, 300001))
# Calculate the y-axis values by dividing Euler_phi(n) by n for each n in the range
y = [euler_phi_efficient(n) / n for n in x]

# Plot the chart
plt.plot(x, y)
plt.xlabel('n')
plt.ylabel('Euler_phi(n) / n')
plt.title('Euler_phi(n) / n')
plt.grid(True)
plt.show()
