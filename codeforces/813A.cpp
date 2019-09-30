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
 
int N,M,x,y,tot=0;
bool flag = true;
 
int main()
{
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		
		cin>>x;
		tot+=x;
		
	}
	cin>>M;
	for(int i=0;i<M and flag;i++)
	{
		
		cin>>x>>y;
		if(tot<x)
		{
			
			flag=false;
			cout<<x;
			
		}
		else if(tot<=y)
		{
			
			cout<<tot;
			flag=false;
			
		}
		
	}
	
	if(flag)
		cout<<-1;
	
}