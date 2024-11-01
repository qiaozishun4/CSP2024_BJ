#include<bits/stdc++.h>
#include<cstdio>
int a[150][150];
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int x,cnt=0;
    cin >> x;
    for(int i=1;i<=x;i++){
        char input[2];
        cin >>input;
        if(a[input[0]][input[1]]==0){
            cnt++;
        }
        a[input[0]][input[1]]++;
    }
    cout << max(0,52-cnt);
    return 0;
    fclose(stdin);
    fclose(stdout);


}
