#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],ss;
bool box[N];
void DFS(int x){
	if(x==n+1){
		int ans=0;
		int lan=0,hong=0;
		for(int i=1;i<=n;i++){
			if(box[i]) lan++;
			else hong++;
			if(box[i]&&lan==1) continue;
			if(!box[i]&&hong==1) continue;
			for(int j=i-1;j>=1;j--){
				if(box[i]==box[j]){
					if(a[i]==a[j]) ans+=a[i];
					break;
				}
			}
		}
		ss=max(ss,ans);
		return;
	}
	for(int i=0;i<=1;i++){
		box[x]=i;
		DFS(x+1);
		box[x]=0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ss=0;
		DFS(1);
		cout<<ss<<'\n';
	}
	return 0;
}