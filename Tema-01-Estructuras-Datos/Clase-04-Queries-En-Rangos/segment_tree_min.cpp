#include <iostream>
#include <vector>

using namespace std;

vector<int> v, st; // st significa segment tree
void llenar_vector(int N){
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
}

void crear_segment_tree(int nodo, int izq, int der){
    if(izq == der){
        st[nodo] = v[izq]; // Caso base de un rango de tamaño uno
        return; 
    }
    int medio = (izq+der)/2;
    // Crear izquierda
    crear_segment_tree(nodo*2,izq,medio);
    // Crear derecha
    crear_segment_tree(nodo*2+1,medio+1,der);
    // Unir ambos segmentos
    st[nodo] = min(st[nodo*2],st[nodo*2+1]);
}

void inicializar_segment_tree(int N){
    st.assign(N*4,INT_MAX); //
    crear_segment_tree(1,0,N-1);
}

int consulta(int a, int b, int nodo, int izq, int der){
    if(der < a || b < izq) return INT_MAX;
    if(a <= izq && der <= b) return st[nodo];
    int medio = (izq+der)/2;
    int res_izq = consulta(a,b,nodo*2,izq,medio);
    int res_der = consulta(a,b,nodo*2+1,medio+1,der);
    return min(res_izq,res_der);
}

void actualizar(int pos, int valor, int nodo, int izq, int der){
    // Implementar esta funcion
}

int main(){
    int N,Q;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    cout<<"Ingrese los "<<N<<" elementos: ";
    llenar_vector(N);
    inicializar_segment_tree(N);
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
            cout<<consulta(a,b,1,0,N-1)<<endl;
        }
        // Si el tipo es 2 es una actualizacion de la posicion pos con valor val
        if(tipo == 2){
            // USARLA ACA
        }
    }
    return 0;
}