#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll T;
ll N,M,K;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>M>>K;
        if(__gcd(N,K)==1 and __gcd(M,K)==1)
            cout<<N*M<<"\n";
        else
            cout<<"-1\n";
    }
}