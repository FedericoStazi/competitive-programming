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
 
int A[3];
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>A[0]>>A[1]>>A[2];
 
    sort(A,A+3);
 
    if(A[0]==1 or (A[1]==2 and A[0]==2) or (A[0]==3 and A[1]==3 and A[2]==3) or (A[0]==2 and A[1]==4 and A[2]==4))
        cout<<"YES";
    else
        cout<<"NO";
 
}