#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned long long int ULL;

int main(){
	ULL num, K, level, one(1), two(2), diff, row_sum, row_max, row_total, x, y;
	int test;
	ifstream in("C-large.in");
	ofstream out("out.txt");

	ios_base::sync_with_stdio(false);
    in.tie(NULL);
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		in >> num >> K;
		
		for (ULL i = 1; i <= ULL(63); i++)
			if ((one << i) - one >= K){
				level = i - one;
				break;
			}
		
		diff = (one << level) - one;
		
		row_sum = num-diff;
		row_total = (one << level);
		
		row_max = row_sum / row_total;
		if (row_sum % row_total)  row_max += one;
		
		//EQUATION: row_max * x + (row_max-1) * y = row_sum, where x + y = row_total
		// -> y = row_total - x -> row_max * x + (row_max-1) * (row_total-x) = row_sum
		// x = row_sum - row_total*(row_max - 1)
		// y = row_total - x 
		
		x = row_sum - row_total*(row_max - one);
		y = row_total - x;
		
		//cout << K << ": " << level << " (diff " << diff << ")\n";
		//cout << row_max << " (" << x << " times) | " << row_max-one << " (" << y << ") times\n";
		
		K -= diff;
		
		if (K > x) row_max -= one;
		
		//cout << K << " pos | " << row_max << " current num\n";
		
		out << "Case #" << t << ": ";
		(row_max % 2)? out << row_max/two << " " << row_max/two << "\n" : 
					   out << row_max/two << " " << row_max/two - one << "\n";
	}
	
	return 0;
}
