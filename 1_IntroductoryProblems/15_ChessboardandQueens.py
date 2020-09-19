class Solution:
    sol = 0

    def __init__(self, queens):
        blocked = set()
        for i in range(queens):
            for j, ch in enumerate(str(input())):
                if ch == "*":
                    blocked.add((i, j))
        self.backTrack(blocked, queens)
        print(self.sol)

    def blockSquares(self, row, col):
        b = set()
        for i in range(8):
            for j in range(8):
                if (i == row or j == col or i-j == row-col or i+j == row+col):
                    b.add((i, j))
        return b

    def backTrack(self, blocked, qns):
        for i in range(8):
            if (8-qns, i) not in blocked:
                if qns == 1:
                    self.sol += 1
                else:
                    b_new = blocked | self.blockSquares(8-qns, i)
                    self.backTrack(b_new, qns-1)


if __name__ == "__main__":
    Solution(8)
