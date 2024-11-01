#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int i,n,p=0;
    cin>>n;
    string s;
    int a[14],b[14],c[14],d[14];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for(i=0;i<n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]>='1' && s[1]<='9'){
                a[s[1]-42]++;
            }
            else if(s[1]=='A') a[0]++;
            else if(s[1]=='T') a[10]++;
            else if(s[1]=='J') a[11]++;
            else if(s[1]=='Q') a[12]++;
            else if(s[1]=='K') a[13]++;
        }
        else if(s[0]=='C'){
            if(s[1]>='1' && s[1]<='9'){
                b[s[1]-42]++;
            }
            else if(s[1]=='A') b[0]++;
            else if(s[1]=='T') b[10]++;
            else if(s[1]=='J') b[11]++;
            else if(s[1]=='Q') b[12]++;
            else if(s[1]=='K') b[13]++;
        }
        else if(s[0]=='H'){
            if(s[1]>='1' && s[1]<='9'){
                c[s[1]-42]++;
            }
            else if(s[1]=='A') c[0]++;
            else if(s[1]=='T') c[10]++;
            else if(s[1]=='J') c[11]++;
            else if(s[1]=='Q') c[12]++;
            else if(s[1]=='K') c[13]++;
        }
        else if(s[0]=='S'){
            if(s[1]>='1' && s[1]<='9'){
                d[s[1]-42]++;
            }
            else if(s[1]=='A') d[0]++;
            else if(s[1]=='T') d[10]++;
            else if(s[1]=='J') d[11]++;
            else if(s[1]=='Q') d[12]++;
            else if(s[1]=='K') d[13]++;
        }
    }
    for(i=0;i<14;i++){
        if(a[i]==0) p++;
        if(b[i]==0) p++;
        if(c[i]==0) p++;
        if(d[i]==0) p++;
    }
    cout<<p-4;
    return 0;
}
