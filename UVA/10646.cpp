#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main(){
	int test, x, y, i, j, k(1);
	string next;
	stack<string> hand, pile;
	
	cin >> test;
	
	while (test-- > 0){
		y = 0;
		
		for (i = 0; i < 52; i++){
			cin >> next;
			pile.push(next);
		}
		
		for (i = 0; i < 25; i++){
			hand.push(pile.top());
			pile.pop();
		}
	
		for (i = 0; i < 3; i++){
			next = pile.top();
			pile.pop();
			
			x = 10;
			 
			if (!isalpha(next[0]))
				x = next[0]-'0';
			
			y += x;
			
			for (j = 0; j < 10-x; j++)
				pile.pop();
			}
			
		for (i = 0; i < 25; i++){
			pile.push(hand.top());
			hand.pop();
		}
		
		x = pile.size();
		for (i = 0; i < x-y+1; i++){
			next = pile.top();
			pile.pop();	
		}
		
		cout << "Case " << k++ << ": " << next << endl;		
		
		while (!pile.empty()) pile.pop();
	}
	
	return 0;
}

