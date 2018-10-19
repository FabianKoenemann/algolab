#include <bits/stdc++.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>

using namespace std;
using namespace boost;

typedef vector<int> vec;
typedef vector<vec> vvec;
typedef std::unordered_map<string, vec> vmap;
typedef adjacency_list<vecS, vecS, undirectedS> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;

void test_case() {
    int n, c, f;
    cin >> n >> c >> f;

    vmap data;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < c; ++j) {
            string str; cin >> str;
            data[str].push_back(i); 
        }

    Graph g(n);
    vvec count(n, vec(n, 0));
    for (auto it = data.begin(); it != data.end(); ++it) {
        const vec& studis = it->second;
        for (int i = 0; i < studis.size(); ++i)
            for (int j = i + 1; j < studis.size(); ++j) {
                int s1 = studis[i], s2 = studis[j]; 
                if(++count[s1][s2] == f + 1) add_edge(s1, s2, g);
            }
    }

    vector<Vertex> buddies(n);
    edmonds_maximum_cardinality_matching(g, &buddies[0]);
    int matchingsize = matching_size(g, &buddies[0]);
    if (matchingsize == n / 2) cout << "not optimal\n";
    else cout << "optimal\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) test_case();
}
