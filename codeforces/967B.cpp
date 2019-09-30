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
ld A,B,S[100005],Q;
 
int main()
{
    cin>>N>>A>>B;
    fori(0,N)
        cin>>S[i];
 
    sort(S+1,S+N,greater<ld>());
 
    fori(0,N)
        Q+=S[i];
 
    fori(1,N)
    {
        //cout<<(S[0]*A)<<" "<<Q<<endl;
        if((S[0]*A)/Q<B)
            Q-=S[i];
        else
        {
            cout<<i-1;
            return 0;
        }
    }
 
    cout<<N-1;
}