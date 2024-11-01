#include <iostream>
using namespace std;
int t,n,m,k,x0,y0,d0,ans;
int c[100086],s[100086],e[100086],a[100086];
string str;
bool q,tmp=false;
bool init(){
    if(q==0&&str[i]+[j+1]=='.')
        return true;
    }
    if(q==1&&str[i-1]+[j]=='.')
        return true;
    }
    if(q==2&&str[i]+[j-1]=='.')
        return true;
    }
    if(q==3&&str[i+1]+[j]=='.')
        return true;
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int k=1;k<=n;k++){
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        c[i]=x0;
        s[i]=y0;
        e[i]=d0;
        a[i]=k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>str;
            }
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=1;i<=n;j++){
            for(int k=1;k<=m;k++){
                if(ans==a[i]){
                    tmp=true;
                    break;
                }
                if(init(q)==true){
                    ans++;
                }
                else{
                    if(e[i]+1!=4){
                        e[i]++;
                    }
                    else{
                        e[i]=0;
                    }
                }
            }
            if(tmp==true){
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}