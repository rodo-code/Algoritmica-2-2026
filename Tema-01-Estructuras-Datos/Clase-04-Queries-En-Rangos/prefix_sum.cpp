#include <iostream>
#include <vector>

using namespace std;

vector<int> v,a;

void inicializar(int N){
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
        if(i==0){
            a.push_back(x);
        }
        else{
            a.push_back(x+a.back());
        }
    }
}

int query(int i,int j){
    if(i==0) return a[j];
    else return a[j]-a[i-1];
}

int main(){
    int N,Q;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    cout<<"Ingrese los "<<N<<" elementos: ";
    inicializar(N);
    cout<<"Ingrese cantidad de consultas: ";
    cin>>Q;
    for(int q=0;q<Q;q++){
        int i,j;
        cout<<"Ingrese su consulta: ";
        cin>>i>>j;
        cout<<"La respuesta a su consulta es "<<query(i,j)<<endl;
    }
    return 0;
}