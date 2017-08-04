#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	int test, c, range, flips;
	string pancake;
	ifstream in("A-large.in");
	ofstream out("out.txt");
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		out << "Case #" << t << ": ";
		flips = 0;
		
		in >> pancake >> range;
		
		for (int i = 0; i < pancake.length(); i++)
			if (pancake[i] == '-'){
				if (range+i > pancake.length()) break; //doesn't cover K pancakes
				for (int j = i; j < i+range; j++) 
					if (pancake[j] == '-') pancake[j] = '+';
					else pancake[j] = '-';
				flips++;
			}
		
		//cout << pancake << endl;	
		for (c = 0; c < pancake.length(); c++)
			if (pancake[c] == '-') break;
		
		(c == pancake.length())? out << flips << "\n" : out << "IMPOSSIBLE\n";
	}
	
	return 0;
}
