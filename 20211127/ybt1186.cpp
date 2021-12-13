#include <iostream>
#include <cmath>
using namespace std;
int t[101];
int main()
{
	int n,tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		tmp+=50;
		t[tmp]++;
	}
	for(int i=0;i<101;i++)
	{
		if(t[i]>=ceil(n/2))
		{
			cout<<i-50;
			return 0;
		}
	}
	cout<<"no";
	return 0;
}
