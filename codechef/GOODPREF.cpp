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

int N;
int T;
string S;
ll a,b,K;
ll ans;
ll p,q;

int d(int x,int y)
{

    float m=x;
    float n=y;
    float res=m/n;
    res=-res;
    return floor(res);

/*
    int res=0;
    x=abs(x);
    y=abs(y);
    for(int i=y;i<=x;i+=y)
        res++;

    return res;
*/
}

int main()
{

    cin>>T;
    while(T--)
    {
        cin>>S;
        cin>>N;

        ans=0;
        K=0;
        a=0;
        b=0;

        for(char c:S)
            if(c=='a')
                K++;

        for(char c:S)
        {
            if(c=='a')
                a++;
            else
                b++;

            p=a-b;
            q=2*K-S.size();

            if(p>0 and q>=0)
                ans+=N;
            if(p>0 and q<0)
                ans+=min(N,d(p-1,q)+1);
            if(p<=0 and q>0)
                ans+=N-min(N,d(p,q)+1);

            //cout<<p<<" "<<q<<" "<<ans<<endl;

        }
        cout<<ans<<endl;

    }

}
/*
7
aba 2
baa 3
bba 3
aaaab 10
abbbb 3
abbaaaa 2
abbaaaa 1
*/

//5 6 0 50 1 11 4
