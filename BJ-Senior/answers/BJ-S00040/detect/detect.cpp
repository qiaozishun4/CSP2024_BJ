#include<bits/stdc++.h>
using namespace std;

int n,T,l,v,cnt=1,ans,ct=0,m,t[2000100],sum,add[200100],j[200100],p[200100],mn[200100];
struct node{
	int d,v,a,mn,mx;
}a[200100];
bool cmp(node a,node b){
	return a.d<b.d;
}
bool cmp2(node a,node b){
	return a.mx<b.mx||(a.mx==b.mx&&a.mn<b.mn);
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> l >> v;
		for(int i=1;i<=n;i++){
			cin >> a[i].d >> a[i].v >> a[i].a ;
			a[i].mx=1e9;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++){
			cin >> p[i];
			while(p[i]>a[cnt].d&&cnt<=n){
				mn[cnt]=i;
				cnt++;
			}
			for(;ct<=p[i];ct++){
				t[ct]=i-1;
			}
		}
		for(int i=p[m]+1;i<=l+1;i++){
			t[i]=m;
		}
		//cout << endl;
		for(int i=1;i<=n;i++){
			if(a[i].a==0){
				if(a[i].v>v){
					ans++;
					a[i].mn=t[a[i].d]+1;
					a[i].mx=t[l+1];
					//cout << a[i].d << ' ' << a[i].mn << ' ' << a[i].mx  << endl;
				}
			}
			else if(a[i].a>0){
				if(sqrt(a[i].v*a[i].v+2*a[i].a*(p[m]-a[i].d))>v){
					ans++;
					//cout << t[a[i].d+(int)ceil((double((v*v-a[i].v*a[i].v)/2*a[i].a+0.000001)))] << endl;
					a[i].mn=t[a[i].d+(int)ceil((double((v*v-a[i].v*a[i].v)/2/a[i].a)))+1]+1;
					a[i].mx=t[l+1];
					//cout << a[i].d << ' ' << a[i].mn << ' ' << a[i].mx  << endl;
				}
			}else if(a[i].a<0){
				if(a[i].v*a[i].v+2*a[i].a*(p[m]-a[i].d)>0){
					if(sqrt(a[i].v*a[i].v+2*a[i].a*(p[m]-a[i].d))>v){
						ans++;
						a[i].mn=t[a[i].d]+1;
						a[i].mx=t[l+1];
						//cout << a[i].d << ' ' << a[i].mn << ' ' << a[i].mx  << endl;
						continue;
					}
				}
				if(a[i].v*a[i].v+2*a[i].a*(p[mn[i]-a[i].d])>0){
					if(sqrt(a[i].v*a[i].v+2*a[i].a*(p[mn[i]]-a[i].d))>v){
						ans++;
						a[i].mn=t[a[i].d]+1;
						a[i].mx=t[a[i].d+(int)floor(double((v*v-a[i].v*a[i].v)/2/a[i].a))+1];
						//cout << a[i].d << ' ' << a[i].mn << ' ' << a[i].mx  << endl;
					}
				}
			}
		}
		//cout << endl;
		sort(a+1,a+1+n,cmp2);
		int mnn=1e9;
		for(int i=1;i<=n;i++){
			//cout << a[i].d << ' ' << a[i].mn << ' ' << a[i].mx << endl;
			if(a[i].mn>mnn){
				sum++;
				mnn=1e9;
			}
			mnn=min(mnn,a[i].mx);
		}
		if(mnn!=1e9){
			sum++;
		}
		cout << ans << ' ' << m-sum << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
