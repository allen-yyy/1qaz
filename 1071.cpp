#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,k,s;
	scanf("%d",&k);
	a=1;b=1;
	for(int i=3; i<=k;++i)
	{
		c=a+b;a=b;b=c;
	}
	printf("%d\n",b);
	return 0;
}
