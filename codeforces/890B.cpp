#include <bits/stdc++.h>
#define fori(x,n) for(int i=x;i<n;i++)
#define forv(d,x,n) for(int d=x;d<n;d++)
#define mp make_pair
#define pb push_back
#define Fx first
#define Sx second
#define pii pair<int,int>
#define ll long long
 
using namespace std;
 
bool V[200005];
int L[200005];
vector<int> S;
int N,x;
 
int main()
{
 
    ios::sync_with_stdio(false);
    cin>>N;
    fori(0,N)
    {
        cin>>x;
        if(!V[x])
        {
            V[x]=true;
            S.pb(x);
        }
        L[x]=i;
    }
 
    int best=1e9;
    int ans=0;
    for(int i:S)
    {
        if(best>L[i])
        {
            best=L[i];
            ans=i;
        }
    }
    cout<<ans;
}