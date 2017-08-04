#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct info{
	int a, d, prio, id;
	info(){};
	info(int a0, int d0, int p0, int id0): a(a0), d(d0), prio(p0), id(id0){};
};

class Compare{
	public:
		bool operator() (info f, info s){
			if (f.prio == s.prio) return f.a > s.a;
			
			return f.prio < s.prio;
		}
};

int main(){
	priority_queue<info, vector<info>, Compare> pq;
	int test, total, a, d, p, time;
	queue<info> b;
	info temp;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ":\n"; 
		cin >> total; time = 0;
		
		for (int i = 0; i < total; i++){
			cin >> a >> d >> p;
			b.push(info(a,d,p,i+1));
		}
		
		for (int i = 0; i < total; i++){
			if (pq.empty()){
				pq.push(b.front()); b.pop();
			}
			
			temp = pq.top(); pq.pop();
			
			time = max(time, temp.a)+temp.d;
			
			cout << temp.id << " " << time << "\n";
			
			while (b.size() && b.front().a <= time){
				pq.push(b.front()); b.pop();
			}
		}
	}
	
	return 0;
}
