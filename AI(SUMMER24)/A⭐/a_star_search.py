import heapq
import pprint
import random

class ASTAR:
    class Node:
        def __init__(self, x=0, y=0, w=float('inf'), heuristic=0):
            self.parent = None
            self.x = x
            self.y = y
            self.w = w
            self.heuristic = heuristic
            self.f = self.w + self.heuristic

        def set_parent(self, parent):
            self.parent = parent

        def set_xy(self, x, y):
            self.x = x
            self.y = y

        def set_params(self, w, heuristic):
            self.w = w
            self.heuristic = heuristic
            self.f = self.w + self.heuristic

        def __lt__(self, other):
            return self.f < other.f
        
    def __init__(self):
        self.__frontier = []
        self.__node_details = []
        self.__visited = []

        self.__heuristic_func = {
            "eu": self.__eu_heuristic
        }
        self.dir = {
            "up": (-1, 0),
            "down": (1, 0),
            "left": (0, -1),
            "right": (0, 1)
        }

    def __reset(self):
        self.__frontier = []
        self.__node_details = []
        self.__visited = []

    def __is_valid(self, x, y, grid):
        return 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 0
    
    def __is_free_path(self, x, y, grid):
        return grid[x][y] == 0
    
    def __is_destination(self, x, y, dest):
        return x == dest[0] and y == dest[1]
    
    def __eu_heuristic(self, x, y, dest):
        return abs(x - dest[0]) + abs(y - dest[1])

    def __trace_path(self, dest_node):
        path = []
        current = dest_node
        while current.parent:
            path.append((current.x, current.y))
            current = current.parent
        path.append((current.x, current.y))
        return path[::-1]

    def search_unw_grid(self, grid, src, dest, tree_mode=False, heuristic="eu"):
        self.__reset()

        if not self.__is_valid(src[0], src[1], grid) or not self.__is_valid(dest[0], dest[1], grid):
            print("Invalid source or destination")
            return None
        
        if self.__is_destination(src[0], src[1], dest):
            print("Source is the destination")
            return None
        
        self.__node_details = [[ASTAR.Node() for _ in range(len(grid[0]))] for _ in range(len(grid))]
        if not tree_mode:
            self.__visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]

        srcNode = self.__node_details[src[0]][src[1]]
        srcNode.set_xy(*src)
        srcNode.set_params(0, self.__heuristic_func[heuristic](src[0], src[1], dest))
        srcNode.set_parent(None)

        heapq.heappush(self.__frontier, srcNode)
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

        return {
            "status": "success" if found_dest else "failure",
            "grid": grid,
            "srouce": src,
            "destination": dest,
            "path": self.__trace_path(self.__node_details[dest[0]][dest[1]]) if found_dest else None,
            "node-visited": self.__visited if not tree_mode else None,
            "node-hueristic": [[node.heuristic for node in row] for row in self.__node_details],
            "node-g-value": [[node.w if node.w != float('inf') else "∞" for node in row] for row in self.__node_details]
        }

    def get_random_test_grid_case(self, max_x=10, max_y=10, prob=0.3):
        grid = [[0 for _ in range(max_y)] for _ in range(max_x)]
        src = [0, 0]
        dest = [0, 0]
        for i in range(max_x):
            for j in range(max_y):
                if random.random() < prob:
                    grid[i][j] = 1
                else:
                    if random.random() * 0.1 < prob:
                        src = [i, j]
                    elif random.random() * 0.1 < prob:
                        dest = [i, j]

        return (grid, src, dest)



if __name__ == "__main__":
    pp = pprint.PrettyPrinter(depth=4)
    solver = ASTAR()

    random_test = True

    if random_test:
        grid, src, dest = solver.get_random_test_grid_case(5, 5, 0.3)
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

    solve = solver.search_unw_grid(grid, src, dest)
    pp.pprint(solve)
