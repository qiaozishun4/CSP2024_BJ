#include<iostream>
#include<string>
using namespace std;
int n,ans;
string ch[110];
int d[15],c[15],h[15],s[15];
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        cin>>ch[i];
        if(ch[i][0] == 'D'){
            if(ch[i][1] == 'A'){
                d[1]++;
            }
            else if(ch[i][1] == 'A'){
                d[10]++;
            }
            else if(ch[i][1] == 'J'){
                d[11]++;
            }
            else if(ch[i][1] == 'Q'){
                d[12]++;
            }
            else if(ch[i][1] == 'K'){
                d[13]++;
            }
            else{
                d[ch[i][1] - '0']++;
            }
        }
        if(ch[i][0] == 'C'){
            if(ch[i][1] == 'A'){
                c[1]++;
            }
            else if(ch[i][1] == 'T'){
                c[10]++;
            }
            else if(ch[i][1] == 'J'){
                c[11]++;
            }
            else if(ch[i][1] == 'Q'){
                c[12]++;
            }
            else if(ch[i][1] == 'K'){
                c[13]++;
            }
            else{
                c[ch[i][1] - '0']++;
            }
        }
        if(ch[i][0] == 'H'){
            if(ch[i][1] == 'A'){
                h[1]++;
            }
            else if(ch[i][1] == 'T'){
                h[10]++;
            }
            else if(ch[i][1] == 'J'){
                h[11]++;
            }
            else if(ch[i][1] == 'Q'){
                h[12]++;
            }
            else if(ch[i][1] == 'K'){
                h[13]++;
            }
            else{
                h[ch[i][1] - '0']++;
            }
        }
        if(ch[i][0] == 'S'){
            if(ch[i][1] == 'A'){
                s[1]++;
            }
            else if(ch[i][1] == 'T'){
                s[10]++;
            }
            else if(ch[i][1] == 'J'){
                s[11]++;
            }
            else if(ch[i][1] == 'Q'){
                s[12]++;
            }
            else if(ch[i][1] == 'K'){
                s[13]++;
            }
            else{
                s[ch[i][1] - '0']++;
            }
        }
    }
    for(int i = 1;i <= 13;i++){
        if(!d[i]) ans++;
        if(!c[i]) ans++;
        if(!h[i]) ans++;
        if(!s[i]) ans++;
    }
    cout<<ans;
    return 0;
}
