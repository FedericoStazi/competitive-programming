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
 
int A[1005],B[1005];
int miss[1005];
int N,D,rip1,rip2,sol=0,S;
 
//test 
//bool usato1[1005],usato2[1005];
 
int main()
{
	
	
	cin>>N;
	for(int i=0;i<N;i++)	
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
		
	
	
	/*
	int TEST=10;
	for(int T=0;T<TEST;T++)
	{
		
		N=10;
		for(int i=0;i<N+1;i++)
		usato1[i]=false;
		
		for(int i=0;i<N;i++)
		{
			
			D=(int)rand()%N+1;
			if(!usato1[D])
			{
				
				A[i]=D;
				usato1[D]=true;
				
			}
			else
			{
				
				i--;
				
			}
			
		}
		
		for(int i=0;i<N;i++)
			B[i]=A[i];
		
		D=(int)rand()%N;
		rip1=D;
		while(rip1==D)
		{
			
			rip1=(int)rand()%N;
			
		}
		A[D]=A[rip1];
		
		
		
		rip2=D;
		while(rip2==D)
			D=(int)rand()%N;
			
		rip1=D;
		while(rip1==D)
		{
			
			rip1=(int)rand()%N;
			
		}
		B[D]=B[rip1];
		
		cout<<"\n";
		cout<<"TESTCASE: "+TEST<<"\n";
		
		cout<<"A[]: ";
		for(int i=0;i<N;i++)
			cout<<A[i]<<" ";
		cout<<"\n";
		
		cout<<"B[]: ";
		for(int i=0;i<N;i++)
			cout<<B[i]<<" ";
		cout<<"\n";
		cout<<"R[]: ";
	
	//********************************************
	*/
	
	
	
	for(int i=1;i<N+1;i++)	
		miss[i]=-1;
		
	for(int i=0;i<N;i++)
		{
			
			if(miss[A[i]]==-1)	
				miss[A[i]]=i;
			else
			{
				
				rip1=i;
				rip2=miss[A[i]];
				
			}
							
		}
		
		S=A[rip1];		
		
		for(int i=1;i<N+1;i++)
			if(miss[i]==-1)
				A[rip1]=i;
				
		for(int i=0;i<N;i++)
			if(A[i]!=B[i])sol++;
		
		if(sol<2)
		{
			
			for(int i=0;i<N;i++)
				cout<<A[i]<<" ";
				
			return 0;
						
		}
		
		A[rip1]=S;
		
		for(int i=1;i<N+1;i++)
			if(miss[i]==-1)
				A[rip2]=i;
		
		for(int i=0;i<N;i++)
				cout<<A[i]<<" ";
		
		
		
		
		
		
		//cout<<rip1<<" "<<rip2<<"\n";
		
		/*
		if(A[rip1]!=B[rip1])
		{
			
			for(int i=1;i<N+1;i++)
				if(miss[i]==-1)
					A[rip1]=i;
			
		}
		else
		{
			
			for(int i=1;i<N+1;i++)
				if(miss[i]==-1)
					A[rip2]=i;			
			
		}
		
		
	
	for(int i=0;i<N;i++)
		if(A[i]!=B[i])
			D++;
		
	if(D==1)
	{
		
		for(int i=0;i<N;i++)
		{
			
			if(miss[A[i]]==-1)	
				miss[A[i]]=i;
			else
				rip1=i;
				rip2=miss[A[i]];
			
		}
		
		if(A[rip1]!=B[rip1])
		{
			
			for(int i=1;i<N+1;i++)
				if(miss[i]==-1)
					A[rip1]=i;
			
		}
		else
		{
			
			for(int i=1;i<N+1;i++)
				if(miss[i]==-1)
					A[rip2]=i;			
			
		}
		
	}
	else
	{
		
		for(int i=0;i<N;i++)
		{
			
			if(miss[A[i]]==-1)	
				miss[A[i]]=i;
			else
				rip1=i;
				rip2=miss[A[i]];
			
		}	
		
		
		
	}
	
	for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
 
*/
	
	
}
 