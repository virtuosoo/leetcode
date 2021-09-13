'''
    leetcode 678
    
    给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。
    有效字符串具有如下规则：

    任何左括号 ( 必须有相应的右括号 )。
    任何右括号 ) 必须有相应的左括号 ( 。
    左括号 ( 必须在对应的右括号之前 )。
    * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
    一个空字符串也被视为有效字符串。

    数据范围小，可以用n^3的区间dp.不过我觉得用栈的方法比较直观，复杂度也低。对左括号和星号分别维护一个栈，
    当遇到右括号时，先尝试与左括号匹配，如果左括号栈为空，再与星号匹配，否则返回false。
    右括号匹配完之后，还要尝试将剩余的左括号与星号匹配。
    这时需要左括号栈顶的元素index < 星号栈顶元素的index

'''

class Solution:
    def checkValidString(self, s: str) -> bool:
        lstk, astk = [], []
        n = len(s)
        for i in range(n):
            if s[i] == "(":
                lstk.append(i)
            elif s[i] == "*":
                astk.append(i)
            else:
                if len(lstk) != 0:
                    lstk.pop()
                elif len(astk) != 0:
                    astk.pop()
                else:
                    return False
        
        while len(lstk) != 0:
            if len(astk) == 0:
                return False
            a, b = lstk[-1], astk[-1]
            lstk.pop()
            astk.pop()
            if a > b:
                return False
        return True