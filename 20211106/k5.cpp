#include <iostream>
#include <string>
using namespace std;
string x;
int a[10086];
int divy(int a[],int n,int len)
{
	int res=0,i=0;
	while(i<len)
	{
		res*=10;
		res+=a[i];
		res%=n;
		i++;		
	}
	return res;
}
int main()
{
	cin>>x;
	int flag=0;
	for(int i=0;i<x.size();i++) a[i]=x[i]-48;
	for(int i=2;i<=100;i++)
	{
		if(!divy(a,i,x.size()))
		{
			flag=1;
			cout<<i<<" ";
		}
	}
	if(flag==0) cout<<"none";
	return 0;
}

