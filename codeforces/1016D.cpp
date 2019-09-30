#include <iostream>
#include <vector>
using namespace std;
 
int N,M;
int A[105],B[105];
int C[105][105];
int R[105][105];
vector<int> P,Q;
 
int main(){
 
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int j=0;j<M;j++)
        cin>>B[j];
 
    for(int c=0;c<31;c++){
 
        P.clear();
        Q.clear();
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                C[i][j]=0;
 
        for(int i=0;i<N;i++)
            if(A[i]%2)
                P.push_back(i);
        for(int j=0;j<M;j++)
            if(B[j]%2)
                Q.push_back(j);
 
        if((P.size()+Q.size())%2==1){
            cout<<"NO";
            return 0;
        }
 
        for(int i=0;i<min(P.size(),Q.size());i++)
            C[P[i]][Q[i]]++;
 
        for(int i=min(P.size(),Q.size());i<P.size();i++)
            C[P[i]][Q.empty()?0:Q[0]]++;
 
        for(int i=min(P.size(),Q.size());i<Q.size();i++)
            C[P.empty()?0:P[0]][Q[i]]++;
 
        for(int i=0;i<N;i++)
            A[i]=A[i]/2;
        for(int j=0;j<M;j++)
            B[j]=B[j]/2;
 
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                R[i][j]+=C[i][j]*(1<<c);
 
    }
 
    cout<<"YES\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            cout<<R[i][j]<<" ";
        cout<<"\n";
    }
 
}