#include <iostream>
#include <cmath>
using namespace std;

int total=0,queen[10][2]={0};

void re()
{
	int i;
	for(i=0;i<=9;i++)
	{
		queen[i][0]=0; queen[i][1]=0;
	}
}

void run(int now)
{
	int i,j,k,c;
	if(now>9)
	{
		total++;
		return;
	}
	if(queen[now][0]!=0)
	{
		run(now+1);
		return;
	}
	for(i=1;i<=9;i++)
	{
		c=0;
		for(j=1;j<=9;j++)
		{
			if(queen[j][0]==0)
				continue;
			if(i==queen[j][1]||(abs(now-queen[j][0])==abs(i-queen[j][1])))
			{
				c=1;
				break;
			}
		}
		if(c)
			continue;
		queen[now][0]=now;
		queen[now][1]=i;
		run(now+1);
		queen[now][0]=0;
		queen[now][1]=0;
	}
}

int main()
{
	int n,i,a,b;
	cin>>n;
	for(;n>0;n--)
	{
		total=0;
		re();
		cin>>a>>b;
		queen[a][0]=a;
		queen[a][1]=b;
		run(1);
		cout<<total<<endl;
	}
}