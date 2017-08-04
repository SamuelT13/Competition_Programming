#include <iostream>
#include <string>
using namespace std;

int main(){
	string word, guess, next, inc;
	int round, i, j, k, count, right;
	
	while (cin >> round && round != -1){
		cin >> word >> guess;
		
		next = inc = "";
		right = 0;
		
		for (i = 0; i < guess.length(); i++){
			count = 0;
			
			for (j = 0; j < next.length(); j++)
				if (guess[i] == next[j]) break;
				
			for (k = 0; k < inc.length(); k++)
				if (guess[i] == inc[k]) break;
				
			if (j == next.length() && k == inc.length()){
				for (j = 0; j < word.length(); j++)
					if (guess[i] == word[j]) count++;
		 
				if (count) next += guess[i];
				else inc += guess[i];
			}
			
			right += count;
			
			if (right == word.length()) break;
			else if (inc.length() == 7) break;
		}
				
		if (right == word.length())
			cout << "Round " << round << endl << "You win." << endl;
		else if (inc.length() >= 7) 
			cout << "Round " << round << endl << "You lose." << endl;
		else
			cout << "Round " << round << endl << "You chickened out." << endl;
	}
	
	return 0;
}
