#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],f[N],len;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	len=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]>a[j]&&f[j]!=1&&f[i]!=1&&f[i]!=2){
					len--;
					f[j]=1;
					f[i]=2;
				}
			}
		}
	cout<<len;
	return 0;
}