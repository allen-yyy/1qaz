#include <cstdio>
using namespace std;
int main()
{
	int a,b,c,i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=2;i<=a;i++)
	{
		if((a%i==b%i) && (b%i==c%i))
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("%d\n",i);
	return 0;
}
