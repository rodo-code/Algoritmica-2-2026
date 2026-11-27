#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000;
vector<int> d;
vector< vector<int> > memo, transicion;
int M;
int resolver(int h, int i){
    // Revisar caso base
    if(h<0) return INF;
    if(i==M){ // Ya revisamos todos los workout
        if(h==0) return 0;
        else return INF; // Infinito porque no es legal esos paso
    }
    // Revisar si ya esta memoizado
    if(memo[h][i]!=-1) return memo[h][i];
    // Transiciones entre estados
    int resultado_up = resolver(h+d[i],i+1);
    int resultado_down = resolver(h-d[i],i+1);
    if(resultado_up <= resultado_down){ // Nos vamos por UP
        transicion[h][i] = 1;
    }
    else{ // Nos vamos por DOWN
        transicion[h][i] = -1;
    }
    return memo[h][i] = max(h,min(resultado_up,resultado_down));
}

int main(){
    int N;
    cin>>N;
    while(N--){ // un while que hace N ciclos
        cin>>M;
        d.clear();
        memo.clear();
        transicion.clear();
        d.assign(M,0);
        memo.assign(1001,vector<int>(M+1,-1));
        transicion.assign(1001,vector<int>(M+1,0));
        for(int i=0;i<M;i++){
            cin>>d[i];
        }
        int max_alt = resolver(0,0);
        if(max_alt == INF) cout<<"IMPOSSIBLE"<<endl;
        else{
            // Reconstruir el camino
            int h=0, i=0;
            while(i<M){
               if(transicion[h][i]==1) cout<<"U";
               if(transicion[h][i]==-1) cout<<"D";   
               h = h + (transicion[h][i])*d[i];
               i++;
            }
            cout<<endl;
        }
    }
    return 0;
}