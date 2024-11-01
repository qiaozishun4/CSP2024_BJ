#include<bits/stdc++.h>
using namespace std;
int t,ab;
int n,k,q,l,qq;
int r[1000014],c[1000014];
int num[114514];
struct node{
    int s[100014],ok,sn;
}a[100014];
void dfs(int x,int y,int cc,int b,int head){//dangqianderen,zhegezifushiyigerenzhongdedijige,xuyaoxuliedejiewei,yijingjielejige,dangqianxuliedekaitou
    if(b>qq) return;
    if(b<=qq&&head==1){
        ab=1;
        cout<<1<<endl;
        return;
    }
    for(int i=y-1;i>=1;i++){
        if(num[a[x].s[i]]>1&&y-i+1<=k){
            for(int j=1;j<=n;j++){
                if(j==x) continue;
                for(int o=1;o<=a[j].sn;o++){
                    if(a[j].s[o]==a[x].s[i]&&o!=1){
                        dfs(j,o,a[j].s[o],b+1,a[x].s[o]);
                    }
                }
            }
        }
    }
    cout<<"0"<<endl;
    return;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i].sn;
            for(int j=1;j<=a[i].sn;j++){
                cin>>a[i].s[j];
                num[a[i].s[j]]++;
            }
        }
        for(int o=1;o<=q;o++){
            cin>>r[o]>>c[o];
            qq=r[o];
            if(num[c[o]]==0){
                cout<<"0"<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=a[i].sn;j++){
                    if(a[i].s[j]==c[o]&&j!=1){
                        dfs(i,j,c[o],1,0);
                    }
                    if(ab==1) break;
                }
                if(ab==1){
                    ab=0;
                    break;
                }
            }
        }
    }
    return 0;
}
