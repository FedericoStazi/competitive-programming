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
 
int N,A[100005],m=2e9;
int p=-1e9;
int ans=1e9;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N;
 
    fori(0,N)
    {
        cin>>A[i];
        m=min(m,A[i]);
    }
 
    fori(0,N)
        if(A[i]==m)
        {
            ans=min(ans,i-p);
            p=i;
        }
 
    cout<<ans;
 
}