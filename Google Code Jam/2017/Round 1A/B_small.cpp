#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const double EPS = 1e-9;

int test, total, packets;
vector<int> servings;
vector<vector<int> > grams;
vector<int> valid, temp;
vector<int> match, vis;
vector<vector<int> > AdjList;

int Aug(int index){
	if (vis[index] == 1) return 0;
	vis[index] = 1;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		if (match[ind2] == -1 || Aug(match[ind2])){
			match[ind2] = index;
			return 1;
		}
	}
	return 0;
}

void find_mult(int i, int j){
    double g;
    
    for (int k = 1; ; k++){
        g = servings[i]*k;
        //if (double(grams[i][j]) - g*0.9 >= EPS && g*1.1 - double(grams[i][j]) >= EPS) temp.push_back(k);
		//else if (g*0.9 - double(grams[i][j]) > EPS) return;
        if (double(grams[i][j]) >= g*0.9 && double(grams[i][j]) <= g*1.1) temp.push_back(k);
        else if (double(grams[i][j]) < g*0.9) return;
    }
}

int main(){
	int ind, ind1, MCBM;
	vector<vector<vector<int> > > indices;
	ifstream in("B-small-attempt0.in");
	ofstream out("out1.txt");
	
	ios_base::sync_with_stdio(false);
	in.tie(NULL);
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		in >> total >> packets;
		out << "Case #" << t << ": ";
        
        AdjList.clear(); AdjList.assign(total*packets, vector<int>());
		grams.clear(); servings.clear();
		indices.clear(); indices.assign(total, vector<vector<int> >());
        grams.assign(total, vector<int>()); servings.assign(total, 0);
		
		for (int i = 0; i < total; i++) in >> servings[i];
		
		for (int i = 0; i < total; i++){
            indices[i].assign(packets, vector<int>());
            grams[i].assign(packets, 0);
			for (int j = 0; j < packets; j++) in >> grams[i][j];
        }
       
        for (int i = 0; i < total; i++)
            for (int j = 0; j < packets; j++){
                temp.clear();
                find_mult(i, j);
                indices[i][j] = temp;
            }
        
        if (total == 1){
            MCBM = 0;
            for (int i = 0; i < packets; i++) if (!indices[0][i].empty()) MCBM++;
            out << MCBM << "\n";
            continue;
        }
        
        //Only works for N = 2... for N > 2, maxflow is needed
        for (int j = 0; j < packets; j++)
                for (int k = 0; k < packets; k++) 
                    for (int l = 0; l < indices[1][k].size(); l++)
                        if (find(indices[0][j].begin(), indices[0][j].end(), indices[1][k][l]) != indices[0][j].end()){         
                            AdjList[j].push_back(packets+k);
                            break;
                        }
        MCBM = 0;
        match.clear(); match.assign(total*packets, -1);

        for (int i = 0; i < packets; i++){
		  vis.assign(packets, -1);
		  MCBM += Aug(i);
	   }
	
	   out << MCBM << "\n";
	}
	return 0;
}
