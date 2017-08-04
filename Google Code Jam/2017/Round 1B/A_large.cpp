#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream in("A-large.in");
	ofstream out("out.txt");
	int test, total;
	double dist, dest, st, sp;
	
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(6);
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		in >> dest >> total;
		
		dist = 0;
		
		for (int i = 0; i < total; i++){
			in >> st >> sp;
			
			dist = max(dist, (dest-st)/sp);
		}
		
		out << "Case #" << t << ": " << dest/dist << "\n";
	}

	return 0;
}
