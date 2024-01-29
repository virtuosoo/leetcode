#include <bits/stdc++.h>
using namespace std;

// 行和列的移动互不影响。
// 能变为棋盘的条件，以行为例：1.原始矩阵中只存在两种行，要么与第一行相同，要么与第一行相反。
// 2、对于第一行，如何n为偶数，则0和1的数量相等；如果n为奇数，则0和1的数量相差1
// 使用状态压缩、位运算的技巧简化编码。
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        unsigned int rowMask = 0, colMask = 0, reverseRowMask = 0, reverseColMask = 0;
        for (int i = 0; i < n; ++i) {
            rowMask |= (board[0][i] << i);
            colMask |= (board[i][0] << i);
        }
        int rowcnt = 0, colcnt = 0;
        reverseRowMask = ((1<<n) - 1) ^ rowMask;
        reverseColMask = ((1<<n) - 1) ^ colMask;
        for (int i = 0; i < n; ++i) {
            unsigned int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; ++j) {
                curRowMask |= (board[i][j] << j);
                curColMask |= (board[j][i] << j);
            }

            if (curRowMask != rowMask && curRowMask != reverseRowMask) {
                return -1;
            }
            if (curRowMask == rowMask) {
                rowcnt += 1;
            }

            if (curColMask != colMask && curColMask != reverseColMask) {
                return -1;
            }
            if (curColMask == colMask) {
                colcnt += 1;
            }
        }
        if (abs(n - 2 * rowcnt) > 1 || abs(n - 2 * colcnt) > 1) {
            return -1;
        }

        int rowMoves = getMove(rowMask, n);
        int colMoves = getMove(colMask, n);
        return (rowMoves == -1 || colMoves == -1) ? -1 : rowMoves + colMoves;
     }

    //mask为需要进行移动的行（列）的位码，cnt为
    int getMove(unsigned int mask, int n) {
        int ones = __builtin_popcount(mask);
        if (n & 1) {
            if (abs(n - ones * 2) > 1) {
                return -1;
            }

            if (ones == n - ones + 1) { //1, 0, 1, 0, 1.. 奇数位变为1，__builtin_popcount(mask & 0x55555555)算出来的是不需要变换的位置数量。
                return ones - __builtin_popcount(mask & 0x55555555);
            } else {
                return ones - __builtin_popcount(mask & 0xAAAAAAAA);
            }
        }

        else {
            if (n != ones * 2) {
                return -1;
            }
            return ones - max(__builtin_popcount(mask & 0x55555555), __builtin_popcount(mask & 0xAAAAAAAA));
        }
    }
};