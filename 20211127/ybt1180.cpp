#include <iostream>
using namespace std;
typedef struct{
	int no;
	int cj;
}ren;
ren a[1000],b[1000];
int main()
{
	int n,m;
	cin>>n>>m;
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		a[i].no=tmp;
		cin>>tmp;
		a[i].cj=tmp;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].cj<a[j].cj) swap(a[i],a[j]);
			if(a[i].cj==a[j].cj&&a[i].no>a[j].no) swap(a[i],a[j]);
		}
	}
	int ming=double(m*1.5);
	int lqfs=a[ming].cj;
	int rs=0;
	cout<<lqfs<<" ";
	for(int i=0;i<n;i++)
	{
		if(a[i].cj>=lqfs)
		{
			rs++;
		}
	}
	cout<<rs<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].cj>=lqfs)
		{
			cout<<a[i].no<<" ";
			cout<<a[i].cj<<endl;
		}
	}
	return 0;
}
