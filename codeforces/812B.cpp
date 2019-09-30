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
 
char A[20][105];
int N,M,x,S,E,topN;
int distD[405],distP[405],topD;
bool isDef[405];
bool flag;
vector<pair<int,int> > grafo[205];
 
int main()
{
	
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M+2;j++)
			cin>>A[N-i-1][j];
	
	N++;
	flag=true;
	while(flag)
	{
		
		N--;
		for(int j=0;j<M+2;j++)
			if(A[N-1][j]=='1')
				flag=false;
		if(N==1 and flag)
		{
			
			cout<<0;
			return 0;
			
		}
		
	}
	
	for(int i=0;i<N-1;i++)
	{
		
		x=0;
		flag=true;
		while(flag and x<=M)
		{
			
			if(A[i][x+1]=='1')
				flag=false;
			
			x++;
			
		}
		
		
		
		//cout<<"2i+1: "<<2*i+1<<"  x: "<<x<<"\n";
		grafo[2*i+1].push_back(make_pair(2*i+3,2*(M-x+1)+1));
		grafo[2*i+1].push_back(make_pair(2*i+2,M+2));//ok
			
		
		x=0;
		flag=true;
		while(flag and x<=M)
		{
			
			if(A[i][M-x]=='1')
				flag=false;
			
			x++;
			
		}
		
		
		//cout<<"2i: "<<2*i<<"  x: "<<x<<"\n";
		grafo[2*i].push_back(make_pair(2*i+2,2*(M-x+1)+1));
		grafo[2*i].push_back(make_pair(2*i+3,M+2));//ok
		
	} 
 
	
	
	x=0;
	flag=true;
	while(flag)
	{
			
		if(A[N-1][x+1]=='1')
			flag=false;
		
		x++;
			
	}
	
	grafo[2*N-1].push_back(make_pair(2*N,M-x+1));
	
	x=0;
	flag=true;
	while(flag)
	{
			
		if(A[N-1][M-x]=='1')
			flag=false;
		
		x++;
		
	}
	
	grafo[2*N-2].push_back(make_pair(2*N,M-x+1));
	
	/*
	for(int i=0;i<2*N;i++)
	{
		
		cout<<i<<":\n";
		cout<<grafo[i][0].first<<" "<<grafo[i][0].second<<"\n";
		if(i!=2*N-1 and i!=2*N-2)cout<<grafo[i][1].first<<" "<<grafo[i][1].second<<"\n";
		cout<<"\n";
		
	}
*/
//*******************************************************************************************************************************************************
 
	E=2*N;
	N=2*N+1;
	S=0;
	
	
	for(int i=0;i<N;i++)
		distP[i]=INF;
		
	distP[S]=0;
		
	while(!isDef[E])
	{
		
		topN=min_element(distP,distP+N)-distP;
		topD=distP[topN];
		
		//for(int i=0;i<N+1;i++)		cout<<i<<": "<<distP[i]<<"\n";
		//cout<<"zxxxxxxxxxxxxxxxxxxxxxx\n";
		
		isDef[topN]=true;
		distD[topN]=topD;
		distP[topN]=INF;
		x=grafo[topN].size();
		
		/*
		cout<<"***"<<topN<<":   \n";		
		if(isDef[topN])
			cout<<"� true\n";
		else	
			cout<<"� false\n";
		*/
		
		for(int i=0;i<x;i++)
		{
			
			//cout<<topN<<" "<<i<<": "<<grafo[topN][i].first<<" ditsP: ";
			if(!isDef[grafo[topN][i].first])
				distP[grafo[topN][i].first]=
					min(distP[grafo[topN][i].first],
					distD[topN]+grafo[topN][i].second);			
			//cout<<distD[topN]<<" "<<grafo[topN][i].second<<"\n";
		}
		
		//cout<<"xx"<<distD[E]<<"\n";
		
	}
	
	cout<<distD[E];
	
}
 