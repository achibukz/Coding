water_tank = int(input("Enter the amount of water in the tank (in mL): "))

one_liter_bottle = water_tank // 1000 
remaining_water = water_tank % 1000 

two_fifty_ml_bottle = remaining_water // 250

print(f"1L bottles filled: {one_liter_bottle} \n250mL bottles filled: {two_fifty_ml_bottle}")
