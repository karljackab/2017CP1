#include <iostream>
#include <vector>
#include <cstdio>

#define modu 1000000007

long long int calc(long long int a,long long int b,char c)
{
	long long int d;
	if(c=='+')
		d=a+b;
	else
		d=a*b;
	return d%modu;
}

using namespace std;
int main()
{
	vector<char> op;
	vector<long long int> nu;
	char c;
	long long int a,b;
	int i;
	while(cin.peek()!=EOF)
	{
		op.clear();
		nu.clear();
		while(cin.peek()!='\n'&&cin.peek()!=EOF)
		{
			cin.get(c);
			if(c-'0'>=0&&c-'0'<=9)
				nu.push_back(c-'0');
			else
			{
				if(c=='+'&&op.size()!=0)
				{
					if(op.back()=='*')
						while(!op.empty())
						{
							if(op.back()=='(')
								break;
							a=nu.back();nu.pop_back();
							b=nu.back();nu.pop_back();
							nu.push_back(calc(a,b,op.back()));
							op.pop_back();
						}
				}
				else if(c==')')
				{
					while(op.back()!='(')
					{
						a=nu.back();nu.pop_back();
						b=nu.back();nu.pop_back();
						nu.push_back(calc(a,b,op.back()));
						op.pop_back();
					}
					if(op.back()=='(')
						op.pop_back();
				}
				if(c!=')')
					op.push_back(c);
			}
		}
		while(!op.empty())
		{
			a=nu.back();nu.pop_back();
			b=nu.back();nu.pop_back();
			nu.push_back(calc(a,b,op.back()));
			op.pop_back();
		}
		cout<<nu.at(0)<<endl;
		if(cin.peek()=='\n')
			cin.get(c);
	}
	return 0;
}