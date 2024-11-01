#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n=0,a[200][200]={},c=52;
    string b;
    cin>>n;
    while(n--){
        cin>>b;
        if(a[b[0]][b[1]]==0){
            c--;
            a[b[0]][b[1]]=1;
        }
    }

    cout<<c;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
