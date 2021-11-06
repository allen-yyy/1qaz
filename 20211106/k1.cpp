#include <iostream>
#include <string>
using namespace std;
string x,y,z;
int a[10000],b[10000],c[10000],lena,lenb,lenc;
int jw;
int main()
{
	cin>>x>>y;
	lena=x.size();
	lenb=y.size();
	for(int i=1;i<=lena;i++) a[i]=x[lena-i]-'0';
	for(int i=1;i<=lenb;i++) b[i]=y[lenb-i]-'0';
	lenc=max(lena,lenb);
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
	z="";
	for(int i=lenc;i>=1;i--) z+=char(c[i]+48); 
	cout<<z;
	return 0;
}
