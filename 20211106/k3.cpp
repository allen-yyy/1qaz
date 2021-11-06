#include <iostream>
#include <string>
using namespace std;
string x,y,z;
int a[10000],b[10000],c[20000],lena,lenb,lenc;
int jw;
int main()
{
	cin>>x>>y;
	lena=x.size();
	lenb=y.size();
	for(int i=1;i<=lena;i++) a[i]=x[lena-i]-'0';
	for(int i=1;i<=lenb;i++) b[i]=y[lenb-i]-'0';
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
	lenc=lena+lenb;
	while(c[lenc]==0&&lenc>1) lenc--;
	z="";
	for(int i=lenc;i>=1;i--) z+=char(c[i]+48); 
	cout<<z;
	return 0;
}

