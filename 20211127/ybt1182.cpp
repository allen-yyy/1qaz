#include <iostream>
#include <cstdio>
using namespace std;
double a[40],b[40];
int main()
{
	int n=0,m=0;
	double t;
	char c[10];
	int r;
	cin>>r;
	for(int i=0;i<r;i++)
	{
		cin>>c>>t;
		if(c[0]=='m') a[n++]=t;
		else b[m++]=t;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(b[i]<b[j]) swap(b[i],b[j]);
		}
	}
	for(int i=0;i<n;i++) printf("%.2lf ",a[i]);
	for(int i=0;i<m;i++) printf("%.2lf ",b[i]);
	return 0;
}
