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
 
int A[1005];
int N;
int ans;
 
int main()
{
    cin>>N;
    fori(0,N)
        cin>>A[i];
    fori(1,N-1)
        if((A[i]>A[i-1] and A[i]>A[i+1])or(A[i]<A[i-1] and A[i]<A[i+1]))
            ans++;
    cout<<ans;
}