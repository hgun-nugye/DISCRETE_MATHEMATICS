#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int main(){
	int n;
	long F[MAX];
	F[0]=0; F[1]=1;
	cin>>n;
	for(int i=2; i<=n; i++)
	{
		F[i]=F[i-1]+F[i-2];
	}
	cout<<F[n];
}