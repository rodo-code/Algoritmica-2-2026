#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > G; // Grafo version lista de adyacencia
vector<int> p, dist;

void BFS(int nodo){
    queue<int> q;
    p[nodo] = nodo; // El padre del nodo inicial es el mismo nodo
    dist[nodo] = 0; // La distancia al nodo inicial es 0
    q.push(nodo);
    while(!q.empty()){
        nodo = q.front(); // Saber quien esta al inicio de la cola
        q.pop(); // Eliminar de la cola al que esta adelante
        for(int vecino: G[nodo]){
            if(p[vecino]==-1){ // Significa que el vecino aun no esta visitado
                q.push(vecino);
                p[vecino] = nodo;
                dist[vecino] = dist[nodo]+1;
            }
        }
    }
}

int main(){
    int nodos, aristas;
    cin>>nodos>>aristas;
    G.assign(nodos,vector<int>()); // Colocamos en G, varios vectores vacios
    p.assign(nodos,-1); // Inicializamos el vector predecesores en -1
    dist.assign(nodos,INT_MAX); // Inicializamos el vector de distancia con INFINITO
    for(int i=0;i<aristas;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // TAREA DE CLASE
    // Pedir al usuario dos nodos X e Y y decirle que camino debe seguir
    // para llegar de X a Y
    return 0;
}