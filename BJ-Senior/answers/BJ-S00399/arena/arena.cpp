#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int aa[1000005][260];
int c[1000005];
int k;
bool d[10000][10000];
unsigned int x[10000][4];
int lg2(int s)
{
	int i;
	for(;s>1;s/=2){i++;}
	return i;
}
int it(double y)
{
	int v=y;
	return v;
}
string change_num(int x)
{
	string p;int ans;
	for(int i=pow(2,lg2(x));i>=1;i/=2)
	{
		if((x%i)/(i/2)==1)p+='1';
		else p+='0';
	}
	return p;
	//for(int i=it(pow(10,p.size()));i>=0;i--)ans+=it(pow(10,i));
	//return ans;
}
int circle_add(int x,int y)
{
	string p,q,ans;
	for(int i=pow(2,lg2(x));i>=1;i/=2)
	{
		if((x%i)/(i/2)==1)p+='1';
		else p+='0';
	}
	for(int i=pow(2,lg2(y));i>=1;i/=2)
	{
		if((y%i)/(i/2)==1)q+='1';
		else q+='0';
	}
	int tmp=max(p.size(),q.size());
	for(int i=0,j=0;i<tmp-p.size(),j<tmp-q.size();i++,j++)
	{
		if(p[i]==1||q[i]==1)ans[i]=0;
		else ans[i]=1;
	}
	int r=0;
	for(int i=ans.size()-1;i>=0;i++)r+=pow(2,i);
	return r;
}
void f(int p)
{
	int win[10000],top=0,ans;
	for(int i=0;i<it(pow(2,lg2(n)));i++)
	{
		for(int j=0;j<lg2(n);j++)
		{
			if(i>n)
			{
				win[top]=i;
				top++;
			}
			else
			{
				bool h=1;
				for(int k=0;k<lg2(n);k++)
				{
					if(change_num(i)[k]!=d[j][i/pow(2,j)])
					{
						h=0;
						k=lg2(n);
					}
				}
				if(h)
				{
					win[top]=i;
					top++;
				}
			}
		}
	}
	ans=win[0];
	for(int i=0;i<top;i++)ans=circle_add(win[i]*i,ans);
	ofstream fout("arena.out",ios::out);
	fout<<ans<<endl;
	fout.close();
}
int main(){
	ifstream fin("arena.in",ios::in);
	fin>>n>>m;
	for(int i=0;i<n;i++)fin>>a[i][0];
	for(int i=0;i<m;i++)fin>>c[i];
	k=lg2(n);
	for(int i=0;i<k;i++)
	for(int j=0;j<it(pow(k-i));j++)fin>>d[i][j];
	fin>>t;
	for(int i=0;i<t;i++)for(int j=0;j<4;j++)fin>>x[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<t;j++)aa[i][j]=circle_add(a[i][0],x[j][i%4]);
	fin.close();
	for(int i=0;i<t;i++)f(i);
	return 0;
}
