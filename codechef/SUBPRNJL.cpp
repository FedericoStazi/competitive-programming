#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;

typedef tree<pii,null_type,less<pii>, rb_tree_tag, 
    tree_order_statistics_node_update> bbst;

int T;
int N,K;
int A[2005];
int F[2005];
bool B[2005];
int ans;
int x,y,l,m,p;
int e;
bbst R;

int main(){
    cin>>T;
    while(T--){

        cin>>N>>K;
        ans=0;
        for(int i=0;i<N;i++)
            cin>>A[i];

        for(int i=0;i<N;i++){

            for(int i=0;i<2005;i++){
                F[i]=0;
                B[i]=false;
            }
            R.clear();

            for(int j=i;j<N;j++){

                B[A[j]]=true;
                R.insert({A[j],e++});
                F[A[j]]++;

                l=j-i+1;
                m=(K+l-1)/l;
                p=(K+m-1)/m;
                y=R.find_by_order(p-1)->first;

                if(B[F[y]])
                    ans++;

            }

        }

        cout<<ans<<"\n";
    }
}