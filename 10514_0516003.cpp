#include <iostream>
#include <algorithm>
using namespace std;

int seq[100500]={0},result[200500]={0},end[1005000]={0};

int test(int step,int n,int size)
{
	int min,max,i=0,j=0,k=0,start=0,temp=0,find=1,premin,premax;
	while(i<n)
	{
		if(!j)
		{
			start=i;
			min=seq[i++];
			premin=min;
			j=1;
		}
		else if(!k)
		{
			max=seq[i++];
			premax=max;
			k=1;
			if(max<min)
			{
				swap(premax,premin);
				swap(max,min);
			}
		}
		else
		{
			if(seq[i]>max)
			{
				premax=max;
				max=seq[i];
			}
			if(seq[i]<min)
			{
				premin=min;
				min=seq[i];
			}
			i++;
		}
		if(j&&k&&(max-min+1)/2>step)
		{
			i--; 
			if(i!=start+1)
			{
				if(seq[i]==max)
					max=premax;
				else 
					min=premin;
				temp=(max+min)/2;
			}
			else
				temp=seq[i-1];
			for(j=start;j<i;j++)
				result[j]=temp;
			j=0; k=0;
			if(!(--size))
			{
				find=0;
				break;
			}
		}
	}
	if(find)
	{
		if(j&&(!k))
			max=min;
		temp=(max+min)/2;
		for(j=start;j<n;j++)
			result[j]=temp;
		size--;
		i=0; start=0; j=0;
		while(i<n)
		{
			start=i;
			while(i+1<n&&result[i]==result[i+1])
				i++;
			if(i>=n-1)
				break;
			while(size>0&&i-start>0)
			{
				end[j++]=start+1; end[j++]=start+1; end[j++]=result[i];
				size--; start++;
			}
			if(i-start>=0)
			{
				end[j++]=start+1; end[j++]=i+1; end[j++]=result[i];
			}
			i++;
		}
		while(size>0&&i-start>=0)
		{
			end[j++]=start+1; end[j++]=start+1; end[j++]=result[i];
			size--; start++;
		}
		if(end[j-2]<n)
		{
			end[j++]=start+1; end[j++]=n; end[j++]=result[i];
		}
	}
	return find;
}

int main()
{
	int step=2147483647/2,n,k,find=0,now=0,i;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>seq[i];
	while(step)
	{
		if(now+step<0)
		{
			step/=2;
			continue;
		}
		find=test(now+step,n,k);
		if(find)
			step/=2;
		else
			now+=step;
	}
	if(!now)
		test(0,n,k);
	for(i=0;end[i+1]!=n;i+=3)
	{
		cout<<end[i]<<" "<<end[i+1]<<" "<<end[i+2]<<endl;
	}
	cout<<end[i]<<" "<<end[i+1]<<" "<<end[i+2]<<endl;
	return 0;
}