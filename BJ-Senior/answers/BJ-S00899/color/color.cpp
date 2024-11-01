#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
void subtask1(){
	int ans=0;
	for(int state=0;state<(1<<n);state++){
		int c=0,lst0=0,lst1=0;
		for(int i=1;i<=n;i++){
			if(state&(1<<(i-1))){
				if(lst1){
					if(a[lst1]==a[i]){
						c+=a[i];
					}
				}
				lst1=i;
			}else{
				if(lst0){
					if(a[lst0]==a[i]){
						c+=a[i];
					}
				}
				lst0=i;
			}
		}
		ans=max(ans,c);
	}
	cout<<ans<<'\n';
}
void subtask2(){
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=15){
			subtask1();
		}else{
			subtask2();
		}
	}
	return 0;
}
