# Author: Pablo Olivares Martinez

import random

class RSAKeyGenerator:
    """RSA key generator class."""

    @staticmethod
    def generate_key(key_size):
        """
        Generate RSA key pair.

        Args:
            key_size (int): The size of the key in bits.

        Returns:
            tuple: Tuple containing the public key (n, e) and the private key (n, d).
        """
        p = RSAKeyGenerator._generate_prime(key_size // 2)
        q = RSAKeyGenerator._generate_prime(key_size // 2)
        n = p * q
        phi = RSAUtils.calculate_phi_euler(p, q)
        e = RSAUtils.choose_public_exponent(phi)
        d = RSAUtils.mod_inverse(e, phi)
        return (n, e), (n, d)

    @staticmethod
    def _generate_prime(key_size):
        """
        Generate a random prime number of the specified key size.

        Args:
            key_size (int): The size of the prime number in bits.

        Returns:
            int: The generated prime number.
        """
        while True:
            num = random.getrandbits(key_size)
            if RSAKeyGenerator._is_prime(num):
                return num

    @staticmethod
    def _is_prime(num):
        """
        Check if a number is prime.

        Args:
            num (int): The number to check.

        Returns:
            bool: True if the number is prime, False otherwise.
        """
        if num < 2:
            return False
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
        return True


class RSAUtils:
    """RSA utility class."""

    @staticmethod
    def calculate_phi_euler(p, q):
        """
        Calculate the Euler's totient function value (phi) for the given prime factors.

        Args:
            p (int): The first prime factor.
            q (int): The second prime factor.

        Returns:
            int: The Euler's totient function value (phi).
        """
        return (p - 1) * (q - 1)

    @staticmethod
    def choose_public_exponent(phi):
        """
        Choose a public exponent (e) within the range (2, phi) that is coprime with phi.

        Args:
            phi (int): The Euler's totient function value (phi).

        Returns:
            int: The chosen public exponent (e).
        """
        while True:
            e = random.randint(2, phi - 1)
            if RSAUtils.gcd(e, phi) == 1:
                return e

    @staticmethod
    def gcd(a, b):
        """
        Calculate the greatest common divisor (GCD) of two numbers.

        Args:
            a (int): The first number.
            b (int): The second number.

        Returns:
            int: The greatest common divisor (GCD) of the two numbers.
        """
        while b != 0:
            a, b = b, a % b
        return a

    @staticmethod
    def mod_inverse(a, m):
        """
        Calculate the modular inverse of a number (a) modulo m.

        Args:
            a (int): The number.
            m (int): The modulus.

        Returns:
            int: The modular inverse of the number (a) modulo m.

        Raises:
            ValueError: If the modular inverse does not exist.
        """
        _, x, _ = RSAUtils.egcd(a, m)
        return x % m

    @staticmethod
    def egcd(a, b):
        """
        Extended Euclidean algorithm to calculate the greatest common divisor (GCD)
        and the Bézout's coefficients (x, y) of two numbers.

        Args:
            a (int): The first number.
            b (int): The second number.

        Returns:
            tuple: Tuple containing the greatest common divisor (GCD) and the Bézout's coefficients (x, y).
        """
        if a == 0:
            return b, 0, 1
        else:
            gcd, x, y = RSAUtils.egcd(b % a, a)
            return gcd, y - (b // a) * x, x
      
    @staticmethod
    def factorize_modulus(n):
        """
        Factorize the modulus (n) into its prime factors (p, q).

        Args:
            n (int): The modulus.

        Returns:
            tuple: Tuple containing the prime factors (p, q).

        Raises:
            ValueError: If the modulus cannot be factorized.
        """
        p = 2
        while p * p <= n:
            if n % p == 0:
                q = n // p
                return p, q
            p += 1
        raise ValueError("Unable to factorize the modulus")

    @staticmethod
    def break_rsa(public_key):
        """
        Break RSA encryption by finding the private key.

        Args:
            public_key (tuple): Tuple containing the public key (n, e).

        Returns:
            tuple: Tuple containing the broken private key (n, d).
        """
        n, e = public_key
        p, q = RSAUtils.factorize_modulus(n)
        phi = RSAUtils.calculate_phi_euler(p, q)
        d = RSAUtils.mod_inverse(e, phi)
        return n, d


class RSA:
    """RSA encryption and decryption class."""

    @staticmethod
    def encrypt(message, public_key):
        """
        Encrypt a message using RSA.

        Args:
            message (str): The message to encrypt.
            public_key (tuple): Tuple containing the public key (n, e).

        Returns:
            list: List of encrypted message values.
        """
        n, e = public_key
        encrypted_message = [pow(ord(char), e, n) for char in message]
        return encrypted_message

    @staticmethod
    def decrypt(encrypted_message, private_key):
        """
        Decrypt an encrypted message using RSA.

        Args:
            encrypted_message (list): List of encrypted message values.
            private_key (tuple): Tuple containing the private key (n, d).

        Returns:
            str: The decrypted message.
        """
        n, d = private_key
        decrypted_message = [chr(pow(char, d, n)) for char in encrypted_message]
        return "".join(decrypted_message)
