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
 
int N;
 
int main()
{
 
    cin>>N;
 
    if(N%2==0)
    {
        if(N/2%2==1)
            cout<<N/2-2<<" "<<N/2+2;
        else
            cout<<N/2-1<<" "<<N/2+1;
    }
    else
        cout<<N/2<<" "<<N/2+1;
 
}