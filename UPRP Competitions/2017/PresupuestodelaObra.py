W, L = [float(x) for x in raw_input().split()]
pi = 3.1416
R = W/2.0

Area = (W*L) - (pi*R*R)
sub = 5.99*Area
IVU = sub*0.115
total = sub+IVU

print("Area = %.3f pies^2" %Area)
print("Subtotal = $%.2f" %sub)
print("IVU tax  = $%.2f" %IVU)
print("Total    = $%.2f" %total)
