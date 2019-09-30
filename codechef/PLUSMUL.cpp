#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll md=1e9+7;
ll N,K;
ll x,y,z,a,ans;
int T;

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        x=y=0;z=1;
        for(int i=0;i<N;i++){
            cin>>a;
            y=(a*(y+z))%md;
            ans=(x+y)%md;
            x=(2*x+y)%md;
            if(i)z=(z*2)%md;
            //cout<<i<<" "<<a<<" "<<x<<" "<<y<<" "<<ans<<endl;
        }
        cout<<ans<<"\n";
    }
}