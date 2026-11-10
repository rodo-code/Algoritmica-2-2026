#include <iostream>
#include <vector>

using namespace std;

vector<int> rep, rk;

void inicializar(int N){
    for(int i=0;i<N;i++){
        rep.push_back(i); // Me genera 0, 1, 2, 3, ...
        rk.push_back(0);
    }
}

int buscar(int x){
    if(x == rep[x]) return x;
    else return rep[x] = buscar(rep[x]);
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
        if(x > y){
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
    inicializar(10);
    unir(7,4);
    unir(1,3);
    unir(1,6);
    unir(4,1);
    cout<<buscar(1)<<endl; // Buscar en realidad encuentra el representante
    cout<<buscar(3)<<endl;
    for(int i=0;i<10;i++){
        cout<<rep[i]<<" ";
    }
    cout<<endl;
    return 0;
}