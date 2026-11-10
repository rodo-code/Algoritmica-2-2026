#include <iostream>
#include <vector>

using namespace std;

vector<int> v, st; // segment tree

void llenar_vector(int N){
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
}

void crear_segment_tree(int nodo, int izq, int der){
    if(izq == der){
        st[nodo]=v[izq]; // Llegamos a una hoja del segment tree
        return;
    }
    int medio = (izq + der)/2;
    // Creamos la izquierda
    crear_segment_tree(nodo*2,izq,medio);
    // Creamos la derecha
    crear_segment_tree(nodo*2+1,medio+1,der);
    // Unir
    st[nodo] = st[nodo*2] + st[nodo*2 + 1]; 
}

void inicializar_segment_tree(int N){
    st.assign(N*4,0);
    crear_segment_tree(1,0,N-1);
}

int main(){
    int N;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    cout<<"Ingrese los "<<N<<" elementos: ";
    llenar_vector(N);
    inicializar_segment_tree(N);
    for(int i=0;i<st.size();i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    return 0;
}