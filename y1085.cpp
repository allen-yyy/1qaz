#include <cstdio>
using namespace std;
int main()
{
	double h; int i=1;
	scanf("%lf",&h);
	double s=h;
	while(i<=9)
	{
		h/=2;
		s+=h*2;
		++i;
	}
	printf("%g\n%g\n",s,h/2);
	return 0;
}

