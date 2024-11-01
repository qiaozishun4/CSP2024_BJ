#include<bits/stdc++.h>
using namespace std;
int a[100010],d[100010],b[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    int n,k=1,p=1,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[p]==a[i]) d[k]++;
        else{
			b[k]=d[k];
			d[++k]=1;
			p=i;
		}
    }b[k]=d[k];
    for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k && b[i]>0;j++){
			int t=b[i]-d[j];
			b[i]=max(t,0);
			d[j]=t>=0?0:-t;
		}
		ans+=b[i];
	}
    printf("%d",ans);
    return 0;
}

