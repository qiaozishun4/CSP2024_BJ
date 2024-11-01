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
int n;
int cnt[100005];
int maxn=-1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        cnt[read()]++;
    }
    for(int i=1;i<=100000;i++){
        maxn=max(maxn,cnt[i]);
    }
    write(maxn);
    return 0;
}