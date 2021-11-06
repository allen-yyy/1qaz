#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[10000002],jw,c[1000000],b[1000];
int main()
{
	int n;
	int k;
	cin>>k>>n;
	int nowbits=1;
	a[1]=1;
	for(int i=0;i<n;i++)
	{
		int j=0;
		for(j=1;j<=nowbits;j++) a[j]*=k;
		for(j=1;j<=nowbits;j++)
		{
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		if(a[j])
		{
			while(a[j]>9)
			{
				a[j+1]+=a[j]/10;
				a[j]%=10;
				j++;
			}
			nowbits=j;
		}
	}
	for(int i=nowbits;i>=1;i--) cout<<a[i];
	return 0;
}

