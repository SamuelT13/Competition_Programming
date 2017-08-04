#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct info{
	info(int l, int r, int i): Ls(l), Rs(r), ind(i){};
	
	int Ls, Rs, ind;
};

bool f(info i1, info i2){
	if (min(i1.Ls, i1.Rs) == min(i2.Ls, i2.Rs)){
		if (max(i1.Ls, i1.Rs) == max(i2.Ls, i2.Rs)) return i1.ind < i2.ind;
		return max(i1.Ls, i1.Rs) > max(i2.Ls, i2.Rs);
	}
	
	return min(i1.Ls, i1.Rs) > min(i2.Ls, i2.Rs);
}

int main(){
	int test, total, le, ri, used;
	string line;
	vector<info> seats;
	ifstream in("C-small-1-attempt0.in");
	ofstream out("out1.txt");
	
	in >> test;
	
	for (int i = 0; i < test; i++){
		in >> total >> used;
		
		total += 2;
		line = ""; for (int t = 0; t < total; t++) line += '.';
		
		line[0] = line[total-1] = 'o';
		
		for (int j = 0; j < used; j++){
			seats.clear();
			for (int k = 0; k < total; k++){
				le = ri = 0;
				
				if (line[k] == 'o') continue;
				
				for (int l = k-1; l >= 0; l--) 
					if (line[l] == 'o') break;
					else le++;
					
				for (int l = k+1; l < total; l++)
					if (line[l] == 'o') break;
					else ri++;
				
				seats.push_back(info(le, ri, k));			
			}
			
			sort(seats.begin(), seats.end(), f);
			line[seats[0].ind] = 'o';
		}
		
		out << "Case #" << i+1 << ": ";
		if (seats.size() == 0) out << max(le, ri) << " " << min(le, ri) << endl;
		else out << max(seats[0].Ls, seats[0].Rs) << " " << min(seats[0].Ls, seats[0].Rs) << endl;
		//cout << line << endl;
	}
	
	return 0;
}
