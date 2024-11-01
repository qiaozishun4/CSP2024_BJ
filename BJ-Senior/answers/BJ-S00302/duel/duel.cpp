#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
bool gj[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int rmax=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rmax=max(rmax,a[i]);
	}
	if(rmax==2){
		int one=0,two=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) one++;
			if(a[i]==2) two++;
		}
		if(two>=one) cout<<two;
		else cout<<n-two;
	}
	else{
		sort(a+1,a+n+1);
		int outt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]<a[j]&&gj[j]==false){
					gj[j]=true;
					outt++;
				}
			}
		}
		cout<<n-outt;
	}
	return 0;
}