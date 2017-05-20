#include <iostream>
#include <algorithm>
using namespace std;

long long int seq[100050]={0};

long long int binsear(long long int value,long long int &size)
{
	long long int i,now=1,n=size/2;
	while(n>0)
	{
		if(n+now<=size&&value<seq[n+now])
			now+=n;
		else
			n/=2;
	}
	if(now==size&&value<seq[now])
		size++;
	if(value<seq[now])
		now++;
	seq[now]=value;
	return now;
}

void change(long long int *a,long long int size)
{
	long long int i,j=(size+1)/2;
	for(i=1;i<=j;i++)
		swap(a[i],a[size-i+1]);
	return;
}

int main()
{
	long long int i,Max,j,t,ssize,isize,dsize,s[100050]={0},inc[100050]={0},dec[100050]={0};
	cin>>t;
	while(t--)
	{
		ssize=0;isize=1;dsize=1;Max=0;
		cin>>ssize;
		for(i=1;i<=ssize;i++)
			cin>>s[i];
		seq[1]=s[ssize];
		inc[ssize]=1;
		for(i=ssize-1;i>0;i--)
			inc[i]=binsear(s[i],isize);
		change(s,ssize);
		seq[1]=s[ssize];
		dec[1]=1;
		for(i=ssize-1;i>0;i--)
			dec[ssize-i+1]=binsear(s[i],dsize);
		for(i=1;i<=ssize;i++)
		{
			if(inc[i]==1||dec[i]==1)
				continue;
			j=inc[i]+dec[i]-1;
			Max=max(Max,j);
		}
		cout<<Max<<endl;
	}
	return 0;
}