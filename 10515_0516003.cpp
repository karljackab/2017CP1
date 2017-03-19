#include <iostream>

using namespace std;
int size;


void run(int *a,int *b,int *c,int count)
{
	int i,j,k,*fl,*gl,*fh,*gh,*ll,*hh,*temp,lsize,hsize,hbase,cbase,larg;
	if(count<40)
		for(i=0;i<count;i++)
			for(j=0;j<count;j++)
				c[i+j]+=a[i]*b[j];
	else
	{
		lsize=count/2;hsize=count-lsize;
		larg=(hsize+1)*2+1;
		hbase=lsize*2;	cbase=lsize;
		temp=new int[larg]();
		ll=new int[larg]();
		hh=new int[larg]();
		fl=new int[lsize+2](); gl=new int[lsize+2]();
		fh=new int[hsize+2](); gh=new int[hsize+2]();
		for(i=0;i<lsize;i++)
		{
			fl[i]=a[i];
			gl[i]=b[i];
		}
		run(fl,gl,ll,lsize);
		for(j=0;i<count;i++,j++)
		{
			fh[j]=a[i];
			gh[j]=b[i];
		}
		run(fh,gh,hh,hsize);
		for(i=0;i<lsize;i++)
		{
			fh[i]+=fl[i];
			gh[i]+=gl[i];
		}
		run(fh,gh,temp,hsize);
		for(i=0;i<larg;i++)
		{
			c[i]+=ll[i];
			c[i+hbase]+=hh[i];
			c[i+cbase]+=temp[i]-ll[i]-hh[i];
		}
		delete []temp;delete []ll;delete []hh;delete []fl;delete []fh; delete []gl;delete []gh;
	}
}

int main()
{
	int n,a[32770],b[32770],i,endsize,result[66000]={0};
	cin>>n;
	for(;n>0;n--)
	{
		cin>>size;
		for(i=0;i<size;i++)
			cin>>a[i];
		for(i=0;i<size;i++)
			cin>>b[i];
		endsize=size*2-1;
		run(a,b,result,size);
		for(i=0;i<endsize;i++)
		{
			cout<<result[i]<<" ";
			result[i]=0;
		}
		cout<<endl;
	}
	return 0;
}