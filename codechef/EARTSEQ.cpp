#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int T,N;
vector<int> P;
bool B[1000006];
int K=1e6;
int x;
int A[1000006];

int main(){
    for(int i=2;i<K;i++)
        if(!B[i]){
            P.push_back(i);
            if(i<sqrt(K)+5)
                for(int j=i*i;j<K;j+=i)
                    B[j]=true;
        }
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;3*i<N+1;i++){
            A[3*i]=2*3;
            A[3*i+1]=3*5;
            A[3*i+2]=2*5;
        }
        x=3;
        for(int i=0;3*i<N+1;i++){
            A[3*i]*=P[x+i%3];
            A[3*i+1]*=P[x+(i+1)%3];
            A[3*i+2]*=P[x+(i+2)%3];
            if(i%3==2)
                x+=3;
        }
        if(N%3==1){
            A[N-4]=P[x+1]*2;
            A[N-3]=P[x+1]*3;
            A[N-2]=P[x+2]*3;
            A[N-1]=P[x+2]*2;
        }
        if(N%3==2){
            A[N-4]=P[x+1]*3;
            A[N-3]=P[x+1]*5;
            A[N-2]=P[x+2]*5;
            A[N-1]=P[x+2]*2;
        }
        for(int i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<"\n";
    }       
}