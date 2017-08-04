#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//sum*dimension = sum(k^2) from 1,2...,dimension
//sum*dimension = (dimension^2)(dimension^2 + 1)/2
//sum = dimension(dimension^2+1)/2

int main(){
    int dimension, sum, c(0), num, x, y, ox, oy, f;
    vector<vector<int> > grid;
    
    while (cin >> dimension){
        if (c++) cout << "\n";
        grid.clear(); grid.assign(dimension, vector<int>());
        
        for (int i = 0; i < dimension; i++) grid[i].assign(dimension, 0);

        x = 0; y = dimension/2; num = 0; sum = (dimension*(dimension*dimension + 1))/2;
        grid[x][y] = ++num;
                    
        for (int i = 1; i < dimension*dimension; i++){
            ox = x; oy = y;
            
            (x == 0)? x = dimension-1 : x--; //up
            (y == dimension-1)? y = 0 : y++; //right
            
            if (grid[x][y]){ 
                x = ox, y = oy; //go back
                (x == dimension-1)? x = 0 : x++; //then down
            }
            
            grid[x][y] = ++num;
        }
        
        f = 0; //fill
        while (num){
            num /= 10;
            f++;
        }
        
        cout << "n=" << dimension << ", sum=" << sum << "\n";
        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension; j++) cout << " " << setw(f) << grid[i][j]; cout << "\n";
        }
    }
    return 0;
}
