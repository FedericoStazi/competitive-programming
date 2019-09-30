#include <iostream>
using namespace std;
typedef long long int ll;

ll T;
ll N,X;
ll A[5005];
ll DP[5005];
ll ans;
ll Stot[5005];
ll Sleft[5005];
ll Sright[5005];

ll S(ll a, ll b){
    a++,b++;
    if(a<b)
        return Sleft[b]-Sleft[a-1]-(Stot[b]-Stot[a-1])*(a-1);
    else
        return Sright[b]-Sright[a+1]-(Stot[a]-Stot[b-1])*(N-a);
}

int main(){
    cin>>T;
    while(T--){
        cin>>N>>X;
        for(int i=0;i<N;i++)
            cin>>A[i];

        ll s=0;
        for(int i=0;i<N;i++)
            s+=A[i];
        if(!s){
            cout<<"0\n";
            continue;
        }

        Stot[1]=A[0];
        Sleft[1]=Sright[N]=Sright[N+1]=0;
        for(int i=1;i<N;i++){
            Stot[i+1]=A[i]+Stot[i-1+1];
            Sleft[i+1]=i*A[i]+Sleft[i-1+1];
        }
        for(int i=N-2;i>=0;i--)
            Sright[i+1]=Sright[i+1+1]+A[i]*(N-1-i);

        for(int i=0;i<N;i++){
            DP[i]=X+S(i,0);
            for(int j=i-1;j>=0;j--){
                ll m=(i+j)/2;
                DP[i]=min(DP[i],DP[j]+S(j,m)+S(i,m+1)+X);
            }
        }

/*      for(int i=0;i<N;i++)
            cout<<S(0,i)<<" ";
        cout<<endl;
*/
        ans=1e18;
        for(int i=0;i<N;i++)
            ans=min(ans,S(i,N-1)+DP[i]);
        cout<<ans<<"\n";
/*
        for(int i=1;i<N+1;i++)
            cout<<i<<": "<<Stot[i]<<" "<<Sleft[i]<<" "<<Sright[i]<<endl;
*/

    }
}