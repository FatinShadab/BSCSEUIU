"""
    Pascal's identity says that,

        (n + 1r + 1) = (nr) + (nr + 1)

    Using Pascal's identity, find the first T
    rows of Pascal's triangle. You will be 
    given T as input. You are only allowed to
    use addition. Multiplication is not
    allowed.

    sample input:
    ---------------
    5

    sample output:
    ---------------
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1

"""

def build_pascal_triangle(t: int) -> list[list[int]]:
    """
        Build Pascal's triangle with 't' rows using only addition.
        
        Parameters:
        t (int): The number of rows to generate.
        
        Returns:
        list[list[int]]: A list of lists representing Pascal's triangle.
    """
    
    triangle: list[list[int]] = [
        [1],  # Initialize with the first row [1]
    ]

    for row in range(1, t):
        current_row = [1]  # Initialize each row with 1

        for col in range(1, len(triangle[row - 1])):
            # Calculate each element using Pascal's identity
            current_row.append(triangle[row - 1][col - 1] + triangle[row - 1][col])

        current_row.append(1)  # Add the last element as 1

        # Append the current row to the triangle
        triangle.append(current_row)

    return triangle

def print_pascal_triangle(t: int) -> None:
    """
        Print Pascal's triangle with 't' rows.
        
        Parameters:
        t (int): The number of rows to print.
        
        Returns:
        None
    """
    for row in build_pascal_triangle(t):
        print(*row)  # Print each row of Pascal's triangle

if __name__ == "__main__":
    t = int(input("Enter the value of t: "))
    print_pascal_triangle(t)  # Generate and print Pascal's triangle with 't' rows
