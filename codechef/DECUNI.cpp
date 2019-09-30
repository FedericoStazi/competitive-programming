#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N,M,Q;
vector<int> grafo[1000005];
int D[1000005];
set<pair<int,int> > S;
queue<int> L;
bool V[1000005];
int x,y;

int main(){

    cin>>N>>M>>Q;

    while(M--){
        cin>>x>>y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }

    L.push(1);
    fill(D,D+N+3,1e9);
    D[1]=0;

    while(!L.empty()){
    
        x=L.front();
        L.pop();

        if(!V[x]){
            
            V[x]=true;

            for(int f:grafo[x])
                if(!V[f]){
                    D[f]=min(D[f],D[x]+1);
                    L.push(f);
                }
        }
    }

    for(int i=0;i<N;i++)
        S.insert(make_pair(D[i+1],grafo[i+1].size()));

    while(Q--){
        cin>>x>>y;
        if(S.count(make_pair(x,y)))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}