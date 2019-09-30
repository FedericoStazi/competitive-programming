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
 
int N,M,K;
char c,C[2005][2005];
int ans,res;
 
int main()
{
 
    cin>>N>>M>>K;
    fori(0,N)
        forv(j,0,M)
            cin>>C[i][j];
 
    fori(0,N)
    {
        res=0;
        forv(j,0,M)
        {
            c=C[i][j];
            if(c=='.')
                res++;
            else
            {
                ans+=max(0,res-K+1);
                res=0;
            }
        }
        ans+=max(0,res-K+1);
    }
 
    fori(0,M)
    {
        res=0;
        forv(j,0,N)
        {
            c=C[j][i];
            if(c=='.')
                res++;
            else
            {
                ans+=max(0,res-K+1);
                res=0;
            }
        }
        ans+=max(0,res-K+1);
    }
 
    if(K==1)
        cout<<ans/2;
    else
        cout<<ans;
 
}