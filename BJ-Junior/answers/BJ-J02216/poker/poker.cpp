#include<bits/stdc++.h>
using namespace std;
int n;
int d[15],c[15],h[15],s[15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string str;
    int cnt=0;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        int x;
        if(str[1]>='2'&&str[1]<='9'){
            x=str[1]-'0';
        }else if(str[1]=='A'){
            x=1;
        }else if(str[1]=='T'){
            x=10;
        }else if(str[1]=='J'){
            x=11;
        }else if(str[1]=='Q'){
            x=12;
        }else{
            x=13;
        }
        if(str[0]=='D'){
            if(d[x]==0){
                cnt++;
                d[x]=1;
            }
        }else if(str[0]=='C'){
            if(c[x]==0){
                cnt++;
                c[x]=1;
            }
        }else if(str[0]=='H'){
            if(h[x]==0){
                cnt++;
                h[x]=1;
            }
        }else{
            if(s[x]==0){
                cnt++;
                s[x]=1;
            }
        }
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
