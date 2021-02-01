while True:
    str = input()
    if str == '.':
        break
    smallcnt = 0
    bigcnt = 0
    flag = 0
    stack = []
    operlist = ['(', ')', '[', ']']
    for idx in range(len(str)):
        if str[idx] in operlist:
            if str[idx] ==')':
                if len(stack) == 0:
                    flag = 1
                    break
                elif stack.pop() != '(':
                    flag = 1
                    break
            elif str[idx] ==']':
                if len(stack) == 0:
                    flag = 1
                    break
                elif stack.pop() != '[':
                    flag = 1
                    break
            else :
                stack.append(str[idx])

    if flag == 0 and len(stack) == 0:
        print("yes")
    else:
        print('no')