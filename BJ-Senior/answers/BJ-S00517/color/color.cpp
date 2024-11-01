#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
inline int read(){
    int s=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n;
int a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T=read();
    while(T--){
        n=read();int ans=-1;
        for(int i=1;i<=n;i++){a[i]=read();}
        for(int i=0;i<(1<<n);i++){
            stack<int>r,b;int tt=0;
            while(!r.empty()){r.pop();}
            while(!b.empty()){r.pop();}
            for(int j=1;j<=n;j++){
                if(i&(1<<(j-1))){
                    if(!r.empty()){
                        int tmp=r.top();
                        if(tmp==a[j]){tt+=a[j];}
                    }
                    r.push(a[j]);
                }
                else{
                    if(!b.empty()){
                        int tmp=b.top();
                        if(tmp==a[j]){tt+=a[j];}
                    }
                    b.push(a[j]);
                }
            }
            ans=max(ans,tt);
        }
        cout<<ans<<endl;
    }
    return 0;
}
