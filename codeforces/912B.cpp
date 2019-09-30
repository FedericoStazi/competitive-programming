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
 
ll N,K;
 
int main()
{
    cin>>N>>K;
    if(K==1)
        cout<<N;
    else
    {
        ll x;
        for(x=1;x<=N;x*=2);
        cout<<x-1;
    }
}