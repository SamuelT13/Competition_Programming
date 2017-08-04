// This is an example of a segment tree for range sum queries.
// It performs range queries (get the min of a range) in O(log N) time.
// It performs range updates (change the values across a range) in O(log N) time.
// Note that this implementation uses 0-based indexing.

struct data
{
  LL sum;
  LL delta;
};

struct segment_tree
{
  int size;
  vector<data> tree;
  
  // Constructs a segment tree from a sequence of initial values.
  segment_tree(const vector<int>& vals)
  {
    size = vals.size();
    tree.resize(4 * size);
    if (size > 0)
      initialize(0, 0, size - 1, vals);
  }
  
  // Initializes the values of nodes recursively.
  LL initialize(int node, int nleft, int nright, const vector<int>& vals)
  {
    if (nleft == nright)
    {
      tree[node].delta = vals[nleft];
      tree[node].sum = vals[nleft];
    }
    else
    {
      int nmid = (nleft + nright) / 2;
      tree[node].delta = 0;
      tree[node].sum =
        initialize(2 * node + 1, nleft, nmid, vals) +
        initialize(2 * node + 2, nmid + 1, nright, vals);
    }
    return tree[node].sum;
  }
  
  // Increases all values in the sequence from start to end by val.
  void update(int start, int end, LL val)
  {
    update(start, end, 0, 0, size - 1, val);
  }
  
  // Increases all values in the sequence from start to end by val
  // and updates all affected nodes recursively.
  LL update(int start, int end, int node, int nleft, int nright, LL val)
  {
    if (start <= nright && nleft <= end)
    {
      if (start <= nleft && nright <= end)
      {
        tree[node].delta += val;
        tree[node].sum += val * (nright - nleft + 1);
      }
      else
      {
        int nmid = (nleft + nright) / 2;
        tree[node].sum = tree[node].delta * (nright - nleft + 1) +
          update(start, end, 2 * node + 1, nleft, nmid, val) +
          update(start, end, 2 * node + 2, nmid + 1, nright, val);
      }
    }
    return tree[node].sum;
  }
  
  // Calculates the sum over the sequence from start to end.
  LL query(int start, int end) const
  {
    return query(start, end, 0, 0, size - 1);
  }
  
  // Calculates the sum over the sequence from start to end recursively.
  LL query(int start, int end, int node, int nleft, int nright) const
  {
    if (nright < start || end < nleft)
      return 0;
    if (start <= nleft && nright <= end)
      return tree[node].sum;
    int nmid = (nleft + nright) / 2;
    int overlap = min(nright, end) - max(nleft, start) + 1;
    return overlap * tree[node].delta +
      query(start, end, 2 * node + 1, nleft, nmid) +
      query(start, end, 2 * node + 2, nmid + 1, nright);
  }
};
