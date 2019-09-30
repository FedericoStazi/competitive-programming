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
 
char c;
int N;
int ciao,pizza;
bool cw,ccw;
 
int main()
{
	//caso n=0
	cin>>c;
	if(c=='v')
		ciao=0;
	if(c=='<')
		ciao=1;
	if(c=='^')
		ciao=2;
	if(c=='>')
		ciao=3;
	
	cin>>c;
	if(c=='v')
		pizza=0;
	if(c=='<')
		pizza=1;
	if(c=='^')
		pizza=2;
	if(c=='>')
		pizza=3;
		
	cin>>N;
	N=N%4;
	
	if((N+ciao)%4==pizza)
		cw=true;
	if((ciao-N+16)%4==pizza)
		ccw=true;
		
	if(cw and ccw)
		cout<<"undefined";
	else
	{
		
		if(cw)
			cout<<"cw";
		if(ccw)
			cout<<"ccw";
		
	}
	
	
}