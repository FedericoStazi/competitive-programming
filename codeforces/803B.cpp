#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
 
int main()
{
 
	int N,x,D1[200005],D2[200005];
	bool V[200005];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		
		cin>>x;
		if(x==0)V[i]=true;
		else V[i]=false;
		
	}
		
	if(V[0])
		D1[0]=0;
	else 
		D1[0]=1000000;
		
	for(int i=1;i<N;i++)
	{
		
		if(V[i])
			D1[i]=0;
		else 
			D1[i]=D1[i-1]+1;
			
	}
	
	if(V[N-1])
		D2[N-1]=0;
	else 
		D2[N-1]=1000000;
		
	for(int i=N-2;i>-1;i--)
	{
		
		if(V[i])
			D2[i]=0;
		else 
			D2[i]=D2[i+1]+1;
			
	}
	
	for(int i=0;i<N;i++)
		cout<<min(D1[i],D2[i])<<" ";
	
 
}
 
 