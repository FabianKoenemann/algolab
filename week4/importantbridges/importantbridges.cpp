#include <bits/stdc++.h>
using namespace std;

#include <boost/graph/connected_components.hpp>
#include <boost/graph/adjacency_list.hpp>
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS> Graph;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_iterator EdgeIt;

void test_case() {
    int n, m;
    cin >> n >> m;

    vector<Graph> g(m, Graph(n));
    vector<pair<int, int>> e;
    for (int i = 0; i < m; ++i) {
        int ei1, ei2;
        cin >> ei1 >> ei2;
        if (ei1 > ei2) e.push_back(make_pair(ei2, ei1));
        else e.push_back(make_pair(ei1, ei2));
        for (int j = 0; j < m; ++j) {
            if (j != i)
                add_edge(ei1, ei2, g[j]);
        }
    }

    vector<int> components(n);
    vector<pair<int, int>> important;
    for (int j = 0; j < m; ++j) {
        int num_components = connected_components(g[j], &components[0]);
        if (num_components > 1) {
            important.push_back(e[j]);
        }
    }

   cout << important.size() << "\n";
   sort(important.begin(), important.end());
   for (auto b : important) {
       cout << b.first << " " << b.second << "\n";
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c; cin >> c;
    while (c--) test_case();
    return 0;
}
