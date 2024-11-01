#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],b[N],c[N],d[N]/*,qzh[N]*/;
struct node{
	long long l,r;
}s[N];
bool cmp1(node a,node b){
	return a.l<b.l;
}
long long bj(long long x,long long y,bool h,long long m){
	long long l=1,r=m,mid;
	while(l<=r){
		mid=(l+r)/2;
		if((h&&(abs(d[mid]*y)<=abs(x)))||((!h)&&(abs(d[mid]*y)<abs(x)))){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l-1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--){
		long long n,m,len,v,i;
		scanf("%lld%lld%lld%lld",&n,&m,&len,&v);
		for(i=1;i<=n;++i)scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		for(i=1;i<=m;++i)scanf("%lld",&d[i]);
		long long ans=0,nn=0;
		for(i=1;i<=n;++i){
			//if(i==4)cout<<1<<endl;
			//if(i==4)cout<<(a[i]*2*c[i])+(v*v-b[i]*b[i])<<" "<<(2*c[i])<<endl;
			if(b[i]<=v&&c[i]>0&&abs((a[i]*2*c[i])+(v*v-b[i]*b[i]))<=abs((2*c[i]*len))){//bu chao su de che zai lu duan shangchao su le
				//1:<= 0:<
				//(l,r]
				long long r=bj(len,1,1,m);//chao su zhong dian ,ji ge ce su yi <=ta
				long long l=bj(a[i]*2*c[i]+(v*v-b[i]*b[i]),(2*c[i]),1,m);//ji ge ce su yi yan ge xiao yv ta
				
				//bu bao kuo l,na me <=de dou bu neng suan(dou yao bj)
				
				if(r-l>=1)ans++;
				if(l+1<=r){
					s[++nn].l=l+1;
					s[nn].r=r;
				}
				//cout<<l<<" "<<r<<endl;
			}
			else if(b[i]>v&&c[i]<0&&abs((a[i]*2*c[i])+(v*v-b[i]*b[i]))<=abs((2*c[i]*len))){//chao su che bu chao su le
				long long r=bj(a[i]*2*c[i]+(v*v-b[i]*b[i]),(2*c[i]),0,m);
				//if(i==5)cout<<a[i]*2*c[i]+(v*v-b[i]*b[i])<<" "<<(2*c[i])<<endl;
				long long l=bj(a[i],1,0,m);
				if(r-l>=1)ans++;
				if(l+1<=r){
					s[++nn].l=l+1;
					s[nn].r=r;
				}
				//cout<<l<<" "<<r<<endl;
			}
			else if(b[i]>v){//yong yuan chao su
				long long r=bj(len,1,1,m);
				long long l=bj(a[i],1,0,m);
				if(r-l>=1)ans++;
				if(l+1<=r){
					s[++nn].l=l+1;
					s[nn].r=r;
				}
				//cout<<l<<" "<<r<<endl;
			}
		}
		printf("%lld ",ans);
		sort(s+1,s+nn+1,cmp1);
		//cout<<nn<<endl;
		//for(i=1;i<=nn;++i)cout<<s[i].l<<" "<<s[i].r<<endl;
		long long end=10000000,cnt=1;
		for(i=1;i<=nn;++i){
			end=min(end,s[i].r);
			if(s[i+1].l>end&&i<nn){
				//cout<<i<<endl;
				cnt++;
				end=10000000;
			}
		}
		printf("%lld\n",m-cnt);
	}
	return 0;
}
