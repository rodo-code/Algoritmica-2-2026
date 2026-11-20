#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>N;
    vector<int> v(N);
    cout<<"Ingrese los "<<N<<" elementos: ";
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    // Max SubRange Sum
    int suma=0,suma_max = 0;
    for(int i=0;i<v.size();i++){
        suma += v[i];
        suma_max = max(suma_max,suma);
        if(suma < 0) suma =0;
    }
    cout<<"La suma maxima de un subrango es "<<suma_max<<endl;
    return 0;
}