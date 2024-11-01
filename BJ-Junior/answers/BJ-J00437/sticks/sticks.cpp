#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int suan(int x){
	if(x==1){
		cout<<-1<<endl;
		return 0;
	}
	bool vis=0;
	while(x>0){
		if(x%7==0){
			int v=x/7;
			for(int i=1;i<=v;i++){
				cout<<8;
			}
			cout<<endl;
			return 0;
		}
		int sum=x%7;
		if(x==7){
			cout<<8<<endl;
			return 0;
		}else if(x>7){
			if(vis==false){
				int ans=10;
				for(int i=1;i<=9;i++){
					if(a[i]>=sum){
						ans=min(ans,i);
					}
				}
				x-=a[ans];
				cout<<ans;
				vis=true;
			}else{
				int ans=10;
				for(int i=0;i<=9;i++){
					if(a[i]>=sum){
						ans=min(ans,i);
					}
				}
				x-=a[ans];
				cout<<ans;
			}
		}else{
			if(vis==false){
				int ans=10;
				for(int i=1;i<=9;i++){
					if(a[i]==sum){
						ans=min(ans,i);
					}
				}
				x-=a[ans];
				cout<<ans;
				vis=true;
			}else{
				int ans=10;
				for(int i=0;i<=9;i++){
					if(a[i]==sum){
						ans=min(ans,i);
					}
				}
				x-=a[ans];
				cout<<ans;
			}
		}
		
	}
	cout<<endl;
	return 0;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		suan(x);
	}
	return 0;
}
