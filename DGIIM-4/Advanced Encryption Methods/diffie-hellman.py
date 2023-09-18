# Author: Pablo Olivares Martinez

import random

class DiffieHellman:
    def __init__(self, shared_prime, shared_base):
        # Initialize the shared prime and base values (agreed upon by both parties)
        self.shared_prime = shared_prime
        self.shared_base = shared_base

        # Initialize private key, public key, and shared secret as None
        self.private_key = None
        self.public_key = None
        self.shared_secret = None

    def generate_private_key(self):
        # Generate a random private key for this party
        self.private_key = random.randint(1, self.shared_prime - 1)

    def calculate_public_key(self):
        # Calculate the public key based on the private key and shared values
        if self.private_key is None:
            raise ValueError("Private key not generated.")
        self.public_key = self.mod_exp(self.shared_base, self.private_key, self.shared_prime)

    def calculate_shared_secret(self, other_party_public_key):
        # Calculate the shared secret based on the other party's public key and own private key
        if self.private_key is None:
            raise ValueError("Private key not generated.")
        self.shared_secret = self.mod_exp(other_party_public_key, self.private_key, self.shared_prime)

    @staticmethod
    def mod_exp(base, exponent, modulus):
        # Calculate modular exponentiation efficiently using the square-and-multiply algorithm
        result = 1
        while exponent > 0:
            if exponent % 2 == 1:
                result = (result * base) % modulus
            base = (base * base) % modulus
            exponent //= 2
        return result

# Example usage:
shared_prime = 23
shared_base = 5

alice = DiffieHellman(shared_prime, shared_base)
bob = DiffieHellman(shared_prime, shared_base)

# Alice and Bob generate their private keys
alice.generate_private_key()
bob.generate_private_key()

# Alice and Bob calculate their public keys
alice.calculate_public_key()
bob.calculate_public_key()

# Alice and Bob calculate the shared secret
alice.calculate_shared_secret(bob.public_key)
bob.calculate_shared_secret(alice.public_key)

# Print the shared secrets
print("Shared Secret (Alice):", alice.shared_secret)
print("Shared Secret (Bob):", bob.shared_secret)

