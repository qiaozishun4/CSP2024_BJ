#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<16){
            for(int i=1;i<=n;i++)scanf("%d",&a[i]);
            int wdc=1<<n;
            int tot=0;
            for(int i=0;i<wdc;i++){
                int cur=0;
                for(int j=1;j<=n;j++){
                    int c=((1<<(j-1))&i);
                    for(int k=j-1;k>=1;k--){
                        int dsjfk=((1<<(k-1))&i);
                        if((c>0&&dsjfk>0)||(c==0&&dsjfk==0)){
                            if(a[j]==a[k]){
                                cur+=a[j];
                            }
                            break;
                        }
                    }
                }
                tot=max(tot,cur);
            }
            printf("%d\n",tot);
        }
    }
    return 0;
}
