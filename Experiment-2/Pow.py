def power(num, pow):
    # Handle the special case where the power is 0
    if pow == 0:
        return 1  # Any number raised to the power of 0 is 1

    # Handle negative exponents
    if pow < 0:
        # Convert the base number to its reciprocal
        num = 1.0 / num
        # Convert the power to positive
        pow = -pow

    # Initialize result to 1
    result = 1.0

    # Loop to multiply num by itself pow times
    for _ in range(pow):
        result *= num  # Multiply result by num in each iteration

    # Return the final result after pow multiplications
    return result


num = float(input("Enter the number: "))  # Read the base number from user input
pow = int(input("Enter the power of the number: "))  # Read the exponent value from user input

# Call the power function and store the result
result = power(num, pow)

# Output the result to the user
print("Result:", result)