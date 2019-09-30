#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
 
int x;
vector<int> A[4];
int P[]={42,23,16,15,8,4};
bool B[100000];
int S[6];
 
int main(){
	for(int i=0;i<4;i++){
		cout<<"? "<<i+1<<" "<<i+2<<endl;
		cin>>x;
		if(x==32){
			A[i].push_back(8);
			A[i].push_back(4);
		}
		else
			for(int j=0;j<6;j++)
				if(x%P[j]==0){
					A[i].push_back(P[j]);
					x/=P[j];
				}
	}
 
	for(int i=0;i<3;i++){
		if(A[i][0]==A[i+1][0] or A[i][0]==A[i+1][1])
			swap(A[i][0],A[i][1]);
		if(A[i][1]==A[i+1][1])
			swap(A[i+1][0],A[i+1][1]);
		S[i]=A[i][0];
		S[i+1]=A[i+1][0];
		B[S[i]]=true;
		B[S[i+1]]=true;
	}
	S[4]=A[3][1];
	B[S[4]]=true;
	for(int i=0;i<6;i++)
		if(!B[P[i]])
			S[5]=P[i];
 
	cout<<"! ";
	for(int i=0;i<6;i++)
		cout<<S[i]<<" ";
	cout<<endl;
 
}