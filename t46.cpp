#include <iostream>
using namespace std;
int main()
{
	int m,n,s,r=1;//s�����ۼӵı���,r�ǽ�� 
	cin>>m>>n;
	for(s=2;s<=m&&s<=n;s++)
	{
		if(m%s==0&&n%s==0){
			r=s;	
		}
			
	} 
	END:
		cout<<r;
	return 0;
}

