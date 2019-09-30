#include <iostream>
#include <vector>
using namespace std;

int T;
int N;
vector<int> L;
vector<int> grafo[100005];
int H[100005];
int S;
int x,y;
int K;

void DFS(int k, int p, int h){
    H[k]=h;
    S+=2*h-1;
    bool flag=true;

    for(int f:grafo[k])
        if(f!=p){
            flag=false;
            DFS(f,k,1-h);
        }

    if(flag)
        L.push_back(k);

}

int main(){
    cin>>T;
    while(T--){

        cin>>N;
        for(int i=0;i<N;i++){
            grafo[i].clear();
            H[i]=0;
        }
        L.clear();
        S=0;

        for(int i=0;i<N-1;i++){
            cin>>x>>y;
            x--,y--;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        DFS(0,-1,0);

        if(S)
            K=2;
        else
            K=1;

        for(int i=0;S!=0;i++)
            if(S>0 and H[L[i]]==1){
                H[L[i]]=0;
                S-=2;
            }
            else if(S<0 and H[L[i]]==0){
                H[L[i]]=1;
                S+=2;
            }

        cout<<K<<"\n";
        for(int i=0;i<N;i++)
            if(H[i])
                cout<<i+1<<" ";
        cout<<"\n";
        for(int i=0;i<N;i++)
            if(!H[i])
                cout<<i+1<<" ";
        cout<<"\n";

    }
        
}