
mystr = "3 + 4 * 5 + ( 3 + 5 * 4) - 3 * ( 5 )"


def postFix(s):
    ret = ""
    stack = []
    for i, c in enumerate(s):
        if c == '-' or c == '+':
            while stack and stack[-1] != '(':
                ret += stack.pop()
            stack.append(c)
        elif c == '*':
            while stack and (stack[-1] == '*'):
                ret += stack.pop()
            stack.append(c)
            pass
        elif c == '(':
            stack.append(c)
            pass
        elif c == ')':
            while stack and stack[-1] != '(':
                ret += stack.pop()
            stack.pop()
        elif c == ' ':
            pass
        else:
            ret += c
            if i + 1 < len(s) and s[i+1] == ' ':
                ret += ' '
            elif i == len(s) - 1:
                ret += ' '
    while stack:
        ret += stack.pop()
    return ret


t1 = "423 + 52"
t2 = "4 * 3 + 4"
print(postFix(t1) == '423 52 +')
print(postFix(t2) == '4 5 3 2 + * +')