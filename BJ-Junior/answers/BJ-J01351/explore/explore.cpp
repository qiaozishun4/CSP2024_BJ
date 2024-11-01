#include<bits/stdc++.h>
using namespace std;
int sx,sy,d,n,m,t;
char a[10010][10010];
bool in(int x, int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}


int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>m>>t;
        cin>>sx>>sy>>d;
        int ssx=sx,ssy=sy;

        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>a[j][k];
            }
        }
        int cnt=0,step=1;
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(t==0){
                    goto p;
                }
                if(step%2==0){
                    if(d==0&&(!in(ssx,ssy+1)||a[ssx][ssy+1]=='x')){
                        d=(d+1)%4;
                    }else if(d==1&&(!in(ssx+1,ssy)||a[ssx+1][ssy]=='x')){
                        d=(d+1)%4;
                    }else if(d==2&&(!in(ssx,ssy-1)||a[ssx][ssy-1]=='x')){
                        d=(d+1)%4;
                    }else if(d==3&&(!in(ssx-1,ssy)||a[ssx-1][ssy]=='x')){
                        d=(d+1)%4;
                    }
                    if(d==0&&(in(ssx,ssy+1)&&a[ssx][ssy+1]=='.')){
                        a[ssx][ssy+1]='1';
                        ssy+=1;
                        cnt++;
                    }else if(d==1&&(in(ssx+1,ssy)&&a[ssx+1][ssy]=='.')){
                        a[ssx+1][ssy]='1';
                        ssx+=1;
                        cnt++;
                    }else if(d==2&&(in(ssx,ssy-1)&&a[ssx][ssy-1]=='.')){
                        a[ssx][ssy-1]='1';
                        ssy-=1;
                        cnt++;
                    }else if(d==3&&(in(ssx-1,ssy)&&a[ssx-1][ssy]=='.')){
                        a[ssx-1][ssy]='1';
                        ssx-=1;
                        cnt++;
                    }

                }else if(step%2==1&&in(ssx,ssy)){
                    if(d==0&&a[ssx][ssy+1]!='1'){
                        a[ssx][ssy+1]='1';
                        ssy+=1;
                    }else if(d==1&&a[ssx+1][ssy]!='1'){
                        a[ssx+1][ssy]='1';
                        ssx+=1;
                    }else if(d==2&&a[ssx][ssy-1]!='1'){
                        a[ssx][ssy-1]='1';
                        ssy-=1;
                    }else if(d==3&&a[ssx-1][ssy]!='1'){
                        a[ssx-1][ssy]='1';
                        ssx-=1;
                    }
                    cnt++;

                }

                t--;
                step++;

            }
        }
        p:;
        cout<<cnt<<"\n";

    }
    return 0;
}
