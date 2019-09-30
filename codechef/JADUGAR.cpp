#include <bits/stdc++.h>
#define fori(x,n) for(int i=x;i<n;i++)
#define forv(d,x,n) for(int d=x;d<n;d++)
#define mp make_pair
#define pb push_back
#define Fx first
#define Sx second
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
//#define cin in
//#define cout out

using namespace std;

ll N,A,B,K,P;
ll ans;
ll M=1e9+7;
ll x,c,r;
ll c1,c2;
ll F[10000015];
ll R[10000015];

ll pot(ll b, ll p)
{

    if(p==0)
        return 1;
    if(p==1)
        return b;
    ll g=pot(b,p/2);
    g=(g*g)%M;
    if(p%2==0)
        return g;
    return (g*b)%M;

}

int main()
{

    cin>>N>>K>>A>>B;
    N--;
    P=(K*B)%M;

    if(A==0)
    {
        ans=pot(P,N);

        for(ll i=N+2;i<2*N+1;i++)
            ans=(ans*i)%M;
        for(ll i=1;i<N+1;i++)
            ans=(ans*pot(i,M-2))%M;

        ans=(ans*K)%M;
        cout<<ans;

        return 0;
    }

    F[0]=1;
    for(ll i=1;i<N+7;i++)
        F[i]=(F[i-1]*i)%M;

    R[N+5]=N+5;
    for(ll i=N+4;i>0;i--)
        R[i]=(R[i+1]*i)%M;

    x=pot(A,N);
    c1=pot(A,M-2);
    c2=pot(F[N+5],M-2);
    c=(c1*c2)%M;

    for(ll i=0;i<N;i++)
    {
        ans=(ans+x)%M;
        x=(x*P)%M;
        x=(x*(N+i+1))%M;
        x=(x*(N-i))%M;
        r=(F[i]*R[i+3])%M;
        x=(x*r)%M;
        x=(x*c)%M;
    }

    ans=(ans+x)%M;

    ans=(ans*K)%M;

    cout<<ans;

}
