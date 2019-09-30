#include<bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pait<ll,ll>

using namespace std;

ll M;
int N,T;
const ll md=1000000007;
ll A,B,x;
ll F[100005];

int main()
{

    F[1]=1;
    F[2]=1;
    fori(3,100005)
        F[i]=(F[i-1]+F[i-2])%md;

    cin>>T;

    while(T--)
    {

        cin>>M>>N;
        A=0;
        B=0;

        fori(0,M)
        {
            cin>>x;
            A=(A+x)%md;
        }

        fori(0,M)
        {
            cin>>x;
            B=(B+x)%md;
        }

        x=0;
        x=(x+F[N-1]*B)%md;
        x=(x+F[N-2]*A)%md;
        x=(x*M)%md;

        if(N==1)
            cout<<(A*M)%md<<endl;
        else if(N==2)
            cout<<(B*M)%md<<endl;
        else
            cout<<x<<endl;

    }

}
