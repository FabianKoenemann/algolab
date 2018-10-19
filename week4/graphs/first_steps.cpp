#include <bits/stdc++.h>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<
    vecS,                           // edge list type
    vecS,                           // vertex list type
    undirectedS,                    // directed/undirected
    no_property,                    // vertex properties
    property<edge_weight_t, int>    // edge properties
> Graph;

typedef graph_traits<Graph>::vertex_descriptor  Vertex;
typedef graph_traits<Graph>::edge_descriptor    Edge;
typedef graph_traits<Graph>::edge_iterator      EdgeIt;

typedef property_map<Graph, edge_weight_t>::type WeightMap;

void test_case() {
    int n, m;
    cin >> n >> m;

    Graph g(n);
    WeightMap wm = get(edge_weight, g);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        Edge e; bool yep;
        tie(e, yep) = add_edge(u, v, g);
        wm[e] = w;
    }

    // minumum spanning tree weight
    vector<Edge> mst;
    kruskal_minimum_spanning_tree(g, back_inserter(mst));
    int mst_sum = 0;
    for (auto mst_edge : mst) mst_sum += wm[mst_edge];
    
    // longest shortest distance from 0
    vector<int> d(n);
    auto d_ipm = make_iterator_property_map(d.begin(), get(vertex_index, g));
    int start_vertex = 0;
    dijkstra_shortest_paths(g, start_vertex, distance_map(d_ipm));
    auto max_it = max_element(d.begin(), d.end());

    cout << mst_sum << " " << *max_it << endl;
}

int main() {
    int t; cin >> t;
    while (t--) test_case();
    return 0;
}
