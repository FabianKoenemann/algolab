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

typedef property_map<Graph, edge_weight_t>::type WeightMap;

void test_case() {
    int n, e, s, a, b;
    cin >> n >> e >> s >> a >> b;

    // build a raw model of the forest as seen by different species
    vector<Graph> g(s, Graph(n));
    vector<WeightMap> wm;
    wm.reserve(s);
    for (int j = 0; j < s; ++j)
        wm.push_back(get(edge_weight, g[j]));
    for (int i = 0; i < e; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        for (int j = 0; j < s; ++j) {
            int wj; cin >> wj;
            Edge edge; bool yep;
            tie(edge, yep) = add_edge(t1, t2, g[j]);
            assert(yep);
            wm[j][edge] = wj;
        }
    }
    vector<int> hives;
    hives.reserve(s);
    for (int j = 0; j < s; ++j) {
        int hive;
        cin >> hive;
        hives.push_back(hive);
    }

    // hives don't matter: networks are minimum spanning trees
    vector<vector<Edge>> mst(s, vector<Edge>());
    for (int j = 0; j < s; ++j) {
        kruskal_minimum_spanning_tree(g[j], back_inserter(mst[j]));
    }
    
    // build the combined graph
    // (just add edges discovered by multiple species multiple times)
    Graph G(n);
    WeightMap WM = get(edge_weight, G);
    for (int j = 0; j < s; ++j) {
        for (const auto& e : mst[j]) {
            Vertex U = source(e, g[j]);
            Vertex V = target(e, g[j]);
            int W = wm[j][e];
            Edge E; bool yep;
            tie (E, yep) = add_edge(U, V, G);
            WM[E] = W;
        }
    }

    // apply dijkstra's on the combined graph
    vector<int> d(n);
    auto d_ipm = make_iterator_property_map(d.begin(), get(vertex_index, G));
    int start_vertex = a;
    dijkstra_shortest_paths(G, start_vertex, distance_map(d_ipm));
    cout << d[b] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) test_case();
    return 0;
}
