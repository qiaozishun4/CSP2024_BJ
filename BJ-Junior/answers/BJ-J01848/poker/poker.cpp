#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
int a[1005],b[1005],c[1005],d[1005];
for(int i=0;i<=20;i++){
    a[i]=0,b[i]=0,c[i]=0,d[i]=0;
}
    string s;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]>='1'&&s[1]<='9')a[s[1]-'0']=1;
            else if(s[1]=='T')a[10]=1;
            else if(s[1]=='J')a[11]=1;
            else if(s[1]=='Q')a[12]=1;
            else if(s[1]=='K')a[13]=1;
        }
        else if(s[0]=='C'){
            if(s[1]>='1'&&s[1]<='9')b[s[1]-'0']=1;
            else if(s[1]=='T')b[10]=1;
            else if(s[1]=='J')b[11]=1;
            else if(s[1]=='Q')b[12]=1;
            else if(s[1]=='K')b[13]=1;
        }
        else if(s[0]=='H'){
            if(s[1]>='1'&&s[1]<='9')a[s[1]-'0']=1;
            else if(s[1]=='T')c[10]=1;
            else if(s[1]=='J')c[11]=1;
            else if(s[1]=='Q')c[12]=1;
            else if(s[1]=='K')c[13]=1;
        }
        else if(s[0]=='S'){
            if(s[1]>='1'&&s[1]<='9')a[s[1]-'0']=1;
            else if(s[1]=='T')d[10]=1;
            else if(s[1]=='J')d[11]=1;
            else if(s[1]=='Q')d[12]=1;
            else if(s[1]=='K')d[13]=1;
        }
    }int num=0;
    for(int i=1;i<=13;i++){
        if(a[i]==0)num++;
        if(b[i]==0)num++;
        if(c[i]==0)num++;
        if(d[i]==0)num++;
    }
    cout<<num;
}
