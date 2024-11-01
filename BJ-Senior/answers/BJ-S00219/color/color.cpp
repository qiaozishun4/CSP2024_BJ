#include<bits/stdc++.h>
using namespace std;
int n, a[200005],maxn,b[200005];
int main(){
    freopen("color.in","r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        maxn=0;
        int cnt=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
            maxn=max(a[i], maxn);
            b[i]=0;
        }
        int old=0;
        for(int i=maxn;i>0;i--){
            old=-1;
            for(int j=0;j<n;j++){
                if(a[j]==i){
                    if(old!=-1){
                        int c=0;
                        for(int k=old+1;k<j;k++){
                            if((c==0&&b[k]==0)||(c==1&&b[k]==2)||(c==2&&b[k]==1))c=c;
                            else if(c==0&&b[k]==1)c=2;
                            else if(c==0&&b[k]==2)c=1;
                            else if(c==b[k])c=-1;
                        }
                        if(c==-1)continue;
                        if(b[old]==0&&b[j]==0){
                            cnt+=a[j];
                            if(c==0){
                                b[old]=1;
                                b[j]=1;
                                for(int k=old+1;k<j;k++)b[k]=2;
                            }else if(c==2){b[old]=2,b[j]=2;for(int k=old+1;k<j;k++)b[k]=1;}
                            else if(c==1){b[old]=1,b[j]=1;for(int k=old+1;k<j;k++)b[k]=2;}
                        }else if(b[old]==b[j]){
                            //printf("%d\n", c);
                            cnt+=a[j];
                            if(c==1&&b[j]==1){for(int k=old+1;k<j;k++)b[k]=2;}
                            else if(c==2&&b[j]==2){for(int k=old+1;k<j;k++)b[k]=1;}
                            else if(c!=b[j])cnt-=a[j];
                            else if(b[j]==1)for(int k=old+1;k<j;k++)b[k]=2;
                            else if(b[j]==2)for(int k=old+1;k<j;k++)b[k]=1;
                        }else if(b[old]==0){
                            if(b[j]==2&&(c==2||c==0)){cnt+=a[j];for(int k=old+1;k<j;k++)b[k]=1;b[old]=b[j];}
                            else if(b[j]==1&&(c==1||c==0)){cnt+=a[j];for(int k=old+1;k<j;k++)b[k]=2;b[old]=b[j];}
                        }else if(b[j]==0){
                            //printf("%d %d %d\n", b[old], c, cnt);
                            if(b[old]==2&&(c==2||c==0)){cnt+=a[j];for(int k=old+1;k<j;k++)b[k]=1;b[j]=b[old];}
                            else if(b[old]==1&&(c==1||c==0)){cnt+=a[j];for(int k=old+1;k<j;k++)b[k]=2;b[j]=b[old];}
                        }
                    }
                    old=j;
                }
            }
            //for(int i=0;i<n;i++){
                //printf("%d ", b[i]);
            //}//printf("\n");
        }
        printf("%d\n", cnt);
    }
}
