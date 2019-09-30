#include<bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define pb push_back
#define mp make_pair
#define Fx first
#define Sx second
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
ll N,M,ans;
map<ll,pll> S;
ll x,y;
 
int main()
{
 
    cin>>N;
    fori(0,N)
    {
        cin>>x>>y;
        S[x].Fx=y;
    }
 
    cin>>N;
    fori(0,N)
    {
        cin>>x>>y;
        S[x].Sx=y;
    }
 
    for(auto p=S.begin();p!=S.end();p++)
        ans+=max(p->Sx.Fx,p->Sx.Sx);
 
    cout<<ans;
 
}