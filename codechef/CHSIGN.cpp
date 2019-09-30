#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define pb push_back
#define mp make_pair
#define Fx first
#define Sx second
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

bool B[100005];
ll A[100005];
ll S[100005];
ll N,T;
pll p,q,x;

int main()
{

    ios::sync_with_stdio(false);

    cin>>T;
    while(T--)
    {

        cin>>N;
        fori(0,N)
            cin>>A[i];

        fori(0,N)
        {
            B[i]=false;
            S[i]=-1;
        }


        if(A[0]<A[1])
            B[0]=true;
        if(A[N-1]<A[N-2])
            B[N-1]=true;

        fori(1,N-1)
            if(A[i]<A[i-1] and A[i]<A[i+1])
                B[i]=true;


        p=q=x=mp(0,-1);

        if(B[0])
            p=mp(A[0],0);
        if(B[1])
            p=mp(A[1],1);

        fori(2,N)
            if(B[i])
            {
                if(!B[i-2])
                {
                    x=mp(max(p,q).Fx+A[i],i);
                    S[i]=max(p,q).Sx;
                }
                else
                {
                    if(A[i]+A[i-2]<A[i-1])
                    {
                        x=mp(max(p,q).Fx+A[i],i);
                        S[i]=max(p,q).Sx;
                    }
                    else
                    {
                        x=mp(q.Fx+A[i],i);
                        S[i]=q.Sx;
                    }
                }

                q=max(p,q);
                p=x;
                x=mp(0,-1);
            }

            ll a=max(p,q).Sx;

            while(a!=-1)
            {
                A[a]=-A[a];
                a=S[a];
            }

            fori(0,N)
                cout<<A[i]<<" ";
            cout<<endl;


    }
}
