#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 200005
using namespace std;
long long ans=-0x3f;
int T,left_2,left_1;
int a[MAXN],c[MAXN],n;
short colour[MAXN];
void memset_m(int qw,int er){
	for(int i=0;i<=200004;i++){
		a[i]=qw;
		c[i]=er;
		ans=0;
	}
}
int dfs(int dis,long long anss){
	dis++;
	int left_1q=left_1,left_2q=left_2,anssq=anss;
	if(dis>n){
		ans=max(ans,anss);
		//cout<<"tes0:"<<anss<<" "<<left_1<<" "<<left_2<<" "<<dis<<endl;
		return 0;
	}
	
	colour[dis]=1;
	if(a[left_1]==a[dis]) anss+=a[dis];
	//cout<<"tes1:"<<anss<<" "<<left_1<<" "<<left_2<<" "<<dis<<endl;
	left_1=dis;
	dfs(dis,anss);
	//cout<<"tes1a:"<<anss<<" "<<left_1<<" "<<left_2<<" "<<dis<<endl;
	left_1=left_1q;
	
	anss=anssq;
	 
	colour[dis]=2;
	if(a[left_2]==a[dis]) anss+=a[dis];
	//cout<<"tes2:"<<anss<<" "<<left_1<<" "<<left_2<<" "<<dis<<endl;
	left_2=dis;
	dfs(dis,anss);
	//cout<<"tes2a:"<<anss<<" "<<left_1<<" "<<left_2<<" "<<dis<<endl;
	colour[dis]=0;
	left_2=left_2q;
	
	//cout<<"tes3:"<<anss<<" "<<left_1<<" "<<left_2<<" "<<dis<<endl;
	return 0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		memset_m(0,0);
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(0,0);	
		cout<<ans<<endl;
	}
	return 0;
}
