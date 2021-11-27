#include <iostream>
using namespace std;
int t[26];
int main()
{
	string tmp;
	cin>>tmp;
	for(int i=0;i<tmp.size();i++)
	{
		t[tmp[i]-'a']++;
	}
	int max=0;
	char maxc='a';
	for(int i=0;i<26;i++)
	{
		if(t[i]>max)
		{
			max=t[i];
			maxc=char(i+'a');
		}
	}
	cout<<maxc<<" "<<max;
	return 0;
}
