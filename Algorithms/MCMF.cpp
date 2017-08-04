#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Min-Cost Max-Flow
//Weighted MCBM

const int INF = 1e7;
vector<vector<int> > cost, res, f, AdjList;
int max_flow, flow, s, t, count, temp;
vector<int> used, e, l, p, dist; //parent

int test, V, total, bonus, max_pay, time_spent, ans, pay, mp;

void update_flow(int change){
	for (int v = t; v != s; v = p[v]) //backtracking
        f[p[v]][v] += change, f[v][p[v]] -= change;
}

void init_graph(int add){
    cost.clear(); cost.assign(V, vector<int>());
    res.clear(); res.assign(V, vector<int>());
    f.clear(); f.assign(V, vector<int>());
    AdjList.clear(); AdjList.assign(V, vector<int>());
    
    for (int i = 0; i < V; i++)  cost[i].assign(V, 0), res[i].assign(V, 0), f[i].assign(V, 0);

    for (int i = 0; i < total; i++){
                         //0 cost from source to entry
        res[s][i+1] = 1; //1 capacity from source to entry
        AdjList[s].push_back(i+1); //edge from source to entry
    }

    for (int i = 0; i < total; i++){
                               //0 cost from leave to sink
        res[total+i+1][t] = 1; //1 capacity from leave to sink
        AdjList[total+i+1].push_back(t); //edge from leave to sink
    }

    for (int i = 0; i < total; i++)
        for (int j = 0; j < total; j++){
            time_spent = l[j]-e[i];
            pay = min((time_spent-bonus)*(time_spent-bonus), max_pay);
            
            res[i+1][total+j+1] = 1; //1 capacity from enter to leave
            AdjList[i+1].push_back(total+j+1); //edge from enter to leave
            AdjList[total+j+1].push_back(i+1); //edge from leave to enter
        
            if (add) pay = add-pay;
        
            if (time_spent > 0) cost[i+1][total+j+1] = pay, mp = max(mp, pay); //actual cost
            else cost[i+1][total+j+1] = INF; //'filler' cost
    }

  /*for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++) cout << res[i][j] << " "; cout << endl;}
    cout << "------\n";
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++) cout << cost[i][j] << " "; cout << endl;}*/
}

bool dijk(){
    p.clear(); p.assign(V, -1); p[s] = s;
    dist.clear(); dist.assign(V, INF); dist[s] = 0;
    
    queue<int> q; q.push(s);
    used.clear(); used.assign(V, 0); used[s] = 1;
    
    while (!q.empty()){
        int v = q.front(); q.pop();
        used[v] = 0;
       
        for (int i = 0; i < AdjList[v].size(); i++){
            int v2 = AdjList[v][i];
            
            if (f[v2][v] > 0 && dist[v] + (-cost[v2][v]) < dist[v2]){
                dist[v2] = dist[v] + (-cost[v2][v]);
                p[v2] = v;
                if (!used[v2]) used[v2] = 1, q.push(v2);
            }
            
            else if (res[v][v2] > f[v][v2] && dist[v] + cost[v][v2] < dist[v2]){
                dist[v2] = dist[v] + cost[v][v2];
                p[v2] = v;
                if (!used[v2]) used[v2] = 1, q.push(v2);
            }
        }
    }
    
    return dist[t] != INF;
}

int MCMF(){
    int min_c(0);
    
    while (dijk()){
        update_flow(1); //cap of flow being transferred
        min_c += dist[t];
        count++;
    }
    
    return min_c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test;
    
    while (test--){
        cin >> total >> bonus >> max_pay;
        s = 0; t = 2*total + 1; //s: 0, t: 2*N+1, V: 2*N+2, entry: 1 to N, leave: N+1 to 2*N
        V = 2*total+2; mp = -1; count = 0;

        e.clear(); e.assign(total, 0);
        l.clear(); l.assign(total, 0);
        for (int i = 0; i < total; i++) cin >> e[i];
        for (int i = 0; i < total; i++) cin >> l[i];
            
        //MIN
        temp = 0;
        init_graph(temp);
        ans = MCMF();
        
        if (count < total){cout << "impossible\n"; continue;}

        cout << ans << " ";
  
        //MAX
        temp = mp;
        init_graph(temp);
        ans = MCMF();
        
        cout << total*mp-ans << "\n";
    }
	return 0;
}
