#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main(){
	string per[20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen",
						"Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur",
						"Chlorine", "Argon", "Potassium", "Calcium"};
	map<string, int> count, code;
	int test;
	string s, temp;
	
	//>.>
	code["H"] = 1, code["He"] = 2, code["Li"] = 3, code["Be"] = 4, code["B"] = 5, code["C"] = 6, code["N"] = 7, 
	code["O"] = 8, code["F"] = 9, code["Ne"] = 10, code["Na"] = 11, code["Mg"] = 12, code["Al"] = 13, code["Si"] = 14, 
	code["P"] = 15, code["S"] = 16, code["Cl"] = 17, code["Ar"] = 18, code["K"] = 19, code["Ca"] = 20;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ":\n";
		
		count.clear(); temp = "";
		
		cin >> s;
		
		for (int i = 0; i < s.length(); i++)
			if (isdigit(s[i])){
				count[per[code[temp]-1]] += s[i]-'0';
				temp = "";
			}
			else if (isupper(s[i])){
				if (temp != ""){
					count[per[code[temp]-1]]++;
					temp = "";
				}
				temp += s[i];
			}
			
			else if (islower(s[i])) temp += s[i];
		
		if (temp != "") count[per[code[temp]-1]]++;
		
		for (int i = 0; i < 20; i++)
			if (count[per[i]]) cout << count[per[i]] << " " << per[i] << "\n";
	}
	
	return 0;
}
