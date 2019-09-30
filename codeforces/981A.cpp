#include<bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define pb push_back
#define mp make_pair
#define Fx first
#define Sx second
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
int N;
string S;
int ans;
 
bool is_pal(int a,int b)
{
 
    bool res=true;
 
    fori(0,b-a)
        if(S[a+i]!=S[b-i])
            res=false;
 
    return res;
 
}
 
int main()
{
 
    cin>>S;
    fori(0,S.size())
        forv(j,i,S.size())
            if(!is_pal(i,j))
                ans=max(ans,j-i+1);
    cout<<ans;
}