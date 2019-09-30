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
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int N,B[1005],A[1005];    //XD
 
int main()
{
 
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>B[i]>>A[i];
		
	for(int i=0;i<N;i++)
		if(A[i]!=B[i])
		{
			
			cout<<"rated";
			return 0;
			
		}
	
	for(int i=0;i<N-1;i++)
		if(A[i]<A[i+1])
		{
			
			cout<<"unrated";
			return 0;
			
		}
 
	cout<<"maybe";
 
 
}