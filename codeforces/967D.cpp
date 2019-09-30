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
//#define cin in
//#define cout out
 
using namespace std;
 
ll N,S1,S2;
vector<pll> V;
ll x,G,K;
ll DP[300005];
 
int main()
{
    cin>>N>>S1>>S2;
    fori(0,N)
    {
        cin>>x;
        V.pb(mp(x,i));
    }
    sort(V.begin(),V.end(),greater<pll>());
 
    G=-1;
    fori(0,N)
    {
        K=(ll)ceil((ld)S1/(ld)V[i].Fx);
        if(i-K>=0)
            if(DP[i-K]!=-1)
            {
                cout<<"Yes\n";
 
                cout<<K<<" "<<i-K+1<<endl;
 
                forv(j,i-K+1,i+1)
                    cout<<V[j].Sx+1<<" ";
                cout<<endl;
 
                forv(j,0,i-K+1)
                    cout<<V[j].Sx+1<<" ";
 
                return 0;
            }
 
        if(G==-1)
            if(V[i].Fx*(i+1)>=S2)
                G=i;
        DP[i]=G;
    }
 
    fill(DP,DP+N,0);
    G=-1;
    fori(0,N)
    {
        K=(ll)ceil((ld)S2/(ld)V[i].Fx);
        if(i-K>=0)
            if(DP[i-K]!=-1)
            {
                cout<<"Yes\n";
 
                cout<<i-K+1<<" "<<K<<endl;
 
                forv(j,0,i-K+1)
                    cout<<V[j].Sx+1<<" ";
                cout<<endl;
 
                forv(j,i-K+1,i+1)
                    cout<<V[j].Sx+1<<" ";
 
                return 0;
            }
 
        if(G==-1)
            if(V[i].Fx*(i+1)>=S1)
                G=i;
        DP[i]=G;
    }
 
    cout<<"No";
 
}