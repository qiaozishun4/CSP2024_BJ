#include <bits/stdc++.h>
using namespace std;
int n,ans;
char s1,s2,a[60],b[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	ans=52-n;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=i-1;j>=1;j--){
			if(s1==a[j]&&s2==b[j]){
				ans++;
				a[i]=0,b[i]=0;
				break;
			}
		}
		a[i]=s1;
		b[i]=s2;
	}
	cout<<ans;
	return 0;
}
