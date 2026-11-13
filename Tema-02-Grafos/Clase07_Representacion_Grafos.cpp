#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > G; // Grafo version lista de adyacencia

int main(){
    int nodos, aristas;
    cin>>nodos>>aristas;
    G.assign(nodos,vector<int>()); // Colocamos en G, varios vectores vacios
    for(int i=0;i<aristas;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // Imprimiendo el grafo
    for(int i=0;i<G.size();i++){
        cout<<"El nodo "<<i<<" esta conectado con: ";
        /*for(int j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }*/
        for(int vecino: G[i]){ // Para los vecinos de la lista G[i]
            cout<<vecino<<" ";
        }
        cout<<endl;
    }
    return 0;
}