#include <iostream>
using namespace std;
 
int a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	if(c)
		cout<<(a and d and a==d);
	else
		cout<<(a==d);
 
}