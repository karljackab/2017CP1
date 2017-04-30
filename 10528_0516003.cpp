#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	long long int t,n,p,s,find,twocnt,fivecnt,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		p=1;	find=0;
		twocnt=0;fivecnt=0;
		while(n--)
		{
			cin>>s;
			p*=s;
			if(!find&&p>=10000)
				find=1;
			while(p&&find&&!(p%10))
				p/=10;
			while(find&&p&&!(p%2))
			{
				p/=2;
				twocnt++;
			}
			while(find&&p&&!(p%5))
			{
				p/=5;
				fivecnt++;
			}
			if(find&&p>10000)
				p%=10000;
		}
		i=twocnt-fivecnt;
		if(i>0)
			for(j=0;j<i;j++)
			{
				p*=2;
				if(p>10000)
					p%=10000;
			}
		else if(i<0)
		{
			i=abs(i);
			for(j=0;j<i;j++)
			{
				p*=5;
				if(p>10000)
					p%=10000;
			}
		}
		cout<<setw(4)<<setfill('0')<<p<<endl;
	}
	return 0;
}