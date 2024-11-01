#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct car{
	int d,v,a;
}c[N];
struct seg{
	int l,r;
}detect[N];    //detect sequence
int n,m,L,V;
int p[N];
int leftcount=2147483647;
int detectcount=0;
bool vis[N];   //p count
void dfs(int k,string s,int num){    //p count and car count
	//~ cout<<k<<" "<<s<<endl;
	if(num>=detectcount){
		leftcount=min(leftcount,k);
		return ;
	}
	if(k>leftcount) return ;
	string s1=s;
	int num1;
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			num1=num;
			for(int j=1;j<=n;j++){
				if(detect[j].l<=p[i]&&p[i]<=detect[j].r){
					if(s1[j-1]=='0'){
						s1[j-1]='1';
						num1++;
					}
				}
			}
			vis[i]=1;
			dfs(k+1,s1,num1);
			vis[i]=0;
		}
	}
}
void solve(){
	leftcount=2147483647;
	detectcount=0;
	memset(vis,0,sizeof(vis));
	memset(detect,0,sizeof(detect));
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].v>>c[i].a;
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	sort(p+1,p+m+1);
	int pmax=lower_bound(p+1,p+m+1,L)-p-1;
	//~ cout<<"pmax: "<<pmax<<endl;
	int s;
	for(int i=1;i<=n;i++){
		if(c[i].v>V){    //detect at start
			if(c[i].a<0){   //speed down
				s=floor(1.0*(V*V-c[i].v*c[i].v)/(2*c[i].a))+c[i].d;   //last detect position
				if(floor(1.0*(V*V-c[i].v*c[i].v)/(2*c[i].a))==ceil(1.0*(V*V-c[i].v*c[i].v)/(2*c[i].a))){
					s--;
				}
				//~ cout<<"last detect position: "<<s<<endl;
				int rp=lower_bound(p+1,p+m+1,s)-p-1;
				//~ if(s>p[m]) rp++;
				//~ cout<<"detect at p:"<<p[rp]<<endl;
				if(p[rp]>=c[i].d){
					//~ cout<<i<<endl;
					detect[i].l=c[i].d;
					detect[i].r=s;
					detectcount++;
				}
			}
			else{
				if(p[pmax]>=c[i].d){
					detect[i].l=c[i].d;
					detect[i].r=L;
					detectcount++;
					//~ cout<<i<<endl;
				}
			}
		}
		else{     //if not detect at start
			if(c[i].a>0){  //speed up
				s=floor(1.0*(V*V-c[i].v*c[i].v)/(2*c[i].a))+c[i].d;   //first detect position
				//~ cout<<"first detect position: "<<s<<endl;
				int rp=lower_bound(p+1,p+m+1,s)-p-1;
				if(p[rp]<=L){
					detect[i].l=s;
					detect[i].r=L;
					detectcount++;
					//~ cout<<i<<endl;
				}
			}
		}
	}
	//~ cout<<endl;
	//~ for(int i=1;i<=n;i++){
		//~ cout<<detect[i].l<<" "<<detect[i].r<<endl;
	//~ }
	string t="";
	for(int i=1;i<=n;i++)t+='0';
	dfs(0,t,0);
	cout<<detectcount<<" "<<m-leftcount<<endl;
	
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
10 10 150307 247
62978 968 -5
51700 883 -3
40408 564 -1
60366 870 -41
35943 797 -7
47476 595 -11
59020 672 -10
81024 964 -11
80637 695 -5
66114 874 -1
46720 48066 57373 60882 68842 72773 82820 116695 122159 150307
*/
