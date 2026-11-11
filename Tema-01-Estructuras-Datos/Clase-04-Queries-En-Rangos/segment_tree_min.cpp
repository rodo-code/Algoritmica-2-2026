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
   
}

void inicializar_segment_tree(int N){
    st.assign(N*4,INT_MAX); //
    crear_segment_tree(1,0,N-1);
}

int main(){
    int N,Q;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    cout<<"Ingrese los "<<N<<" elementos: ";
    llenar_vector(N);
    inicializar_segment_tree(N);
    /*cout<<"Ingrese cantidad de consultas: ";
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
    }*/
    return 0;
}