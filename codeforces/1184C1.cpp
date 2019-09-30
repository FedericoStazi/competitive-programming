#include <iostream>
using namespace std;
 
int N,g;
int X[100],Y[100];
int maxX=-1e9,maxY=-1e9,minX=1e9,minY=1e9;
 
int main(){
	cin>>N;
	N=4*N+1;
	for(int i=0;i<N;i++){
		cin>>X[i]>>Y[i];
		maxX=max(maxX,X[i]);
		minX=min(minX,X[i]);
		maxY=max(maxY,Y[i]);
		minY=min(minY,Y[i]);
	}
 
	g=0;
	for(int i=0;i<N;i++)
		if(X[i]==maxX)
			g++;
	if(g==1){
		for(int i=0;i<N;i++)
			if(X[i]==maxX)
				cout<<X[i]<<" "<<Y[i];
		return 0;
	}
 
	g=0;
	for(int i=0;i<N;i++)
		if(X[i]==minX)
			g++;
	if(g==1){
		for(int i=0;i<N;i++)
			if(X[i]==minX)
				cout<<X[i]<<" "<<Y[i];
		return 0;
	}
 
	g=0;
	for(int i=0;i<N;i++)
		if(Y[i]==maxY)
			g++;
	if(g==1){
		for(int i=0;i<N;i++)
			if(Y[i]==maxY)
				cout<<X[i]<<" "<<Y[i];
		return 0;
	}
 
	g=0;
	for(int i=0;i<N;i++)
		if(Y[i]==minY)
			g++;
	if(g==1){
		for(int i=0;i<N;i++)
			if(Y[i]==minY)
				cout<<X[i]<<" "<<Y[i];
		return 0;
	}
 
	for(int i=0;i<N;i++)
		if(X[i]!=minX and X[i]!=maxX and Y[i]!=minY and Y[i]!=maxY)
			cout<<X[i]<<" "<<Y[i];
}