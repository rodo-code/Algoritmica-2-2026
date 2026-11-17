#include <iostream>
#include <vector>
#include <set>

using namespace std;

// v guarda las aristas en formato (peso, (a,b) )
vector< pair< int, pair<int,int> > > v;

vector<int> rep, rk;

void inicializar(int N){
    rep.clear();
    rk.clear();
    for(int i=0;i<N;i++){
        rep.push_back(i); // Me genera 0, 1, 2, 3, ...
        rk.push_back(0);
    }
}

int buscar(int x){
    if(x == rep[x]) return x;
    else{
        rep[x] = buscar(rep[x]);
        return rep[x];
    }
}

void unir(int x, int y){
    x = buscar(x);
    y = buscar(y);
    if(x == y) return; // No tenemos que unir nada ya estan unidos
    if(rk[x] > rk[y]){
        rep[y] = x;
    } else if (rk[x] < rk[y]) {
        rep[x] = y;
    } else { // rk[x] == rk[y]
        if(x > y){ // No es absolutamente necesario
            rep[y] = x;
            rk[x]++;
        }
        else { 
            rep[x] = y;
            rk[y]++;
        }
    }
}

int main(){
    int nodos, aristas;
    while(cin>>nodos>>aristas){
        vector< pair<int,int> > aristasMST;
        v.clear(); // Reseteamos el vector que guarda las aristas
        if(nodos == 0 && aristas == 0) break;
        for(int i=0;i<aristas;i++){
            int a,b,peso;
            cin>>a>>b>>peso;
            if(a>b) swap(a,b); // Intercambiamos a y b, para que a < b
            v.push_back(make_pair(peso,make_pair(a,b)));
        }
        // ALGORITMO DE KRUSKAL
        sort(v.begin(),v.end()); // Ordenamos el vector por peso
        int pesoMST = 0;
        inicializar(nodos); // inicializar el UNION FIND
        for(auto arista: v){
            int peso = arista.first;
            int a = arista.second.first;
            int b = arista.second.second;
            if(buscar(a)!=buscar(b)){
                unir(a,b); // 1. Unimos en el union find
                pesoMST += peso; // 2. Sumamos esa arista para el MST
                aristasMST.push_back(make_pair(a,b)); // 3. Agregamos a las aristas del MST
            }
        }
        // Finalmente vemos si se pudo hallar un MST
        if(aristasMST.size()==nodos-1){
            cout<<pesoMST<<endl;
            sort(aristasMST.begin(),aristasMST.end());
            for(auto arista: aristasMST){
                cout<<arista.first<<" "<<arista.second<<endl;
            }
        }
        else{
            cout<<"Impossible"<<endl;
        }
    }
}