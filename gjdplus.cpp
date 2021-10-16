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
	lenc=max(lena,lenb);
	for(int i=0;i<lena;i++) a[lena-i]=x[i]-48;
	for(int i=0;i<lenb;i++) b[lenb-i]=y[i]-48;
	for(int i=1;i<=lenc;i++)
	{
		c[i]=a[i]+b[i]+jw;
		jw=c[i]/10;
		c[i]%=10;
	}
	if(jw) {
		lenc++;
		c[lenc]=jw;
	}
	while(c[lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>=1;i--) z=z+char(c[i]+48);
	cout<<z;
	return 0;
}


