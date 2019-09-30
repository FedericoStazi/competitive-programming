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

int T,N,M;
char A[1005][1005],B[2][1005][1005];
char c='R';
int a,b;

int main()
{

    cin>>T;

    fori(0,200)
    {
        forv(j,0,i+1)
            B[0][i-j][j]=c;

        if(c=='R')
            c='G';
        else
            c='R';

        forv(j,0,i+1)
            B[1][i-j][j]=c;
    }

    while(T--)
    {
        cin>>N>>M;
        fori(0,N)
            forv(j,0,M)
                cin>>A[i][j];

        a=b=0;

        fori(0,N)
            forv(j,0,M)
            {
                if(B[0][i][j]=='R' and A[i][j]=='G')
                    a+=3;
                if(B[0][i][j]=='G' and A[i][j]=='R')
                    a+=5;
            }

        fori(0,N)
            forv(j,0,M)
            {
                if(B[1][i][j]=='R' and A[i][j]=='G')
                    b+=3;
                if(B[1][i][j]=='G' and A[i][j]=='R')
                    b+=5;
            }

        cout<<min(a,b)<<endl;

    }

}
