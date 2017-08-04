#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
ifstream in("datos.txt"); ofstream out("sumas.txt");
 
// prints subset found
void printSubset(vector<int>& data, vector<int> t, int t_size){
	for (int i = 0; i < t_size; i++)
        	if (t[i]){
			*find(data.begin(), data.end(), t[i]) = 0;
			out << "$" << t[i]/100 << "." << setw(2) << setfill('0') << t[i]%100 << "\n";
    		}    
    	out << endl;
}
 
bool f(int d1, int d2){
	return d1 > d2;
}

bool subset_sum(vector<int>& s, vector<int> t, int s_size, int t_size, int sum, int ite, int const target_sum){ 
    	if (target_sum == sum){
        	// We found sum
        	out << "Target Sum found:\n";
        	printSubset(s, t, t_size);
		return true;
    	}
    
    	else{
		if (ite < (int)s_size && sum + s[ite] <= target_sum) // generate nodes along the breadth
            	for (int i = ite; i < (int)s_size; i++){
			t[t_size] = s[i];

                	if (sum + s[i] <= target_sum) 
				if (subset_sum(s, t, s.size(), t_size + 1, sum + s[i], i + 1, target_sum)) return true;
                // consider next level node (along depth)
            	}
    	}
    
    return false;
}
 
// Wrapper that prints subsets that sum to target_sum
void generateSubsets(vector<int>& s, int target_sum){
	vector<int> tuplet_vector(s.size());
 
    	int total(0);
 
    	// sort the set
    	sort(s.begin(), s.end());
	 
    	for (int i = 0; i < (int)s.size(); i++) total += s[i];
 	
    	if (s[0] <= target_sum && total >= target_sum){
		if (!subset_sum(s, tuplet_vector, s.size(), 0, 0, 0, target_sum)) out << "No matches found!\n\n";
	}
	else out << "No matches found!\n\n";
	
    	tuplet_vector.clear();
}
 
struct info{
	int d, m;
	int amount;
};

int main(){
    	vector<int> data;
    	vector<info> total, needed;
	int amount, target;
	info temp;
	int month, day, s, t, j, k, mult, num;
	char dash;
	string next, type;
		
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);
		
	while (in >> month >> dash >> day){
		temp.m = month; temp.d = day;
		
		while (in >> type){
			if (type == "NEXT" || type == "END") break;
			in >> next;
			mult = 1; num = 0;
			
			for (int i = next.length()-1; i >= 0; i--)
				if (next[i] != '.'){
					num += mult*(next[i]-'0');
					mult *= 10;
				}
				
			temp.amount = num;
			if (type == "Data:") total.push_back(temp);
			else needed.push_back(temp);
		}
		if (type == "END") break;
	}

	//for(int i = 0; i < (int)total.size(); i++) cout << "Day: " << total[i].d << " / Month: " << total[i].m << " / Amount: $" << total[i].amount << endl;
	//for(int i = 0; i < (int)needed.size(); i++) cout << "TARGET Day: " << needed[i].d << " / Month: " << needed[i].m << " / Amount: $" << needed[i].amount << endl;

	for (int i = 0; i < (int)needed.size(); i++){
		data.clear();
		month = needed[i].m; day = needed[i].d;
		
		
		s = 0;
		for (j = 0; j < (int)total.size(); j++)
			if (total[j].m < month || total[j].m == month && total[j].d <= day){
				data.push_back(total[j].amount);
			}
			else break;
		t = j-1;
	
    	out << "-------------------------------\n";
		out << "Date: " << month << "/" << day << endl; 
		out << "Target: $" << needed[i].amount/100 << "." << setw(2) << setfill('0') << needed[i].amount%100 << endl << endl;
		
    	generateSubsets(data, needed[i].amount);
    	
 		for (j = s, k = 0; j <= t && k < (int)data.size(); j++, k++)
		 	total[j].amount = data[k];
	}
	out << "-------------------------------\n";
		 
    return 0;
}
