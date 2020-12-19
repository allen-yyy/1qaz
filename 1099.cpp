#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i,n,s=0;
	cin>>n;
	for(i=2;;++i)
	{
		int x;
		x=2;
		while(x<=floor(sqrt(i))&&i%x!=0)     x+=1;
		if(x>floor(sqrt(i)))
		{
			s++;
			if(s==n)
			{
				cout<<i; 
				break;
			}
		}
	}
	return 0;
}

