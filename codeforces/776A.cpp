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
 
int N;
string A,B,C,D;
 
int main()
{
	
	cin>>A>>B;
	cin>>N;
	cout<<A<<" "<<B<<"\n";
	for(int i=0;i<N;i++)
	{
		
		cin>>C>>D;
		if(A==C)
			A=D;
		else
			B=D;
			
		cout<<A<<" "<<B<<"\n";
		
	}
	
}