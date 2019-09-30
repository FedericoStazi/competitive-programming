#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
 
int T;
int N,M;
int x,y;
vector<int> A;
bool V[300005];
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin>>T;
	while(T--){
 
		cin>>N>>M;
	
		A.clear();
		for(int i=1;i<3*N+1;i++)
			V[i]=false;
 
		for(int i=0;i<M;i++){
			cin>>x>>y;
			if(!V[x] and !V[y]){
				A.push_back(i+1);
				V[x]=V[y]=true;
			}
		}
 
		if(A.size()>=N){
			cout<<"Matching\n";
			for(int i=0;i<N;i++)
				cout<<A[i]<<" ";
			cout<<"\n";
		}
		else{
			x=0;
			cout<<"IndSet\n";
			for(int i=1;x<N;i++)
				if(!V[i]){
					cout<<i<<" ";
					x++;
				}
			cout<<"\n";
		}
 
	}
}