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
 
int N,A[50][50];
bool flag;
 
int main()
{
	
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
		
			cin>>A[i][j];
		
		}
			
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		if(A[i][j]!=1)
		{
			
			flag=false;
			for(int k=0;k<N;k++)
				if(k!=i)
				{
					
					for(int h=0;h<N;h++)
						if(h!=j)
							if(A[i][h]+A[k][j]==A[i][j])
								flag=true;
							
						
					
				}		
				
			if(!flag)
				{
						
					cout<<"No";
					return 0;
						
				}
					
			
		}	
		
		cout<<"Yes";
				
}