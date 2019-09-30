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

ll T;
ll N,K;
ll A[100005],D[100005],B[100005];
ll M[1000005];
ll mi,ma,x;
ll ans;
ll C,S;

int main()
{

    cin>>T;
    while(T--)
    {

        cin>>N>>K;

        fori(0,N)
            cin>>A[i];
        fori(0,N)
            cin>>D[i];
        fori(0,K)
            cin>>B[i];

        C=0;
        fori(0,N)
            C+=D[i];

        fori(0,1e6+3)
            M[i]=0;

        fori(0,N)
            M[A[i]]+=D[i];

        mi=0;
        ma=1e6+3;
        ans=0;

        fori(0,K)
        {
            //cout<<i<<" "<<ma<<" "<<mi<<endl;

            S=C-B[i];
            if(i%2==0)
            {
                while(S)
                {
                    x=min(S,M[mi]);
                    S-=x;
                    M[mi]-=x;
                    if(M[mi]==0)
                        mi++;
                }
            }
            else
            {
                while(S)
                {
                    x=min(S,M[ma]);
                    S-=x;
                    M[ma]-=x;
                    if(M[ma]==0)
                        ma--;
                }
            }
            C=B[i];
        }

        fori(0,1e6+3)
            ans+=M[i]*i;
        cout<<ans<<endl;

    }

}
