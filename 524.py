'''
    leetcode 524
    给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
    如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。

    这道题很简单，对于python来说就是要知道怎么对字符串按题目要求来排序，
    并且简洁地判断一个字符串是否是另一个的子序列。
    （这个代码是官方题解的，我写的太丑了）
'''



class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        dictionary.sort(key=lambda x: (-len(x), x)) #按先长度降序，再按字典序升序
        for t in dictionary:
            i = j = 0
            while i < len(t) and j < len(s):
                if t[i] == s[j]:
                    i += 1
                j += 1
            if i == len(t):
                return t
        return ""
