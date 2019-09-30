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
 
int N,K;
string S;
int porte[1000006];
int curr=0;
bool flag;
 
int main()
{
 
	cin>>N>>K;
	cin>>S;
	
	for(char c='A';c<='Z';c++)
	{
	
		flag=true;
		for(int i=0;i<N and flag;i++)
		{
			
			if(S[i]==c)
			{
				
				flag=false;
				porte[i]++;
				
			}
			
		}
		
	}
	
	for(char c='A';c<='Z';c++)
	{
		
		flag=true;
		for(int i=N-1;i>=0 and flag;i--)
		{
			
			if(S[i]==c)
			{
				
				flag=false;
				porte[i+1]--;
				
			}
			
		}
		
	}
	
	flag=true;
	for(int i=0;i<=N;i++)
	{
 
		curr+=porte[i];
		if(curr>K)
			flag=false;
		
	}
	
	if(flag)
		cout<<"NO";
	else
		cout<<"YES";
		
	
}