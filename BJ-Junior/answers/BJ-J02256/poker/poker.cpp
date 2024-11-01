#include<iostream>
using namespace std;
#include<stdio.h>
bool d[14],c[14],h[14],s[14];
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c%c\n",&a,&b);
        switch(a){
            case 'C':
                switch(b){
                    case 'T':c[10]=true;break;
                    case 'J':c[11]=true;break;
                    case 'Q':c[12]=true;break;
                    case 'K':c[13]=true;break;
                    case 'A':c[1]=true;break;
                    default: c[b-'0']=true;
                };
                break;
            case 'S':
                switch(b){
                    case 'T':s[10]=true;break;
                    case 'J':s[11]=true;break;
                    case 'Q':s[12]=true;break;
                    case 'K':s[13]=true;break;
                    case 'A':s[1]=true;break;
                    default: s[b-'0']=true;
                };
                break;
            case 'D':
                switch(b){
                    case 'T':d[10]=true;break;
                    case 'J':d[11]=true;break;
                    case 'Q':d[12]=true;break;
                    case 'K':d[13]=true;break;
                    case 'A':d[1]=true;break;
                    default: d[b-'0']=true;
                };
                break;
            case 'H':
                switch(b){
                    case 'T':h[10]=true;break;
                    case 'J':h[11]=true;break;
                    case 'Q':h[12]=true;break;
                    case 'K':h[13]=true;break;
                    case 'A':h[1]=true;break;
                    default: h[b-'0']=true;
                };
                break;

        }
    }
    for(int i=1;i<14;i++)ans-=(int)c[i];
    for(int i=1;i<14;i++)ans-=(int)d[i];
    for(int i=1;i<14;i++)ans-=(int)s[i];
    for(int i=1;i<14;i++)ans-=(int)h[i];
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
