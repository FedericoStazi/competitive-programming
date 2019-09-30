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
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int N,M,x,y;
int ans,res;
vector<int> grafo[300005];
bool V[300005];
string S;
bool flag;
int DP[300005];
vector<int> T;
int X[300005];
 
void DFS(int k)
{
    for(int f:grafo[k])
    {
        if(X[f]==-1)
            flag=true;
        else if(X[f]==0)
        {
            X[f]=-1;
            DFS(f);
        }
    }
    X[k]=1;
}
 
void TS(int k)
{
    for(int f:grafo[k])
        if(!V[f])
        {
            V[f]=true;
            TS(f);
        }
    T.push_back(k);
 
}
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N>>M;
    cin>>S;
    fori(0,M)
    {
        cin>>x>>y;
        x--;
        y--;
        grafo[x].pb(y);
    }
 
    fori(0,N)
        if(X[i]==0)
        {
            X[i]=-1;
            DFS(i);
        }
 
    if(flag)
    {
        cout<<-1;
        return 0;
    }
 
    fori(0,N)
        if(!V[i])
        {
            V[i]=true;
            TS(i);
        }
 
    reverse(T.begin(),T.end());
 
    for(char c='a';c<='z';c++)
    {
        res=0;
        memset(DP,0,sizeof(DP));
        fori(0,N)
        {
            if(S[T[i]]==c)
                DP[T[i]]++;
            for(int f:grafo[T[i]])
                DP[f]=max(DP[f],DP[T[i]]);
            res=max(res,DP[T[i]]);
        }
        ans=max(ans,res);
    }
 
    cout<<ans;
 
}