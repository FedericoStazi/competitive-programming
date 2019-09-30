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
 
int A,B;
 
int main()
{
	
	int sol=1;
	cin>>A>>B;
	for(int i=2;i<=min(A,B);i++)
		sol*=i;
	cout<<sol;
 
}