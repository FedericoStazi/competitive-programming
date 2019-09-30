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
 
int N,P,L,R;
int main()
{
 
    cin>>N>>P>>L>>R;
    if(L!=1 and R!=N)
        cout<<min(abs(P-L)+1+R-L+1,abs(P-R)+1+R-L+1);
    else if(L!=1)
        cout<<abs(P-L)+1;
    else if(R!=N)
        cout<<abs(P-R)+1;
    else
        cout<<0;
}