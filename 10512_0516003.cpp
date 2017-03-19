#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n,i;
	long long int count=1,total=0,a[100050]={0};
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]+=a[i-1];
			if(!a[i])
				total++;
		}
		sort(a+1,a+n+1);
		count=1;
		for(i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
				count++;
			else
			{
				total+=count*(count-1)/2;
				count=1;
			}
		}
		if(a[n]==a[n-1]&&n!=1)
			total+=count*(count-1)/2;
		cout<<total<<endl;
		total=0;
	}
	return 0;
}
