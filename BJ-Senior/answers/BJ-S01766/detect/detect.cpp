#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long ret=0;
    long long w=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-'){
            w=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch)){
        ret=(ret<<1)+(ret<<3)+ch-'0';
        ch=getchar();
    }
    return ret*w;
}
void written(long long ret){
    if(ret>9){
        written(ret/10);
    }
    putchar(ret%10+'0');
    return;
}
void write(long long ret){
    if(ret<0){
        putchar('-');
        ret=-ret;
    }
    written(ret);
    return;
}
struct str{
    double d,v,a;
}car[100005];
int T;
int n,m;
int L,V;
int cntfast;
double fastl[100005];
double fastr[100005];
bool toofast[100005];
int p[100005];
int pre[1000006];
bool choose[100005];
int ans,cnt;
void solve1(int id){
    if(car[id].v<=V){
        return;
    }
    fastl[id]=car[id].d;
    fastr[id]=(double)L;
    if(pre[(int)fastr[id]]-pre[(int)fastl[id]-1]>0){
        cntfast++;
        toofast[id]=true;
        // cout<<id<<endl;
    }
}
void solve2(int id){
    if(car[id].v>V){
        fastl[id]=car[id].d;
        fastr[id]=(double)L;
        if(pre[(int)fastr[id]]-pre[(int)fastl[id]-1]>0){
            cntfast++;
            toofast[id]=true;
            // cout<<id<<endl;
        }
    }else if(car[id].v==V){
        fastl[id]=car[id].d+1;
        fastr[id]=(double)L;
        if(pre[(int)fastr[id]]-pre[(int)fastl[id]-1]>0){
            cntfast++;
            toofast[id]=true;
            // cout<<id<<endl;
        }
    }else{
        double fz=V*V-(car[id].v*car[id].v);
        double fm=2*car[id].a;
        double plc=fz/fm+car[id].d;
        fastl[id]=(double)ceil(plc);
        fastr[id]=(double)L;
        if(pre[(int)fastr[id]]-pre[(int)fastl[id]-1]>0){
            cntfast++;
            toofast[id]=true;
            // cout<<id<<endl;
        }
    }
    return;
}
void solve3(int id){
    if(car[id].v<=V){
        return;
    }else{
        double fz=V*V-(car[id].v*car[id].v);
        double fm=2*car[id].a;
        double plc=fz/fm+car[id].d;
        fastl[id]=car[id].d;
        fastr[id]=(double)floor(plc);
        // cout<<plc<<' '<<fz<<' '<<fm<<endl;
        if(pre[(int)fastr[id]]-pre[(int)fastl[id]-1]>0){
            cntfast++;
            toofast[id]=true;
            // cout<<id<<endl;
        }
    }
    return;
}
bool check(){
    for(int i=1;i<=n;i++){
        if(toofast[i]==false){
            continue;
        }
        bool flag=false;
        for(int j=1;j<=m;j++){
            if(choose[j]==false){
                continue;
            }
            if(p[j]>=fastl[i] && p[j]<=fastr[i]){
                flag=true;
            }
        }
        if(flag==false){
            return false;
        }
    }
    return true;
}
void dfs(int dep){
    if(check()){
        ans=min(ans,cnt);
        // for(int i=1;i<=m;i++){
        //     if(choose[i]){
        //         cout<<i<<' ';
        //     }
        // }
        // cout<<endl;
        return;
    }
    if(dep>m){
        return;
    }
    dfs(dep+1);
    choose[dep]=true;
    cnt++;
    dfs(dep+1);
    cnt--;
    choose[dep]=false;
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        m=read();
        L=read();
        V=read();
        cntfast=0;
        memset(toofast,0,sizeof(toofast));
        memset(p,0,sizeof(p));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=100002;i++){
            fastl[i]=0.0;
            fastr[i]=0.0;
            car[i]={0.0,0.0,0.0};
        }
        if(n<=20 && m<=20){
            for(int i=1;i<=n;i++){
                car[i].d=(double)read();
                car[i].v=(double)read();
                car[i].a=(double)read();
            }
            for(int i=1;i<=m;i++){
                p[i]=read();
                pre[p[i]]=1;
            }
            for(int i=1;i<=1000002;i++){
                pre[i]=pre[i]+pre[i-1];
            }
            for(int i=1;i<=n;i++){
                if(car[i].a==0.0){
                    solve1(i);
                }else if(car[i].a>0.0){
                    solve2(i);
                }else{
                    solve3(i);
                }
            }
            // for(int i=1;i<=n;i++){
            //     cout<<fastl[i]<<' '<<fastr[i]<<endl;
            // }
            write(cntfast);
            putchar(' ');
            ans=2147483647;
            cnt=0;
            dfs(1);
            write(m-ans);
            putchar(10);
        }
        for(int i=1;i<=n;i++){
            car[i].d=(double)read();
            car[i].v=(double)read();
            car[i].a=(double)read();
        }
        for(int i=1;i<=m;i++){
            p[i]=read();
            pre[p[i]]=1;
        }
        for(int i=1;i<=1000002;i++){
            pre[i]=pre[i]+pre[i-1];
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(car[i].a!=0.0){
                flag=false;
                break;
            }
        }
        if(flag){
            // cout<<T<<endl;
            for(int i=1;i<=n;i++){
                solve1(i);
            }
            write(cntfast);
            putchar(' ');
            write(m-1);
            putchar(10);
        }
        flag=true;
        for(int i=1;i<=n;i++){
            if(car[i].a<=0.0){
                flag=false;
                break;
            }
        }
        if(flag){
            // cout<<T<<endl;
            for(int i=1;i<=n;i++){
                solve2(i);
            }
            write(cntfast);
            putchar(' ');
            write(m-1);
            putchar(10);
        }
    }
    return 0;
}