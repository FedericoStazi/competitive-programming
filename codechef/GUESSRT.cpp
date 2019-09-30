#include <iostream>
using namespace std;
typedef long long int ll;

ll md=1e9+7;
int T;
ll x,y;
ll N,K,M;

ll pot(ll a, ll b){

    if(!b)
        return 1;

    ll c=pot(a,b/2);
    c=(c*c)%md;

    if(b%2)
        c=(c*a)%md;

    return c;

}

int main(){
    cin>>T;
    while(T--){

        cin>>N>>K>>M;
        M++;

        x=pot(N-1,M/2);
        y=pot(N,M/2);

        if(M%2)
            cout<<(((((N+K)*(md+y-x)+x)%md)*pot((y*(N+K))%md,md-2))%md)<<"\n";
        else
            cout<<(md-(((md+x-y)%md)*(pot(y,md-2)))%md)<<"\n";

    }
}