#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
	ifstream in("B-large.in");
	int total, c, t(1);
	ofstream out("out.txt");
	string next, temp;
	char prev;
	
    ios_base::sync_with_stdio(false);
    in.tie(NULL);
    
	in >> total;
	
	while (total--){
		in >> next;
		
		temp = next;
		sort(temp.begin(), temp.end());
		
		if (temp == next){out << "Case #" << t++ << ": " << next << "\n"; continue;} //easy case
				
		while (true){
			for (int i = 0; i < next.length(); i++){
				if (!i){prev = next[i]; continue;}
				
				if (next[i] < prev){				
					for (int j = i; j < next.length(); j++) next[j] = '9';
					
					for (int j = i-1; j >= 0; j--)
						if (next[j] == '0'){
							if (j == next.length()) next[j] = '0'; //what?? [6/4/2017]
							else next[j] = '9';
						}
						else{
							next[j] = next[j]-1;
							break;
						}
						
					break;		
				}
				prev = next[i];
			}
			
			for (c = 0; c < next.length(); c++) if (next[c] != '0') break;
			
			next = next.substr(c, next.length());
			temp = next;
			sort(temp.begin(), temp.end());
			
			if (temp == next){ out << "Case #" << t++ << ": " << next << "\n"; break;}
		}
	}
	
	return 0;
}
