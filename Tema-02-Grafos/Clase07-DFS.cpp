#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > G; // Grafo version lista de adyacencia
vector<bool> vis;

void DFS(int nodo){
    vis[nodo] = true;
    for(int vecino: G[nodo]) {
        if(!vis[vecino]){
            DFS(vecino);
        }
    }
}

int main(){
    int nodos, aristas;
    cin>>nodos>>aristas;
    G.assign(nodos,vector<int>()); // Colocamos en G, varios vectores vacios
    vis.assign(nodos,false);
    for(int i=0;i<aristas;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // Llamar al DFS
    DFS(0);
    for(int i=0;i<vis.size();i++){
        if(vis[i]) cout<<"El nodo "<<i<<" fue visitado"<<endl;
        else cout<<"El nodo "<<i<<" NO fue visitado"<<endl;
    }
    // TAREA DE CLASE
    // Usar el DFS para responder a la consulta
    // de cuantas componentes tiene el grafo
    return 0;
}