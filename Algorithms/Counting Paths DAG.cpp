Counting Paths in DAG

Clearly the underlying graph of the problem above is a DAG as one can move forward in
time, but cannot go backward. The number of such paths can be found easily by computing
one (any) topological order in O(V + E) (in this problem, vertex 0/birth will always be the
first in the topological order and the vertex n/death will always be the last in the topological
order). We start by setting num paths[0] = 1. Then, we process the remaining vertices
one by one according to the topological order. When processing a vertex u, we update each
neighbor v of u by setting num paths[v] += num paths[u]. After such O(V + E) steps,
we will know the number of paths in num paths[n].
