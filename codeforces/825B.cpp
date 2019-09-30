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
#include <list>
#include <map>
using namespace std;
 
//ifstream in("input.txt");
//ofstream out("output.txt");
 
//io uso X
char M[10][10];
 
int main()
{
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cin>>M[i][j];
	
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			
			bool flag=false;
		
			if(M[i][j]=='.')
			{
				
				M[i][j]='X';
				flag=true;
				
			}
				
 
				
			for(int x=0;x<10;x++)
				for(int y=0;y<6;y++)
					if(M[x][y]=='X' and M[x][y+1]=='X' and M[x][y+2]=='X' and M[x][y+3]=='X' and M[x][y+4]=='X')
					{
						
						cout<<"YES";
						return 0;
						
					}
		
			for(int x=0;x<10;x++)
				for(int y=0;y<6;y++)
					if(M[y][x]=='X' and M[y+1][x]=='X' and M[y+2][x]=='X' and M[y+3][x]=='X' and M[y+4][x]=='X')
					{
						
						cout<<"YES";
						return 0;
						
					}
			for(int x=0;x<6;x++)
				for(int y=0;y<6;y++)
					if(M[9-x][y]=='X' and M[8-x][y+1]=='X' and M[7-x][y+2]=='X' and M[6-x][y+3]=='X' and M[5-x][y+4]=='X')
					{
						
						cout<<"YES";
						return 0;
						
					}
		
			for(int x=0;x<6;x++)
				for(int y=0;y<6;y++)
					if(M[y][x]=='X' and M[y+1][x+1]=='X' and M[y+2][x+2]=='X' and M[y+3][x+3]=='X' and M[y+4][x+4]=='X')
					{
						
						cout<<"YES";
						return 0;
						
					}
		
		if(flag)
			M[i][j]='.';
		
		}
	
	cout<<"NO";
	
}
 
 