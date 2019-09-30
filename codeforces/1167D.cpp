#include <iostream>
using namespace std;
 
int N;
string S;
int h;
 
int main(){
	cin>>N>>S;
	for(int i=0;i<N;i++)
		if(S[i]=='('){
			h++;
			cout<<h%2;
		}
		else{
			cout<<h%2;
			h++;
		}
}