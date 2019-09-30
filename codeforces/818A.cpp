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
 
long long N,K;
 
 
int main()
{
	
	cin>>N>>K;
	
	long long x=floor(N/(2*K+2));
	
	cout<<x<<" "<<K*x<<" "<<N-x-K*x;
	
}
	/*
	cin>>N>>Al;
	
	for(int i=0;i<N;i++)
		cin>>C[i];
	
	int primo=0;
	int y=0;	
	while(y<N and C[y]!=Al)
	{
		
		B[C[y]]=true;
		AL[listaSize].col=C[y];
		AL[listaSize].dav=y+1;
		AL[listaSize].die=y-1;
		listaSize++;
		y++;
		
	}
	if(y==N)
	{
		
		cout<<C[0];
		return 0;
		
	}
	
	for(int i=0;i<N;i++)
		A[i]=0;
	
	for(int i=0;i<N;i++)
	{
		
		int listaPunt=0;
		if(C[i]==Al)
		{
			
			M=listaSize;
			for(int j=0;j<M;j++)
			{
				
				if(A[AL[listaPunt].col]>0 and B[AL[listaPunt].col])
				{
						
					A[AL[listaPunt].col]--;
						
				}
				else
				{
					
					B[AL[listaPunt].col]=false;
					//elimino
					if(listaPunt==primo)
						primo=AL[listaPunt].dav;
					AL[AL[listaPunt].die].dav=AL[listaPunt].dav;
					AL[AL[listaPunt].dav].die=AL[listaPunt].die;
					listaSize--;
					//cout<<AL[listaPunt].col<<"\n";
					
				}
				
				listaPunt++;
					
				
			}
			
		}
		else if(B[C[i]])
			A[C[i]]++;
		
	}
	
	if(listaSize==0)
		cout<<-1;
	else	
		cout<<AL[primo].col;
		
	
}
*/