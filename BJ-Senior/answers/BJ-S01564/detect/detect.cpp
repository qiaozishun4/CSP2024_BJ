#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int getint(){
    char c=getchar();
    int a=0;
    bool neg=0;
    while(c<'0'||c>'9'){
            if(c=='-'){
                neg=1;
            }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a=a*10+c-48;
        c=getchar();
    }
    return a;
}
int n,m,l,vm;
int d[100001],p[100001],rd[1000001],rd1[1000001],rd2[1000001];
int a[100001],v[100001];
bool mp[3001][3001];
int fvas(int a,int v,int s){
    if(v==0){
        return a;
    }
    return sqrt(a*a+2*v*s);
}
int fs(int a,int v,int t){
    if(v==0){
        return a*t;
    }
    return a*t+0.5*v*t*t;
}
int fvas2(int v1,int a,int v,int s){
    if(v==0){
        return -1;
    }
    return s+(v1*v1-a*a)/(2*v);
}
bool check2(int l,int r){
    if(l>r){
        return 0;
    }
    if(rd1[r]>=l){
        return 1;
    }
    return 0;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(rd,0,sizeof(rd));
        memset(rd1,0,sizeof(rd1));
        memset(mp,0,sizeof(mp));
        memset(rd2,0,sizeof(rd2));
        n=getint();m=getint();l=getint();vm=getint();
        for(int i=0;i<n;i++){
            d[i]=getint();
            v[i]=getint();
            a[i]=getint();
        }
        for(int i=0;i<m;i++){
            p[i]=getint();
            rd[p[i]]=i;
        }
        int la=0,la1=0;
        for(int i=0;i<=l;i++){
            if(rd[i]!=0){
                la=i;
                la1=rd[i];
            }
            rd1[i]=la;
            rd2[i]=la1;

        }
        int ans1=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                if(v[i]<=vm){
                    continue;
                }
                else{
                    if(check2(d[i],l)){
                        ans1++;
                    }
                }
            }
            else if(a[i]<0){
                if(v[i]<=vm){
                    continue;
                }
                int u=min(fvas2(vm,v[i],a[i],d[i]),l);
                if(check2(d[i],u)){
                    ans1++;
                }
            }
            else{
                int u=min(fvas2(vm,v[i],a[i],d[i]),l),t=l;
                if(check2(u,t)){
                    ans1++;
                }
            }
        }
        cout<<ans1<<' ';
        int ans2=m;
        for(int i=0;i<n;i++){
            int le=rd2[d[i]]+1;
            if(rd2[d[i]]!=rd2[d[i]-1]){
                le--;
            }
            int ri=rd2[min(fvas2(vm,v[i],a[i],d[i]),l)];
            for(int j=le;j<=ri;j++){
                mp[i][j]=1;
            }
        }
            for(int j=0;j<m;j++){
                bool f=1;
                for(int k=0;k<m;k++){
                    for(int i=0;i<n;i++){
                        if(mp[i][k]<mp[i][j]){
                            f=0;
                            break;
                        }
                    }
                    if(!f){
                        break;
                    }
                }
            if(f)ans2--;
            }
        cout<<m-ans2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
