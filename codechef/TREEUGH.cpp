#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N,Q,x,y;
ll A[1000005],P[1000005];
vector<ll> grafo[1000005];

void DFS(ll k, ll p, ll v){

    v+=P[k];
    A[k]+=v;

    for(ll f:grafo[k])
        if(f!=p)
            DFS(f,k,v);

}

int main(){

    cin>>N>>Q;

    for(ll i=0;i<N;i++)
        cin>>A[i];

    for(ll i=0;i<N-1;i++){
        cin>>x>>y;
        x--;
        y--;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }

    while(Q--){
        cin>>x>>y;
        x--;
        P[x]+=y;
    }

    DFS(0,-1,0);

    for(ll i=0;i<N;i++)
        cout<<A[i]<<" ";

}