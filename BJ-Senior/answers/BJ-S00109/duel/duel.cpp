#include<bits/stdc++.h>
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,r[100005],num=0,p,q1=0,q2=0,m;
    int ri[100005];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&r[i]);
        if(r[i]==1) q1=q1+1;
        if(r[i]==2) q2=q2+1;
        ri[i]=1;
    }
    if(q1+q2==n){
        m=q1-q2;
        if(m>0) printf("%d",q2+m);
        else printf("%d",q2);
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            if(r[j]<r[j-1] && r[j-1]!=0){
                p=r[j];
                r[j]=r[j-1];
                r[j-1]=p;
            }

        }
        for(int k=0;k<n;k++){
            if(r[k]>r[k+1] && r[k+1]!=0){
                p=r[k];
                r[k]=r[k+1];
                r[k+1]=p;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(r[i]>r[j] && ri[i]==1 && (ri[j]==1 || ri[j]==2)){
                ri[i]=2;
                ri[j]=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ri[i]==2 || ri[i]==1){
            num=num+1;
        }
    }
    printf("%d",num);
    return 0;
}