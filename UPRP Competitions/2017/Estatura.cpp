#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<double, string> ds;
bool f(ds d1, ds d2){
    if (d1.first == d2.first) return d1.second < d2.second;
    return d1.first > d2.first;
}

int main() {
    int total;
    string next, mea;
    double d;
    vector<ds> names;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);     
    
    cin >> total;
    
    for (int i = 0; i < total; i++){
        cin >> next >> d >> mea;    
        
        if (mea == "m") d *= 1000.0;
        else if (mea == "dm") d *= 100.0;
        else if (mea == "cm") d *= 10.0;
       
        names.push_back(ds(d, next));     
    }
    
    sort(names.begin(), names.end(), f);
    
    for (int i = 0; i < 3; i++) cout << i+1 << ". " << names[i].second << "\n";

    return 0;
}

