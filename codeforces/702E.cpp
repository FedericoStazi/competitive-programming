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
 
ll F[100005],W[100005],S[100005][40],M[100005][40],P[100005][40];
ll N,K;
ll p,s,m;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N>>K;
 
    fori(0,N)
        cin>>F[i];
    fori(0,N)
        cin>>W[i];
 
    fori(0,N)
        P[i][0]=F[i];
 
    for(int j=1;j<40;j++)
        fori(0,N)
            P[i][j]=P[P[i][j-1]][j-1];
 
    fori(0,N)
        M[i][0]=S[i][0]=W[i];
 
    for(int j=1;j<40;j++)
    {
        fori(0,N)
            M[i][j]=min(M[i][j-1],M[P[i][j-1]][j-1]);
        fori(0,N)
            S[i][j]=S[i][j-1]+S[P[i][j-1]][j-1];
    }
 
    fori(0,N)
    {
        p=i;
        s=0;
        m=1e9;
        for(ll k=K,j=0;k>0;k/=2,j++)
            if(k%2==1)
            {
                s+=S[p][j];
                m=min(m,M[p][j]);
                p=P[p][j];
            }
        cout<<s<<" "<<m<<endl;
    }
 
}