#include <cstdio>
using namespace std;
int main()
{
	int a,b,c,d,n,m,i,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&m);
		a=m/1000;
		b=m/100%10;
		c=m/10%10;
		d=m%10;
		if(d-a-b-c>0) s++;
	}
	printf("%d\n",s);
	return 0;
}
