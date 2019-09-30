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
 
int S,V1,V2,T1,T2;
 
int main()
{
	
	cin>>S>>V1>>V2>>T1>>T2;
	
	if(S*V1+2*T1<S*V2+2*T2)
		cout<<"First";
	else if (S*V1+2*T1>S*V2+2*T2)
		cout<<"Second";
	else
		cout<<"Friendship";
	
}