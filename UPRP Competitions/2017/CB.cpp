#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool f(string s1, string s2){
    string t1 = s1+s2, t2 = s2+s1;
    
    //if (t1.length() != t2.length()) cout << "!!!!!";
    for (int i = 0; i < t1.length(); i++)
        if (t1[i] > t2[i]) return 1;
        else if (t2[i] > t1[i]) return 0;
 
    return (s1+s2) > (s2+s1);
    //return t1[t1.length()-1] == t2[t2.length()-1];
}

int main() {
    int test, a, b, mi, ma, num;
    string temp;
    vector<string> nums;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test;
    
    for(int t = 1; t <= test; t++){
        cin >> a >> b;
        
        mi = min(a, b); ma = max(a, b);
        nums.clear();
        
        for (int i = mi; i <= ma; i++){
            num = i;
            temp = "";
            
            if (!num) temp = "0";
            
            while (num){
                temp += (num%10)+'0';
                num /= 10;
            }
            
            reverse(temp.begin(), temp.end());
            nums.push_back(temp);
            //cout << temp << " ";
        } 
        sort(nums.begin(), nums.end(), f);
        
        cout << "Case #" << t << ": "; for (int i = 0; i < nums.size(); i++) cout << nums[i]; cout << "\n";
    }
    
    return 0;
}
