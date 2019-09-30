#include <bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define Fx first
#define Sx second
#define ll long long int
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
 
using namespace std;
 
int N,A[100005],B[100005],x,ans;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N;
    fori(0,N)
        cin>>A[i];
 
    sort(A,A+N);
 
    fori(0,N)
        A[i]+=1e9;
    fori(0,N-1)
        B[i]=A[i+1]-A[i];
 
    x=B[0];
    fori(1,N-1)
        x=__gcd(x,B[i]);
 
    fori(0,N-1)
        ans+=B[i]/x-1;
 
    cout<<ans;
 
}