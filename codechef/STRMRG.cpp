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

int T,N,M;
string A,B;
int DP[5005][5005][2];

int F(char a, char b)
{
    if(a!=b)
        return 1;
    else
        return 0;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        cin>>A>>B;

        DP[0][0][0]=0;
        DP[0][0][1]=0;

        fori(1,N+1)
            DP[0][i][0]=1e9;
        fori(1,M+1)
            DP[i][0][1]=1e9;


        fori(0,N+1)
            forv(j,0,M+1)
            {
                if(i)
                    DP[i][j][0]=min(DP[i-1][j][0]+F(A[i-1],A[i-2]),DP[i-1][j][1]
                        +F(A[i-1],B[j-1]));
                if(j)
                    DP[i][j][1]=min(DP[i][j-1][0]+F(A[i-1],B[j-1]),DP[i][j-1][1]
                        +F(B[j-1],B[j-2]));
            }
/*
        fori(0,N+1)
        {
            forv(j,0,M+1)
                cout<<DP[i][j][0]<<","<<DP[i][j][1]<<" ";
            cout<<endl;
        }
*/
        cout<<min(DP[N][M][0],DP[N][M][1])<<endl;
    }
}
