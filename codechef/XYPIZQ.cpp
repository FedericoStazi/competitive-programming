#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N,t,x,y,z;

void stampa(int x, int y){
    cout<<x/__gcd(x,y)<<" "<<y/__gcd(x,y)<<"\n";
}

int main(){
    cin>>T;
    while(T--){
        cin>>N>>t>>x>>y>>z;
        if(t==3){
            swap(x,z);
            t=1;
        }
        if(t==4){
            t=2;
        }
        if(t==1){
            if(x==z)
                stampa(x,2*N+1);
            else
                stampa(2*N+1-z,2*N+1);
        }
        if(t==2)
            stampa(2*N+1-2*y,2*N+1);
    }
}