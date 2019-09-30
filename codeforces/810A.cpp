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
 
 
double N,K,sol=0,T=0,x,avg;
 
int main()
{
	
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		cin>>x;
		avg+=x;
	}
	
	while(avg/(N+sol)<K-0.5)
	{
		
		//cout<<sol<<" "<<avg<<"\n";
		sol++;
		avg+=K;
		
	}
	
	cout<<sol;
		
}