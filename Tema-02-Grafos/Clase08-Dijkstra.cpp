#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector< vector< pair<int,int> > > G;

int main(){
    int nodos,aristas;
    cin>>nodos>>aristas;
    G.assign(nodos, vector< pair<int,int> >());
    for(int i=0;i<aristas;i++){
        int a, b, peso;
        cin>>a>>b>>peso;
        G[a].push_back(make_pair(b,peso));
        G[b].push_back(make_pair(a,peso));
    }
    // Recorrer la lista de Adyacencia 
    for(int i=0;i<G.size();i++){
        cout<<"El nodo "<<i<<" esta conectado a ..."<<endl;
        for(pair<int,int> vecino: G[i]){
            cout<<vecino.first<<" con una distancia de "<<vecino.second<<endl;
        }
    }
}