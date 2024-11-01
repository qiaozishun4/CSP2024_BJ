#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],pai[100005],n=0;
bool c[100005];
int search(int m){
    if(m==0)return 0;
    for(int i=1;i<=n;i++){
        if(pai[i]==m)return i;
    }
    return search(m-1);
}
bool bsearch(int m){
    for(int i=1;i<=n;i++){
        if(pai[i]==m)return true;
    }
    return false;
}
bool nosearch(int u,int l){
    for(int i=1;i<=n;i++){
        if(pai[i]==u&&i!=l)return true;
    }
    return false;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int num=0,ans=0;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(a[i]<=2)num++;
    }
    if(num==n){
        int q=0,w=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)q++;
            if(a[i]==2)w++;
        }
        cout<<w+max(0,q-w);
        return 0;
    }
    int maxn=-1,maxop=0,cnt=1,rnt=0;
    while(1){
        for(int j=1;j<=n;j++){
            if(b[j]>maxn){
                maxn=b[j];
                maxop=j;
            }
        }
        if(maxn==0)break;
        pai[maxop]=cnt;b[maxop]=0;
        for(int j=1;j<=n;j++){
            if(b[j]==maxn){
                pai[j]=cnt;
                b[j]=0;
            }
        }
        cnt++;maxn=-1;
    }
    cnt--;rnt=cnt-1;
    while(1){
        while(1){if(!bsearch(cnt)){cnt--;}else{break;}if(cnt<=0){break;}}
        while(1){if(!bsearch(cnt-1)){rnt--;}else{break;}if(rnt<=0){break;}}
        int k=search(cnt),s=search(rnt);
        //cout<<k<<"-"<<s<<" ";
        while(c[s]==1){
            if(bsearch(rnt))s=nosearch(rnt,search(rnt));
            else s=nosearch(rnt-1,search(rnt));
        }
        //cout<<k<<"-"<<s<<" ";
        if(k<=0||s<=0||rnt>=cnt)break;
        //cout<<k<<"-"<<s<<" ";
        pai[k]=0;
        c[s]=1;
        //for(int i=1;i<=n;i++){
        //    cout<<pai[i]<<" ";
        //}cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(pai[i])ans++;
    }
    cout<<ans;
    return 0;
}
