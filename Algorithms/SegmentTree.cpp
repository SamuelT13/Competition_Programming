#include <iostream>
#include <vector>
using namespace std;

const int MAX_VALUE = 2000000000;
struct segment_tree{
	int size;
	vector<int> tree;
	
	segment_tree(const vector<int>& vals){
		size = vals.size();
		tree.resize(4*size);
		initialize(0,0,size-1,vals);
	}
	
	int initialize(int node, int nleft, int nright, const vector<int>& vals){
		if (nleft == nright) tree[node] = vals[nleft];
		else{
			int nmid = (nleft+nright)/2;
			tree[node] = min(initialize(2*node+1,nleft,nmid,vals),
							 initialize(2*node+2,nmid+1,nright,vals));
		}
		return tree[node];
	}
	
	int update(int index, int val){
		update(index,0,0,size-1,val);
	}
	
	int update(int index, int node, int nleft, int nright, int val){
		if (nleft <= index && index <= nright){
			if (nleft == nright)
				tree[node] = val;
			else{
				int nmid = (nleft+nright)/2;
				
				tree[node] = min(update(index,2*node+1,nleft,nmid,val),
								 update(index,2*node+2,nmid+1,nright,val));
			}
		}
		
		return tree[node];
	}
	
	int query(int start, int end) const{
		return query(start,end,0,0,size-1);
	}
	
	int query(int start, int end, int node, int nleft, int nright) const{
		if (nright < start || end < nleft)
			return MAX_VALUE;
		if (start <= nleft && nright <= end)
			return tree[node];
		int nmid = (nleft+nright)/2;
		
		return min(query(start,end,2*node+1,nleft,nmid),
				   query(start,end,2*node+2,nmid+1,nright));
	}
};
