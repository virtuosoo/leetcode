import bisect



class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fib = [0, 1, 1]
        while True:
            tmp = fib[-1] + fib[-2]
            fib.append(tmp)
            if tmp > k:
                break
        
        ans = 0
        while k:
            idx = bisect.bisect_left(fib, k)
            if fib[idx] == k:
                ans += 1
                break
            idx -= 1
            k -= fib[idx]
            ans += 1
        return ans