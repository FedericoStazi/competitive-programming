#include <bits/stdc++.h>
#define fori(x,n) for(int i=x;i<n;i++)
#define forv(d,x,n) for(int d=x;d<n;d++)
#define mp make_pair
#define pb push_back
 
using namespace std;
 
ifstream in("input.txt");
ofstream out("output.txt");
//ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef long long int ll;
 
ll a,b,c;
const ll M=998244353;
const int Max=5005;
 
ll PBC[Max][Max];
 
ll BC(int x, int y)
{
    return PBC[x][y];
    if(x==0 or y==0)
    {
        PBC[x][y]=1;
        return 1;
    }
    PBC[x][y]=(((PBC[x-1][y])?PBC[x-1][y]:BC(x-1,y))+((PBC[x][y-1])?PBC[x][y-1]:BC(x,y-1)))%M;
    return PBC[x][y];
 
}
 
ll F(int x, int y)
{
 
    ll ans=1;
    for(ll i=x;i>y;i--)
        ans=(ans*i)%M;
    return ans;
 
}
 
int main()
{
 
    cin>>a>>b>>c;
 
    for(int i=0;i<Max;i++)
        for(int j=0;j<=i;j++)
            PBC[i][j]=(i==j or i==0)?1:(PBC[i-1][j-1]+PBC[i-1][j])%M;
    //cout<<BC(1,0)<<" "<<F(2,2)<<" "<<BC(1,1)<<" "<<F(2,1)<<endl;
 
    ll ans=0;
    ll tot=1;
    for(ll i=0;i<=min(a,b);i++)
        ans=(ans+((BC(min(a,b),i))%M)*(F(max(a,b),max(a,b)-i))%M)%M;
    tot=(tot*ans)%M;
    //for(ll i=0;i<=min(a,b);i++)
      //  cout<<ans<<" "<<tot<<" "<<BC(min(a,b),i)<<" "<<F(max(a,b),max(a,b)-i)<<endl;
    //cout<<ans<<" "<<tot<<endl;
    swap(a,c);
    ans=0;
    for(ll i=0;i<=min(a,b);i++)
        ans=(ans+((BC(min(a,b),i))%M)*(F(max(a,b),max(a,b)-i))%M)%M;
    tot=(tot*ans)%M;
    //cout<<ans<<" "<<tot<<endl;
    swap(b,c);
    ans=0;
    for(ll i=0;i<=min(a,b);i++)
        ans=(ans+((BC(min(a,b),i))%M)*(F(max(a,b),max(a,b)-i))%M)%M;
    tot=(tot*ans)%M;
    //cout<<ans<<" "<<tot<<endl;
 
    cout<<tot;
 
}