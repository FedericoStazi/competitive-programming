#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

ll T;
ll N,Q;
ll x,y;
ll V[200005];
ll P1[200005];
ll P2[200005];
vector<pii> S;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>Q;
        S.clear();
        for(ll i=0;i<N;i++){
            cin>>V[i];
            S.push_back({V[i],i});
        }
        sort(S.begin(),S.end());
        for(ll i=0;i<N;i++){
            x=S[i].second;
            if(i)
                y=S[i-1].second;
            if(i and V[x]==V[y])
                P1[x]=P1[y];
            else P1[x]=i;
        }
        for(ll i=N-1;i>=0;i--){
            x=S[i].second;
            if(i!=N-1)
                y=S[i+1].second;
            if(i!=N-1 and V[x]==V[y])
                P2[x]=P2[y];
            else P2[x]=i;
        }

        while(Q--){
            cin>>x>>y;
            x--,y--;
            cout<<y-x+abs(V[x]-V[y])<<" "<<max(P2[x],P2[y])-min(P1[x],P1[y])+1
                <<"\n";
        }
    }
}