test = int(raw_input())

for i in xrange(test):
    N = int(raw_input())
    ans = 0
    
    while (N > 0):
        N >>= 1
        ans += 1
    
    print ans
