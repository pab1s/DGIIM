from queue import PriorityQueue

class BestFirstSearchSolver:
    def __init__(self, puzzle):
        self.puzzle = puzzle
        self.queue = PriorityQueue()
        self.visited = set()

    def heuristic(self):
        h = 0
        for i in range(3):
            for j in range(3):
                if self.puzzle[i][j] != 0 and self.puzzle[i][j] != i*3+j+1:
                    h += 1              
        return h

    def is_goal(st):
        return st == [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

    def solve(self):
        self.queue.put((self.heuristic(), self.puzzle))

        while not self.queue.empty():
            state = self.queue.get()[1]

            # Convert the state to a tuple before adding it to the visited set
            if tuple(state) not in self.visited:
                self.visited.add(tuple(state))

                if self.is_goal(state):
                    return state

                # Get the successors of the current state
                successors = self.get_states()

                # Add the successors to the queue
                for successor in successors:
                    self.queue.put((successor.heuristic(), successor))
        return None

    def get_states(self):
        states = []
        for i in range(3):
            for j in range(3):
                if self.puzzle[i][j] == 0:
                    if i > 0:
                        states.append(self.swap(self.puzzle, i, j, i-1, j))
                    if i < 2:
                        states.append(self.swap(self.puzzle, i, j, i+1, j))
                    if j > 0:
                        states.append(self.swap(self.puzzle, i, j, i, j-1))
                    if j < 2:
                        states.append(self.swap(self.puzzle, i, j, i, j+1))
        return states

    def swap(self, puzzle, i1, j1, i2, j2):
        puzzle[i1][j1], puzzle[i2][j2] = puzzle[i2][j2], puzzle[i1][j1]
        return puzzle

solver = BestFirstSearchSolver([[8, 1, 2], [0, 4, 3], [7, 6, 5]])
result = solver.solve()

if result is not None:
    print("Solution found:")
    for row in result:
        print(row)
else:
    print("No solution")
