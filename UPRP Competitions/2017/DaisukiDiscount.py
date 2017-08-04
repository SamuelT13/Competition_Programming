total = int(raw_input())

prices = []
for i in xrange(total):
    num = int(raw_input())
    prices.append(num)
    
prices.sort()

mid = int(total/2)
charge = 0.00

for i in xrange(len(prices)):
    if (i < mid): charge += prices[i]/2.0
    else: charge += prices[i]
        
print("%.2f" %charge)
