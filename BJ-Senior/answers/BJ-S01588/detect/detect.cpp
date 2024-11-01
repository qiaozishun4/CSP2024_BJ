#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T;
int n,m,l,V;
int d[100010],v[100010],a[100010];
int p[100010];
int ans1=0,ans2=0;
bool flag=true;
bool p1[110][110],pcmp[110][110];
bool car[100010],carcmp[100010];
int pshut[100010];//1kai 2guan 3bukaolv guan

bool check(){
    for(int i=1;i<=n;i++){
        carcmp[i]=false;
        for(int j=1;j<=m;j++){
            pcmp[i][j]=false;
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pshut[j]!=1){
                continue;
            }
            if(p[j]<d[i]){
                continue;
            }
            double v1=sqrt(2*a[i]*(p[j]-d[i])+pow(v[i],2));
            if(v1<=0){
                break;
            }
            if(v1>V*1.0){
                pcmp[i][j]=true;
            }
        }
        for(int j=1;j<=m;j++){
            if(pcmp[i][j]==true){
                carcmp[i]=true;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(car[i]!=carcmp[i]){
            return false;
        }
    }
    return true;

}
int count1(){
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(pshut[i]==2||pshut[i]==3){
            cnt++;
        }
    }
    return cnt;


}
void dfs(int x){
    if(x>=m+1){
        if(check()==true){
            ans2=max(ans2,count1());
        }

        return;
    }
    if(pshut[x]!=3){
        pshut[x]=1;
        dfs(x+1);
        pshut[x]=2;
        dfs(x+1);
        pshut[x]=0;
    }else{
        dfs(x+1);
    }



}

void init(){
    ans1=0;
    ans2=0;
    for(int i=1;i<=n;i++){
        car[i]=false;

        for(int j=1;j<=m;j++){
            p1[i][j]=false;

        }
    }

    for(int i=1;i<=m;i++){
        pshut[i]=0;
    }


}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans1=0;
        ans2=0;
        flag=true;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i]<0){
                flag=false;
            }
        }

        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        if(flag==true){
            int pmax=0;
            for(int i=1;i<=m;i++){
                pmax=max(p[i],pmax);
            }
            for(int i=1;i<=n;i++){
                if(d[i]>pmax){
                    continue;
                }
                double v1=sqrt(2*a[i]*(pmax-d[i])+pow(v[i],2));
                if(v1>V*1.0){
                    ans1++;
                    ans2=m-1;
                }

            }
            if(ans1==0){
                ans2=m;
            }
            printf("%d %d\n",ans1,ans2);
            continue;
        }



        init();
        int pmax=0;
        for(int i=1;i<=m;i++){
            pmax=max(p[i],pmax);
        }
        for(int i=1;i<=n;i++){
            if(d[i]>pmax){
                continue;
            }
            for(int j=1;j<=m;j++){
                if(p[j]<d[i]){
                    continue;
                }
                double v1=sqrt(2*a[i]*(p[j]-d[i])+pow(v[i],2));
                if(v1<=0){
                    break;
                }
                if(v1>V*1.0){
                    p1[i][j]=true;

                }
            }
            for(int j=1;j<=m;j++){
                if(p1[i][j]==true){
                    ans1++;
                    car[i]=true;
                    break;
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                if(p1[i][j]==true){
                    break;
                }
                if(i==n){
                    pshut[j]=3;
                }
            }
        }

        dfs(1);
        printf("%d %d\n",ans1,ans2);
    }


    return 0;
}
