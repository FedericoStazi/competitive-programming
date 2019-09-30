#include <iostream>
using namespace std;

int N,M,T;
int A[500][500];
bool flag;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        if(N==1 and M==1){
            cout<<"1\n1\n";
        }
        else if(N==1){
            if(M==2)
                cout<<"1\n";
            else
                cout<<"2\n";
            for(int i=0;i<M;i++)
                cout<<(i/2)%2+1<<" ";
            cout<<"\n";
        }       
        else if(M==1){
            if(N==2)
                cout<<"1\n";
            else
                cout<<"2\n";
            for(int i=0;i<N;i++)
                cout<<(i/2)%2+1<<"\n";
        }
        else if(N==2 and M==2){
            cout<<"2\n1 1\n2 2\n";
        }
        else if(N==2){
            cout<<"3\n";
            for(int i=0;i<M;i++)
                cout<<i%3+1<<" ";
            cout<<"\n";
            for(int i=0;i<M;i++)
                cout<<i%3+1<<" ";
            cout<<"\n";
        }
        else if(M==2){
            cout<<"3\n";
            for(int i=0;i<N;i++)
                cout<<i%3+1<<" "<<i%3+1<<"\n";
        }
        else{
            cout<<"4\n";
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++)
                    cout<<(i/2+j/2)%2+2*(j%2)+1<<" ";
                cout<<"\n";
            }
        }
    }
}