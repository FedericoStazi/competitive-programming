#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define B(x,y) B[T][{min(x,y),max(x,y)}]
typedef pair<int,int> pii;

int T;
int N,M;
int x,y;
vector<int> grafo[100005];
pii A[100005];
map<pii,bool> B[7];
bool V[100005];

void DFS(int k, int p){

    if(V[k]) return;
    V[k]=true;

    int a=0;

    for(int f:grafo[k])
        DFS(f,k);

    for(int f:grafo[k])
        if((k<f and B(k,f)) or (f<k and !B(k,f)))
            a++;

    if(a%2) B(k,p)=!B(k,p);
}


int main(){

    cin>>T;
    while(T--){

        cin>>N>>M;

        for(int i=0;i<N;i++){
            V[i]=false;
            grafo[i].clear();
        }

        for(int i=0;i<M;i++){
            cin>>x>>y;
            x--,y--;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
            A[i]={x,y};
            B(x,y)=x>y;
        }

        DFS(0,-1);

        if(M%2)
            cout<<-1;
        else
            for(int i=0;i<M;i++)
                cout<<((A[i].first>A[i].second)^(B(A[i].first,A[i].second)))<<" 
                    ";
        cout<<endl;

    }
}
