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
 
int N,M,A[40];
vector<int> V1,V2;
int ans,x;
 
int main()
{
 
    cin>>N>>M;
    fori(0,N)
        cin>>A[i];
 
    fori(0,1<<N/2)
    {
        x=0;
        for(int j=0,k=i;j<N/2;j++,k/=2)
            if(k%2)
                x=(x+A[j])%M;
        V1.pb(x%M);
    }
 
    fori(0,1<<(N+1)/2)
    {
        x=0;
        for(int j=0,k=i;j<(N+1)/2;j++,k/=2)
            if(k%2)
                x=(x+A[j+N/2])%M;
        V2.pb(x%M);
    }
 
    V1.pb(0);
    V2.pb(0);
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
 
    int j=V2.size()-1;
    fori(0,V1.size())
    {
        while(j>=0 and V2[j]+V1[i]>=M)
            j--;
        if(V1[i]+V2[j]<M)
            ans=max(ans,V1[i]+V2[j]);
    }
 
    j=V2.size()-1;
    fori(0,V1.size())
    {
        while(j>=0 and V2[j]+V1[i]>=2*M)
            j--;
        if(V1[i]+V2[j]<2*M)
            ans=max(ans,V1[i]+V2[j]-M);
    }
 
    cout<<ans;
 
}