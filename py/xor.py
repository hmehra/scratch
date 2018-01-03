''' https://www.hackerrank.com/challenges/maximizing-xor '''
def xor_range(l,r):
    ans = 0
    for i in range(l,r+1):
        for j in range(l+1,r+1):
            if (i ^ j) > ans:
                ans = i ^ j
    print ans

l = int(raw_input())
r = int(raw_input())
xor_range(l,r)

