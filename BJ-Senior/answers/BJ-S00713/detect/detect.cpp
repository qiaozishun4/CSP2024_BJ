#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vm,d[102337],v[102337],a[102337],pos[102337],le[102337],ri[102337];
bool c[102337];
queue<int> q;
int findnext(int dis){
	int ll=1,rr=m;
	while(ll<rr){
		int mid=(ll+rr)/2;
		if(pos[mid]<dis)ll=mid+1;
		else rr=mid;
	}
	return rr;
}
inline int vel(int vv,int aa,int xx){
	return vv*vv+2*aa*xx;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> t;
	for(int tt=0;tt<t;tt++){
		int ans=0;
		memset(c,false,sizeof(c));
		cin >> n >> m >> l >> vm;
		for(int i=1;i<=n;i++)cin >> d[i] >> v[i] >> a[i];
		for(int i=1;i<=m;i++)cin >> pos[i];
		sort(pos+1,pos+1+m);
		if(n<=20&&m<=20){
			int shut=0,usage[22],isokay[22];
			for(int i=1;i<=n;i++){
				int x0=0,flag=0,left=23372337,right=0;
				if(a[i]<0){
					x0=d[i]+v[i]*v[i]/(-2*a[i]);
				}
				for(int j=1;j<=m;j++){
					if(pos[j]<d[i])continue;
					int vv=vel(v[i],a[i],pos[j]-d[i]);
					if(a[i]>=0){
						if(vv>vm*vm){
							flag=1;
							left=min(left,j);
							right=max(right,j);
						}
					}else{
						if(vv>vm*vm&&x0>pos[j]){
							flag=1;
							left=min(left,j);
							right=max(right,j);
						}
					}
				}
				//cout << x0 << endl;
				if(flag){
					c[i]=1;
					ans++;
					le[i]=left;
					ri[i]=right;
					//cout << i << " " << le[i] << " " << ri[i] << endl;
				}
			}
			cout << ans << " ";
			for(int i=0;i<(1<<m);i++){
				memset(isokay,0,sizeof(isokay));
				int fl=0,st=0;
				int cod=i;
				for(int j=1;j<=m;j++){
					usage[j]=(cod>>(j-1))%2;
					if(usage[j]==0)st++;
					else{
						for(int k=1;k<=n;k++){
							if((le[k]<=j&&ri[k]>=j)||c[k]==0){isokay[k]=1;}
						}
					}
				}
				for(int j=1;j<=n;j++)if(!isokay[j])fl=1;
				if(!fl){shut=max(shut,st);}
			}
			cout << shut << endl;
		}else{
		for(int i=1;i<=n;i++){
			if(d[i]>pos[m])continue;
			int left=findnext(d[i]),right=m;
			//cout << left << " " << i << endl;
			if(a[i]==0){
				//cout << "c1";
				if(v[i]>vm){
					c[i]=1;
					ans++;
					le[i]=left,ri[i]=right;
				}
			}else if(a[i]>0){
				//cout << "c2";
				int vmax=vel(v[i],a[i],pos[m]-d[i]);
				if(vmax<=vm*vm)continue;
				else{
					while(left<right){
						int mid=(left+right)/2;
						int vn=vel(v[i],a[i],pos[mid]-d[i]);
						if(vn<=vm*vm)left=mid+1;
						else right=mid;
					}
					//cout << right << endl;
					c[i]=1;
					ans++;
					le[i]=right,ri[i]=m;
				}
			}
			//cout << "live";
			/*if(a[i]<0){
				//cout << "ok1";
				if(vel(v[i],a[i],pos[left]-d[i])<=vm*vm)continue;
				int x0=d[i]-v[i]*v[i]/(2*a[i]);
				if(x0<=pos[left])continue;
				int ll=1,rr=m;
				cout << "ok2";
				while(ll<=rr){
					int mid=(ll+rr)/2;
					if(pos[mid]<=x0)ll=mid;
					else rr=mid-1;
				}
				right=ll;
				int lef=left;
				cout << "ok3";
				while(left<=right){
					int mid=(left+right)/2;
					int vn=vel(v[i],a[i],pos[mid]-d[i]);
					if(vn<=vm*vm)left=mid;
					else right=mid-1;
				}
				c[i]=1;
				ans++;
				le[i]=lef,ri[i]=left-1;
			}*/
		}
		cout << ans << " ";
		if(ans==0)cout << m << endl;
		else cout << m-1 << endl;
		}
	}
	return 0;
}