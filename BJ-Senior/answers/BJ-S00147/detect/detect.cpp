#include<bits/stdc++.h>
using namespace std;
double n,m,k,x,v[100005],a[100005],t[5005][5005],d[100005],w[100005],ans1,s[5005][5005],e,y,T;
int ll(int l,int r){
    int o=0,p=0;
    for(int i=1;i<=n;i++){
        o=0;
        for(int j=l;j<=r;j++){
            if(s[i][j]==1){
               o=1;
               break;
            } 
        }
        if(o==1) p++;
    }
    if(p==ans1) return 1;
    else return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans1=0;
		cin>>n>>m>>k>>x;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>w[i];
        for(int i=1;i<=n;i++){
            int f=0;
            for(int j=1;j<=m;j++){
                if(d[i]<w[j]) t[i][j]=sqrt(v[i]*v[i]+2*a[i]*(w[j]-d[i]));
                if(t[i][j]>x) s[i][j]=1;
                if(t[i][j]>x) f=1;
            }
            if(f==1) ans1++; 
        }
        cout<<ans1<<" ";
        int e=0;
        for(int i=1;i<=m;i++){
            if(ll(i,i)==1){
               e=1;
               break;
            }
        }
        if(e==1) cout<<m-1<<endl;
        else cout<<m-2<<endl;
    }
    return 0;
}
