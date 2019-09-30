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
 
ll D[]={1,0,1,2,9};
ll N,K,ans,res;
 
int main()
{
 
    cin>>N>>K;
    while(K>=0)
    {
        res=1;
        for(ll i=N;i>N-K;i--)
            res*=i;
        for(ll i=2;i<=K;i++)
            res/=i;
        res*=D[K];
        ans+=res;
        K--;
    }
    cout<<ans;
}