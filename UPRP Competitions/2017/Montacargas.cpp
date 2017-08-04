#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int test, total, m_peso;
    vector<int> peso, valor;
    vector<vector<int> > memo;
    
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test;
    
    for (int t = 1; t <= test; t++){
        memo.clear(); valor.clear(); peso.clear();
        
        cin >> m_peso >> total;
        
        memo.assign(total+1, vector<int>());
        peso.assign(total+1, 0); valor.assign(total+1, 0);
        
        for (int i = 0; i <= total; i++){
            memo[i].assign(m_peso+1, 0);
            if (!i) continue;
            cin >> peso[i] >> valor[i];
        }
        
        for (int i = 1; i <= total; i++)
            for (int j = 0; j <= m_peso; j++){
                memo[i][j] = memo[i-1][j]; //not taking ith item
                if (j - peso[i] >= 0)
                    memo[i][j] = max(memo[i][j], valor[i] + memo[i-1][j-peso[i]]); //not taking ith item, or taking it
        }
    
        cout << "Caso #" << t << ": $" << memo[total][m_peso] << ".00\n";
    }
       
    return 0;
}

