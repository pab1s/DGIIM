# Import the required modules
import sys
from heapq import heappush, heappop

class Dijkstra:
    def __init__(self, graph):
        self.graph = graph
        
    def compute_shortest_path(self, start):
        # Initialize distances and previous nodes dictionaries
        distances = {node: sys.maxsize for node in self.graph}
        distances[start] = 0
        previous = {node: None for node in self.graph}

        # Create a priority queue
        queue = []
        heappush(queue, (0, start))

        # Iterate until the queue is empty
        while queue:
            # Pop the node with the smallest distance
            distance, node = heappop(queue)

            # Iterate through the neighbors of the node
            for neighbor, weight in self.graph[node].items():
                # Compute the new distance to the neighbor
                new_distance = distance + weight

                # If the new distance is shorter than the previous one, update it
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance
                    previous[neighbor] = node

                    # Push the neighbor to the queue
                    heappush(queue, (new_distance, neighbor))

        # Define a function to backtrack the path from a node to the starting node
        def get_path(node):
            path = []
            while node is not None:
                path.append(node)
                node = previous[node]
            return path[::-1]

        # Compute the paths to the other nodes
        paths = {node: get_path(node) for node in self.graph}

        return distances, paths

# Define the graph as a dictionary of dictionaries with the weights
# between the nodes
graph = {
    'A': {'B': 5, 'C': 1},
    'B': {'A': 5, 'C': 2, 'D': 1},
    'C': {'A': 1, 'B': 2, 'D': 4, 'E': 8},
    'D': {'B': 1, 'C': 4, 'E': 3, 'F': 6},
    'E': {'C': 8, 'D': 3},
    'F': {'D': 6}
}

# Create an instance of the Dijkstra class with the graph
dijkstra = Dijkstra(graph)

# Compute the shortest path from node 'A' to all the other nodes
distances, paths = dijkstra.compute_shortest_path('A')

# Print the distances to the other nodes
print(distances)

# Print the paths to the other nodes
print(paths)
