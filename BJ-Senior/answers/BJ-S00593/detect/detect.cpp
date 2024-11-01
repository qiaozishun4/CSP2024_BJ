#include<bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a;
}s[100005];
int check[100005];
int hash_c[1000005],hash_[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>s[i].d>>s[i].v>>s[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>check[i];
            hash_c[check[i]]=1;
            hash_[check[i]]=1;
        }
        int num=0;
        for(int i=1;i<=n;i++){
            if(s[i].a<=0){
                if(s[i].v<=V){
                    continue;
                }
                else{
                    for(int j=s[i].d;j<=l;j++){
                        if(hash_[j]==1&&sqrt((j-s[i].d)*s[i].a*2+s[i].v*s[i].v)>V){
                            hash_c[j]=0;
                            //cout<<i<<endl;
                            num++;
                            break;
                        }
                    }
                }
            }
            else{
                if(int(s[i].d+0.5*V*V/s[i].a-0.5*s[i].v*s[i].v/s[i].a+1)<l){
                    for(int j=int(s[i].d+0.5*V*V/s[i].a-0.5*s[i].v*s[i].v/s[i].a+1);j<=l;j++){
                        if(hash_[j]==1){
                            hash_c[j]=0;
                            num++;
                            //cout<<i<<endl;
                            break;
                        }
                    }
                }
                else{
                    continue;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=l;i++){
            cnt+=(hash_c[i]==1);
            hash_[i]=0,hash_c[i]=0;
        }
        cout<<num<<" "<<cnt<<endl;
    }
    return 0;
}
