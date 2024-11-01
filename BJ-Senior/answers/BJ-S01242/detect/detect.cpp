#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005,MAXL=1000005;
int T;
int n,m,L,V;
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
int l[MAXN],r[MAXN],over_speed[MAXN];
bool all_z,all_zh,all_f;
long long getq(int id){
	double s=(V*V*1.0-v[id]*v[id]*1.0)/(a[id]*2.0);
	return (d[id]*1.0+s)*1000000LL;
}
int tmp[MAXL];
double get_speed(int pos,int id){
	double v0=v[id]*1.0,A=a[id]*1.0,s=pos*1.0-d[id]*1.0;
	double speed=sqrt(v0*v0+2*A*s);
	return speed;
}
int find_lst(int id){
	double s=(V*V*1.0-v[id]*v[id]*1.0)/(a[id]*2.0)-0.00001;
	return d[id]+floor(s);
}
int find_fst(int id){
	double s=((V*V*1.0)-(v[id]*v[id]*1.0))/(2.0*a[id])+0.00001;
	return ceil(s)+d[id];
}
int getw(int x){
	int w=0,ans=0;
	while(x){
	    ans+=(1-(x&1));
	    w++;
	    x>>=1;
	}
	return ans+(m-w);
}
int check(int x){
	memset(tmp,0,sizeof(tmp));
	int w=0;
	while(x){
		w++;
		if(x&1)tmp[p[w]]=1;
		x>>=1;
	}
	int ans=0;
	for(int i=1;i<=L;i++)tmp[i]+=tmp[i-1];
	for(int i=1;i<=n;i++){
		if(over_speed[i]&&tmp[r[i]]-tmp[l[i-1]]){	
			over_speed[i]=1;
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		all_z=all_zh=all_f=1;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i],all_z&=(a[i]==0),all_zh&=(a[i]>0),all_f&=(a[i]<0);
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+m+1);
		if(all_z){
			int ans1=0;
			for(int i=1;i<=n;i++){
				if(v[i]>V&&d[i]<=p[m]*1.0)ans1++;
			}
			cout<<ans1<<" "<<(ans1!=0?m-1:m)<<endl;
			continue;
		}//20pts
		else if(all_zh){
			int ans1=0;
			for(int i=1;i<=n;i++){
				if((long long)getq(i)<(long long)p[m]*1000000LL)ans1++;
			}
			cout<<ans1<<" "<<(ans1!=0?m-1:m)<<endl;
		}//20pts
		else if(n<=20){
			for(int i=1;i<=n;i++){
				if(a[i]>0){
					if(get_speed(L,i)){
						over_speed[i]=1;
						l[i]=find_fst(i),r[i]=L;
					}
				}
				else if(a[i]==0){
					if(v[i]>V){
						over_speed[i]=1;
						l[i]=d[i],r[i]=L;
					}
				}
				else{
					if(v[i]>V){
						over_speed[i]=1;
						l[i]=d[i],r[i]=find_lst(i);
					}
				}
			}
			//for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;
			int ans1=0,ans2=0;
			memset(tmp,0,sizeof(tmp));
			for(int i=1;i<=m;i++)tmp[p[i]]++;
			for(int i=1;i<=L;i++)tmp[i]+=tmp[i-1];
			for(int i=1;i<=n;i++){
				if(over_speed[i]&&tmp[r[i]]-tmp[l[i-1]]){	
					over_speed[i]=1;
					ans1++;
				}
			}
			cout<<ans1<<" ";//<<" "<<ans2<<endl;
			for(int S=0;S<(1<<m);S++){
				if(check(S)==ans1)ans2=max(ans2,getw(S));
			}
			cout<<ans2<<endl;
			continue;
		}
	}
	return 0;
}
