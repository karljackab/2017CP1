#include <iostream>
using namespace std;
int **record,*quest,top,down,equ; //record quest begin with 1

int qu(int index,int type,int m)
{
	//type 0down  1top  2bdown 3btop
	int step=m>>1,now=top;
	while(step)
	{
		if(now+step>=down)
		{
			step>>=1;
			continue;
		}
		if(type==1)
		{
			while(now+step<down&&record[now+step][0]>=index&&record[now+step][index]>quest[index])
				now+=step;
			step>>=1;
		}
		else if(!type)
		{
			while(now+step<down&&record[now+step][0]>=index&&record[now+step][index]>=quest[index])
				now+=step;
			step>>=1;
		}
		else if(type==2)
		{
			while(now+step<down&&(record[now+step][0]<index||(record[now+step][index]<=quest[index])))
				now+=step;
			step>>=1;
		}
		else
		{
			while(now+step<down&&(record[now+step][0]<index||(record[now+step][index]<quest[index])))
				now+=step;
			step>>=1;
		}
	}
	if(type==0||type==2)
	{
		now++;
		if(now-1>0&&index==quest[0]&&record[now-1][index]==quest[index])
		{
			now--;
			equ=1;
		}
	}
	return now;
}

void query(int m)
{
	int i,j,k;
	for(i=1;i<=quest[0];i++)
	{
		if(i%2)
		{
			down=qu(i,0,m);
			top=qu(i,1,m);
			if(top+1==down||top==down)
				break;
		}
		else
		{
			down=qu(i,2,m);
			top=qu(i,3,m);
			if(top+1==down||top==down)
				break;
		}
	}
	return;
}

int main()
{
	int t,n,m,q,i,j,k,r,presize=-1;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		record=new int*[m+2];
		for(i=1;i<=m;i++)
		{
			cin>>r;
			record[i]=new int[r+2];
			record[i][0]=r;
			for(k=1;k<=record[i][0];k++)
				cin>>record[i][k];
		}
		quest=new int[2]();
		for(i=0;i<q;i++)
		{
			top=0;down=m+1;equ=0;
			cin>>r;
			if(r+2>presize)
			{
				delete []quest;
				quest=new int[r+2]();
			}
			quest[0]=r;
			for(k=1;k<=quest[0];k++)
				cin>>quest[k];
			query(m);
			if(equ)
				cout<<down<<endl;
			else if(top==0)
				cout<<"<1"<<endl;
			else if(down>m)
				cout<<">"<<m<<endl;
			else
				cout<<top<<" "<<down<<endl;
		}
		delete []quest;
		for(i=1;i<=m;i++)
			delete []record[i];
		delete []record;
	}
	return 0;
}