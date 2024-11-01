#include<bits/stdc++.h>
using namespace std;
string a;
int d[13],c[13],h[13],s[13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a[0]=='D'){
            if(a[1]=='A')   d[0]=1;
            else if(a[1]=='T')  d[9]=1;
            else if(a[1]=='J')  d[10]=1;
            else if(a[1]=='Q')  d[11]=1;
            else if(a[1]=='K')  d[12]=1;
            else d[a[1]-'1']=1;
        }else if(a[0]=='C'){
            if(a[1]=='A')   c[0]=1;
            else if(a[1]=='T')  c[9]=1;
            else if(a[1]=='J')  c[10]=1;
            else if(a[1]=='Q')  c[11]=1;
            else if(a[1]=='K')  c[12]=1;
            else c[a[1]-'1']=1;
        }else if(a[0]=='H'){
            if(a[1]=='A')   h[0]=1;
            else if(a[1]=='T')  h[9]=1;
            else if(a[1]=='J')  h[10]=1;
            else if(a[1]=='Q')  h[11]=1;
            else if(a[1]=='K')  h[12]=1;
            else h[a[1]-'1']=1;
        }else if(a[0]=='S'){
            if(a[1]=='A')   s[0]=1;
            else if(a[1]=='T')  s[9]=1;
            else if(a[1]=='J')  s[10]=1;
            else if(a[1]=='Q')  s[11]=1;
            else if(a[1]=='K')  s[12]=1;
            else s[a[1]-'1']=1;
        }
    }
    int ans=0;
    for(int i=0;i<13;i++){
        ans+=d[i]+c[i]+h[i]+s[i];
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
