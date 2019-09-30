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
 
int N,T,K,P;
int A[205];
bool V[205];
int ans;
 
int main()
{
 
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        fori(0,K)
        {
            cin>>A[i];
            A[i]--;
        }
        P=0;
        memset(V,false,sizeof(V));
        for(ans=0;P<N;ans++)
        {
            fori(0,K)
            {
                if(A[i]+ans<N and !V[A[i]+ans])
                {
                    V[A[i]+ans]=true;
                    P++;
                }
                if(A[i]-ans>=0 and !V[A[i]-ans])
                {
                    V[A[i]-ans]=true;
                    P++;
                }
            }
        }
        cout<<ans<<endl;
    }
 
}