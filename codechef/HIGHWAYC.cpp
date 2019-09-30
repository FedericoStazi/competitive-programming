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

int T;
int N;
ld S,Y;
ld V[15],D[15],P[15],C[15];
ld A[15],B[15];
ld DP[15];
ld ans,t;
ld INF=1e18;
bool flag;
ld K=1;
string str;
float e=1e-6;

void s()
{
    cout<<"***********************************\n";
        fori(0,N)
        {
            cout<<"i="<<i<<endl;
            cout<<A[i]<<" "<<B[i]<<endl;
        }

        cout<<"DP:\n";

        fori(0,N)
            cout<<DP[i]<<" ";
        cout<<endl;

        cout<<"ans="<<ans<<endl;
}

int main()
{

    cin>>T;
    while(T--)
    {
        cin>>N>>S>>Y;
        fori(0,N)
            cin>>V[i];
        fori(0,N)
            cin>>D[i];
        fori(0,N)
            cin>>P[i];
        fori(0,N)
            cin>>C[i];

        Y*=K;
        fori(0,N)
            P[i]*=K;
        fori(0,N)
            C[i]*=K;

        fori(0,N)
            if(D[i]==1)
            {
                A[i]=-P[i]/V[i]-e;
                B[i]=(C[i]-P[i])/V[i]+e;
            }
            else
            {
                A[i]=P[i]/V[i]-e;
                B[i]=(P[i]+C[i])/V[i]+e;
            }

        fori(0,N)
            DP[i]=INF;

        for(int i=N-1;i>=0;i--)
        {
            t=0;
            flag=true;
            for(int j=i+1;j<=N and flag;j++)
            {
                t+=Y/S;
                if(j==N)
                    DP[i]=min(DP[i],t);
                else
                {
                    if(B[i]+t<B[j])
                        DP[i]=min(DP[i],B[j]-B[i]+DP[j]);
                    if(!(B[i]+t+Y/S<A[j] or B[i]+t>=B[j]))
                        flag=false;
                }
            }
        }

        t=0;
        ans=INF;
        flag=true;
        for(int j=0;j<=N and flag;j++)
        {
            if(j==N)
                ans=min(ans,t);
            else
            {
                if(t<B[j])
                    ans=min(ans,B[j]+DP[j]);
                if(!(t+Y/S<A[j] or t>=B[j]))
                    flag=false;
            }
            t+=Y/S;
        }

        //s();
        /*
        str=to_string(ans);
        fori(0,str.size()-6)
            cout<<str[i];
        cout<<'.';
        fori(str.size()-6,str.size())
            cout<<str[i];
        cout<<'\n';*/
        cout<<ans<<'\n';
    }
}
