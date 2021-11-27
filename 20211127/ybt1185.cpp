#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a[100];
	string t;
	int n=0;
	while(cin>>t)
	{
		a[n]=t;
		n++;
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=i+1;j<n+1;j++)
		{
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=0;i<n+1;i++)
	{
		if(i!=0&&a[i-1].compare(a[i])==0) goto next;
		cout<<a[i]<<endl;
		next:
		i+1;
	}
	return 0;
}
