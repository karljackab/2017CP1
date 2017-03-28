#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned long long int calc(unsigned long long int n)
{
	unsigned long long int i,a=1;
	for(i=2;i<=n;i++)
		a*=i;
	return a;
}

int main()
{
	unsigned long long int asize,bsize,now,b=0,n,i,j,c,d;
	cin>>n;
	while(n--)
	{
		vector<int> order;
		cin>>asize>>bsize;
		for(i=0;i<=asize;i++)
			order.push_back(i);
		b=bsize-1;
		for(i=1;b&&i<=asize;i++)
		{
			if(asize-i>20)
				continue;
			c=calc(asize-i);
			for(j=asize;j>i;j--)
			{
				if(asize-i==20&&j-i>7)
					continue;
				now=(j-i)*c;
				if(b>=now)
				{
					b-=now;
					for(int k=j-1;k>=i;k--)
						swap(order[k],order[k+1]);
					break;
				}
			}
		} 
		cout<<"(";
		for(i=1;i<asize;i++)
			cout<<order[i]<<",";
		cout<<order[i]<<")"<<endl;
	}
	return 0;
}