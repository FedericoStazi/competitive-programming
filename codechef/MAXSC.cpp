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

ll A[705][705];
ll T,N,K=2e9,ans,x;
bool flag;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;
        fori(0,N)
            forv(j,0,N)
                cin>>A[i][j];
        ans=0;
        K=2e9;
        fori(0,N)
            sort(A[i],A[i]+N,greater<int>());

        flag=true;
        for(int i=N-1;i>=0 and flag;i--)
        {
            x=-1;
            forv(j,0,N)
                if(A[i][j]<K and x==-1)
                    x=j;

            if(x==-1)
            {
                cout<<-1<<endl;
                flag=false;
            }
            else
            {
                ans+=A[i][x];
                K=A[i][x];
            }
        }

        if(flag)
            cout<<ans<<endl;

    }
}
