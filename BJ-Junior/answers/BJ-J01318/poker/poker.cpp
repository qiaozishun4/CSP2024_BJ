#include<stdio.h>
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    char s[2];
    bool d[13],s1[13],c[13],h[13];
    for(int i=0;i<13;i++)d[i]=0;
    for(int i=0;i<13;i++)s1[i]=0;
    for(int i=0;i<13;i++)c[i]=0;
    for(int i=0;i<13;i++)h[i]=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        if(s[0]=='D'){
            if('2'<=s[1]&&s[1]<='9')d[s[1]-49]=true;
            else if(s[1]=='A')d[0]=true;
            else if(s[1]=='T')d[9]=true;
            else if(s[1]=='J')d[10]=true;
            else if(s[1]=='Q')d[11]=true;
            else d[12]=true;
        }
        else if(s[0]=='S'){
            if('2'<=s[1]&&s[1]<='9')s1[s[1]-49]=true;
            else if(s[1]=='A')s1[0]=true;
            else if(s[1]=='T')s1[9]=true;
            else if(s[1]=='J')s1[10]=true;
            else if(s[1]=='Q')s1[11]=true;
            else s1[12]=true;
        }
        else if(s[0]=='C'){
            if('2'<=s[1]&&s[1]<='9')c[s[1]-49]=true;
            else if(s[1]=='A')c[0]=true;
            else if(s[1]=='T')c[9]=true;
            else if(s[1]=='J')c[10]=true;
            else if(s[1]=='Q')c[11]=true;
            else c[12]=true;
        }
        else{
            if('2'<=s[1]&&s[1]<='9')h[s[1]-49]=true;
            else if(s[1]=='A')h[0]=true;
            else if(s[1]=='T')h[9]=true;
            else if(s[1]=='J')h[10]=true;
            else if(s[1]=='Q')h[11]=true;
            else h[12]=true;
        }
    }
    for(int i=0;i<13;i++)if(d[i]==0)ans++;
    for(int i=0;i<13;i++)if(s1[i]==0)ans++;
    for(int i=0;i<13;i++)if(h[i]==0)ans++;
    for(int i=0;i<13;i++)if(c[i]==0)ans++;
    printf("%d",ans);
    return 0;
}
