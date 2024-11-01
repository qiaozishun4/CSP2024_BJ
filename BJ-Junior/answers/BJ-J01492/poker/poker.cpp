#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,ans,b[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
        char s[5];
        cin>>s;
        ll t,x;
        if(s[0]=='D'){
            t=0;
            if('2'<=s[1]&&s[1]<='9'){
                x=t+s[1]-'0';
            }else{
                if(s[1]=='A') x=t+1;
                if(s[1]=='T') x=t+10;
                if(s[1]=='J') x=t+11;
                if(s[1]=='Q') x=t+12;
                if(s[1]=='K') x=t+13;
            }
            b[x]=1;
        }else if(s[0]=='C'){
            t=20;
            if('2'<=s[1]&&s[1]<='9'){
                x=t+s[1]-'0';
            }else{
                if(s[1]=='A') x=t+1;
                if(s[1]=='T') x=t+10;
                if(s[1]=='J') x=t+11;
                if(s[1]=='Q') x=t+12;
                if(s[1]=='K') x=t+13;
            }
            b[x]=1;
        }else if(s[0]=='H'){
            t=40;
            if('2'<=s[1]&&s[1]<='9'){
                x=t+s[1]-'0';
            }else{
                if(s[1]=='A') x=t+1;
                if(s[1]=='T') x=t+10;
                if(s[1]=='J') x=t+11;
                if(s[1]=='Q') x=t+12;
                if(s[1]=='K') x=t+13;
            }
            b[x]=1;
        }else if(s[0]=='S'){
            t=60;
            if('2'<=s[1]&&s[1]<='9'){
                x=t+s[1]-'0';
            }else{
                if(s[1]=='A') x=t+1;
                if(s[1]=='T') x=t+10;
                if(s[1]=='J') x=t+11;
                if(s[1]=='Q') x=t+12;
                if(s[1]=='K') x=t+13;
            }
            b[x]=1;
        }
    }
    for(int i=0;i<=60;i+=20){
        for(int j=i+1;j<=i+13;j++){
            if(!b[j]) ans++;
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
