"""
Task 2: Approximating π

Consider the vertical axis as 𝑌-axis and the horizontal axis as 𝑋-axis.
Take a circle with a radius of 1 and center it at the origin 𝑂(0, 0).
This circle sits inside a square of side length 2, as shown in the figure below.

Circle in Square

Your task is to approximate the value of π (pi) using a Monte Carlo simulation.
You will be given an integer 𝑇 as input, representing the number of random points
to generate within the square.

To approximate π, follow these steps:

    Generate 𝑇 random points inside the square. To do this, generate two random 
    numbers 𝑥 and 𝑦, both between -1 and 1. These coordinates, (𝑥, 𝑦), will give 
    you random points inside the square.

    Check if each generated point is inside the circle with radius 1. You can use
     the distance formula to check if a point is inside the circle. If the distance
      between the point (𝑥, 𝑦) and the origin (0, 0) is less than or equal to 1, the
       point is inside the circle.

    Count the number of points that fall inside the circle, denoted as 𝑀.

    Calculate the approximate value of π using the formula:

    𝜋 (pi) ≈ 4 * (𝑀 / 𝑇)

Your task is to implement this approximation method in a Python program. Read the integer 𝑇 
from input, perform the calculations, and print the approximate value of π as output.

Input:

    An integer 𝑇 (1 ≤ 𝑇 ≤ 10^6) representing the number of random points to generate within 
    the square.

Output:

    A float representing the approximate value of π (pi) based on the generated random points.
     The output should be accurate to several decimal places.
"""

import random

def point_inside_circle(point_x_coord: float, point_y_coord: float, circle_radius: int) -> bool:
    """
        Checks if a point with given coordinates is inside a circle with the specified radius.
        
        Args:
        point_x_coord (float): The x-coordinate of the point.
        point_y_coord (float): The y-coordinate of the point.
        circle_radius (int): The radius of the circle.
        
        Returns:
        bool: True if the point is inside the circle, False otherwise.
    """
    return (point_x_coord ** 2 + point_y_coord ** 2) <= circle_radius

def get_approximate_pi(T: int) -> float:
    """
        Approximates the value of π using a Monte Carlo method.
        
        Args:
        T (int): The number of random points to generate.
        
        Returns:
        float: The approximate value of π.
    """
    valid_random_points = 0
    
    circle_radius = 1
    square_side = 2
    valid_point_range = (-1, 1)

    for _ in range(T):
        x_coord = random.uniform(valid_point_range[0], valid_point_range[1])
        y_coord = random.uniform(valid_point_range[0], valid_point_range[1])

        if point_inside_circle(x_coord, y_coord, circle_radius):
            valid_random_points += 1
    
    return (valid_random_points / T) * 4


if __name__ == "__main__":
    T = int(input("Enter the number of random points (T): "))
    
    approxPI = get_approximate_pi(T)

    print(f"Approximate value of π: {approxPI}")
