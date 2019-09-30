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
 
bool quad[23][23],sol[49][49];
int disp;
 
int N;
 
int main()
{
	
	//for(N=7;N<20;N+=2){
	
	//dispari=true
 
	cin>>N;
	//N=11;
	if(N==1)
		cout<<1;
	else if(N==3)
		cout<<"2 1 4\n3 5 7\n6 9 8";
	else if(N==5)
		cout<<"1 2 3 4 5\n6 8 7 10 12\n9 11 13 15 17\n14 16 19 18 20\n21 22 23 24 25";
	else
	{
	
		disp=((N*N+1)/2-2*N-3)/4;
		//cout<<disp<<"\n\n";
		
		if(disp%2==((N-3)/2)%2)
			for(int i=0;i<(N-3)/2;i++)
			{
				
				quad[i][i]=true;
				disp--;
				
			}
		else
			for(int i=1;i<(N-3)/2;i++)
			{
				
				quad[i][i]=true;
				disp--;
				
			}
				
		for(int i=0;i<(N-3)/2;i++)
			for(int j=0;j<(N-3)/2 and j<i;j++)
				if(disp>0)
				{
					
					quad[i][j]=true;
					quad[j][i]=true;
					disp-=2;
					
				}
				
			
			/*
		for(int i=0;i<(N-3)/2;i++)
		{
			for(int j=0;j<(N-3)/2;j++)
				cout<<quad[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
		*/
		
		
		for(int i=0;i<(N-3)/2;i++)
			for(int j=0;j<(N-3)/2;j++)
				sol[i][j]=quad[i][j];
				
		for(int i=0;i<(N-3)/2;i++)
			for(int j=0;j<(N-3)/2;j++)
				sol[N-i-1][j]=quad[i][j];
				
		for(int i=0;i<(N-3)/2;i++)
			for(int j=0;j<(N-3)/2;j++)
				sol[i][N-j-1]=quad[i][j];
				
		for(int i=0;i<(N-3)/2;i++)
			for(int j=0;j<(N-3)/2;j++)
				sol[N-i-1][N-j-1]=quad[i][j];
				
		for(int i=0;i<N;i++)
		{
			
			sol[(N-1)/2][i]=true;
			sol[i][(N-1)/2]=true;
			
		}
		
		sol[(N-1)/2-1][(N-1)/2-1]=true;
		sol[(N-1)/2-1][(N-1)/2+1]=true;
		sol[(N-1)/2+1][(N-1)/2-1]=true;
		sol[(N-1)/2+1][(N-1)/2+1]=true;
		
	/*	
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<sol[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
		*/
		
		
		int P=2;
		int D=1;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				if(sol[i][j])
				{
					
					cout<<D<<" ";
					D+=2;
				
				}
				else
				{
					
					cout<<P<<" ";
					P+=2;
					
				}
				
			cout<<"\n";
		
		}
		
		//cout<<"N^2: "<<N*N<<" P: "<<P<<" D: "<<D<<"\n \n \n \n";
		
	/*	
		int tot=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				tot+=sol[i]
				*/
		
	}
 
	
}