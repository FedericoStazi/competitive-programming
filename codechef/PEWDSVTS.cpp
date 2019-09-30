#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;

int T;
ll x;
ll N,A,B,X,Y,Z,G;
ll ans;
priority_queue<ll> PQ;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>A>>B>>X>>Y>>Z;
        ans=0;

        while(!PQ.empty())
            PQ.pop();
        for(int i=0;i<N;i++){
            cin>>x;
            PQ.push(x);
        }

        G=((Z-B+Y-1)/Y)-1;
        if(G==-1){
            cout<<"RIP\n";
            continue;
        }

        A=A+X*G;
        while(A<Z){
            x=PQ.top();
            PQ.pop();
            PQ.push(x/2);
            if(!x){
                ans=-1;
                break;
            }
            ans++;
            A+=x;
        }
        
        if(ans==-1)
            cout<<"RIP\n";
        else
            cout<<ans<<"\n";
    }
}