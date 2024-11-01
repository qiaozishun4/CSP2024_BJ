#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int x=0,f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    return x*f;
}
void read(int &x){
    int f=1; x=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    x*=f;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    putchar(x%10+'0');
}
const int N=1e5+5;
string dp[N];
int num[15]={6,2,5,5,4,5,6,3,7,6};
const int inf=0x3f3f3f3f;
string mm(string a,string b){
    if(a=="yjh") return b;
    if(a.size()<b.size()) return a;
    else if(a.size()>b.size()) return b;
    else return min(a,b);
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=1;i<=N-5;i++) dp[i]="yjh";
    dp[2]="1";
    dp[3]="7";
    dp[4]="4";
    dp[5]="2";
    dp[6]="6";
    dp[7]="8";
    for(int i=8;i<=21;i++){
        for(int j=1;j<=7;j++){
            if(dp[j]=="yjh") continue;
            if(dp[i-j]=="yjh") continue;
            if(j==6) dp[i]=mm(dp[i],dp[i-j]+"0");
            else dp[i]=mm(dp[i],dp[i-j]+dp[j]);
        }
    }
    int T=read();
    while(T--){
        int n=read();
        int l=(n+6)/7;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(l<=3) cout<<dp[n]<<endl;
        else{
            cout<<dp[(n-1)%7+15];
            for(int i=4;i<=l;i++) putchar('8');
            puts("");
        }
    }
    return 0;
}
