#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b;
	for(int i;i<=a;i++)
	{
		cin>>c;
		if(c==b) d++;
	}
	cout<<d;
        return 0;
}
