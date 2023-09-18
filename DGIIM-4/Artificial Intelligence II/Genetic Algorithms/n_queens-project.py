# Author: Pablo Olivares
# N-queens problem. Given a board of NxN, place N queens in the board without
# them attacking each other. Find all possible solutions.

class NQueens:
    def __init__(self, n):
        self.n = n
        self.board = [-1] * n
        self.solutions = []

    # Method to obtain all possible combinations of the 
    # N-Queens' Problem given n.
    def solve(self, pos=0):
        # Base case of recursion. A solution was found.
        if pos == self.n:
            self.solutions.append(self.board.copy())
            return
        
        # For the actual position, checks if it is not attacking the previous 
        # queens and if so, continues to the next column of the board.
        for i in range(self.n):
            self.board[pos] = i
            if self.isNotAttack(pos):
                if self.solve(pos+1) and pos != 0:
                    return

    # Method to check if Queens from the board and at pos (last column by 
    # the moment) are attacking each other.
    # There is no need to check columns due to how the program is defined.
    def isNotAttack(self, pos):
        # Check all queens until the moment
        for i in range(pos):
            # Check 1st row and 2nd diagonal
            if self.board[i] == self.board[pos] or pos - i == abs(self.board[pos] - self.board[i]):
                return False
        return True

    # Method to get the i-th solution found.
    def getSolution(self, i):
        return self.solutions[i]

    # Method to get the number of solutions found.
    def numberOfSolutions(self):
        return len(self.solutions)

    # Method to print the solutions found.
    def printSolutions(self):
        for i in range(len(self.solutions)):
            print("Solution " + str(i+1) + ":")
            for j in range(self.n):
                print(self.solutions[i][j], end=" ")
            print()

    # Method to print the matrix of solutions found.
    def printMatrix(self):
        for i in range(len(self.solutions)):
            print("Solution " + str(i+1) + ":")
            for j in range(self.n):
                for k in range(self.n):
                    if self.solutions[i][j] == k:
                        print("1", end=" ")
                    else:
                        print("0", end=" ")
                print()
            print()


eightQueens = NQueens(5)
eightQueens.solve()
print(eightQueens.numberOfSolutions())
eightQueens.printMatrix()
