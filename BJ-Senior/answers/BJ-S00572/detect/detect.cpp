#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int t,n,m,L,V;
struct bruh{
	int a;
	bool b=0;
}ce[100005];
struct node{
	int d,v,a;
}car[100005];
void detect(int i){
	for(int i=0;i<n;i++){
		cin>>car[i].d>>car[i].v>>car[i].a;
	}
}
void over(int i){
	int disance=(V*V-car[i].v*car[i].v)/(2*car[i].a);
	for(int j=0;j<m;j++){
		if(disance+car[i].d>=ce[j].a){
			ce[j].b=1;
			break;
		}
	}
	
	
	
}
	

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>L>>V;
		for(int i=0;i<t;i++){
			detect(i);
		}
		for(int i=0;i<m;i++){
			cin>>ce[i].a;
		}
		for(int i=0;i<n;i++){
			over(i);
		}
		for(int i=0;i<m;i++){
			if(ce[i].b==1)
			cnt++;
		}
		cout<<cnt;
		}

	fclose(stdin);
	fclose(stdout);
	return 0;
	
}