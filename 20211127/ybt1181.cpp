#include <iostream>
using namespace std;
int a[10],b[10];
int main()
{
	int n=0,m=0;
	int t;
	for(int i=0;i<10;i++)
	{
		cin>>t;
		if(t%2) a[n++]=t;
		else b[m++]=t;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(b[i]>b[j]) swap(b[i],b[j]);
		}
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	for(int i=0;i<m;i++) cout<<b[i]<<" ";
	return 0;
}
