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

int A,B,C,D,T;

int main()
{

    cin>>T;
    while(T--)
    {
        cin>>A>>B>>C>>D;

        if((A==B and C==D) or (A==C and B==D) or (A==D and B==C))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}
