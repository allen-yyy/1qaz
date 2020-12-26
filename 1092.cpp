#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b,n;
	double e=1;
	cin>>n;
	for(a=1;a<=n;a++)
	{
		    b*=a;
			e+=1.0/b;
		
	}
	printf("%.10lf",e);
	return 0;
}

