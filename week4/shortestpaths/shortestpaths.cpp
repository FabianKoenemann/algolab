#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> coord;
typedef vector<coord> cvec;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
using namespace boost;
typedef adjacency_list<vecS, vecS, directedS, no_property, property<edge_weight_t, int>> Graph;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef property_map<Graph, edge_weight_t>::type WeightMap;

#define submit_verion

int main () {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n, m , q;
    cin >> n >> m >> q;

    cvec coords;
    coords.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }

    Graph g(n);
    WeightMap wm = get(edge_weight, g);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        Edge e; bool yep;
        tie(e, yep) = add_edge(a, b, g);
        assert(yep);
        wm[e] = c;
    }

    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        if (s == t) {
            cout << "0\n" << s << "\n";
            continue;
        }
        vector<int> predecessors(n);
        vector<int> distances(n);
        auto p_ipm = make_iterator_property_map(predecessors.begin(), get(vertex_index, g));
        auto d_ipm = make_iterator_property_map(distances.begin(), get(vertex_index, g));
        // ToDo: Already have a hashmap root -> distances to avoid calling dijkstra's again
        // Edit: Apparently, this optimization is not needed for 100 points
        dijkstra_shortest_paths(g, s, predecessor_map(p_ipm).distance_map(d_ipm));
        if (predecessors[t] == t) {
            cout << "unreachable\n";
        } else {
            cout << distances[t] << "\n";
#ifndef submit_version
            // generate input for visualization script
            int curr = t;
            while (s != curr) {
                cout << (curr = predecessors[curr]) << " ";
            }
            cout << "\n";
#endif
        }
    }
}
