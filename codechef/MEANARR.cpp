#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N,K,L,R,S;
ll A[1000005];
ll ans;

int main(){

    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>A[i];
        S+=A[i];
    }

    R=N;
    while(L<N){

        while(S>=(R-L)*K and R>L)
            S-=A[--R];

        ans+=max(R-L,0LL);

        S-=A[L++];

    }

    cout<<ans;

}