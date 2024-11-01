#include<bits/stdc++.h>
using namespace std;
int n,a[100005],s,live,m1,m2;
bool use[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	live=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) m1++;
		if(a[i]==2) m2++;
		use[i]=true;
	}
	sort(a+1,a+n+1);
	if((m1+m2)==n){
		cout<<max(m1,m2)<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]&&use[j]==true){
				live--;
				use[j]=false;
				break;
			}
		}
	}
	cout<<live<<endl;
	return 0;
}
