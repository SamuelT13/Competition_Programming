total = int(raw_input())

total_dist = total_time = avg_dist = 0

for i in xrange(total):
    d, t = [int(x) for x in raw_input().split()]
    total_dist += d
    total_time += t
    
avg_dist = int(total_dist/total_time)
        
print total_dist, total_time, avg_dist
