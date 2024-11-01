#include<bits/stdc++.h>
using namespace std;
char c[1002][1002];
int n,m,t,k,ans=1,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=m;i++){
            for(int i=1;i<=n;i++){
                cin>>c[i][j];
            }
        }
        for(int i=x;i<=n;i++){
            bool fl=true;
            for(int j=y;j<=m;j++){
                if(k==1){
                    k++;
                }
                if(d==0){
                    if(c[x][y+1]!='x' && ans<k){
                        y=y+1;
                        ans++;
                    }else if(c[x][y+1]=='x';){
                        d=(d+1)%4;
                        ans++;
                    }else if(ans==k){
                        cout<<ans<<endl;
                        ans=1;
                        fl=false;
                        break;
                    }
                }else if(d==1){
                    if(c[x+1][y]!='x' && ans<k){
                        y=y+1;
                        ans++;
                    }else if(c[x+1][y]=='x';){
                        d=(d+1)%4;
                        ans++;
                    }else if(ans==k){
                        cout<<ans<<endl;
                        ans=1;
                        fl=false;
                        break;
                    }
                }
                else if(d==2){
                    if(c[x][y-1]!='x' && ans<k){
                        y=y+1;
                        ans++;
                    }else if(c[x][y-1]=='x';){
                        d=(d+1)%4;
                        ans++;
                    }else if(ans==k){
                        cout<<ans<<endl;
                        ans=1;
                        fl=false;
                        break;
                    }
                }else{
                    if(c[x-1][y]!='x' && ans<k){
                        y=y+1;
                        ans++;
                    }else if(c[x-1][y]=='x';){
                        d=(d+1)%4;
                        ans++;
                    }else if(ans==k){
                        cout<<ans<<endl;
                        ans=1;
                        fl=false;
                        break;
                    }
                }
            }
            if(fl=false)break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}