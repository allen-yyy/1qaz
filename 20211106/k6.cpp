#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[10000002],jw,c[1000000],b[1000],tmp[2];
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
string plus1(int a[],int b[],int lena,int lenb)
{
	memset(c,0,1000000);
	int lenc=max(lena,lenb);
	jw=0;
	for(int i=1;i<=lenc;i++)
	{
		c[i]=a[i]+b[i]+jw;
		jw=c[i]/10;
		c[i]%=10;
	}
	if(jw)
	{
		lenc++;
		c[lenc]=jw;
	}
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
	cin>>n;
	int nowbits=1,size=1,size2=1;
	string z="";
	string zzz="";
	a[1]=1;
	b[1]=1;
	tmp[1]=1;
	for(int i=0;i<n-1;i++)
	{
		zzz=plus1(b,tmp,size2,1);
		size2=zzz.size();
		n2bit(zzz,b);
		z=times(a,b,size,size2);
		size=z.size();
		n2bit(z,a);
	}
	cout<<z;
	return 0;
}

