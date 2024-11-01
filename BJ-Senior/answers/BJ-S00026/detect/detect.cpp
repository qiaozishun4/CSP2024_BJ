#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
int cnt,cnt2;
struct car{
	int d,v,a;
	int l,r;
	bool cs=true;
};
car c[3005];
struct cesu{
	int p;
	int num=0;
	bool cr[3005];
	bool sheqi=false;
};
cesu p[3005];

int jisuan1(int v, int vb, int a){
	int ans=vb*vb-v*v;
	a*=2;
	if(ans%a==0){
		ans=ans/a;
		return ans;
	}
	else {
		ans=ans/a;
		ans+=1;
		return ans;
	}
}
int jisuan2(int v, int vb, int a){
	int ans=vb*vb-v*v;
	a*=2;
	if(ans%a==0){
		ans=ans/a;
		ans-=1;
		return ans;
	}
	else {
		ans=ans/a;
		return ans;
	}
}
bool cmp1(cesu a, cesu b){
	return a.num<b.num;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>m>>L>>V;
		cnt=n;
		cnt2=0;
		for(int j=0;j<n;j++){
			cin>>c[j].d>>c[j].v>>c[j].a;
			if(c[j].v<=V&&c[j].a<=0){
				c[j].cs=false;
				cnt--;
			}
			else if(c[j].v<=V&&c[j].a>0){
				c[j].r=L;
				c[j].l=c[j].d+jisuan1(c[j].v,V,c[j].a);
			}
			else if(c[j].v>=V&&c[j].a<0){
				c[j].l=c[j].d;
				c[j].r=c[j].d+jisuan2(c[j].v,V,c[j].a);
			}
			else{
				c[j].l=c[j].d;
				c[j].r=L;
			}
		}
		for(int j=0;j<n;j++){
			cin>>p[j].p;
		}
		for(int j=0;j<n;j++){
			if(c[j].cs==true){
				bool flag=false;
				for(int l=0;l<n;l++){
					if(p[l].p>=c[j].l&&p[l].p<=c[j].r){
						flag=true;
						p[l].cr[j]=true;
						p[l].num++;
					}
					else{
						p[l].cr[j]=false;
					}
				}
				if(flag==false){
					c[j].cs=false;
					cnt--;
				}
			}
		}
		sort(p,p+n,cmp1);
		for(int j=0;j<n;j++){
			bool use=false;
			for(int k=0;k<n;k++){
				bool diff=true;
				if(p[j].cr[k]==false){
					continue;
				}
				for(int l=0;l<n;l++){
					if(l==j){
						continue;
					}
					if(p[l].sheqi==true){
						continue;
					}
					if(p[l].cr[k]==true){
						diff=false;
					}
				}
				if(diff==true){
					use=true;
				}
			}
			if(use==false){
				p[j].sheqi=true;
				cnt2++;
			}
		}
		cout<<cnt<<" "<<cnt2<<endl;
	}
	return 0;
}