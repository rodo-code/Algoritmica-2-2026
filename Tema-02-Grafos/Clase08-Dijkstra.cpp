#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector< vector< pair<int,int> > > G;
vector<int> p, dist;

void DIJKSTRA(int nodo){
    p[nodo] = nodo;
    dist[nodo] = 0;
    set< pair<int,int> > pq;
    pq.insert(make_pair(0,nodo));
    while(!pq.empty()){
        pair<int,int> par = *(pq.begin()); // Obtener el elemento menor
        int distancia = par.first;
        nodo = par.second;
        pq.erase(pq.begin()); // Eliminar al elemento menor
        // Proceso de relajar las aristas del nodo
        for(pair<int,int> vecino: G[nodo]){
            // Si mejoramos la distancia
            int nodoVecino = vecino.first;
            int peso = vecino.second;
            if(distancia+peso < dist[nodoVecino]) {
                // Proceso para borrar si hubiera uno anterior
                if(dist[nodoVecino]!=INT_MAX){
                    // Buscamos si existe un par (dist[nodoVecino], nodoVecino) en la cola
                    auto it = pq.find(make_pair(dist[nodoVecino],nodoVecino));
                    if(it!=pq.end()){ // Si fue encontrada la parejita
                        pq.erase(it);
                    }
                }
                // Insertamos la nueva pareja
                dist[nodoVecino] = distancia+peso;
                p[nodoVecino] = nodo;
                pq.insert(make_pair(dist[nodoVecino],nodoVecino));
            }
        }
    }
}

int main(){
    int nodos,aristas;
    cin>>nodos>>aristas;
    G.assign(nodos, vector< pair<int,int> >());
    p.assign(nodos, -1);
    dist.assign(nodos,INT_MAX);
    for(int i=0;i<aristas;i++){
        int a, b, peso;
        cin>>a>>b>>peso;
        G[a].push_back(make_pair(b,peso));
        G[b].push_back(make_pair(a,peso));
    }
    DIJKSTRA(0);
        // Recorrer la lista de Adyacencia 
    for(int i=0;i<G.size();i++){
        cout<<"El nodo "<<i<<" tiene como predecesor al nodo "<<p[i]<<" y distancia desde el 0 de "<<dist[i]<<endl;
    }
}