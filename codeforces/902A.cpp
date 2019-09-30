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
 
vector<int> grafo[105];
int N,M,x,y;
bool V[105];
 
void DFS(int k)
{
 
    for(int f:grafo[k])
        if(!V[f])
        {
            V[f]=true;
            DFS(f);
        }
 
}
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N>>M;
    fori(0,N)
    {
        cin>>x>>y;
        forv(j,x,y+1)
        grafo[x].pb(j);
    }
 
    V[0]=true;
    DFS(0);
 
    if(V[M])
        cout<<"YES";
    else
        cout<<"NO";
 
}