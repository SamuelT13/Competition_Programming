test = int(raw_input())

for i in xrange(test):
    low = up = alp = num = 0
    
    word = raw_input()
    
    for j in xrange(len(word)):
        if (word[j].isalpha()):
            alp += 1
            if (word[j].islower()): low += 1
            else: up += 1
        elif (word[j].isdigit()): num += 1
            
    if (alp == num and low == up): print("Caso #"+str(i+1)+(": Balanceada."))
    elif (alp == num): print("Caso #"+str(i+1)+(": Parcialmente Balanceada."))
    else: print("Caso #"+str(i+1)+(": No Balanceada."))
