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
#define ld long double
//#define cin in
//#define cout out

using namespace std;

int N,M,K;
ll A[1000006];
ll P[1000006];
ll S[1000006];
ll D[1000006];
ll ans,res,best;

void s()
{
    fori(0,N)
        cout<<A[i]+D[i]<<" ";
    cout<<"\nans="<<ans<<endl;
}

int main()
{
    srand(time(0));

    cin>>N>>M>>K;
    fori(0,N)
        cin>>A[i];
    fori(0,M)
        cin>>P[i];

    forv(t,0,75)
    {
        if(t)
            fori(0,N)
                D[i]=rand()%K;

        ans=0;

        fori(0,M)
        {
            res=1;
            forv(j,0,N)
                res=(res*(A[j]+D[j]))%P[i];
            ans+=res;
        }

        if(best<ans)
        {
            best=ans;
            fori(0,N)
                S[i]=A[i]+D[i];
        }

    }

    fori(0,N)
        cout<<S[i]<<" ";
    //cout<<"\nbest="<<best;
}
