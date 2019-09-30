#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

ll T;
ll N,M;
ll x,y;
ll A[100005];
ll DP[100005];
ll ans;
vector<pii> L;
vector<pair<ll,pii> > E;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(ll i=0;i<N;i++)
            cin>>A[i];
        for(ll i=0;i<N;i++)
            DP[i]=0;
        ans=0;
        E.clear();

        for(ll i=0;i<M;i++){
            cin>>x>>y;
            x--,y--;
            if(x==y or A[x]==A[y])
                continue;
            if(A[x]>A[y])
                swap(x,y);
            E.push_back({A[y]-A[x],{x,y}});
        }

        sort(E.begin(),E.end(),greater<pair<ll,pii> >());

        y=0;

        for(auto p:E){
            if(p.first!=y){
                for(auto u:L)
                    DP[u.first]=max(DP[u.first],u.second);
                L.clear();
            }
            y=p.first;
            L.push_back({p.second.first,DP[p.second.second]+1});
        }

        for(auto u:L)
            DP[u.first]=max(DP[u.first],u.second);
        L.clear();

        cout<<*max_element(DP,DP+N)+1<<"\n";

    }
}