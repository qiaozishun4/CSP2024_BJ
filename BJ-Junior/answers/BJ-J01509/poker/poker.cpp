#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;
string s;
int ret = 52;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s;
        if(mp[s] == 0){
            ret--;
        }
        mp[s] = 1;
    }
    printf("%d",ret);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
