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
 
int N;
int D[100005];
int x,y,c,K=-1;
vector<int> grafo[100005];
 
int DFS(int k,int p)
{
    for(int f:grafo[k])
        if(f!=p)
            return DFS(f,k);
    return k;
}
 
int main()
{
    cin>>N;
    fori(0,N-1)
    {
        cin>>x>>y;
        x--;
        y--;
        grafo[x].pb(y);
        grafo[y].pb(x);
        D[x]++;
        D[y]++;
    }
 
    fori(0,N)
        if(D[i]>2)
        {
            c++;
            K=i;
        }
    if(c>1)
        cout<<"No";
    else
    {
        cout<<"Yes\n";
        if(K==-1)
        {
            cout<<"1\n";
            fori(0,N)
                if(D[i]==1)
                    cout<<i+1<<" ";
        }
        else
        {
            cout<<D[K]<<"\n";
            for(int f:grafo[K])
                cout<<K+1<<" "<<DFS(f,K)+1<<'\n';
        }
    }
 
}
 
 