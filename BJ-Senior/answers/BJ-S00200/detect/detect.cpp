#include<bits/stdc++.h>
using namespace std;
#define ll long long

int t;
struct Car{
	ll l,r,fb=-1,fn=-1,ln=-1,lb=-1;
	int v0,a;
};
ll book[100007];
vector<Car> car;
void print(Car ci)
{
	printf("l==%lld,r==%lld,fb==%lld\n",ci.l,ci.r,ci.fb);
	printf("a==%d,v0==%d\n",ci.a,ci.v0);
}




int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		car.clear();
		ll n,m,l,v,s;
		ll cntn=0;
		ll lix[100007],v0[100007],a[100007];
		scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
			
			for(int i=1;i<=n;i++)
			{
				scanf("%lld%lld%lld",&lix[i],&v0[i],&a[i]);
			}
			for(int i=1;i<=m;i++)
			{
				scanf("%lld",&s);
			}
			for(int i=1;i<=n;i++)
			{
				if((int)sqrt(2*a[i]*(s-lix[i])+v0[i]*v0[i])>v) cntn++;
				
			} 
			if(cntn==0) printf("0 %lld\n",m);
			else printf("%lld %d\n",cntn,max(0,(int)m-1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
