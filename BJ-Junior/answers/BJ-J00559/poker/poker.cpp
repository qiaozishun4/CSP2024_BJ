#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt = 0;
    cin >>n;
    for(int i = 0;i < n;i++){
    string d;
    cin >>d;
    int b = int(d[0]) + int(d[1]);
    if(a[b] == 0){
        cnt++;
        a[b]++;
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}