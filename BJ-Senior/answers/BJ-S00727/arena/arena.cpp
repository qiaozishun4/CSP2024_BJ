#include <bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int n,m;
int a[MAXN],c[MAXN];//c[i]表示前缀长度。

int solvek(int n){
    int t=1;
    for(int i=1;i<=n;i++){
        if(t>=n) return i;
        t=t*2;
    }
}
/*int solve1(int x){
    int ans=1;
    for(int i=1;i<=x;i++)
        ans*=2;
    return ans;
}//2的x次方*/
int T;
int power[4][MAXN];
int Real[MAXN][260];//前n后t
int yihuo(int a,int b){
    bool a2[MAXN],b2[MAXN],c2[MAXN];
    memset(a2,0,sizeof(a2));
    memset(b2,0,sizeof(b2));
    memset(c2,0,sizeof(c2));
    int n1,n2;
    for(int i=0;i<a;i++){
        if(1<<i > a){
            n1=i;
            break;
        }else if(1<<i == a){
            n1=i+1;
            break;
        }
    }
    for(int i=0;i<b;i++){
        if(1<<i > b){
            n2=i;
            break;
        }else if(1<<i == b){
            n2=i+1;
            break;
        }
    }
    //cout<<n1<<n2<<endl;
    for(int i=1;i<=n1;i++){
        a2[n1-i]=a%2;
        a/=2;
        //cout<<a2[n1-i];
    }
    //cout<<endl;
    for(int i=1;i<=n2;i++){
        b2[n2-i]=b%2;
        b/=2;
        //cout<<b2[n2-i];
    }
    //cout<<endl;
    for(int i=1;i<=max(n1,n2);i++){
        if(a2[i]!=b2[i]){
            c2[i]=0;
        }else{
            c2[i]=1;
        }
        //cout<<c2[i];
    }
    //cout<<endl;
    int ans=0;
    for(int i=1;i<=max(n1,n2);i++){
        ans+=c2[i]*(1<<(i-1));
    }

    return ans;
}

int k;//轮数
bool solve2(int x){
    int i=0;
    while(i<=x){
        if(x==1){
            k=i;
            return true;
        }
        if(x%2==1) return false;
        x/=2;
        i++;
    }
}//判断✖是不是2的整数次密

/*int need(int x){
    int ne;
    for(int i=0;i<=1<<(x-1);i++){
        if(solve2(n+i))
            ne=i;
    }
    return ne;
}
*/
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int K;
    K=solvek(n);
    bool game[MAXN][MAXN];
    for(int i=1;i<=K;i++){
        for(int j=1;j<=1<<(K-i);j++){
            cin>>game[i][j];
        }
    }
    cin>>T;
/*
    for(int z=1;z<=T;z++){
        int sum=0;
        cin>>power[1][z]>>power[2][z]>>power[3][z]>>power[4][z];
        bool vis[MAXN];
        int nt=c[z];//+need(c[i])
        memset(vis,1,sizeof(vis));
        for(int i=1;i<=n;i++){
            Real[i][z]=yihuo(power[i%4][i],a[i]);
        }

        for(int i=1;i<=k;i++){
            for(int j=1;j<=nt/2;j+=2){
                int z_index=j;
                if(game[i][j]){
                    z_index=j+1;
                }
                if(Real[z_index][z]>=i){
                    vis[z_index+1]=0;
                }else{
                    vis[z_index]=0;
                }
            }
            nt/=2;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                sum+=i;
                break;
            }
        }
        cout<< sum<<endl;
    }
    //int a1=5,a2=8;
    //cout<<yihuo(a1,a2);



    /*int need;

    for(int i=0;i<=1<<(n-1);i++){
        if(solve2(n+i)){
            need=i;
        }
    }*/


    return 0;
}
