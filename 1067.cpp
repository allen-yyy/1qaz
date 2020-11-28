#include<iostream>
using namespace std;
int main()
{
	int n,number;
	int sum_1=0,sum_5=0,sum_10=0;
	int i;
 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>number;
		if(number==1)	sum_1++;
		if(number==5)	sum_5++;
		if(number==10)	sum_10++;
	}
	cout<<sum_1<<endl;
	cout<<sum_5<<endl;
	cout<<sum_10<<endl;
        return 0;
}
