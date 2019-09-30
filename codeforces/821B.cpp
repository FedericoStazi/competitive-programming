#define INF 1000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
typedef long long ll;
ll M,B,x,sol;
 
 
 
int main()
{
	
	cin>>M>>B;
	sol=0;
	
	for(ll y=0;y<=B;y++)
	{
		
		x=M*(B-y);
		//cout<<x<<" "<<y<<"\n";
		sol=max(sol,((x*(x+1))/2*(y+1)+(y*(y+1))/2*(x+1)));
		
	}
	
	
	
	cout<<sol;	
}