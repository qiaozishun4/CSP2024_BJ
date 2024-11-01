#include<bits/stdc++.h>
using namespace std;

int n,m;
int a1[114514];
int a[114514];
int c[114514];
int d[1048576];
long long num[1048576][20];
long long ans[1048576];

int work(){
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
    //cout<<"work!"<<endl;
    int ly=ceil(log10(n)/log10(2)),LY=ly;
    for(int i=1;i<=n;i++){
        ly=ceil(log10(n)/log10(2));
        int upd=i+(1<<ly)-1,adds=1;
        num[upd][0]=i;
        num[upd][19]=0;
        //if(!(upd&1))num[upd+1][19]=adds;
        for(;;upd>>=1,ly--){
            //cout<<i<<' '<<upd<<' '<<ly<<' '<<d[upd]<<endl;
            if(upd==i+(1<<ly)-1);else
            if(!d[upd])
                if(a[num[upd*2][0]]>=LY-ly){
                    num[upd][0]=num[upd*2][0];
                    for(int i=1;i<20;i++)num[upd][i]=0;
                }
                else {
                    for(int i=0;i<19;i++)if(num[upd*2+1][i]!=0&&a[num[upd*2+1][i]]>=LY-ly)num[upd][i]=num[upd*2+1][i];
                    num[upd][19]=num[upd*2+1][19];
                }
            else {
                if(num[upd*2+1][19]){
                    num[upd][0]=num[upd*2][0];
                    for(int i=1;i<19;i++)if(num[upd*2+1][i-1]!=0&&a[num[upd*2+1][i-1]]>=LY-ly)num[upd][i]=num[upd*2+1][i-1];
                    num[upd][19]=num[upd*2+1][19];
                }else {
                    bool flag=0;
                    for(int i=0;i<19;i++)if(num[upd*2+1][i]!=0&&a[num[upd*2+1][i]]>=LY-ly)num[upd][i]=num[upd*2+1][i],flag=1;
                    num[upd][19]=num[upd*2+1][19];
                    if(!flag)num[upd][0]=num[upd*2][0];
                }

            }
            
            if(!(upd&1))for(int i=0;i<20;i++)num[upd+1][i]=(i==19?adds:0);
            adds<<=1;
            //for(int i=0;i<20;i++)cout<<num[upd][i]<<' ';cout<<endl;
            if(upd-(1<<ly)==0){
                //for(int i=0;i<20;i++)cout<<num[upd][i]<<' ';cout<<endl;
                ans[i]=0;
                for(int j=0;j<19;j++)ans[i]+=num[upd][j];
                long long maxn=upd-(1<<ly)+adds;
                maxn/=2;
                ans[i]+=(maxn*(maxn+1)-(maxn-upd[num][19])*(maxn-upd[num][19]+1))/2;
                //cout<<ans[i]<<endl;
                break;
            }
        }
        
    }
    long long allans=0;
    for(int i=0;i<m;i++)allans^=((i+1)*ans[c[i]]);
    //for(int i=0;i<n;i++)cout<<ans[i]<<' ';cout<<endl;
    
    cout<<allans<<endl;
    return 0;
}

int main(){freopen("arena.in","r",stdin);
freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a1[i];
    for(int i=0;i<m;i++)cin>>c[i];
    string ss[20];
    int cnt=0,cnt2=0;
    for(int i=n;i;i>>=1,cnt++)cin>>ss[cnt];
    reverse(ss,ss+cnt);
    for(int i=0;i<cnt;i++){
        for(auto v:ss[i])d[++cnt2]=v-'0';
    }
    int t;
    cin>>t;
    while(t--){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)a[i]=a1[i]^x[i%4];
        work();
    }
    //cout<<"input over!"<<endl;
    return 0;
}//freopen
//I didn't have time to write something
//this code just can AC at simple#1
//I don't think this code can get any point
//F**K!
//I can just get 220 point
//maybe I can't 1=,then I must AFO
//hope get higher point in NOIP.

//love xyc forever.
