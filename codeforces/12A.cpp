#include <iostream>
using namespace std;
 
char A[9];
int ans;
 
int main(){
	for(int i=0;i<9;i++)
		cin>>A[i];
 
	for(int i=0;i<9;i++)
		if(A[i]!=A[8-i])
			ans=1;
 
	if(ans)
		cout<<"NO";
	else
		cout<<"YES";
 
}