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
#include<list>
using namespace std;
 
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int N,P[200005],grafo[200005],x,sol1,sol2;
bool visitato[200005];
 
void DFS(int k)
{
	
	if(!visitato[grafo[k]])
	{
		
		visitato[grafo[k]]=true;
		DFS(grafo[k]);
		
	}
	
}
 
int main()
{
	
	cin>>N;
	
	int sol=0;
	bool flag=true;
	
	for(int i=1;i<N+1;i++)
		cin>>grafo[i];
	
	for(int i=0;i<N;i++)
	{
		
		cin>>x;
		if(x==1)
			flag=!flag;
		
	}	
	if(flag)
		sol1++;
		
	for(int i=1;i<N+1;)
	{
		
		visitato[i]=true;
		DFS(i);
		
		while(visitato[i] and i<N+1)
			i++;
			
		sol2++;
		
	}
	
	//cout<<sol2<<" ";
	if(sol2==1)
		sol2=0;
	cout<<sol1+sol2;
	
}