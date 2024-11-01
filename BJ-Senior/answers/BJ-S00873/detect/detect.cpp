
#include<bits/stdc++.h>
using namespace std;
struct s{
	int d,v,a,c;
	int x=0,y=0;
}ca[100000];
int bj[100000];
int qj[10000][10000];
int n,m,l,xv;
int maxx=0;
void dfs(int mi,int su){
	//cout<<mi<<" "<<su<<endl;
	 int fl=0;
	 if(mi==m){
		 maxx=max(maxx,su-1);
		 return;
	 }	 
	if(mi!=-1){
		for(int i=1;i<qj[mi][0];i++){
			if(bj[qj[mi][i]]>1){
				
			}else{
				fl=1;
			}
			bj[qj[mi][i]]--;
		}
		//for(int i=0;i<n;i++){
			//cout<<bj[i]<<" ";
		//}
		//cout<<endl;
		if(fl==1){
			//<<"!"<<endl;
			for(int i=1;i<qj[mi][0];i++){
				bj[qj[mi][i]]++;
			}
			return;
		}
	}
	maxx=max(maxx,su);
	for(int i=mi+1;i<=m;i++){
		dfs(i,su+1);
	}
	for(int i=1;i<qj[mi][0];i++){
		bj[qj[mi][i]]++;
	}
	
}
void f(){
	for(int i=0;i<100000;i++){
		bj[i]=0;
	}
	for(int i=0;i<10000;i++){
		qj[i][0]=1;
	}
	cin>>n>>m>>l>>xv;
	for(int i=0;i<n;i++){
		cin>>ca[i].d>>ca[i].v>>ca[i].a;
		if(ca[i].a==0){
			if(ca[i].v>xv){
				ca[i].x=ca[i].d;
				ca[i].y=l;
			}else{
				ca[i].x=ca[i].y=0;
			}
		}else if(ca[i].a>0){
			ca[i].c=(xv*xv-ca[i].v*ca[i].v)/(2*ca[i].a)+1;
			ca[i].x=ca[i].d+ca[i].c;
			ca[i].y=l;
		}else{
			if(ca[i].v>xv){
				ca[i].c=(xv*xv-ca[i].v*ca[i].v)/(2*ca[i].a);
				ca[i].c-=(((xv*xv-ca[i].v*ca[i].v)%(2*ca[i].a))==0);
				ca[i].x=ca[i].d;
				ca[i].y=ca[i].d+ca[i].c;
			}else{
				ca[i].x=ca[i].y=0;
			}
		}
		//cout<<ca[i].x<<" "<<ca[i].y<<endl;
	}
	//cout<<"!"<<endl;
	int lcs;
	for(int i=0;i<m;i++){
		cin>>lcs;
		for(int j=0;j<n;j++){
			if(lcs>=ca[j].x&&lcs<=ca[j].y){
				qj[i][qj[i][0]]=j;
				qj[i][0]++;
				bj[j]++;
			}
		}
	}
	int anc=0;
	for(int i=0;i<n;i++){
		
		if(bj[i]>=1){
			anc++;
		}
	}
	//cout<<"!"<<endl;
	maxx=0;
	dfs(-1,0);
	cout<<anc<<" "<<maxx<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		f();
	}
	return 0;
}
	
	
