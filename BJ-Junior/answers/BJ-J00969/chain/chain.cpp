#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],h[200010];
int flag,n,k;
void dfs(int cur,int endt,int last,int lp){
    if(cur==0){
        if(last==endt)flag=1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==lp)continue;
        for(int j=1;j<=1010;j++){
			if(a[i][j]==last){
                for(int len=2;len<=k;len++){
                    dfs(cur-1,endt,a[i][j+len-1],i);
                    if(flag==1)return;
                }
			}
        }
    }
}
int main(){
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
                h[a[i][j]]++;
            }
        }
        for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			if(h[c]==0)cout<<0<<endl;
			else{
				dfs(r,c,1,0);
				cout<<flag<<endl;
			}
			flag=0;
		}
    }
    return 0;
}