# Create a diamond star pattern using Python
def diamond_star_pattern(n):
    # Upper part of the diamond
    for i in range(n):
        print(' ' * (n - i - 1) + '*' * (2 * i + 1))
    
    # Lower part of the diamond
    for i in range(n - 2, -1, -1):
        print(' ' * (n - i - 1) + '*' * (2 * i + 1))


if __name__ == "__main__":
    try:
        rows = int(input("Enter the number of rows: "))
        if rows < 1:
            print("Please enter a positive integer.")
        else:
            diamond_star_pattern(rows)
    except ValueError:
        print("Please enter a whole number.")