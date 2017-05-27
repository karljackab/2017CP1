#include <iostream>
#include <cstring>
using namespace std;
int w[20],v[20],l[20];
long long int cp[100010],temp;


int main()
{
	int i,j,k,t,n,W,num;
	cin>>t;
	while(t--)
	{
		cin>>n>>W;
		for(i=0;i<n;i++)
			cin>>w[i]>>v[i]>>l[i];
		memset(cp,0,sizeof(cp));
		for(i=0;i<n;i++)
		{
			num=W/w[i];
			if(l[i]<num)
				num=l[i];
			for(j=1;num>0;j*=2)
			{
				if(j>num)
					j=num;
				num-=j;
				for(k=W;k>=w[i]*j;k--)
				{
					temp=cp[k-w[i]*j]+v[i]*j;
					if(cp[k]<temp)
						cp[k]=temp;
				}
			}
		}
		cout<<cp[W]<<endl;
	}
	return 0;
}