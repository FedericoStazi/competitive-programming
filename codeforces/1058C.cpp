#include <iostream>
using namespace std;
 
int N,G,s,k;
string S;
int A[100005];
bool flag=false;
bool g;
 
int main(){
 
	cin>>N;
	cin>>S;
	for(int i=0;i<N;i++)
		A[i]=(int)(S[i])-(int)'0';
 
	for(int p=0;p<N-1;p++){
 
		s=0;
		for(int i=0;i<=p;i++)
			s+=A[i];
		k=s;
 
		s=0;
		g=false;
		for(int i=p+1;i<N;i++){
			
			s+=A[i];
 
			if(s==k){
				g=true;
				s=0;
			}
			else if(s>k)
				break;
		}
 
		if(s==0 and g)
			flag=true;
 
	}
 
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
 
}