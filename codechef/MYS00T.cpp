#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
typedef pair<int,int> pii;

int T;
int N,M;
int x,y;
bool V[1000006];
int DP[1000006];
vector<pii> grafo[1000006];
int q,a;

int F(int a, int b, int c){

    if(DP[c]!=-1)
        return DP[c];

    DP[c]=1;
    for(pii f:grafo[b])
        if(f.first!=a)
            if(V[f.first])
                DP[c]+=F(b,f.first,f.second);
    return DP[c];

}

int find_centroid(int a, bool r=false){

    if(r)
        for(int i=0;i<2*N+1;i++)
            DP[i]=-1;

    F(-1,a,0);
    int K=DP[0];

    for(pii f:grafo[a])
        if(V[f.first])
            if(F(a,f.first,f.second)>K/2)
                return find_centroid(f.first);

    return a;

}

int main(){

    cin>>T;

    while(T--){

        cin>>N;

        for(int i=0;i<N+1;i++){
            V[i]=true;
            grafo[i].clear();
        }

        int c=1;
        for(int i=0;i<N-1;i++){
            cin>>x>>y;
            grafo[x].push_back({y,c++});
            grafo[y].push_back({x,c++});
        }

        q=1;
        for(;;){
            q=find_centroid(q,true);
            V[q]=false;
            cout<<"1 "<<q<<endl;
            cin>>a;
            if(a==-1){
                cout<<"2 "<<q<<endl;
                break;
            }
            q=a;
        }
        cin>>q;
        assert(q==1);

    }
}