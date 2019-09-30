#include <iostream>
#include <cmath>
using namespace std;
typedef long double ld;
 
int N,K,M;
int solution[105],started[105];
int A[1005];
bool B[1005];
int p;
int ans;
 
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<K;i++)
		solution[i]=-1;
 
	for(int t=0;M<N;t++){
 
		for(int i=0;i<K;i++){
			if(solution[i]==-1 and p<N){
				solution[i]=p;
				started[i]=t;
				p++;
			}
			if(started[i]+A[solution[i]]==t){
				if(p<N){
					solution[i]=p;
					started[i]=t;
					p++;
				}
				else
					solution[i]=-1;
				M++;
			}
		}
 
		for(int i=0;i<K;i++)
			if(solution[i]!=-1 and t-started[i]+1==floor(0.5+100*(ld)M/(ld)N))
				B[solution[i]]=true;
 
	}
	
		for(int i=0;i<N;i++)
			if(B[i])
				ans++;
 
		cout<<ans;
 
}