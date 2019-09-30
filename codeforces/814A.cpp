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
 
int A[105],B[105];
int N,K;
 
int main()
{
	
	cin>>N>>K;
	for(int i=0;i<N;i++)	
		cin>>A[i];
	for(int i=0;i<K;i++)
		cin>>B[i];
	
	sort(B,B+N);
	
	int j=N-1;
	for(int i=0;i<N;i++)
		if(A[i]==0)
		{
			
			A[i]=B[j];
			j--;		
			
		}
	
	bool flag=true;	
	for(int i=0;i<N-1;i++)
	{
	
		if(A[i]>A[i+1])
			flag=false;	
	
	}
	
	if(!flag)
		cout<<"Yes";
	else
		cout<<"No";
	
}
 