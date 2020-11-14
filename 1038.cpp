#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
int n,x,y;

cin>>n>>x>>y;
n=n-ceil(y*1.0/x);
if(n<0) n=0;
cout<<n;
}
