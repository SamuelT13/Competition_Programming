#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int test, total, ind, prev, cur, next;
    vector<int> nums;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    cin >> test;
    
    for (int t = 1; t <= test; t++){
        cin >> total;
        
        ind = prev = cur = 0; next = -1;
        
        nums.clear(); nums.assign(total, 0);
        for (int i = 0; i < total; i++){
            cin >> nums[i]; nums[i]--;
        }
      
        while (prev != next){
            prev = nums[ind];
            cur = nums[prev];
            next = nums[cur];
            ind = cur;
        }
       
        cout << "Case #" << t << ": " << min(prev, cur) + 1 << " " << max(prev, cur) + 1 << "\n";
    }
    
    return 0;
}

