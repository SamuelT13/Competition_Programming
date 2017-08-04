#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;


int main() {
    int test, alp, num, up, low;
    string next;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test;
    
    for (int t = 1; t <= test; t++){
        cin >> next;
        alp = num = up = low = 0;

        for (int i = 0; i < next.length(); i++)
            if (isalpha(next[i])){
                alp++;
                if (isupper(next[i])) up++;
                else low++;
            }
            else if (isdigit(next[i])) num++;
                
        cout << "Caso #" << t << ": ";
        if (alp == num && up == low) cout << "Balanceada.\n";
        else if (alp == num) cout << "Parcialmente Balanceada.\n";
        else cout << "No Balanceada.\n";
    }
    
    return 0;
}

