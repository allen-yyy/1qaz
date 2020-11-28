#include <cstdio>
using namespace std;
int main()
{
	int n; double s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		if(i%2==0) s-=1.0/i;
		else s+=1.0/i;
	}
	printf("%.4f\n",s);
	return 0;
}
