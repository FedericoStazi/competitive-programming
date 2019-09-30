#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
    
int N,M;
int x,y;
int D[1000005];
vector<int> grafo[1000005];
priority_queue<pii> Q;
vector<pii> S;

int main(){

    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>x>>y;
        x--,y--;
        grafo[y].push_back(x);
        D[x]++;
    }

    for(int i=0;i<N;i++)
        if(!D[i])
            Q.push({-grafo[i].size(),i});

    while(!Q.empty()){

        x=Q.top().second;
        Q.pop();
        if(Q.empty())
            y=-1;
        else{
            y=Q.top().second;
            Q.pop();
        }

        for(int f:grafo[x])
            if(!(--D[f]))
                Q.push({-grafo[f].size(),f});

        if(y!=-1)
            for(int f:grafo[y])
                if(!(--D[f]))
                    Q.push({-grafo[f].size(),f});

        S.push_back({x,y});

    }

    cout<<S.size()<<endl;
    for(pii p:S)
        if(p.second==-1)
            cout<<"1 "<<p.first+1<<endl;
        else
            cout<<"2 "<<p.first+1<<" "<<p.second+1<<endl;

}
