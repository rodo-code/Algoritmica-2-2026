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

int main(){
    int N;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    cout<<"Ingrese los "<<N<<" elementos: ";
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    crear_fenwick_tree(N);
    for(int i=0;i<ft.size();i++) cout<< ft[i] <<" ";
    cout<<endl;
    return 0;
}