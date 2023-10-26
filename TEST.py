number = int(input("Enter a 3 digit positive number: "))

first_digit = number // 100
second_digit = (number // 10) % 10
third_digit = number % 10

product = first_digit * second_digit * third_digit

print(f"The product of the 1st and 2nd digits is:{product}")
