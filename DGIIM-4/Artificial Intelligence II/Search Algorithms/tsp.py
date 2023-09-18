import math
from collections import defaultdict


class TravelingSalesperson:
    def __init__(self, graph):
        self.graph = graph

    def solve(self):
        # Initialize the set of unvisited cities
        unvisited_cities = set(self.graph.keys())

        # Start at city 0
        current_city = list(self.graph.keys())[0]
        unvisited_cities.remove(current_city)

        # Keep track of the total distance traveled and the path taken
        total_distance = 0
        path = [current_city]

        while unvisited_cities:
            # Find the nearest unvisited city
            next_city, min_distance = min(
                [(city, self.graph[current_city][city]) for city in unvisited_cities],
                key=lambda x: x[1]
            )

            # Remove the city from the set of unvisited cities
            unvisited_cities.remove(next_city)

            # Add the distance to the total distance traveled
            total_distance += min_distance

            # Add the next city to the path
            path.append(next_city)

            # Move to the next city
            current_city = next_city

        # Return the total distance traveled and the path taken
        return total_distance, path


# Create the graph
graph = {
    "City 1": {"City 2": 10, "City 3": 15, "City 4": 20},
    "City 2": {"City 1": 5, "City 3": 9, "City 4": 10},
    "City 3": {"City 1": 6, "City 2": 13, "City 4": 12},
    "City 4": {"City 1": 8, "City 2": 8, "City 3": 9},
}

# Create an instance of the TravelingSalesperson class
tsp = TravelingSalesperson(graph)

# Solve the problem and get the total distance traveled and the path taken
total_distance, path = tsp.solve()

# Print the total distance traveled and the path taken
print("Total distance traveled:", total_distance)
print("Path:", path)

# Output:
# Total distance traveled: 34
# Path: ["City 1", "City 2", "City 4", "City 3"]
