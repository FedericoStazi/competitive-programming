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

int N;
vector<pii> S;
int x,y,ans;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    fori(0,N)
    {
        cin>>x>>y;
        S.pb(mp(y,x));
    }

    V.pb(0);
    V.pb(100000);

    sort(S.begin(),S.end(),greater<pii>());

    for(int h=1;h<=500;h++)
    {
        while(!S.empty() and S.back().Fx==h-1)
        {
            V.pb(S.back().Sx);
            S.pop_back();
        }

        sort(V.begin(),V.end());

        fori(1,V.size())
            ans=max(ans,h*(V[i]-V[i-1]));
    }
    cout<<ans;
}
