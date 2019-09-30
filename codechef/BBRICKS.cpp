#include <iostream>
#include <assert.h>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;
int T;
ll N,K;
ll ans,res;

ll pot(ll a, ll b){

    assert(a>=0);

    if(b==0)
        return 1;

    ll x=pot(a,b/2);
    x=(x*x)%mod;

    if(b%2)
        x=(x*a)%mod;

    return x;

}

ll coeff_bin(ll a, ll b){

    ll res=1;
    for(ll i=a-b+1;i<=a;i++)
        res=(res*i)%mod;
    for(ll i=1;i<=b;i++)
        res=(res*pot(i,mod-2))%mod;
    return res;

}

int main(){

    cin>>T;

    while(T--){

        cin>>N>>K;
        ans=0;

        res=(N-K+1)*2;
        ans=res;

        for(ll X=2;X-1<=K and X<=N-K+1;X++){
            ll p=1;
            p=(p*(K-X+1))%mod;
            p=(p*pot(X,mod-2))%mod;
            p=(p*(N-K-X+2))%mod;
            p=(p*pot(X-1,mod-2))%mod;
            p=(p*2)%mod;
            res=(res*p)%mod;
            ans=(ans+res)%mod;
        }
/*
        if(K==1)
            ans=2*N;
        if(K==N)
            ans=2;
            */
        if(K>N)
            ans=0;

        cout<<ans<<"\n";

    }

}