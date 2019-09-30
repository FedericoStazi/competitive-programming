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

int N,X,K;
vector<int> P[105];
int DP[105][105][105];
int ans;

int main()
{

    cin>>N>>X>>K;

    fori(1,101)
        forv(j,1,101)
            if(__gcd(i,j)==1)
                P[i].pb(j);

    DP[0][1][0]=1;

    fori(0,N)
    {
        forv(j,0,101)
            forv(k,0,K+1)
                for(int a:P[j])
                    if(a==X)
                        DP[i+1][a][k+1]=(DP[i+1][a][k+1]+DP[i][j][k])%(int)(1e9
                            +7);
                    else
                        DP[i+1][a][k]=(DP[i+1][a][k]+DP[i][j][k])%(int)(1e9+7);
    }

    fori(0,101)
        ans=(ans+DP[N][i][K])%(int)(1e9+7);

    cout<<ans;

}
