#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a,b=0;
	cin>>a;
	if(a<0) cout<<"-"; a=abs(a);
	if(a==0){
		cout<<"0";return 0;	
	} 
	
	while(a!=0)
	{
		b=b*10+a%10;
		a=a/10;
	}
	cout<<b;
	return 0;
}

