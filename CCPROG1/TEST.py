# Step 1: Input the prices of three items
price1 = float(input("Enter the price of the first item: "))
price2 = float(input("Enter the price of the second item: "))
price3 = float(input("Enter the price of the third item: "))

# Step 2: Calculate the discounts
# No discount for the first item
discount1 = 0
# 15% discount for the second item
discount2 = 0.15 * price2
# Discount equal to the average of the first two items for the third item
discount3 = (price1 + price2) / 2

# Step 3: Calculate the total cost
total_cost = price1 - discount1 + price2 - discount2 + price3 - discount3

# Step 4: Output the total cost
print(f"The total cost after applying discounts is: ${total_cost:.2f}")