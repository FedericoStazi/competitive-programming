#include <iostream>
using namespace std;

int N,M;
int x;
int a=2e9,b=-2e9,p,q;

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x<a){
            a=x;
            p=i;
        }
    }
    for(int i=0;i<M;i++){
        cin>>x;
        if(x>b){
            b=x;
            q=i;
        }
    }
    for(int i=0;i<M;i++)
        cout<<p<<" "<<i<<"\n";
    for(int j=0;j<N;j++)
        if(j!=p)
            cout<<j<<" "<<q<<"\n";
}

