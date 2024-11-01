#include<iostream>
using namespace std;
int n,m[50][20],ans;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        s=" "+s;
        if(s[2]=='T'){
            m[s[1]-'A'][10]=1;
            continue;
        }
        if(s[2]=='J'){
            m[s[1]-'A'][11]=1;
            continue;
        }
        if(s[2]=='Q'){
            m[s[1]-'A'][12]=1;
            continue;
        }
        if(s[2]=='K'){
            m[s[1]-'A'][13]=1;
            continue;
        }
        if(s[2]=='A'){
            m[s[1]-'A'][1]=1;
            continue;
        }
        else m[s[1]-'A'][s[2]-'0']=1;

    }
    for(int i=1;i<=13;i++){
        if(m['S'-'A'][i]==0)ans++;
        if(m['C'-'A'][i]==0)ans++;
        if(m['D'-'A'][i]==0)ans++;
        if(m['H'-'A'][i]==0)ans++;
    }
    cout<<ans;
    return 0;
}
