#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	double M;
	double ls; 
	cin>>n>>M>>ls;
	
	double m;
	m=M*pow((1+ls/100/12),n);
	cout<<fixed << setprecision(6)<<m;
	
}