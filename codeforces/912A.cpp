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
 
ll A,B,X,Y,Z;
 
int main()
{
    ios::sync_with_stdio(false);
    cin>>A>>B>>X>>Y>>Z;
    A-=2*X;
    A-=Y;
    B-=Y;
    B-=3*Z;
    if(A>0)
        A=0;
    if(B>0)
        B=0;
    cout<<-(A+B);
}