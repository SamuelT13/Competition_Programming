#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct sat{
	int pos, rad, cap;
	
	sat(){};
	sat(int p0, int r0, int c0): pos(p0), rad(r0), cap(c0){};
};

bool f(sat s1, sat s2){
	if (s1.pos == s2.pos){
		if (s1.rad == s2.rad) return s1.cap < s2.cap;
		return s1.rad < s2.rad;
	}
	
	return s1.pos < s2.pos;
}

int main(){
	int test, phone, ans, towers, n;
	vector<sat> s;
	map<int, int> p;
	sat temp;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		s.clear(); p.clear();
		
		cin >> phone >> towers;
		s.assign(towers, sat());
		
		for (int i = 0; i < phone; i++){
			cin >> n; p[n]++;
		}
		
		for (int i = 0; i < towers; i++){
			cin >> temp.pos >> temp.rad >> temp.cap; temp.pos += temp.rad;
			
			s[i] = temp;
		}
		sort(s.begin(), s.end(), f);
		
		ans = 0;
		for (int i = 0; i < s.size(); i++)
			for (map<int, int>::iterator it = p.lower_bound(s[i].pos-2*s[i].rad);
				s[i].cap && it != p.end() && it->first <= s[i].pos; it++){
				 	if (!it->second) continue;
					while (it->second && s[i].cap) ans++, s[i].cap--, it->second--;
					//if (!it->second) p.erase(it);
			}
            
		
		cout << ans << "\n";
	}
	
	return 0;
}
