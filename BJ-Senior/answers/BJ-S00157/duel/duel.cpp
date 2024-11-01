#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int buc[100111];
int can, ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int tin=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&tin);
        buc[tin]++;
    }
    ans=n;
    for(int i=1;i<=100000;i++){
        if(buc[i]==0) continue;
        if(buc[i]>can){
            ans-=can;
            can=0;
        } else {
            ans-=buc[i];
            can-=buc[i];
        }
        can+=buc[i];
    }
    cout << ans << endl;
	return 0;
}
//?
