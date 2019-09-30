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
 
vector<int> grafo[10005];
int N,x,ans;
int C[10005];
 
void DFS(int k,int p,int c)
{
 
    if(c!=C[k])
    {
        ans++;
        c=C[k];
    }
 
    for(int f:grafo[k])
        if(f!=p)
            DFS(f,k,c);
}
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N;
    fori(2,N+1)
    {
        cin>>x;
        grafo[i].pb(x);
        grafo[x].pb(i);
    }
    fori(0,N)
        cin>>C[i+1];
 
    DFS(1,-1,0);
 
    cout<<ans;
 
}