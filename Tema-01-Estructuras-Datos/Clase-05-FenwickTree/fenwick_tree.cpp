#include <iostream>
#include <vector>

using namespace std;

vector<int> v, ft;

int bit_bajo(int i) {
    return (i & -i);
}

void crear_fenwick_tree(int N){
    ft.assign(N+1,0);
    for(int i=1;i<=N;i++){
        ft[i] += v[i-1]; // Sumar el elemento del vector
        if (i + bit_bajo(i) <= N) {
            ft[i + bit_bajo(i)] += ft[i];
        }
    }
}

int consulta(int a, int b){
    if(a == 1) {
        int i=b;
        int acum = 0;
        while(i>0){
            acum += ft[i];
            i -= bit_bajo(i);
        }
        return acum;
    }
    else {
        return consulta(1,b) - consulta(1,a-1);
    }
}

void actualizacion(int pos, int val){
    int delta = val - v[pos];
    v[pos] = val; 
    pos++;
    // ...
}

int main(){
    int N,Q;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    cout<<"Ingrese los "<<N<<" elementos: ";
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    crear_fenwick_tree(N);
    cout<<"Ingrese cantidad de consultas: ";
    cin>>Q;
    for(int i=0;i<Q;i++){
        int tipo;
        // Primero pedimos el tipo
        cin>>tipo;
        // Si el tipo es 1 es una consulta del rango [a,b]
        if(tipo == 1){
            int a,b;
            cin>>a>>b;
            cout<<consulta(a+1,b+1)<<endl;
        }
        // Si el tipo es 2 es una actualizacion de la posicion pos con valor val
        if(tipo == 2){
            // Implementar Actualizacion
        }
    }
    return 0;
}