#include<bits/stdc++.h>
using namespace std;
long Co(int n)
{
	if(n==0) return 1;
	else return 2*Co(n-1);
}


int main(){
	int n;
	cin>>n;
	cout<<Co(n);
}