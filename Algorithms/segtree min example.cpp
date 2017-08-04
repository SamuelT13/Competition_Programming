// This is an example of a segment tree for range minimum queries.
// It performs range queries (get the min of a range) in O(log N) time.
// It performs point updates (change the value at a position) in O(log N) time.
// Note that this implementation uses 0-based indexing.

const int MAX_VALUE = 2000000000;

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
      tree[node] = min(
        initialize(2 * node + 1, nleft, nmid, vals),
        initialize(2 * node + 2, nmid + 1, nright, vals));
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
        tree[node] = min(
          update(index, 2 * node + 1, nleft, nmid, val),
          update(index, 2 * node + 2, nmid + 1, nright, val));
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
    return min(
      query(start, end, 2 * node + 1, nleft, nmid),
      query(start, end, 2 * node + 2, nmid + 1, nright));
  }
};