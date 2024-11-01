#include <bits/stdc++.h>
using namespace std;

int T,n,m,l,v,ans1=0,ans2=0;
int p[1000005][2]={0};

struct car{
	int d,v,a;
	bool s;//over v car
}aa[100005];

void sou(int bijiao){
	for(int i=0;i<l;i++){
		if(p[i][0]>bijiao&&p[i][1]!=1){
			p[i][1]=1;//suo3 ce4 su4 yi2
			break;
		}
	}
	return ;
}

void shuru(){
	for(int i=0;i<n;i++){
		aa[i].s=0;
		cin>>aa[i].d>>aa[i].v>>aa[i].a;
	}
	for(int i=0;i<l;i++){
		cin>>p[i][0];
	}
	return ;
}

void shuchu(){
	for(int i=0;i<n;i++){
		if(aa[i].s==1){
			ans1++;
		}
	}
	for(int i=0;i<l;i++){
		if(p[i][1]==1){
			ans2++;
		}
	}
	cout<<ans1<<" "<<l-ans2<<endl;
	return ;
}

int main(){
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	cin>>T;
	cin>>n>>m>>l>>v;
	int t,s;
	for(int i=1;i<=T;i++){
		shuru();
		for(int i=0;i<n;i++){
			//a=0
			if(aa[i].a==0){
				if(aa[i].v>v){
					aa[i].s=1;
					sou(aa[i].d);
				}
			}
			//a>0
			if(aa[i].a>0){
				t=(v-aa[i].v)/aa[i].a;
				s=aa[i].v*t+0.5*aa[i].a*t*t+aa[i].d;
				if(s<=p[l-1][0]){//maybe make a mistake
					aa[i].s=1;
					sou(s);
				}
			}
		}
		shuchu();
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
