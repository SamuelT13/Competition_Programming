#include <iostream>
using namespace std;

int main(){
	double height, pos, climb, down, fatigue;
	int i;
	
	while(cin >> height >> climb >> down >> fatigue && height){
		fatigue *= climb/100;
		pos = 0;
		
		for (i = 1; ; i++){
			if (i != 1) climb -= fatigue;
			if (climb < 0) climb = 0;
			
			pos += climb;
			
			if (pos > height){
				cout << "success on day " << i << endl;
				break;
			} 
			
			pos -= down;
						
			if (pos < 0){
				cout << "failure on day " << i << endl;
				break;
			}
		}
	}
	return 0;
}
