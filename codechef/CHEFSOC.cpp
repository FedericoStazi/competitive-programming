#include <iostream>
#include <assert.h>
using namespace std;
typedef long long int ll;

ll md=1e9+7;
int T;
ll N;
ll A[1000016];
ll DP[1000016];
ll S[1000016];
ll last;
ll x;

int main(){

    cin>>T;

    while(T--){

        cin>>N;
        for(int i=0;i<N;i++)
            cin>>A[i];

        for(int i=0;i<N+5;i++)
            DP[i]=S[i]=0;

        DP[N-1]=1;
        DP[N-2]=2;
        S[N-2]=1;

        for(ll i=N-3;i>=0;i--){

            DP[i]=(1+DP[i+1])%md;
            S[i]=1;

            if(A[i]==2){

                DP[i]=(DP[i]+1)%md;
                S[i]=(S[i]+1)%md;

                if(A[i+1]==2)
                    DP[i]=(DP[i]+DP[i+3])%md;

                DP[i]=(DP[i]+DP[i+2])%md;
                if(A[i+3]==2){
                    DP[i]=(DP[i]+S[i+2])%md;
                    S[i]=(S[i]+S[i+2])%md;
                }

            }


        }

        //for(int i=0;i<N;i++)cout<<DP[i]<<" "<<S[i]<<endl;
        cout<<DP[0]<<"\n";

    }
}


/*
            DP[i]=(1+DP[i+1]+(A[i]-1)+DP[i+2]+DP[i+3]+S[i+2]);
            S[i]=1+(A[i])

            for(ll j=i+2;j<N;j+=2){
            
                if(A[j-2]==1)
                    break;

                if(A[j-1]==1)
                    last=j-1;

                x=(j-1-last)/2+1;

                if(j==N-1)
                    DP[i]=(DP[i]+1+x)%md;
                else
                    DP[i]=(DP[i]+1+A[j+1]*x+A[j-1]*DP[j+1])%md;

            }

*/
