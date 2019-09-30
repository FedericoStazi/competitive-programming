#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll N,M;
vector<pll> V[2005];
bool B[2005][2005];
ll x,y;
int K;
int p;

bool comp(pll a, pll b){
    if(a.first%2)
        a.second=-a.second;
    if(b.first%2)
        b.second=-b.second;
    return a<b;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<2*M;i++){
        cin>>x>>y;
        B[x][y]=true;
    }

    for(int i=1;i<N+1;i++)
        for(int j=(i%2)?1:N;j<N+1 and j>0;j+=(i%2)?1:-1){
            bool flag=false;
            if(B[i][j] and !K){
                K=1;
                flag=true;
            }
            if(K)
                V[p].push_back({i,j});
            if(B[i][j] and K and !flag){
                K=0;
                p++;
            }
        }
    for(int i=0;i<M;i++){
        cout<<V[i].size()<<" ";
        for(pll p:V[i])
            cout<<p.first<<" "<<p.second<<" ";
        cout<<"\n";
    }
}
