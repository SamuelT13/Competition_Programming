#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 0;

struct segment_tree
{
  int size;
  vector<int> tree;
  
  // Constructs a segment tree from a sequence of initial values.
  segment_tree(const vector<int>& vals)
  {
    size = vals.size();
    tree.resize(4 * size);
    if (size > 0)
      initialize(0, 0, size - 1, vals);
  }
  
  // Initializes the values of nodes recursively.
  int initialize(int node, int nleft, int nright, const vector<int>& vals)
  {
    if (nleft == nright)
      tree[node] = vals[nleft];
    else
    {
      int nmid = (nleft + nright) / 2;
      tree[node] = 
        initialize(2 * node + 1, nleft, nmid, vals)+
        initialize(2 * node + 2, nmid + 1, nright, vals);
    }
    return tree[node];
  }
  
  // Sets the value at the specified sequence index.
  void update(int index, int val)
  {
    update(index, 0, 0, size - 1, val);
  }
  
  // Sets the value at the specified sequence index and updates all affected nodes recursively.
  int update(int index, int node, int nleft, int nright, int val)
  {
    if (nleft <= index && index <= nright)
    {
      if (nleft == nright)
        tree[node] = val;
      else
      {
        int nmid = (nleft + nright) / 2;
        tree[node] =
          update(index, 2 * node + 1, nleft, nmid, val)+
          update(index, 2 * node + 2, nmid + 1, nright, val);
      }
    }
    return tree[node];
  }
  
  // Calculates the minimum value in the sequence from start to end.
  int query(int start, int end) const
  {
    return query(start, end, 0, 0, size - 1);
  }
  
  // Calculates the minimum value in the sequence from start to end recursively.
  int query(int start, int end, int node, int nleft, int nright) const
  {
    if (nright < start || end < nleft)
      return MAX_VALUE;
    if (start <= nleft && nright <= end)
      return tree[node];
    int nmid = (nleft + nright) / 2;
    return
      query(start, end, 2 * node + 1, nleft, nmid)+
      query(start, end, 2 * node + 2, nmid + 1, nright);
  }
};

int main(){
	vector<int> list;
	list.assign(100,0);
	segment_tree nums(list);
	int q, a, b, i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (i = 1; i <= 100; i++)
		if (i % 2) nums.update(i,i);
	
	cin >> q;
	
	for (i = 0; i < q; i++){
		cin >> a >> b;
		cout << "Case " << i+1 << ": " << nums.query(a,b) << "\n";
	}
	return 0;
}
