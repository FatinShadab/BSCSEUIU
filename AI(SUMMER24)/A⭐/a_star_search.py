import os
import math
import heapq
import pprint
import random

class ASTAR:
    class Node:
        def __init__(self, x=0, y=0, w=float('inf'), heuristic=0):
            """
            Initialize a new node.

            :param x: X-coordinate of the node.
            :param y: Y-coordinate of the node.
            :param w: Weight (g-value) of the node.
            :param heuristic: Heuristic (h-value) of the node.
            """
            self.parent = None
            self.x = x
            self.y = y
            self.w = w
            self.heuristic = heuristic
            self.f = self.w + self.heuristic

        def set_parent(self, parent):
            """
            Set the parent of the node.

            :param parent: Parent node.
            """
            self.parent = parent

        def set_xy(self, x, y):
            """
            Set the coordinates of the node.

            :param x: X-coordinate.
            :param y: Y-coordinate.
            """
            self.x = x
            self.y = y

        def set_params(self, w, heuristic):
            """
            Set the parameters of the node.

            :param w: Weight (g-value) of the node.
            :param heuristic: Heuristic (h-value) of the node.
            """
            self.w = w
            self.heuristic = heuristic
            self.f = self.w + self.heuristic

        def __lt__(self, other):
            """
            Less-than comparison based on f-value.

            :param other: Another node.
            :return: True if this node's f-value is less than the other's, False otherwise.
            """
            return self.f < other.f

    def __init__(self):
        """
        Initialize the A* solver with empty structures.
        """
        self.__frontier = []
        self.__node_details = []
        self.__visited = []

        self.__heuristic_func = {
            "euclidean": self.__euclidean_heuristic,
            "manhattan": self.__manhattan_heuristic
        }
        self.dir = {
            "up": (-1, 0),
            "down": (1, 0),
            "left": (0, -1),
            "right": (0, 1)
        }

    def __reset(self):
        """
        Reset the solver's internal structures for a new search.
        """
        self.__frontier = []
        self.__node_details = []
        self.__visited = []

    def __is_valid(self, x, y, grid):
        """
        Check if a position is within the grid bounds and not an obstacle.

        :param x: X-coordinate.
        :param y: Y-coordinate.
        :param grid: The grid.
        :return: True if the position is valid, False otherwise.
        """
        return 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 0
    
    def __is_free_path(self, x, y, grid):
        """
        Check if a position is not an obstacle.

        :param x: X-coordinate.
        :param y: Y-coordinate.
        :param grid: The grid.
        :return: True if the position is free, False otherwise.
        """
        return grid[x][y] == 0
    
    def __is_destination(self, x, y, dest):
        """
        Check if a position is the destination.

        :param x: X-coordinate.
        :param y: Y-coordinate.
        :param dest: Destination coordinates.
        :return: True if the position is the destination, False otherwise.
        """
        return x == dest[0] and y == dest[1]
    
    def __euclidean_heuristic(self, x, y, dest):
        """
        Calculate the heuristic (Euclidean distance) from (x, y) to the destination.
        
        :param x: X-coordinate.
        :param y: Y-coordinate.
        :param dest: Destination coordinates.
        :return: The heuristic value.
        """
        return math.sqrt((x - dest[0]) ** 2 + (y - dest[1]) ** 2)

    def __manhattan_heuristic(self, x, y, dest):
        """
        Calculate the heuristic (Manhattan distance) from (x, y) to the destination.
        
        :param x: X-coordinate.
        :param y: Y-coordinate.
        :param dest: Destination coordinates.
        :return: The heuristic value.
        """
        return abs(x - dest[0]) + abs(y - dest[1])

    def __trace_path(self, dest_node):
        """
        Trace back the path from the destination node to the source node.

        :param dest_node: The destination node.
        :return: The traced path as a list of coordinates.
        """
        path = []
        current = dest_node
        while current.parent:
            path.append((current.x, current.y))
            current = current.parent
        path.append((current.x, current.y))
        return path[::-1]

    def __simulate(self, grid, current, dest):
        """
        Simulate the search process by printing the grid with the current state.
        :param grid: The grid.
        :param current: The current node.
        :param dest: The destination coordinates.
        """
        grid_mask = [['⬛' if value == 1 else "⬜" for value in row] for row in grid]

        for row in self.__node_details:
            for node in row:
                if node.w != float('inf'):
                    grid_mask[node.x][node.y] = f"{node.f:02d}"

        grid_mask[dest[0]][dest[1]] = "⭐"
        grid_mask[current.x][current.y] = "🤖"
        
        for row in grid_mask:
            print(*row)

        input("Press Enter to continue...")
        os.system("cls" if os.name == "nt" else "clear")

    def search_unw_grid(self, grid, src, dest, tree_mode=False, heuristic="euclidean", simulation=False):
        """
        Perform A* search on an unweighted grid.

        :param grid: The grid (2D list of integers).
        :param src: Source coordinates (tuple).
        :param dest: Destination coordinates (tuple).
        :param tree_mode: If True, don't use visited set (for tree structures).
        :param heuristic: The heuristic function to use.
        :return: A dictionary with the search results.
        """
        self.__reset()

        # Check if the source and destination are valid
        if not self.__is_valid(src[0], src[1], grid) or not self.__is_valid(dest[0], dest[1], grid):
            print("Invalid source or destination")
            return None
        
        # Check if the source is the destination
        if self.__is_destination(src[0], src[1], dest):
            print("Source is the destination")
            return None
        
        # Initialize nodes
        self.__node_details = [[ASTAR.Node() for _ in range(len(grid[0]))] for _ in range(len(grid))]
        if not tree_mode:
            self.__visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]

        # Setup source node
        src_node = self.__node_details[src[0]][src[1]]
        src_node.set_xy(*src)
        src_node.set_params(0, self.__heuristic_func[heuristic](src[0], src[1], dest))
        src_node.set_parent(None)

        heapq.heappush(self.__frontier, src_node)
        found_dest = False

        while self.__frontier:
            current = heapq.heappop(self.__frontier)
            if not tree_mode:
                self.__visited[current.x][current.y] = True

            if self.__is_destination(current.x, current.y, dest):
                found_dest = True
                break

            for d in self.dir.values():
                x, y = current.x + d[0], current.y + d[1]

                if self.__is_valid(x, y, grid) and self.__is_free_path(x, y, grid):
                    if not tree_mode and self.__visited[x][y]:
                        continue

                    new_w = current.w + 1
                    new_heuristic = self.__heuristic_func[heuristic](x, y, dest)
                    new_f = new_w + new_heuristic

                    if self.__node_details[x][y].f > new_f:
                        self.__node_details[x][y].set_xy(x, y)
                        self.__node_details[x][y].set_params(new_w, new_heuristic)
                        self.__node_details[x][y].set_parent(current)
                        heapq.heappush(self.__frontier, self.__node_details[x][y])

                    if simulation:
                        self.__simulate(grid, current, dest)

        return {
            "status": "success" if found_dest else "failure",
            "grid": grid,
            "source": src,
            "destination": dest,
            "path": self.__trace_path(self.__node_details[dest[0]][dest[1]]) if found_dest else None,
            "node-visited": self.__visited if not tree_mode else None,
            "node-heuristic": [[node.heuristic for node in row] for row in self.__node_details],
            "node-g-value": [[node.w if node.w != float('inf') else "∞" for node in row] for row in self.__node_details]
        }

    def get_random_test_grid_case(self, max_x=10, max_y=10, prob=0.3):
        """
        Generate a random test case for the grid.

        :param max_x: Maximum number of rows.
        :param max_y: Maximum number of columns.
        :param prob: Probability of a cell being an obstacle.
        :return: A tuple containing the grid, source, and destination coordinates.
        """
        grid = [[0 for _ in range(max_y)] for _ in range(max_x)]
        src = [0, 0]
        dest = [0, 0]
        for i in range(max_x):
            for j in range(max_y):
                if random.random() < prob:
                    grid[i][j] = 1
                else:
                    if random.random() * random.random() < prob * random.choice([0.1, 0.2, 0.3, 0.4, 0.5]):
                        src = [i, j]
                    if random.random() * random.choice([0.1, 0.2, 0.3, 0.4, 0.5]) < prob * random.random():
                        dest = [i, j]

        return (grid, src, dest)


if __name__ == "__main__":
    pp = pprint.PrettyPrinter(depth=4)
    solver = ASTAR()

    random_test = True

    if random_test:
        grid, src, dest = solver.get_random_test_grid_case(random.choice(range(25)), random.choice(range(25)), 0.33)
    else:
        grid = (
            (0, 0, 0, 0, 0),
            (0, 0, 1, 0, 1),
            (0, 1, 1, 1, 0),
            (0, 0, 0, 1, 0),
            (0, 0, 0, 0, 0)
        )

        src = (0, 0)
        dest = (2, 4)

    solve = solver.search_unw_grid(grid, src, dest, heuristic="manhattan", simulation=True)

    pp.pprint(solve)
