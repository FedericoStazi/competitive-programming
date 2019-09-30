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
 
int N,Q,C,x,y,z;
int t,x1,x2,y_1,y2;
int sum[105][105][11];
int sky[105][105][11];
 
int main()
{
	
	cin>>N>>Q>>C;
	/*
	for(int a=0;a<105;a++)
		for(int b=0;b<105;b++)
			for(int c=0;c<11;c++)
			{
				
				sum[a][b][c]=0;
				sky[a][b][c]=0;
				
			}
	*/
	for(int i=0;i<N;i++)
	{
		
		cin>>x>>y>>z;
		for(int j=0;j<=C;j++)
			sky[x][y][j]+=(z+j)%(C+1);		
		
	}
	
	
	
	for(int c=0;c<=C;c++)
	{
		
		sum[0][0][c]=sky[0][0][c];
		for(int i=1;i<105;i++)
			sum[0][i][c]=sum[0][i-1][c]+sky[0][i][c];
		for(int i=1;i<105;i++)	
			sum[i][0][c]=sum[i-1][0][c]+sky[i][0][c];
	
		for(int i=1;i<105;i++)
			for(int j=1;j<105;j++)
				sum[i][j][c]=sum[i][j-1][c]+sum[i-1][j][c]+sky[i][j][c]-sum[i-1][j-1][c];		
		
	}
	/*
	for(int c=0;c<=C;c++)
	{
		cout<<"C: "<<c<<"\n";
		for(int i=0;i<10;i++)
		{
			
			for(int j=0;j<10;j++)
				cout<<sky[i][j][c]<<" ";
			cout<<"\n";
			
		}
		
		cout<<"\n";		
		
	}		
	cout<<"\n\n";
	for(int c=0;c<=C;c++)
	{
		cout<<"C: "<<c<<"\n";
		for(int i=0;i<10;i++)
		{
			
			for(int j=0;j<10;j++)
				cout<<sum[i][j][c]<<" ";
			cout<<"\n";
			
		}
		
		cout<<"\n";		
		
	}
	*/
	for(int i=0;i<Q;i++)
	{
		
		cin>>t>>x1>>y_1>>x2>>y2;
		x1--;
		y_1--;
		cout<<(sum[x1][y_1][t%(C+1)]-sum[x1][y2][t%(C+1)]-sum[x2][y_1][t%(C+1)]+sum[x2][y2][t%(C+1)])<<"\n";
		//cout<<sum[x1][y_1][t%(C+1)]<<" "<<sum[x1][y2][t%(C+1)]<<" "<<sum[x2][y_1][t%(C+1)]<<" "<<sum[x2][y2][t%(C+1)]<<"\n";
		
	}
	
}
 