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
 
int N,S;
vector<int> V;
int h,m,ans;
 
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>S;
    V.pb(-S-1);
    fori(0,N)
    {
        cin>>h>>m;
        V.pb(h*60+m);
    }
    V.pb(1e9);
 
    fori(0,N+1)
        if(V[i+1]-V[i]>2*S+1)
        {
            if(i==0)
                cout<<"0 0";
            else
            {
                ans=V[i]+S+1;
                cout<<ans/60<<" "<<ans%60;
            }
            return 0;
        }
 
}