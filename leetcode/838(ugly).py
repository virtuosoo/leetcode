
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        left = [[-1] * (n + 5) for i in range(2)]
        right = [[n] * (n + 5)  for i in range(2)]
        for i in range(n):
            if dominoes[i] == 'L':
                left[0][i] = i
            elif dominoes[i] == 'R':
                left[1][i] = i
            left[0][i] = max(left[0][i], left[0][i - 1])
            left[1][i] = max(left[1][i], left[1][i - 1])
        
        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'L':
                right[0][i] = i
            elif dominoes[i] == 'R':
                right[1][i] = i
            right[0][i] = min(right[0][i], right[0][i + 1])
            right[1][i] = min(right[1][i], right[1][i + 1])
        
        ans = [' '] * n
        for i in range(n):
            if dominoes[i] != ' ':
                ans[i] = dominoes[i]
            else:
                if left[1][i] > left[0][i]:
                    if right[0][i] < right[1][i]:
                        disl, disr = i - left[1][i], right[0][i] - i
                        if disl > disr:
                            ans[i] = 'L'
                        elif disl < disr:
                            ans[i] = 'R'
                        else:
                            ans[i] = '.'
                    else:
                        ans[i] = 'R'
                else:
                    if right[0][i] < right[1][i]:
                        ans[i] = 'L'
                    else:
                        ans[i] = '.'

        return ''.join(ans)