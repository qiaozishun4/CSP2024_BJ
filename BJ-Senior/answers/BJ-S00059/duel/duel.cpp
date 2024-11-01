#include <bits/stdc++.h>
using namespace std;
int n,r[100001][2]={0};
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int cnt=n,mx=0,mxcnt=1,mn=0x7f7f7f,mncnt=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i][0]);
        if(r[i][0]>mx) mx=r[i][0],mxcnt=1;
        else if(r[i][0]==mx) mxcnt++;
        if(r[i][0]<mn) mn=r[i][0],mncnt=1;
        else if(r[i][0]==mn) mncnt++;
    }
    if(mx<=2) cnt=max(mxcnt,mncnt);
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(r[i][0]>r[j][0]) swap(r[i][0],r[j][0]);
            }
        }
        for(int i=1;i<=n;i++){
            if(r[i][1]!=-1){
                for(int j=i+1;j<=n;j++){
                    if(r[j][1]!=-2&&r[j][0]>r[i][0]){
                        r[i][1]=-1;
                        r[j][1]=-2;
                        cnt--;
                        break;
                    }
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
