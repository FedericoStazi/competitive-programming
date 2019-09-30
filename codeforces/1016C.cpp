#include <iostream>
using namespace std;
typedef long long int ll;
 
ll N;
ll A[2][300005];
ll M[2][300005];
ll S[300005];
ll res,ans;
 
int main(){
 
    cin>>N;
    for(ll j=0;j<2;j++)
        for(ll i=0;i<N;i++)
            cin>>M[j][i];
 
    for(ll i=N-1;i>=0;i--)
        S[i]=S[i+1]+M[0][i]+M[1][i];
 
    for(ll j=0;j<2;j++)
        for(ll i=N-1;i>=0;i--)
            A[j][i]=A[j][i+1]+S[i+1]+M[(j+1)%2][i]*(2*(N-i)-1);
 
    //for(ll i=0;i<N;i++)cout<<i<<" "<<S[i]<<" "<<A[0][i]<<" "<<A[1][i]<<endl;
 
    ans=A[0][0];
 
    for(ll i=0;i<N;i++){
        res+=2*i*M[i%2][i]+(2*i+1)*M[(i+1)%2][i];
        ans=max(ans,res+A[(i+1)%2][i+1]+2*(i+1)*S[i+1]);
    }
 
    cout<<ans;
 
}
 
/*
3
1 100000 10000
10 100 1000
*/