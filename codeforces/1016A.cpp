#include <iostream>
using namespace std;
 
int N,M,A;
int res;
 
int main(){
 
    cin>>N>>M;
 
    for(int i=0;i<N;i++){
        cin>>A;
        res+=A;
        cout<<res/M<<" ";
        res=res%M;
    }
 
}