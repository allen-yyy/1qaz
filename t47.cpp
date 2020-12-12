#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n=0,k;
	float s; 
	cin>>k;
	//if(k==1) {
	//	cout<<1;
	//	return 0;
	//}
	while(s<k){
		n++;
		s=s+1.0/n;	
	}
	cout<<n; 
	return 0;
}

