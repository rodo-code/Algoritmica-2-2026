
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct FlowNetwork {
    int n;
    vector< vector<int> > adj;
    vector< vector<int> > residual;
    vector< vector<int> > original;

    FlowNetwork(int n) : n(n) {
        adj.assign(n, vector<int> ());
        residual.assign(n, vector<int>(n, 0));
        original.assign(n, vector<int>(n, 0));
    }

    // Agregar una arista dirigida
    void addEdge(int u, int v, int capacity) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Para la red residual
        residual[u][v] += capacity;
        original[u][v] += capacity;
    }

    // Buscar camino aumentante mediante BFS
    bool bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(s);
        parent[s] = s;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 &&
                    residual[u][v] > 0) {
                    parent[v] = u;
                    if (v == t)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    // Edmonds-Karp
    int maxFlow(int s, int t, const vector<string>& names) {
        if (s == t) return 0;
        int totalFlow = 0;
        vector<int> parent(n);
        while (bfs(s, t, parent)) {
            int bottleneck = INT_MAX;
            // Calcular cuello de botella
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                bottleneck = min(bottleneck, residual[u][v]);
            }
            // Reconstruir el camino
            vector<int> path;
            for (int v = t; v != s; v = parent[v])
                path.push_back(v);
            path.push_back(s);
            reverse(path.begin(), path.end());
            cout << "Camino: ";
            for (int i = 0; i < (int)path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << names[path[i]];
            }

            cout << " | Flujo: " << bottleneck << "\n";
            
            // Actualizar red residual
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                residual[u][v] -= bottleneck;
                residual[v][u] += bottleneck;
            }

            totalFlow += bottleneck;
        }

        return totalFlow;
    }
};

int main() {
    // S=0, A=1, B=2, C=3, D=4, E=5, T=6
    FlowNetwork g(7);

    vector<string> names = {
        "S", "A", "B", "C", "D", "E", "T"
    };

    g.addEdge(0, 1, 10); // S -> A
    g.addEdge(0, 2, 8);  // S -> B
    g.addEdge(0, 3, 6);  // S -> C

    g.addEdge(1, 4, 5);  // A -> D
    g.addEdge(1, 5, 4);  // A -> E
    g.addEdge(1, 2, 2);  // A -> B

    g.addEdge(2, 4, 4);  // B -> D
    g.addEdge(2, 5, 6);  // B -> E

    g.addEdge(3, 2, 3);  // C -> B
    g.addEdge(3, 5, 5);  // C -> E

    g.addEdge(4, 6, 9);  // D -> T
    g.addEdge(4, 5, 2);  // D -> E

    g.addEdge(5, 6, 10); // E -> T
    

    cout << "FLUJO MAXIMO\n\n";

    int result = g.maxFlow(0, 6, names);

    cout << "\nResultado: " << result << "\n";
}
