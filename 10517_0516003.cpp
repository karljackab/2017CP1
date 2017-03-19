#include <iostream>
using namespace std;
long long int total=0;

int* run(int *a,int leng)
{
	int i,j,now,*b,*z,leng2=leng/2,leng3=leng-leng2;
	b=new int[leng];z=a+leng2;
	if(leng2>1)
		a=run(a,leng2);
	if(leng3>1)
		z=run(z,leng3);
	now=0;i=0;j=0;
	while(i<leng2&&j<leng3)
	{
		if(a[i]<=z[j])
		{
			b[now]=a[i];
			i++;now++;
		}
		else if(a[i]>z[j])
		{
			b[now]=z[j];
			j++;now++;total+=leng2-i;
		}
	}
	while(i<leng2)
	{
		b[now]=a[i];now++;i++;
	}
	while(j<leng3)
	{
		b[now]=z[j];now++;j++;
	}
	return b;
}

int main()
{
	int m,n,i,j,*a;
	cin>>m;
	while(m--)
	{
		cin>>n;
		a=new int[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		a=run(a,n);
		cout<<total<<endl;
		delete []a;
		total=0;
	}
	return 0;
}