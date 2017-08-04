#include <iostream>
using namespace std;

int main(){
	int L, i;
	string move, pos;
	
	while (cin >> L && L){
		pos = "+x";
		for (i = 0; i < L-1; i++){
			cin >> move;
			
			if (move != "No"){
				if (pos == "+x"){
					if (move == "+y") pos = "+y";
					else if (move == "-y") pos = "-y";
					else if (move == "+z") pos = "+z";
					else if (move == "-z") pos = "-z";
				}	
				else if (pos == "-x"){
					if (move == "+y") pos = "-y";
					else if (move == "-y") pos = "+y";
					else if (move == "+z") pos = "-z";
					else if (move == "-z") pos = "+z";
				}
				else if (pos == "+y"){
					if (move == "+y") pos = "-x";
					else if (move == "-y") pos = "+x";
					else if (move == "+z") pos = "+y";
					else if (move == "-z") pos = "+y";
				}
				else if (pos == "-y"){
					if (move == "+y") pos = "+x";
					else if (move == "-y") pos = "-x";
					else if (move == "+z") pos = "-y";
					else if (move == "-z") pos = "-y";
				}
				else if (pos == "+z"){
					if (move == "+y") pos = "+z";
					else if (move == "-y") pos = "+z";
					else if (move == "+z") pos = "-x";
					else if (move == "-z") pos = "+x";
				}
				else if (pos == "-z"){
					if (move == "+y") pos = "-z";
					else if (move == "-y") pos = "-z";
					else if (move == "+z") pos = "+x";
					else if (move == "-z") pos = "-x";
				}
			}
		}
	cout << pos << endl;

	}
	
	return 0;
}
