#include<bits/stdc++.h>
using namespace std;
int car[100005][4];
int p[100005];
int jia[100005];
int j2[100005][3];
int m;
bool find(int a,int b){
	for(int i=1;i<=m;i++){
		if(p[i]>=a&&p[i]<=b) return 1;
	}
	return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T){
		int n,l,v,top1=0,top2=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++) cin>>car[i][1]>>car[i][2]>>car[i][3];
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++){
			if(car[i][2]<=v&&car[i][3]<=0) continue;
			int x;
			if(car[i][3]>0){
				if(car[i][2]>v){
					if(p[m]>=car[i][1]){
						top1++;
						jia[top1]=car[i][1];
					}
					continue;
				}
				if(car[i][2]==v){
					if(p[m]>=car[i][1]+1){
						top1++;
						jia[top1]=car[i][1]+1;
					}
					continue;
				}
				else{
					x=(v*v-car[i][2]*car[i][2])/(2*car[i][3]);
					if((v*v-car[i][2]*car[i][2])%(2*car[i][3])!=0){ 
						x++;
						if(x+car[i][1]<=p[m]){
							top1++;
							jia[top1]=car[i][1]+x;
						}
					}
					else{
						if(x+car[i][1]<p[m]){
							top1++;
							jia[top1]=car[i][1]+x;
						}
					}
					continue;
				}
			}
			else if(car[i][3]==0){
				if(p[m]>=car[i][1]){
					top1++;
					jia[top1]=car[i][1];
				}
			}
			else{
				x=(car[i][2]*car[i][2]-v*v)/(2*car[i][3]*-1);
				if((car[i][2]*car[i][2]-v*v)%(2*car[i][3])!=0) x++;
				if(x+car[i][1]>=l){
					top1++;
					jia[top1]=car[i][1];
				}
				else if(find(car[i][1],car[i][1]+x)){
					top2++;
					j2[top2][1]=car[i][1];
					j2[top2][2]=car[i][1]+x;
				}
			}
		}
		cout<<top1+top2<<" ";
		if(top1+top2==0)cout<<m<<endl;
		else if(top2==0) cout<<m-1<<endl;
		T--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}