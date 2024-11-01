#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m;
int lg[131500];
int abase[100050];
int a[100050];
int q[100050];
string s[20];
int wn[18][131500];
bool op[18][131500];
//round-fight
int lp[18][131500];
int rp[18][131500];
void dfs(int step,int base){
    if(step!=1){
        dfs(step-1,base<<1);
    }else{

    }
    for(int i=1;i<=base;i++){
        lp[step][i]=lp[step+1][i*2-1];
        rp[step][i]=rp[step+1][i*2];
        if(s[step][i]=='0'){
            if(a[wn[step-1][i*2-1]]>=step){
                wn[step][i]=wn[step-1][i*2-1];
                op[step][i]=1;
            }
            else{
                wn[step][i]=wn[step-1][i*2];
                op[step][i]=0;
            }

        }else{
            if(a[wn[step-1][i*2]]>=step)wn[step][i]=wn[step-1][i*2];
            else wn[step][i]=wn[step-1][i*2-1];
        }
    }
}
int tar;
int ans=0;
void dfs2(int nw,int hg){
    if(hg>=tar)return;
    if(nw%2==0){
        //you
        if(op[hg+1][(nw+1)<<1]==0)ans=lp[hg][nw+1];
    }
    dfs(nw/2,hg+1);
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    long long base=1;
    long long tms=0;
    for(;tms<=17;tms++){
        lg[base]=tms;
        base=base<<1;
    }
    for(int i=131072;i>=2;i--){
        if(!lg[i])lg[i]=lg[i+1];
    }
    //cout<<lg[256];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>abase[i];
    }
    bool op1=1;
    for(int i=1;i<=m;i++){
        cin>>q[i];
        if(q[i]!=1&&lg[q[i]]==lg[q[i]+1])op1=false;
    }
    bool op2=1;
    for(int i=1;i<=lg[n];i++){
        cin>>s[i];s[i]='-'+s[i];
    }
    int t;cin>>t;while(t--){
        int k[4];for(int i=0;i<4;i++)cin>>k[i];
        for(int i=1;i<=n;i++){
            a[i]=abase[i]^k[i%4];
            wn[0][i]=i;
        }
        int mx=(1<<lg[n]);
        for(int i=1;i<=mx;i++)lp[0][i]=rp[0][i]=i;
        //cout<<endl;
        if(op1){
            dfs(lg[n],1);
            long long ans=0;
            for(long long i=1;i<=m;i++){
                if(q[i]==1){
                    ans^=(i);
                }else{
                    ans^=(i*wn[lg[q[i]]][1]);
                }
            }
            cout<<ans<<endl;
        }
        if(op2){
            dfs(lg[n],1);
            long long anser=0;
            for(long long i=1;i<=m;i++){
                if(q[i]==1){
                    anser^=(i);
                }else{
                    if(lg[q[i]]!=lg[q[i]+1])anser^=(i*wn[lg[q[i]]][1]);
                    else{
                        tar=lg[q[i]];
                        ans=q[i]+1;
                        dfs2(q[i]+1,0);
                        anser^=(i*(wn[lg[q[i]]][1]+((mx-ans)+(mx))*(mx-ans+1)/2));
                    }
                }
            }
            cout<<anser<<endl;
        }
    }
}
