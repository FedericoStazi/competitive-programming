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

ll T,N,K,A[100005],DP[100005],L,R,x,C,S,ans,B=-1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        L=R=C=x=ans=0;
        B=-1e9;
        cin>>N>>K;
        fori(0,N)
            cin>>A[i];

        fori(0,N)
        {
            x+=A[i];
            L=max(L,x);
            B=max(B,A[i]);
        }

        S=x;
        x=0;

        for(int i=N-1;i>=0;i--)
        {
            x+=A[i];
            R=max(R,x);
        }

        DP[0]=A[0];
        fori(1,N)
            DP[i]=max(DP[i-1]+A[i],A[i]);

        fori(0,N)
            C=max(C,DP[i]);

        if(B<0)
            cout<<B<<endl;
        else if(K==1)
            cout<<C<<endl;
        else
            cout<<max(max(L+R,C),max(S*K,S*(K-2)+L+R))<<endl;

    }
}
