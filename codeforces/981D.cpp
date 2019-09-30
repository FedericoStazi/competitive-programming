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
 
int N,M;
ll A[55];
ll P[55];
ll ans;
bool DP[55][55][55];
bool B[55][55][55];
 
ll S(int a, int b)
{
    return P[b+1]-P[a];
}
 
bool F(int a, int b, int k)
{
 
    bool res=false;
 
    if(b==N-1)
        return ((k==M-1) and ((S(a,b)&ans)==ans));
 
    if(!B[a][b][k])
    {
        B[a][b][k]=true;
 
        if(k>=M)
            return false;
 
        if((S(a,b)&ans)==ans)
            res=(res or F(b+1,b+1,k+1));
 
        res=(res or F(a,b+1,k));
 
        DP[a][b][k]=res;
    }
 
    return DP[a][b][k];
 
}
 
int main()
{
    cin>>N>>M;
    fori(0,N)
        cin>>A[i];
 
    fori(1,N+1)
        P[i]=P[i-1]+A[i-1];
 
    for(int x=62;x>=0;x--)
    {
        memset(B,false,sizeof(B));
 
        ans=ans|(1ll<<x);
 
        if(!F(0,0,0))
            ans=ans^(1ll<<x);
    }
 
    cout<<ans;
 
}