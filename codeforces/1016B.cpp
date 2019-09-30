#include <iostream>
using namespace std;
 
int N,M,Q;
int x,y;
string S,T;
int B[1005];
int A[1005];
 
int main(){
    cin>>N>>M>>Q;
    cin>>S>>T;
 
    for(int i=0;i<N-M+1;i++){
        bool flag=true;
        for(int j=0;j<M;j++)
            if(S[i+j]!=T[j])
                flag=false;
        B[i]=flag;
    }
 
    for(int i=0;i<N;i++)
        A[i+1]=A[i]+B[i];
 
    while(Q--){
        cin>>x>>y;
        if(y-x+1<M)
            cout<<"0\n";
        else
            cout<<A[y-M+1]-A[x-1]<<"\n";
    }
}