#include <iostream>
using namespace std;
 
int N;
int x;
 
int main(){
 
	cin>>N;
	while(N--){
		cin>>x;
		if(x){
			cout<<"HARD";
			return 0;
		}
	}
 
	cout<<"EASY";
 
}