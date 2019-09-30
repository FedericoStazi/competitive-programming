#include <bits/stdc++.h>
using namespace std;

int T;
int N,M;
char A[1005][1005];
bool X[1005],Y[1005];
bool flag;

int main(){
    
    cin>>T;
    while(T--){

        cin>>N>>M;

        for(int i=0;i<N;i++)
            X[i]=false;
        for(int j=0;j<M;j++)
            Y[j]=false;
        flag=false;

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                cin>>A[i][j];
                if(A[i][j]=='1'){
                    flag=true;
                    X[i]=Y[j]=true;
                }
            }

        if(flag){
            
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    if(A[i][j]=='1')
                        cout<<"0 ";
                    else if(X[i] or Y[j])
                        cout<<"1 ";
                    else
                        cout<<"2 ";
                }
                cout<<"\n";
            }

        }
        else{

            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++)
                    cout<<"-1 ";
                cout<<"\n";
            }

        }

    }

}