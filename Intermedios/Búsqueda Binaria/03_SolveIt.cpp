/*
Author:		Jesús Kaimorts Díaz Medina
Date:		August 23th, 2018.
Problem:	Solve it
Judge:		UVa Judge
Topic:		Binary Search
URL: 		https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#define ERROR 1e-9
#define D double

using namespace std;

int p,q,r,s,t,u;
D minCOTA, maxCOTA, middle, y;

D f(D x){
	return (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u;
}

D binarySearch(){
	minCOTA = 0.0;
	maxCOTA = 1.0;
	for(int j=0; j<50; j++){
		middle = (minCOTA + maxCOTA)/2;
		y = f(middle);
		if(y > 0) 
			minCOTA = middle;
		else
			maxCOTA = middle;
	}
	return minCOTA;
}

int main(){
	while(cin >> p >> q >> r >> s >> t >> u){
		D worseCase = p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u;
		if( worseCase > ERROR || p+r+u<0){
			cout << "No solution\n";
			continue;
		}
		
		cout << fixed << showpoint;
		cout << setprecision(4);
		cout << binarySearch() << "\n";
	}
	return 0;
}