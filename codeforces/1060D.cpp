#include <iostream>
#include <set>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
 
ll N;
ll L[200005],R[200005];
set<pll> A,B;
ll ans;
int x,y;
int c;
 
int main(){
    cin>>N;
    c=N;
    for(int i=0;i<N;i++){
        cin>>L[i]>>R[i];
        A.insert({-L[i],i});
        B.insert({-R[i],i});
    }
 
    while(A.size()>1){
 
        x=(*A.begin()).second;
        y=(*B.begin()).second;
 
        ans+=max(L[x],R[y]);
 
        L[c]=L[y];
        R[c]=R[x];
 
        if(x==y){
            A.erase({-L[x],x});
            B.erase({-R[x],x});
        }
        else{
            A.erase({-L[x],x});
            A.erase({-L[y],y});
            B.erase({-R[x],x});
            B.erase({-R[y],y});
            A.insert({-L[c],c});
            B.insert({-R[c],c});
            c++;
        }
    }
 
    cout<<ans+N-min((*A.begin()).first,(*B.begin()).first);
 
}