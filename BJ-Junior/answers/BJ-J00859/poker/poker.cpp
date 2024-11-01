#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int d[15],c[15],s[15],h[15];
    string ss;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ss;
        if(ss[0]=='D'){
            if(ss[1]=='A'){
                d[1]=1;
            }
            else if(ss[1]=='T'){
                d[10]=1;
            }
            else if(ss[1]=='J'){
                d[11]=1;
            }
            else if(ss[1]=='Q'){
                d[12]=1;
            }
            else if(ss[1]=='K'){
                d[13]=1;
            }
            else d[ss[1]-48]=1;
        }
        else if(ss[0]=='S'){
            if(ss[1]=='A'){
                s[1]=1;
            }
            else if(ss[1]=='T'){
                s[10]=1;
            }
            else if(ss[1]=='J'){
                s[11]=1;
            }
            else if(ss[1]=='Q'){
                s[12]=1;
            }
            else if(ss[1]=='K'){
                s[13]=1;
            }
            else s[ss[1]-48]=1;
        }
        if(ss[0]=='H'){
            if(ss[1]=='A'){
                h[1]=1;
            }
            else if(ss[1]=='T'){
                h[10]=1;
            }
            else if(ss[1]=='J'){
                h[11]=1;
            }
            else if(ss[1]=='Q'){
                h[12]=1;
            }
            else if(ss[1]=='K'){
                h[13]=1;
            }
            else h[ss[1]-48]=1;
        }
        if(ss[0]=='C'){
            if(ss[1]=='A'){
                c[1]=1;
            }
            else if(ss[1]=='T'){
                c[10]=1;
            }
            else if(ss[1]=='J'){
                c[11]=1;
            }
            else if(ss[1]=='Q'){
                c[12]=1;
            }
            else if(ss[1]=='K'){
                c[13]=1;
            }
            else c[ss[1]-48]=1;
        }
    }
    int num=0;
    for(int i=1;i<=13;i++){
        if(d[i]==0) num+=1;
        if(s[i]==0) num+=1;
        if(h[i]==0) num+=1;
        if(c[i]==0) num+=1;
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
