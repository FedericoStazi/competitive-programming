#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll md=1e9+7;
ll N,K;
priority_queue<pll> PQ;
ll L[1000006];
ll A[1000006];
ll DP[1000006];
ll S[1000006];
ll ans;

int main(){

    cin>>N>>K;
    if(K>N){
        ans=1;
        N--;
        while(N--)
            ans=(ans*2)%md;
        cout<<ans;
        return 0;
    }

    for(int i=0;i<N;i++)
        cin>>A[i+1];
    for(int i=0;i<=K;i++)
        PQ.push({0,i});

    DP[0]=S[0]=1;

    for(int i=1;i<N+1;i++){
        if(A[i]<=K){
            L[A[i]]=i;
            PQ.push({-i,A[i]});
        }
        while(L[PQ.top().second]!=-PQ.top().first)
            PQ.pop();
        int p=-PQ.top().first+1;
        DP[i]=(S[i-1]-((p-2>=0)?S[p-2]:0)+md)%md;
        S[i]=(S[i-1]+DP[i])%md;
    }

    cout<<DP[N];

}   