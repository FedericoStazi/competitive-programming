#include <iostream>
#include <assert.h>
using namespace std;

int a,b,x;
int A[200005];
int N,T;

int main(){

    cin>>T;
    while(T--){

        cin>>N;
        cout<<"1 1 3 4"<<endl;
        cin>>a;
        assert(a!=-1);
        cout<<"1 2 3 4"<<endl;
        cin>>b;
        assert(b!=-1);

        cout<<"1 1 2 5"<<endl;
        cin>>x;
        assert(x!=-1);
        A[5]=a^b^x;
        cout<<"1 1 2 6"<<endl;
        cin>>x;
        assert(x!=-1);
        A[6]=a^b^x;

        for(int i=5;i<=N-2;i++){
            cout<<"1 "<<i<<" "<<i+1<<" "<<i+2<<endl;
            cin>>x;
            assert(x!=-1);
            A[i+2]=x^A[i]^A[i+1];
        }

        cout<<"1 3 "<<N-1<<" "<<N<<endl;
        cin>>x;
        assert(x!=-1);
        A[3]=x^A[N-1]^A[N];
        cout<<"1 4 5 "<<N<<endl;
        cin>>x;
        assert(x!=-1);
        A[4]=x^A[5]^A[N];

        A[1]=a^A[3]^A[4];
        A[2]=b^A[3]^A[4];

        cout<<"2 ";
        for(int i=0;i<N;i++)
            cout<<A[i+1]<<" ";
        cout<<endl;
        cin>>x;

    }

}