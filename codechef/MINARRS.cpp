#include <iostream>
using namespace std;
typedef long long int ll;

ll T;
ll N;
ll A[100005];
ll B[100005];
ll ans,p;

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        ans=0;
        for(ll i=0;i<N;i++)
            cin>>B[i];
        for(ll i=0;i<N;i++)
            A[i]=B[i];
        for(ll c=0,s=1;c<30;c++,s*=2){
            ll res=0;
            for(ll i=0;i<N;i++)
                if(A[i]%2)
                    res++;
            if(res>N/2)
                ans+=s;
            for(ll i=0;i<N;i++)
                A[i]/=2;
        }
        p=0;
        for(ll i=0;i<N;i++)
            p+=B[i]^ans;
        cout<<p<<"\n";
    }
}