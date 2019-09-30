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
 
vector< pair<int,int> > grafo[101];
int N,x,y,z;
bool visitato[101];
 
int distanza(int P)
{
	
	int sol=0;
	for(int i=0;i<grafo[P].size();i++)
	{
		
		if(!visitato[grafo[P][i].first])
		{
			
			visitato[grafo[P][i].first]=true;
			sol=max(sol,grafo[P][i].second+distanza(grafo[P][i].first));
			
		}
		
		
	}
	
	return sol;
	
}
 
int main()
{
	
	cin>>N;
	for(int i=0;i<N-1;i++)
	{
		
		cin>>x>>y>>z;
	
		grafo[x].push_back(make_pair(y,z));
		grafo[y].push_back(make_pair(x,z));
		
	}
	
	visitato[0]=true;
	cout<<distanza(0);
	
}