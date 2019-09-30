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

ll T,N,A[100005],S[100005];
ll ans[100005];
int l,r,m;

ll F(int x, int y)
{
/*
    ll k=0;
    fori(x,y+1)
        k+=A[i];
    return k;
*/

    if(x)
        return S[y]-S[x-1];
    else
        return S[y];

}

int main()
{

    cin>>T;
    while(T--)
    {
        cin>>N;

        fori(0,N)
            ans[i]=0;

        fori(0,N)
        {
            cin>>A[i];
            if(i)
                S[i]=S[i-1]+A[i];
            else
                S[i]=A[i];
        }

        fori(0,N)
        {
            l=0;
            r=i;
            while(l<r)
            {
                m=(l+r)/2;
                if(F(m,i-1)<=A[i])
                    r=m;
                else
                    l=m+1;
            }
            //cout<<i<<" "<<l<<endl;
            forv(j,l-1,i)
                if(j>=0)
                    ans[j]++;
        }


        reverse(A,A+N);

        fori(0,N)
        {
            if(i)
                S[i]=S[i-1]+A[i];
            else
                S[i]=A[i];
        }

        fori(0,N)
        {
            l=0;
            r=i;
            while(l<r)
            {
                m=(l+r)/2;
                if(F(m,i-1)<=A[i])
                    r=m;
                else
                    l=m+1;
            }
            //cout<<i<<" "<<l<<endl;
            forv(j,l-1,i)
                if(j>=0)
                    ans[N-j-1]++;
        }

        fori(0,N)
            cout<<ans[i]<<" ";
        cout<<endl;

    }

}
