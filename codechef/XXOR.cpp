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
#define tt pair<pii,int>
//#define cin in
//#define cout out

using namespace std;

int N,Q,A[100005];
int S[32][100005];
int a,b;
int K,ans;

int main()
{

    cin>>N>>Q;
    fori(0,N)
        cin>>A[i];

    //cout<<A[0]<<" "<<(1<<j)<<" "<<(A[0] & (1<<j))<<endl;
    //cout<<endl;
    forv(j,0,31)
        if(A[0] & (1<<j))
            S[j][0]=1;


    fori(1,N)
        forv(j,0,31)
        {
            S[j][i]=S[j][i-1];
            if(A[i] & (1<<j))
                S[j][i]++;
        }
/*
    fori(0,N)
        {

            forv(j,0,31)
                cout<<S[j][i]<<" ";
            cout<<endl;
        }
*/

    while(Q--)
    {
        ans=0;
        cin>>a>>b;
        a--;
        b--;
        forv(j,0,31)
        {
            K=0;
            if(a)
                K=S[j][b]-S[j][a-1];
            else
                K=S[j][b];

            if(K<=(b-a)/2)
                ans+=(1<<j);
        }

        cout<<ans<<endl;

    }

}
