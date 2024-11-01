#include <bits/stdc++.h>
using namespace std;
int a1[55];
int a2[55];
int a3[55];
int a4[55];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            if(s[1]>='2'&&s[1]<='9'){
                a1[s[1]-48]=1;
            }
            else if(s[1]=='A'){
                a1[1]=1;
            }
            else if(s[1]=='T'){
                a1[10]=1;
            }
            else if(s[1]=='J'){
                a1[11]=1;
            }
            else if(s[1]=='Q'){
                a1[12]=1;
            }
            else if(s[1]=='K'){
                a1[13]=1;
            }
        }
        if(s[0]=='C'){
            if(s[1]>='2'&&s[1]<='9'){
                a2[s[1]-48]=1;
            }
            else if(s[1]=='A'){
                a2[1]=1;
            }
            else if(s[1]=='T'){
                a2[10]=1;
            }
            else if(s[1]=='J'){
                a2[11]=1;
            }
            else if(s[1]=='Q'){
                a2[12]=1;
            }
            else if(s[1]=='K'){
                a2[13]=1;
            }
        }
        if(s[0]=='H'){
            if(s[1]>='2'&&s[1]<='9'){
                a3[s[1]-48]=1;
            }
            else if(s[1]=='A'){
                a3[1]=1;
            }
            else if(s[1]=='T'){
                a3[10]=1;
            }
            else if(s[1]=='J'){
                a3[11]=1;
            }
            else if(s[1]=='Q'){
                a3[12]=1;
            }
            else if(s[1]=='K'){
                a3[13]=1;
            }
        }
        if(s[0]=='S'){
            if(s[1]>='2'&&s[1]<='9'){
                a4[s[1]-48]=1;
            }
            else if(s[1]=='A'){
                a4[1]=1;
            }
            else if(s[1]=='T'){
                a4[10]=1;
            }
            else if(s[1]=='J'){
                a4[11]=1;
            }
            else if(s[1]=='Q'){
                a4[12]=1;
            }
            else if(s[1]=='K'){
                a4[13]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=13;i++){
        cnt+=a1[i];
        cnt+=a2[i];
        cnt+=a3[i];
        cnt+=a4[i];
    }
    cout<<52-cnt;
    return 0;
}
