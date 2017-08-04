#include <iostream>
using namespace std;

class QuickFind{
	private:
		int *id;
	
	public:
		QuickFind(int N){
			id = new int[N];
			for (int i = 0; i < N; i++) id[i] = i;
		}
		
		boolean find(int p, int q){
			return id[p] == id[q];
		}
		
		void unite(int p, int q){
			int p_id = id[p];
			for (int i = 0; i < id.length(); i++)
				if (id[i] == pid) id[i] = id[q];
		}
};

int main(){
	return 0;
}
