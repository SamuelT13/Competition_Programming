err = "Frase no es valida"

line = raw_input()
change = []

ok = True
for word in line.split():
    for i in xrange(len(word)):
        if (not word[i].isalpha()): ok = False
    if (not ok): break
    
    first = word[0]
    last = word[len(word)-1]
    
    if (len(word) > 1): word = last+word[1:len(word)-1]+first+"pi"
    else: word = word+"pi"
    change.append(word)
    
if (not ok): 
    print err
else:
    temp = ""
    ind = 0
    i = 0
    
    while i < len(line):
        if (line[i].isalpha()):
            temp = temp + change[ind]
            ind += 1
            while (i < len(line) and line[i].isalpha()):
                i += 1
        
        if (i < len(line)): temp = temp+line[i]
        i += 1
    print temp
        
