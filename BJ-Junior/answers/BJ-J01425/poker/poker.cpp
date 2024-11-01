#include<iostream>
#include<string>
using namespace std;
bool a[57];
int to(string k){
    int y;
    if(k[0]=='D') y=0;
    else if(k[0]=='C') y=13;
    else if(k[0]=='H') y=26;
    else y=39;
    if(k[1]=='A') return y+1;
    else if('2'<=k[1]&&k[1]<='9') return y+(k[1]-'0');
    else if(k[1] == 'T') return y+10;
    else if(k[1] == 'J') return y+11;
    else if(k[1] == 'Q') return y+12;
    else return y+13;
    return -1;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        a[to(tmp)] = 1;
    }
    int cnt=0;
    for(int i=1;i<=52;i++){
        if(a[i]) cnt++;
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}