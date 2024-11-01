#include <bits/stdc++.h>
using namespace std;
int a[10000005],sc[10000005],ec[10000005],ms[10000005],me[10000005],ch[10000005],ne[10000005],aa[21],mmm=0;
int di(int a,int b,bool c)
{
	if(c and a%b==0) return a/b;
	return a/b+1;
}
int how(int now,int v,int a,int v1)
{
	int s=di(v1*v1-v*v,2*a,a<0);
	return now+s;
}
bool in(int p,int a[],int n)
{
	for (int i=1;i<=n;i++) if(a[i]==p) return 1;
	return 0;
}
bool cha(int x,int w)
{
	int bb[22],tm=0;
	for(int i=0;i<w;i++) if(aa[i]) bb[tm++]=a[i];
	for(int i=1;i<=x;i++) 
	{
		bool flag=0;
		for(int z=0;z<tm;z++) if(ms[i]<=bb[z] and me[i]>=bb[z]) flag=1;
		if(!flag) return 0;
	}
	return 1;
}
int ch1(int n)
{
	int ans=0;
	for(int i=0;i<n;i++) if(aa[i]==1) ans++;
	return ans;
}
void c(int s,int w)
{
	int po=1<<w,tt=0;
	while(w--)
	{
		tt++;
		po/=2;
		a[tt]=s/po;
		if(s>=po) s-=po;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T--){
	int n,m,v,l;
	cin>>n>>m>>l>>v;
	for (int i=1;i<=l;i++) ms[i]=me[i]=ch[i]=a[i]=sc[i]=ec[i]=ne[i]=0;
	for(int i=1;i<=n;i++)
	{
		int d,v0,a;
		cin>>d>>v0>>a;
		if(a==0 and v0>v){sc[i]=d;ec[i]=l;}
		else if(a>0 and v0<=v)
		{
			int tm=how(d,v0,a,v);
			if (tm<=l) {sc[i]=tm;ec[i]=l;}
		}	
		else if(a>0 and v0>v) {sc[i]=d;ec[i]=l;}
		else if(a<0 and v0>v) 
		{
			int tm=how(d,v0,a,v);
			if (tm<=l) {sc[i]=d;ec[i]=tm-1;}
			else {sc[i]=d;ec[i]=l;}
		}
		else sc[i]=ec[i]=0;
	}
	int ans=0,mmm=0;
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=n;i++) 
	{
		//if (T==2) cout<<sc[i]<<" "<<ec[i]<<endl;
		if(sc[i]==0 and ec[i]==0) continue;
		bool flag=0;
		for(int j=sc[i];j<=ec[i];j++) if(in(j,a,m)) flag=1;
		if(flag)
		{
			ans++;
			ms[++mmm]=sc[i];
			me[mmm]=ec[i];
			for(int j=sc[i];j<=ec[i];j++) ch[j]++;
		}
	}
	
	cout<<ans<<" ";
	ans=0;
	//for(int i=1;i<=mmm and ne[i]==0;i++) cout<<ms[i]<<" "<<me[i]<<endl;
	for(int i=1;i<=mmm;i++)
	{
		if(ne[i]!=0) continue;
		int mn=0,mc=0;
		for(int j=ms[i];j<=me[i];j++)
		{
			if(in(j,a,m))
			{
				if(ch[j]>=mc) {mn=j;mc=ch[j];}
			}
		}
		//cout<<mn<<endl;
		//if(tm==1) {ans++;continue;}
		for(int j=1;j<=mmm;j++)
		if(ms[j]<=mn and me[j]>=mn) 
		{
			ne[j]=1;
			for(int z=ms[j];z<=me[j];z++) ch[z]--;
		}
		ans++;
	}
	cout<<m-ans<<endl;
}
	return 0;
}
