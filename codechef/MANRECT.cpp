#include <iostream>
#include <assert.h>
using namespace std;
typedef pair<int,int> pii;

int inf=1e9;
int T;
int V[]={0,inf};
int A[2][2];
int xa,xb,ya,yb;

int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                cout<<"Q "<<V[i]<<" "<<V[j]<<endl;
                cin>>A[i][j];
                assert(A[i][j]>=0);
            }
        cout<<"Q "<<((A[0][0]+inf-A[1][0])/2)<<" 0"<<endl;
        cin>>ya;
        assert(ya>=0);
        xa=A[0][0]-ya;
        xb=-A[1][0]+ya+inf;
        yb=-A[0][1]+xa+inf;
        cout<<"A "<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<endl;
        cin>>ya;
        assert(ya==1);
    }
}