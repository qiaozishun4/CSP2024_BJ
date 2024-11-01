#include<bits/stdc++.h>
using namespace std;
int a,b[1000005],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&b[i]);
	}
	sort(b+1,b+a+1);
	int l=2,r=1;
	ans=a;
	while(1){
		if(l==a+1)break;
		if(b[l]>b[r]){
			ans--;
			l++;
			r++;
		}else{
			l++;
		}
	}
	printf("%d",ans);
}
