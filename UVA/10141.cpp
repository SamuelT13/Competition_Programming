#include <iostream>
#include <fstream>
using namespace std;

struct Proposal{
	int met;
	double price;
	string name;
};

int main(){
	int req, prop, i, j, max, index, num(1);
	double min;
	Proposal *p, temp;
	string s_t;

	while(cin >> req >> prop && (req != 0 || prop!= 0)){
		if (num != 1) cout << endl;
		cin.ignore(1000,'\n');
		
		p = new Proposal[prop];
		
		for	(i = 0; i < req; i++) getline(cin, s_t);
		
		for (i = 0; i < prop; i++){
			getline(cin, p[i].name);
			cin >> p[i].price >> p[i].met;
		
			cin.ignore(1000,'\n');
			
			for (j = 0; j < p[i].met; j++)	getline(cin, s_t);
		}
		
		max = -1;
		min = -1;
		for (i = 0; i < prop; i++)
			if (p[i].met > max) max = p[i].met;
		for (i = 0; i < prop; i++)
			if (p[i].met == max){
				if (min == -1 || p[i].price < min){
					index = i;
					min = p[i].price;
				}
			}
		
	cout << "RFP #" << num++ << endl << p[index].name << endl;
	delete [] p;
	}
}
