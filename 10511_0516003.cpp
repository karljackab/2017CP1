#include <iostream>

using namespace std;
int main()
{
	int n,a[5],i,end=0,check[5];
	while(cin>>n)
	{
		if(n==0)
			break;
		for(i=0;i<5;i++)
			check[i]=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==i+1)
				check[i]=1;
		}
		end=1;
		for(i=0;i<n;i++)
			if(!check[a[i]-1])
			{
				end=0;
				break;
			}
		if(end)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}