#include <bits/stdc++.h>
#define fori(x,n) for(int i=x;i<n;i++)
#define forv(d,x,n) for(int d=x;d<n;d++)
#define mp make_pair
#define pb push_back
#define Fx first
#define Sx second
#define pii pair<int,int>
#define ll long long
 
using namespace std;
 
int A[200005];
int N;
bool V[200005];
int ans,pos;
bool flag;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N;
    fori(0,N)
        cin>>A[i+1];
 
    for(int i=N;i>=0;i--)
    {
        pos=i;
        flag=false;
        while(!V[pos])
        {
            flag=true;
            V[pos]=true;
            pos=A[pos];
        }
        if(flag)
            ans++;
    }
    cout<<ans;
}