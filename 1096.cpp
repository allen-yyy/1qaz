#include <iostream>
using namespace std;
int main()
{
	int i,l,a,j,r,s=0;
	cin>>l>>r;
	for(i=l;i<=r;++i)
	{
		a=i;
		do
		{
			j=a%10;
			a/=10;
			if(j==2) s++;
		}while(a!=0);
		
	}
	cout<<s;
	return 0;
}

