#define INF 1000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int A,B,X,Y,x,y;
 
int PANE(int a,int b)
{
	
	int k=a%b;
	if(k>=0)
		return k;
	else 
		return b+k;
	
}
 
int main()
{
 
	cin>>x>>y>>A>>B>>X>>Y;
	
	A-=x;
	B-=y;
	X=abs(X);
	Y=abs(Y);
	
	if(PANE(A,X)!=0 or PANE(B,Y)!=0)
	{
		
		cout<<"NO";
		return 0;
		
	}
	
	if((PANE(A,2*X)==0 and PANE(B,2*Y)==0) or (PANE(A,2*X)==X and PANE(B,2*Y)==Y) )
	{
		
		
		cout<<"YES";
		return 0;
		
	}
 
	cout<<"NO";
 
}