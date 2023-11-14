# Step 1: Input a random number from the user
random_number = int(input("Enter a random number (1 to 36): "))

# Step 2: Calculate the chosen hat based on the random number
chosen_hat = random_number % 3 + 1

# Step 3: Output the chosen hat
print(f"If you choose random number {random_number}, the chosen hat is Hat {chosen_hat}")