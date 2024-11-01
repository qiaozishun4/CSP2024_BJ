#include<bits/stdc++.h>
using namespace std;
int a[100010];
int Mmax=0;
    int n;
void dfs(int ad,char color[],int c[]){
    if(ad==n){
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
 //                   cout<<"color["<<i<<"]="<<color[i]<<" color["<<j<<"]="<<color[j]<<endl;
                if(color[i]==color[j]){
                    if(a[i]==a[j]){
                        c[i]=a[i];
                    }
                    break;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
 //           cout<<a[i]<<" ";
            sum+=c[i];
        }
 /*       cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;*/
        Mmax=max(Mmax,sum);
        return;
    }
    color[ad]='R';
    dfs(ad+1,color,c);
    color[ad]='B';
    dfs(ad+1,color,c);
}
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int c[100010];
        memset(c,0,sizeof(c));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        char color[100010];
        memset(color,'B',sizeof(color));
        dfs(1,color,c);
        cout<<Mmax<<endl;
        Mmax=0;
    }
    return 0;
}

