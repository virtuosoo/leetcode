from typing import List

def check(board, x, y, i):
    for k in range(9):
        if board[x][k] == str(i):
            return False
    for k in range(9):
        if board[k][y] == str(i):
            return False    
    
    for nx in range(x // 3 * 3,  (x + 3) // 3 * 3):
        for ny in range(y // 3 * 3,  (y + 3) // 3 * 3):
            if board[nx][ny] == str(i):
                return False
    return True


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.ok = False
        def dfs(board, x, y):
            if x == 9:
                self.ok = True
                return
            if self.ok:
                return
            if(board[x][y] == '.'):
                for i in range(1, 10):
                    if check(board, x, y, i):
                        board[x][y] = str(i)
                        dfs(board, x + (y + 1) // 9, (y + 1) % 9)
                        if self.ok:
                            break
                        else:
                            board[x][y] = '.'
            else:
                dfs(board, x + (y + 1) // 9, (y + 1) % 9)
        dfs(board, 0, 0)
                        