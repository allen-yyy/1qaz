#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
typedef struct abcx{
	string id;
	int old;
	int no;
}ren;
ren a[10000],b[10000];
int main()
{
	int n=0,m=0;
	double t;
	string c;
	int r;
	cin>>r;
	for(int i=0;i<r;i++)
	{
		cin>>c>>t;
		if(t>=60)
		{
			a[n].old=t;
			a[n].id=c;
			a[n].no=i;
			n++;
		}else
		{
			b[m].old=t;
			b[m].id=c;
			b[m].no=i;
			m++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].old<a[j].old) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(b[i].no>b[j].no) swap(b[i],b[j]);
		}
	}
	for(int i=0;i<n;i++) cout<<a[i].id<<endl;
	for(int i=0;i<m;i++) cout<<b[i].id<<endl;
	return 0;
}
