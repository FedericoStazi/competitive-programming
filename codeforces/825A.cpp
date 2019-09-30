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
 
int N,K=0;
char x;
 
int main()
{
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		
		cin>>x;
		if(x=='1')
			K++;
		else
		{
			
			cout<<K;
			K=0;
			
		}		
		
	}
	cout<<K;
	
}