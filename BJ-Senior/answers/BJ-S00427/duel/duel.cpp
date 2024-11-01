#include<iostream>
using namespace std;
int a[100009];
int b[100009];
int maxi = -1;
int mini = 200000;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		a[tmp]++;
		b[tmp]++;
		maxi = max(maxi,tmp);
		mini = min(mini,tmp);
        }

	if(maxi==mini){
		printf("%d",n);
		return 0;
	}
	int ans = n;
	int l = mini,r = mini+1;
	while(l<maxi&&r<=maxi){
		if(a[l]<=b[r]){
			b[r]-=a[l];
			a[l] = 0;
			l++;
			
			if(l==r)r++;
		}
		else{
			a[l]-=b[r];
			b[r] = 0;
			r++;
		}
		
	}
	ans = 0;
	for(int i = mini;i<=maxi;i++){
		ans+=a[i];
	}
	printf("%d",ans);
	return 0;

}
