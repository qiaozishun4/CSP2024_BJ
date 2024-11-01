#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int a[100][1000];
int type[]={'D','C','H','S'};
int num[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        a[s[0]][s[1]]++;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!a[type[i]][num[j]]) {
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

