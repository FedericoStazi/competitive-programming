#include<bits/stdc++.h>
using namespace std;
 
int main()
{
		int x,y,z;
		cin>>x>>y>>z;
		cout<<min(x,y+z)+min(z,x+y)+min(y,x+z);
}