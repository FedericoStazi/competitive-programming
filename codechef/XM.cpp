#pragma GCC optimize("Ofast")
#include <iostream>
using namespace std;
typedef long long int ll;

ll T;
ll N,Q;
ll A[100005];
ll S[100][100005];
ll P[100][100005];
ll x,y;
ll G=30;

ll prv(ll x, ll s, ll a){
    ll k=x/s;
    if(s*k+a>x)
        k--;
    return min(N,s*k+a);
}

ll sm(ll a, ll b, ll g, ll s){
    if(b<=a+s)
        return P[g][a]-P[g][b];
    else
        return sm(a,a+s,g,s) + (b-a-s)*s-(P[g][a+s]-P[g][b]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T--){
        cin>>N>>Q;
        for(int i=0;i<N;i++)
            cin>>A[i];

        A[N]=0;
        for(ll g=0,s=1;g<G;g++,s*=2)
            S[g][N]=P[g][N]=0;      

        for(ll g=0,s=1;g<G;g++,s*=2)
            for(int i=N-1;i>=0;i--)
                P[g][i]=(A[i]&s)+P[g][i+1];

        for(ll g=0,s=1;g<G;g++,s*=2){
            x=0;
            for(int i=N-1;i>=0;i--){
                x+=(A[i]&s)-(A[min(N,i+s)]&s);
                S[g][i]=x+max(0ll,N-i-s)*s-(S[g][min(N,i+s)]);
            }
        }

        while(Q--){
            cin>>x>>y;
            x--,y--;
            ll ans=0;
            for(ll g=0,s=1;g<G;g++,s*=2)
                ans+=S[g][x]-S[g][prv(y+1,s*2,x%(2*s))]+sm(prv(y+1,s*2,x%(2*s
                    )),y+1,g,s);
            cout<<ans<<"\n";
        }

    }
}