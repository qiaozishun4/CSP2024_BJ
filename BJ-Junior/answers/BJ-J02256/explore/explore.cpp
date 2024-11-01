#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
char s[1001];
bool vis[1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x0,y0,d0,ans=0,cnt;
    char tmpchar;
    cin>>t;
    for(int i=0;i<t;i++){
        scanf("%d %d %d\n%d %d %d\n",&n,&m,&k,&x0,&y0,&d0);
        d0%=4;
        if(n==1){
            if(m<3){
                cin>>s[1]>>tmpchar>>s[2]>>tmpchar;
                if(x0==1){
                    if(d0%2==1 || d0==2)cout<<1;
                    else if(s[2]=='.')cout<<2;
                    else cout<<1;
                }
                else{
                    if(d0%2==1 || d0==4)cout<<1;
                    else if(s[1]=='.')cout<<2;
                    else cout<<1;
                }
                ans=0;
                strcpy(s,"");
                continue;
            }
            cerr<<n<<' '<<m<<' '<<k<<' '<<x0<<' '<<y0<<' '<<d0<<endl;
            for(int j=0;true;j++){
                scanf("%c%c",&s[j],&tmpchar);
                if(tmpchar=='\n')break;
            }
            cerr<<s<<endl;
            for(;k>0;k--){
                if(d0%2==1){
                    d0=(d0+1)%4;
                    cerr<<k<<' '<<"xyz"<<endl;
                }else if(d0==2){
                    if(y0-1<1 || s[y0-1]!='.'){
                        d0=(d0+1)%4;
                        cerr<<k<<' '<<"xyz"<<endl;
                        continue;
                   }else{
                        y0--;
                        if(!vis[y0]){
                            vis[y0]=true;
                            ans++;
                            cerr<<k<<' '<<ans<<endl;
                        }
                   }
                }else if(d0==0){
                    if(y0+1>m || s[y0+1]!='.'){
                        d0=(d0+1)%4;
                        cerr<<k<<' '<<"xyz"<<endl;
                        continue;
                    }else{
                        y0++;
                        if(!vis[y0]){
                            vis[y0]=true;
                            ans++;
                            cerr<<k<<' '<<ans<<endl;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
        strcpy(s,"");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
