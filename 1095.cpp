#include <iostream>
using namespace std;
int main()
{
	int i,a,s=1,n,j;
	cin>>n;
	for(i=2;i<=n;++i)
	{
		a=i;
		do{
			j=a%10;
			a/=10;
			if(j==1)  s++;
		}while(a!=0);
	 } 
	 cout<<s;
	return 0;
}

