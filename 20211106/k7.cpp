#include <iostream>
#include <string>
using namespace std;
int a[10000],b[10000];
string x;
int divy(int a[],int b[],int n,int len,int& x)
{
	int res=0,i=0;
	while(i<len)
	{
		res*=10;
		res+=a[i];
		b[i]=res/n;
		res%=n;
		i++;		
	}
	x=i;
	return res;
}
int main()
{
	cin>>x;
	int lena=x.size();
	for(int i=0;i<lena;i++) a[i]=x[i]-'0';
	int o=0,ip=0;
	int res=divy(a,b,13,lena,o);
	while(b[ip]==0) ip++; 
	for(int i=ip;i<o;i++) cout<<b[i];
	cout<<endl<<res;
	return 0;
}

