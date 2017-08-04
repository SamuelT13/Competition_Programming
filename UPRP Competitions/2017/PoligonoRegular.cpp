#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const double pi = 3.1416;

int main() {
    int test, L;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    
    cin >> test;
    
    for (int t = 1; t <= test; t++){
        cin >> L;
        
        cout << "Caso #" << t << ": ";
        cout << L*L*(pi - 3*sqrt(3)/2.0) << "\n";
    }
    
    return 0;
}

