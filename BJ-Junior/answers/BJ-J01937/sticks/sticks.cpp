#include <bits/stdc++.h>
using namespace std;
int num[15]={6,2,5,5,4,5,6,3,7,6},n,T,len,tmp,now,l,minn;
char s[100010];
int nxt(int x){
    if(x==0 || x==6 || x==9) return 8;
    if(x==1) return 7;
    if(x==7) return 4;
    if(x==4) return 2;
    if(x==2 || x==3 || x==5) return 0;
    if(x==8) return -1;
}
int pre(int x){
    if(x==0 || x==6 || x==9) return 2;
    if(x==1) return -1;
    if(x==7) return 1;
    if(x==4) return 7;
    if(x==2 || x==3 || x==5) return 4;
    if(x==8) return 6;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==1){
            printf("-1\n");
            continue;
        }
        now=0;
        tmp=0;
        len=(n+6)/7;
        for(int i=0; i<len; i++){
            if(i==len-1) s[i]='1';
            else s[i]='0';
            tmp+=num[s[i]-'0'];
        }
        while(true){
            if(tmp==n){
                for(int i=len-1; i>=0; i--){
                    printf("%c",s[i]);
                }
                printf("\n");
                break;
            }
            if(tmp<n){
                minn=0;
                while(nxt(s[minn]-'0')==-1 && minn<len) minn++;
                for(int i=0; i<len; i++){
                    if((nxt(s[i]-'0')<nxt(s[minn]-'0') && (i!=len-1||s[i]!='2'&&s[i]!='3'&&s[i]!='5') || i==len-1&&(s[i]=='2'||s[i]=='3'||s[i]=='5') && nxt(nxt(s[i]-'0'))<nxt(s[minn]-'0'))&&nxt(s[i]-'0')!=-1){
                        minn=i;
                    }
                }
                if(minn==len-1 && (s[minn]=='2'||s[minn]=='3'||s[minn]=='5')){tmp+=2;s[minn]=nxt(nxt(s[minn]-'0'))+'0';}
                else{tmp++;
                s[minn]=nxt(s[minn]-'0')+'0';}
            }else{
                minn=0;
                while(pre(s[minn]-'0')==-1 && minn<len) minn++;
                for(int i=0; i<len; i++){
                    if(pre(s[i]-'0')<pre(s[minn]-'0') && s[i]!='1'){
                        minn=i;
                    }
                }
                tmp--;
                s[minn]=pre(s[minn]-'0')+'0';
            }
        }
    }
    return 0;
}
