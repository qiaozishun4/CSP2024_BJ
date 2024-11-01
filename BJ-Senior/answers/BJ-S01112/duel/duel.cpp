#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
bool check(){
	int ans1,ans2;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1&&a[i]!=-2){	
			ans1=max(ans1,a[i]);
			ans2=min(ans2,a[i]);
		}
	}
	return ans1>ans2;
}	
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num=1,num2=1;
	while(check()){
		if(a[num]!=a[num2]&&a[num]!=-1&&a[num2]!=-1&&a[num2]!=-2){
			a[num]=-1;
			a[num2]=-2;
			num++;
			num2=num;
			ans--;
		}else{
			if(num2==n){
				break;
			}
			num2++;
		}
	}
	cout<<ans;
	return 0;
}
