def my_func(s):
    left = 0
    right = len(s) - 1
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    return True

print(my_func([1,2,1]))

def palindrom(s, left, right):
    if left<right:
        return True
    elif s[left]!=s[right]:
        return False
    else:
        return palindrom(s, left+1, left-1)

print(palindrom([1,2,1], 0, len([1,2,1])))