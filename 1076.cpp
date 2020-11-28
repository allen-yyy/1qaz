#include<cstdio>
using namespace std;
int main()
{
	int a,b,i,n,t,m,j,max=0;
	
	scanf("%d",&n); t=0;

	for(i=1; i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		if(a>=90&&a<=140&&b>=60&&b<=90)
		{
			t++;
			if(t>max) max=t;
		}else{
			t=0;
		}
	}
	printf("%d\n",max);
	return 0;
}
