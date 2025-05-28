#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int find(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v], parent);
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> result;
    for (Edge e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            result.push_back(e);
            union_sets(e.u, e.v, parent, rank);
        }
    }

    cout << "Edge \tWeight\n";
    int total = 0;
    for (Edge e : result) {
        cout << e.u << " - " << e.v << " \t" << e.weight << "\n";
        total += e.weight;
    }
    cout << "Total weight of MST: " << total << endl;
    return 0;
}
