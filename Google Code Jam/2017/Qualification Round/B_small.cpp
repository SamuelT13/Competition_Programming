#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
 	ifstream in("B-small-attempt0.in");
	int total, t, num;
	string n, temp;
	ofstream out("out1.txt");
	
	in >> total;
	
	for (int i = 0; i < total; i++){
		in >> num;
		
		for (int j = num; j >= 0; j--){
			t = j;
			n = "";
			
			while (t){
				n += (t%10)+'0';
				t /= 10;
			}
			
			temp = n;
			sort(temp.begin(), temp.end(), greater<char>());
			
			if (temp == n){
				reverse(temp.begin(), temp.end());
				out << "Case #" << i+1 << ": " << temp << "\n";
				break;
			}
		}
	}
	
}
