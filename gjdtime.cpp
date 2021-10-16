#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[205],b[205],c[205],lena,lenb,lenc,jw,j;
string x,y,z;
int main()
{
	cin>>x>>y;
	lena=x.size();
	lenb=y.size();
	for(int i=0;i<lena;i++) a[lena-i]=x[i]-48;
	for(int i=0;i<lenb;i++) b[lenb-i]=y[i]-48;
	for(int i=1;i<=lena;i++)
	{
		jw=0;
		for(j=1;j<=lenb;j++)
		{
			c[i+j-1]+=a[i]*b[j]+jw;
			jw=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lenb]=jw;
	}
	lenc=lena+lenb;
	while(c[lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>=1;i--) z=z+char(c[i]+48);
	cout<<z;
	return 0;
}


