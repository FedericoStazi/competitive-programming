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
//ifstream in("savein.txt");
//ofstream out("saveout.txt");

int T,A;
long long A2,N;

int pot(int x, long long y)
{

    if(y==0)
        return 1;

    int p=pot(x,y/2);
    if(y%2==0)
        return (p*p)%9;
    if(y%2==1)
        return (p*p*x)%9;

}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>A2>>N;
        A=A2-((A2/9)*9);
        if(pot(A,N)==0)
            cout<<9<<endl;
        else
            cout<<pot(A,N)<<endl;
    }
}
