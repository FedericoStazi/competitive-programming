#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll,ll> pll;

ll T;
ll M,L;
vector<ll> V;
vector<ll> P;
vector<pll> G;
bool B[10000005];

void F(ll x, ll k){
    if(k==G.size())
        V.push_back(x);
    else
        for(ll i=0,s=1;i<2*G[k].second+1 and s<M+1;i++,s*=G[k].first)
            if(x*s<M+1)
                F(x*s,k+1);
            else
                return;
}

int main(){

    ll K=1e7+1;
    for(ll i=2;i<K;i++)
        if(!B[i]){
            P.push_back(i);
            for(ll s=i*i;s<K;s+=i)
                B[s]=true;
        }

    cin>>T;
    while(T--){

        cin>>M;
        L=M;
        G.clear();
        V.clear();

        for(ll p:P)
            if(M%p==0){
                G.push_back({p,0});
                while(M%p==0){
                    M/=p;
                    G.back().second++;
                }
            }
        if(M!=1)
            G.push_back({M,1});
        M=L;
        
        F(1,0);

        sort(V.begin(),V.end());
        cout<<V.size()<<"\n";
        for(ll x:V)
            cout<<M+x<<"\n";

    }

}