#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll A,B,C,D;
ll N;
ll V[1000005];
ll P[1000005];
ll T;
ll M=1000000007;

int main(){
    cin>>T;
    while(T--){

        cin>>N;

        for(int i=0;i<N;i++){
            P[i]=0;
            cin>>V[i];
        }

        A=B=C=D=0;
        for(int i=0;i<N-1;i++){
            A=(A+V[i])%M;
            B=(B+A)%M;
            C=(C+B)%M;
            D=(D+C)%M;
            P[i+1]=(P[i+1]+D)%M;
        }

        A=B=C=D=0;
        for(int i=N-1;i>0;i--){
            A=(A+V[i])%M;
            B=(B+A)%M;
            C=(C+B)%M;
            D=(D+C)%M;
            P[i-1]=(P[i-1]+D)%M;
        }

        for(int i=0;i<N;i++)
            cout<<P[i]<<" ";
        cout<<"\n";

    }
}