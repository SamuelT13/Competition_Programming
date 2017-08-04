#include <iostream>
using namespace std;

int main(){
	int test, players, obst, rolls, i, j, x, y, turn;
	int obs[100][2];
	int* space = new int[1000000];
	bool won;
	
	cin >> test;
	
	while(test-- > 0){
		won = false;
		cin >> players >> obst >> rolls;
		turn = 0;
		
		for (i = 0; i < players; i++) space[i] = 1;
		
		for (i = 0; i < obst; i++){
			cin >> x >> y;
			obs[i][0] = x;
			obs[i][1] = y;
			}
		
		for (i = 0; i < rolls; i++){
			cin >> x;
			if (space[turn] < 100) space[turn] += x;
			
			if (space[turn] < 100)
				for (j = 0; j < obst; j++)
					if (space[turn] == obs[j][0])
						space[turn] = obs[j][1];
			
			if (space[turn] >= 100){
				space[turn] = 100;
				break;
			}
			turn = (turn+1)%players;
		}
		
		if (i != rolls)
			for (; i < rolls-1; i++) cin >> x;
		
		for (i = 0; i < players; i++){
			cout << "Position of player " << i+1 << " is " << space[i] << "." << endl;
		}
	}
	return 0;
}
