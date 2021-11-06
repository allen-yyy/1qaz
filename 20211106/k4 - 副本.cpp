#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[10000002],jw,c[1000000],b[1000];
string times(int a[],int b[],int lena,int lenb)
{
	memset(c,0,1000000);
	for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lenb;j++)
		{
			c[i+j-1]+=a[i]*b[j]+jw;
			jw=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lenb]=jw;
	}
	int lenc=lena+lenb;
	while(c[lenc]==0&&lenc>1) lenc--;
	string z="";
	for(int i=lenc;i>=1;i--) z+=char(c[i]+48);
	return z;
}
int bits(int n)
{
	int i=0;
	if(n==0) return 1;
	while(n!=0)
	{
		n/=10;
		i++;
	}
	return i;
}
void n2bit(string k,int a[])
{
	for(int i=1;i<=k.size();i++) a[i]=k[k.size()-i]-'0';
}
int main()
{
	int n;
	string k;
	cin>>k>>n;
	int nowbits=1,size=1,size1=k.size();
	string z="";
	a[1]=1;
	n2bit(k,b);
	for(int i=0;i<n;i++)
	{
		z=times(a,b,size,size1);
		size=z.size();
		n2bit(z,a);
	}
	cout<<z;
	return 0;
}

