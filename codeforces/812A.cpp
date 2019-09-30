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
 
char A[4][4];
bool sol=true;
 
int main()
{
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>A[i][j];
	
	for(int i=0;i<4;i++)
	if(A[i][3]=='1')
	{
		
		for(int j=0;j<3;j++)
			if(A[i][j]=='1')
				sol=false;
				
		for(int j=0;j<4;j++)
			if(j!=i)
				if(A[j][(j-i-1+16)%4]=='1')
					sol=false;
 
	}
		
	if(!sol)cout<<"YES";
	else cout<<"NO";	
	
 
}