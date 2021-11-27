#include <iostream>
using namespace std;
int t[10000];
int main()
{
	int n;
	cin>>n;
	int m,r=0;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		if(t[m]==0) r++;
		t[m]++;
	}
	cout<<r<<endl;
	for(int i=0;i<10000;i++)
		if(t[i]) cout<<i<<" ";
	return 0;
}
