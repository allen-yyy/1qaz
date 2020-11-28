#include <cstdio>
using namespace std;
int main()
{
	int i,n,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		s+=i;
	}
	printf("%d\n",s);
	return 0;
}
