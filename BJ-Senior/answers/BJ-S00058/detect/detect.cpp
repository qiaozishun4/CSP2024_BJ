#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,v,a;
};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		node a[100005];
		int b[100005];
		bool h[100005]={0};
		int h1[100005];
		//a<0 left
		int h2[100005];
		//a>0 right
		int n,m,l,v;
		int ans=0;
		scanf("%d %d %d %d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].d,&a[i].v,&a[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			h[i]=0;
		}
		for(int i=1;i<=n;i++){
			
			double x=a[i].d,y=a[i].v,z=a[i].a;
			if(x>b[m]){
				
				h1[i]==n;
				h2[i]==1;
				continue;
			}
			if(z==0){
				if(y>v){
					int g=lower_bound(b+1,b+m+1,x)-b;
					h2[i]=g;
					h1[i]=n;
					ans++;
				}else{
					h1[i]=n;
					h2[i]=1;
				}
				continue;
			}else if(z>0){
				if(y>v){
					int g=lower_bound(b+1,b+m+1,x)-b;
					h2[i]=g;
					h1[i]=n;
					ans++;
				}else
				{
					double sv=(v*v-y*y)/2/z;
					double sd=x+sv;
					int sd1=ceil(sd);
					if(sd>=1.0*b[m]){
						h1[i]=n;
						h2[i]=1;
					}else{
						ans++;
						
						int g=lower_bound(b+1,b+m+1,sd1)-b;
						h2[i]=g;
						h1[i]=n;
					}
				}
				continue;
			}else if(z<0){
				if(y<=v){
					h1[i]=n;
					h2[i]=1;
				}else{
					double sv=(v*v-y*y)/2/z;
					double sd=x+sv;
					int sd1=floor(sd);
					if(sd<=1.0*b[1]){
						h1[i]=n;
						h2[i]=1;
					}else{
						ans++;
						int g=upper_bound(b+1,b+m+1,sd1)-b;
						h1[i]=g-1;
						h2[i]=1;
					}
				}
				continue;
			}
		}
		if(ans==0){
			cout<<ans<<' '<<m<<endl;
		}
		else
			cout<<ans<<' '<<m-1<<endl;
	}
	return 0;
}
