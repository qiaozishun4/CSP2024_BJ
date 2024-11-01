#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
struct puke{
    string pm = "";
    int gs = 0;
} pukes[52];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int cnt = 1;
    int len = 0;
    for(int i = 0;i < n;i++){
        string s;
        cin>>s;
        bool tf = 0;
        for(int j = 1;j <= cnt;j++){
            if(pukes[j].pm == s){
                pukes[j].gs += 1;
                tf = 1;
            }
        }
        if(tf != 1){
            pukes[cnt].pm = s;
            pukes[cnt].gs = 1;
        }
        cnt++;
    }
    int ans = 0;
    for(int i = 1;i <= 52;i++){
        if(pukes[i].gs == 0) ans++;
    }
    cout<<ans;
    return 0;
}
