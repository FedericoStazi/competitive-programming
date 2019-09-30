#include <iostream>
#include <assert.h>
using namespace std;

int T;
int N,K;
int G=500;
int A[100005];
int B[100005];
int x,y,ans;
int sol[100005];

int main(){

    cin>>T;

    while(T--){

        cin>>N>>K;
        for(int i=0;i<N;i++)
            cin>>A[i];

        for(int i=0;i<N;i++)
            B[i]=0;

        for(int i=0;i<N;i++){
            for(x=1;;x++){
                int d=A[i]/x+1;
                if(d<G+1)
                    break;
                if(i-d+1>=0)
                    B[i-d+1]++;
            }
        }

        ans=N+1;
        y=0;

        for(int i=N-1;i>=0;i--){
            x=0;
            for(int j=0;j<G and j+i<N;j++)
                x+=A[j+i]/(j+1);
            y-=B[i];
            if(x+y<=K)
                ans=i+1;
            if(i+G-1<N)
                y+=A[i+G-1]/G;
        }
    
        cout<<ans<<"\n";

    }
}
