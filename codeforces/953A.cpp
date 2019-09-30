#include <bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define Fx first
#define Sx second
#define ll long long int
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
 
using namespace std;
 
ll L,R;
set<ll> S;
int ans;
 
int main()
{
 
    cin>>L>>R;
 
    for(ll i=1;i<=2e9;i*=2)
        for(ll j=1;j*i<=2e9;j*=3)
            S.insert(i*j);
 
    //cout<<S.lower_bound(R)-S.lower_bound(L-1);
    auto it=S.lower_bound(L);
    while(it!=S.lower_bound(R+1))
    {
        ans++;
        it++;
    }
 
    cout<<ans;
 
}