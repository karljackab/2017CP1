#include <iomanip>
#include <iostream>
using namespace std;
#define big 1000000000000000000

unsigned long long int num[100][10002]={0};

int main()
{
	int i,j,t,n,k,l;
	for(i=1;i<=10000;i++)
	{
		num[0][i]++;
		for(j=i;j<=10000;j++)
		{
			for(k=0;num[k][j]||num[k][j-i];k++)
			{

				num[k][j]+=num[k][j-i];
				for(l=k;num[l][j]>=big;l++)
				{
					num[l+1][j]+=num[l][j]/big;
					num[l][j]%=big;
				}
			}
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;num[i][n];i++);
		i--;
		cout<<num[i--][n];
		for(;i>=0;i--)
			cout<<setw(18)<<setfill('0')<<num[i][n];
		cout<<endl;
	}
	return 0;
}