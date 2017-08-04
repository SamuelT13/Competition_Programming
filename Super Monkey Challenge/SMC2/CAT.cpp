#include <iostream>
#include <string>
using namespace std;

int main(){
	int test, count;
	unsigned int i, j, k;
	string dna;
	
	cin >> test;
	
	while (test-- > 0){
		count = 0;
		cin >> dna;

		for (i = 0; i < dna.length(); i++)
			if (dna[i] == 'C')
				for (j = i+1; j < dna.length(); j++)
					if (dna[j] == 'A')
						for (k = j+1; k < dna.length(); k++)
							if (dna[k] == 'T')
								count++;
		cout << count << endl;
	}
	
	return 0;
}
