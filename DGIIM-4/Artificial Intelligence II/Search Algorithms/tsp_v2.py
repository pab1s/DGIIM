from itertools import permutations

def tsp(cities):
  # get all possible permutations of the cities
  all_permutations = permutations(cities.keys())

  # filter the permutations to only include those that start and end with the first city
  first_city = list(cities.keys())[0]
  filtered_permutations = [perm for perm in all_permutations if perm[0] == first_city and cities[perm[-1]][first_city] != float('inf')]

  # calculate the total distance for each permutation
  # and store the permutation with the minimum distance
  min_distance = float('inf')
  min_permutation = None
  for permutation in filtered_permutations:
    # calculate the total distance for this permutation
    distance = 0
    for i in range(len(permutation)):
      city1 = permutation[i]
      city2 = permutation[(i+1) % len(permutation)]  # wrap around to the first city
      distance += cities[city1][city2]

    # check if this permutation is the minimum distance so far
    if distance < min_distance:
      min_distance = distance
      min_permutation = permutation

  # return the minimum distance and the corresponding permutation of cities
  return min_distance, min_permutation


# example usage
cities = {
  'C1': {'C2': 12, 'C3': 22, 'C4': 15, 'C5': 21, 'C6': 21, 'C7': 15, 'C8': 21, 'C9': 21},
  'C2': {'C1': 12, 'C3': 8, 'C4': 11, 'C5': 13, 'C6': 13, 'C7': 11, 'C8': 13, 'C9': 13},
  'C3': {'C1': 22, 'C2': 8, 'C4': 16, 'C5': 18, 'C6': 18, 'C7': 16, 'C8': 18, 'C9': 18},
  'C4': {'C1': 15, 'C2': 11, 'C3': 16, 'C5': 19, 'C6': 19, 'C7': 16, 'C8': 19, 'C9': 19},
  'C5': {'C1': 21, 'C2': 13, 'C3': 18, 'C4': 19, 'C6': 14, 'C7': 19, 'C8': 20, 'C9': 20},
  'C6': {'C1': 21, 'C2': 13, 'C3': 18, 'C4': 19, 'C5': 14, 'C7': 12, 'C8': 12, 'C9': 21},
  'C7': {'C1': 15, 'C2': 11, 'C3': 16, 'C4': 16, 'C5': 19, 'C6': 12, 'C8': 22, 'C9': 13},
  'C8': {'C1': 21, 'C2': 13, 'C3': 18, 'C4': 19, 'C5': 20, 'C6': 12, 'C7': 22, 'C9': 18},
  'C9': {'C1': 21, 'C2': 13, 'C3': 18, 'C4': 19, 'C5': 20, 'C6': 21, 'C7': 13, 'C8': 18},
}
min_distance, min_permutation = tsp(cities)

print(f'Minimum distance: {min_distance}')
print(f'Minimum route: {" -> ".join(min_permutation)}')
