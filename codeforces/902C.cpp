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
 
int H,A[100005];
bool flag;
int isA=-1,p,s;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>H;
    fori(0,H+1)
        cin>>A[i];
 
    fori(1,H+1)
    {
        if(flag and A[i]!=1)
            isA=i;
        if(A[i]!=1)
            flag=true;
        if(A[i]==1)
            flag=false;
    }
 
    if(isA==-1)
    {
        cout<<"perfect";
        return 0;
    }
 
    cout<<"ambiguous\n";
    fori(0,H+1)
    {
        p=s;
        s+=A[i];
        if(isA==i)
        {
            cout<<p-1<<" ";
            forv(j,1,A[i])
                cout<<p<<" ";
        }
        else
            forv(j,0,A[i])
                cout<<p<<" ";
    }
 
    p=0;
    s=0;
    cout<<endl;
 
    fori(0,H+1)
    {
        p=s;
        s+=A[i];
        forv(j,0,A[i])
            cout<<p<<" ";
    }
 
}