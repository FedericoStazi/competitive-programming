#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N,M;
int x;
vector<int> A[100005],B[100005];
 
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>x;
			A[i+j].push_back(x);
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>x;
			B[i+j].push_back(x);
		}
	for(int i=0;i<N+M-1;i++){
		sort(A[i].begin(),A[i].end());
		sort(B[i].begin(),B[i].end());
	}
	for(int i=0;i<N+M-1;i++)
		for(int j=0;j<A[i].size();j++)
			if(A[i][j]!=B[i][j]){
				cout<<"NO";
				return 0;
			}
	cout<<"YES";
}