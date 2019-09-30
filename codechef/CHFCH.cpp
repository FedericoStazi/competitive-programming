#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

ll INF=1e18;
int T;
ll N,K;
ll ans;
vector<ll> V[300005];
vector<ll> R[300005];
ll A[300005];

ll s(ll x){
    return (x*(x+1))/2;
}

ll w(ll a, ll b){
    if(b==-1)
        return 0;
    else
        return R[a][b];
    ll c=0;
    for(int i=0;i<=b;i++)
        c+=V[a][i];
    return c;
}

int main(){
    cin>>T;
    while(T--){
        cin>>N>>K;
        ans=INF;
        for(ll i=0;i<N;i++){
            cin>>A[i];
            V[A[i]].clear();
            R[A[i]].clear();
        }

        for(ll i=0;i<N;i++){
            V[A[i]].push_back(i);
            R[A[i]].push_back(i);
            if(R[A[i]].size()!=1)
                R[A[i]][R[A[i]].size()-1]+=R[A[i]][R[A[i]].size()-2];
            if(V[A[i]].size()>=K){
                ll med=V[A[i]].size()-1-K/2;
                ll res=0;
                ll x=med-(K+1)/2;
                ll y=med+K/2;
                res=w(A[i],y)-2*w(A[i],med)+w(A[i],x)+V[A[i]][med];
                res-=s((K+1)/2-1)+s((K+2)/2-1);
                if(K%2==0)
                    res-=V[A[i]][med];
                ans=min(ans,res);
            }
        }

        cout<<((ans==INF)?-1:ans)<<"\n";

    }
}