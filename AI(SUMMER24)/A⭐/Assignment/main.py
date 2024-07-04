import os
import math
import heapq


class Node:
    def __init__(self, label, x, y):
        self.label = label
        self.x, self.y = x, y
        self.parent = None
        self.heuristicCost = float('inf')
        self.estimatedCost = float('inf')
        self.actualCost = float('inf')

    def set_parent(self, parent):
        self.parent = parent

    def estimate_cost(self):
        self.estimatedCost = self.actualCost + self.heuristicCost
    
    def __lt__(self, other):
        return self.estimatedCost < other.estimatedCost


class DGraph:
    def __init__(self):
        self.nodes = {}
        self.adjList = {}

    def add_node(self, node):
        self.nodes[node.label] = node
        self.adjList[node.label] = []

    def add_edge(self, node1Label, node2Label, edgeWeight):
        self.adjList[node1Label].append((node2Label, edgeWeight))

    def get_neighbors(self, nodeLabel):
        return self.adjList[nodeLabel]


class ASTAR:
    def __init__(self, treeMode=False, debugMode=True):
        self.__frontier = []
        self.__explored = set()
        self.treeMode = treeMode
        self.debugMode = debugMode

    def __euclidean_heuristic(self, node, goal):
        return math.sqrt((node.x - goal.x)**2 + (node.y - goal.y)**2)
    
    def __build_path(self, goal):
        path = []
        while goal:
            path.append(goal.label)
            goal = goal.parent
        return path[::-1]
    
    def __explore(self, node, goal, graph):
        for neighbor, edgeWeight in graph.get_neighbors(node.label):
            if not self.treeMode and neighbor in self.__explored: continue
            
            neighborNode = graph.nodes[neighbor]
            
            newCost = node.actualCost + edgeWeight
            newHeuristic = self.__euclidean_heuristic(neighborNode, goal)

            if neighborNode.estimatedCost > newCost + newHeuristic:
                neighborNode.actualCost = newCost
                neighborNode.heuristicCost = newHeuristic
                neighborNode.estimate_cost()
                neighborNode.set_parent(node)
                heapq.heappush(self.__frontier, neighborNode)

    def search(self, start, goal, graph, treeMode=None):
        if self.debugMode:
            print(f"A* variant: {'Tree' if treeMode else 'Graph'}:")
        if treeMode: self.treeMode = treeMode

        start.actualCost = 0
        start.heuristicCost = self.__euclidean_heuristic(start, goal)
        start.estimate_cost()
        start.set_parent(None)

        heapq.heappush(self.__frontier, start)
        
        while self.__frontier:
            current = heapq.heappop(self.__frontier)
            if self.debugMode:
                print(f"Exploring: {current.label, current.estimatedCost}")
            if not self.treeMode: self.__explored.add(current.label)
            
            if not self.treeMode:
                if current.label == goal.label:
                    return self.__build_path(current)
                
            if self.debugMode:
                if current.label == goal.label:
                    print("Path Found: " + "->".join(self.__build_path(current)) + f", with cost: {current.actualCost}")

            self.__explore(current, goal, graph)

        return self.__build_path(goal)
    

if __name__ == "__main__":
    debug = True
    solver = ASTAR()
    graph = DGraph()

    inputFilePath = "input.txt" # change this to the path of the input file
    outputFilePath = "output.txt" # chnage this to the path of the output file

    while not os.path.exists(inputFilePath):
        inputFilePath = input("Please enter the correct path of the input file: ")

    with open(inputFilePath, 'r') as file:
        lines = file.readlines()
        V = int(lines[0].strip())
        E = int(lines[V+1].strip())

        for data in lines[1:V+1]:
            label, x, y = data.strip().split()
            graph.add_node(Node(label, int(x), int(y)))

        for data in lines[V+2:V+E+2]:
            u, v, w = data.strip().split()
            graph.add_edge(u, v, int(w))

        start = lines[V+E+2].strip()
        goal = lines[V+E+3].strip()

    path = solver.search(graph.nodes[start], graph.nodes[goal], graph, treeMode=False)

    with open(outputFilePath, 'w') as file:
        file.write("Solution path " + "-".join(path) + "\n")
        file.write(f"Solution cost {graph.nodes[goal].actualCost}\n")

    if debug:
        print(f"\nSource: {start}, Destination: {goal}")
        print("\nNode analysis details: ")
        for node in graph.nodes.values():
            print(f"{node.label}: h({node.heuristicCost}), A({node.actualCost}), E({node.estimatedCost})")
        print("\nOptimal path: ", "->".join(path) + ", path cost: ", graph.nodes[goal].actualCost)