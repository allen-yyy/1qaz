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
	while(x[0]=='0')
	{
		x.erase(0,1);
		lena--;
	}
	while(y[0]=='0')
	{
		y.erase(0,1);
		lenb--;
	}
	if(lena<lenb||(lena==lenb&&x<y)){
		swap(lena,lenb);
		cout<<"-";
		swap(x,y);
	}
	for(int i=1;i<=lena;i++) a[i]=x[lena-i]-'0';
	for(int i=1;i<=lenb;i++) b[i]=y[lenb-i]-'0';
	lenc=max(lena,lenb);
	for(int i=1;i<=lenc;i++)
	{
		if(a[i]<b[i]){ a[i]+=10; a[i+1]--;}
		c[i]=a[i]-b[i];
	}
	while(c[lenc]==0&&lenc>1) lenc--;
	z="";
	for(int i=lenc;i>=1;i--) z+=char(c[i]+48); 
	cout<<z;
	return 0;
}

