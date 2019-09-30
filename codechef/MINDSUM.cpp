#include <iostream>
#include <assert.h>
using namespace std;
typedef long long int ll;

ll S(ll k){
    ll res=0;
    for(;k;k/=10)
        res+=k%10;
    return res;
}

int T;
ll N,D;
int ans,mosse;

int F(ll k, ll m){

    if(k<10 and m==0)
        return 0;
    if(m==0)
        return 1+F(S(k),m);
    if(k<10)
        return 1+F(k+D,m-1);

    return 1+min(F(S(k),m),F(k+D,m-1));

}

int main(){

    cin>>T;
    while(T--){

        cin>>N>>D;

        if(N==0)

        ans=0;
        mosse=0;
        if(D%9==0);
        else if(D%3==0)
            while(N%9>3 or N%9==0){
                mosse++;
                N+=D;
            }
        else
            while(N%9>1 or N%9==0){
                mosse++;
                N+=D;
            }

        N-=mosse*D;

        ans=F(N,mosse);

        N+=mosse*D;
        while(N>9)
            N=S(N);

        cout<<N<<" "<<ans<<"\n";

    }

}