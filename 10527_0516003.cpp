#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int f[31][50013];

int main()
{
	int t,i,j,k,x,n,q,now,l,count;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&q);
		for(i=1;i<=n;i++)
			scanf("%d",&f[0][i]);
		for(i=1;i<30;i++)
			for(l=1;l<=n;l++)
				f[i][l]=f[i-1][f[i-1][l]];
		for(i=0;i<q;i++)
		{
			scanf("%d %d",&k,&x);
			j=0;
			while(k)
			{
				if(k&1)
					x=f[j][x];
				k>>=1;
				j++;
			}
			printf("%d\n",x);
		}
	}
	return 0;
}