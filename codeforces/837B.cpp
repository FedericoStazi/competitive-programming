#define INF 1000000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <map>
using namespace std;
 
//ifstream in("input.txt");
//ofstream out("output.txt");
 
char F[101][101];
int N,M;
 
int main()
{
	
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>F[i];
	
	bool flag,ans=false;
	
	if(N%3==0)
	{
		
		flag=true;					
		if(F[N/3][0]==F[0][0])
			flag=false;
		if(F[2*N/3][0]==F[0][0] or F[2*N/3][0]==F[N/3][0])
			flag=false;
			
		for(int i=0;i<N/3;i++)
			for(int j=0;j<M;j++)
				if(F[i][j]!=F[0][0])
					flag=false;
					
		for(int i=N/3;i<2*N/3;i++)
			for(int j=0;j<M;j++)
				if(F[i][j]!=F[N/3][0])
					flag=false;
					
		for(int i=2*N/3;i<N;i++)
			for(int j=0;j<M;j++)
				if(F[i][j]!=F[2*N/3][0])
					flag=false;
				
		if(flag)
			ans=true;
		
	}
	if(M%3==0)
	{
		
		flag=true;					
		if(F[0][M/3]==F[0][0])
			flag=false;
		if(F[0][2*M/3]==F[0][0] or F[0][2*M/3]==F[0][M/3])
			flag=false;
			
		for(int i=0;i<M/3;i++)
			for(int j=0;j<N;j++)
				if(F[j][i]!=F[0][0])
					flag=false;
					
		for(int i=M/3;i<2*M/3;i++)
			for(int j=0;j<N;j++)
				if(F[j][i]!=F[0][M/3])
					flag=false;
					
		for(int i=2*M/3;i<M;i++)
			for(int j=0;j<N;j++)
				if(F[j][i]!=F[0][2*M/3])
					flag=false;
		
		if(flag)
			ans=true;		
		
	}
	
	if(ans)
		cout<<"YES";
	else	
		cout<<"NO";
		
}
 
 