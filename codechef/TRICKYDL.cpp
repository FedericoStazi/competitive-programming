#include <iostream>
using namespace std;
typedef long long int ll;

int T;
ll A;
ll M,x,y,z;

int main(){
    cin>>T;
    while(T--){
        cin>>A;
        x=0,y=0,z=0,M=0;
        for(ll d=1;;d++){
            M+=A-(1LL<<(d-1));
            //cout<<d<<" "<<M<<"\n";
            if(M>z){
                z=M;
                y=d;
            }
            if(M<0){
                x=d-1;
                break;
            }
        }
        cout<<x<<" "<<y<<"\n";
    }
}