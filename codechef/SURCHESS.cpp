#include <iostream>
#include <assert.h>
using namespace std;

int G[2][2][205][205][205];
// che colore, pari o dispari, x, y, lato quadrato
int N,M,Q;
char A[205][205];
int sol[205];
int x;

int main(){

    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>A[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            G[A[i][j]-'0'][(i+j)%2][i][j][1]=1;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int k=2;k<=min(N,M);k++)
                if(min(i,j)+1>=k)
                    for(int col=0;col<2;col++)
                        for(int par=0;par<2;par++){
                            G[col][par][i][j][k]=
                                G[col][par][i-1][j][k-1]+G[col][par][i][j-1][k
                                    -1]-G[col][par][i-1][j-1][k-2]
                                +G[col][par][i-k+1][j-k+1][1]
                                    +G[col][par][i][j][1];
                        }
                        
/*
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int k=1;k<=min(N,M);k++)
                if(min(i,j)+1>=k)
                    for(int x=i-k+1;x<=i;x++)
                        for(int y=j-k+1;y<=j;y++)
                            G[A[x][y]-'0'][(x+y)%2][i][j][k]++;
*/
    for(int i=0;i<=min(N,M);i++)sol[i]=1e9+42;

    for(int k=1;k<=min(N,M);k++)
        for(int i=k-1;i<N;i++)
            for(int j=k-1;j<M;j++)
                sol[k]=min(sol[k],min(G[0][0][i][j][k]+G[1][1][i][j][k]
                    ,G[0][1][i][j][k]+G[1][0][i][j][k]));

    for(int k=2;k<=min(N,M);k++)
        assert(sol[k]>=sol[k-1]);

    cin>>Q;
    while(Q--){
        cin>>x;
        int i;
        for(i=1;i<=min(N,M);i++)
            if(sol[i]>x)
                break;
        cout<<i-1<<"\n";
    }

}

    //for(int i=0;i<=min(N,M);i++)cout<<sol[i]<<" ";cout<<endl;
    /*
    //cout<<col<<" "<<par<<" "<<i<<" "<<j<<" "<<k<<endl;
    int a=0,b=1;
    for(int k=1;k<max(N,M);k++){
        cout<<"K "<<k<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                cout<<G[a][b][i][j][k]<<" ";
            cout<<endl;
        }
    }
    */