template<int max_set>struct Set{
  bool is_element[max_set];
};
// Implementation - Set
template<int max_size>class Digraph{
  int count;
  Set<max_size>neighbors[max_size];
  /*
  {}
   */
};
// Implementation - Adjacency table
template<int max_size>class Digraph{
  int count; // number of vertices, at most max_size
  bool adjacency[max_size][max_size];
}
// Implementation - Adjacency list
typedef int Vertex;
template<int max_size>class Digraph {
int count; // number of vertices, at most max_size
List<Vertex> neighbors[max_size];