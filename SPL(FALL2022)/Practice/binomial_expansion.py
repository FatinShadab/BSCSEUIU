"""
    Task 3: Generating binomial expansion

    You are given 3 numbers 𝑎, 𝑏, 𝑛 as input. Generate the binomial expansion of (𝑎𝑥 + 𝑏𝑦) .
    How to find (𝑛 𝑟 ) for 1≤𝑟≤𝑛? If you did task 1, you can use the 𝑛th row of Pascal’s 
    triangle from there.

    Sample Input    |     Sample Output
    ----------------|-------------------------------------------------------
    4 3 2           |     (4x+3y)^2 = 16(x^2)(y^0)+24(x^1)(y^1)+9(x^0)(y^2)
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

def generate_binomial_expansion(a : int, b : int, n : int) -> None:
    """
        Generate and print the binomial expansion of (ax + by)^n.

        Parameters:
        a (int): The coefficient of the x term.
        b (int): The coefficient of the y term.
        n (int): The exponent to which the binomial is raised.

        Returns:
        None: This function does not return a value, it prints the result.

        Example:
        >>> generate_binomial_expansion(4, 3, 2)
        (4x + 3y)^2 = 16(x^2)(y^0) + 24(x^1)(y^1) + 9(x^0)(y^2)
    """

    expression : list[str] = []  # Initialize a list to store the individual terms of the expansion
    pascal_triangle : list[list[int]] = build_pascal_triangle(n+1)  # Build Pascal's triangle

    # Calculate each term of the binomial expansion
    for p in range(n+1):
        math_term = pascal_triangle[n][p] * (a ** (n - p)) * (b ** p)
        expression.append(f"{math_term}(x^{n-p})(y^{p})")

    # Print the binomial expansion
    print(f"({a}x + {b}y)^{n} = " + " + ".join(expression))


if __name__ == "__main__":
    a, b, n = tuple(map(int, input("Enter the value of a, b, n : ").split()))
    
    generate_binomial_expansion(a, b, n)
