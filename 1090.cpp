#include <iostream>
using namespace std;
int main()
{
	int k,m,i,a,tmp;
	cin>>m>>k;
	a=m;
	if(m%19==0){
		while(a!=0)
		{
			tmp=a%10;
			if(tmp==3) i++;
			a/=10;
		}
		if(i==k){
			cout<<"YES";
			return 0;
		}
	}else{
		goto NO;
	}
	NO:
		cout<<"NO"<<endl;
	return 0;
}

