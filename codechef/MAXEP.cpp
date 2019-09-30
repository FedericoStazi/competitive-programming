#include <iostream>
using namespace std;
    
int N,C,L;
int x;
int K=54;

int main(){

    cin>>N>>C;

    L=1;
    for(x=0;!x;){
        cout<<"1 "<<L<<endl;
        cin>>x;
        L=min(N,L+K*K);
    }
    L=max(1,L-2*K*K);
    cout<<2<<endl;

    for(x=0;!x;){
        cout<<"1 "<<L<<endl;
        cin>>x;
        L=min(N,L+K);
    }
    L=max(1,L-2*K);
    cout<<2<<endl;

    for(x=0;!x;){
        cout<<"1 "<<L<<endl;
        cin>>x;
        L++;
    }
    L=max(0,L-2);
    cout<<"3 "<<L+1<<endl;

}
