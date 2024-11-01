#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N], ap[N], c[N],x[10];string s[100];
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int k = 0;
	for(int i=1;;i++){
		if(pow(2,i)>=n){
			k=i;
			break;
		}
	}
	for(int i=1;i<=k;i++){
		string ss;
		cin>>ss;
		s[i] = ss;
	}
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<4;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			ap[i] = a[i]^x[i%4];
		}
		for(int i=1;i<=m;i++){
			int ans=0;
			int k = 0;
			for(int j=1;;j++){
				if(pow(2,j)>=c[j]){
					k=j;
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}