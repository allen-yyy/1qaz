#include <iostream>
using namespace std;
int main()
{
	int n,i;
	long long r=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		if(i%7!=0 && i/10!=7 && i%10!=7)
			r+=i*i;
	}
	cout<<r<<endl;
	return 0;
}

