graph = {
    'A': ['B', 'S'],
    'S': ['C', 'G'],
    'C': ['D', 'E', 'F'],
    'F': ['C', 'G'],
    'G': ['F'],
    'E': ['H'],
    'B': [],
    'D': [],
    'H': [],
}

# Function to implement BFS algorithm
def bfs(graph, start, end):
    found = False
    path = []
    queue = [start]

    if start == end:
        return path
    if start not in graph:
        return None
    while(not found):
        if len(queue) == 0:
            return None
        node = queue.pop(0)
        if(node not in path):
            path.append(node)
        if(node == end):
            found = True
        
        for neighbor in graph[node]:
            if neighbor not in path:
                queue.append(neighbor)

    return path

print(bfs(graph, 'A', 'H'))
