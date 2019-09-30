#include <iostream>
using namespace std;
typedef long long int ll;

ll N,M;
ll A[100005],B[100005];

bool check(ll G){
    ll p=M;
    ll x;
    for(int i=0;i<N;i++){
        x=max(0LL,A[i]-G/B[i]);
        p-=x;
    }
    return p>=0;
}

int main(){

    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<N;i++)
        cin>>B[i];

    ll l=0,r=1e18,m;

    while(l<r){
        m=(l+r)/2;
        if(check(m))
            r=m;
        else
            l=m+1;
    }

    cout<<l;

}