#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct node{
    int value;
    int alive;
} a[N];
int n,sum;
bool cmp(node x,node y){
    return x.value < y.value;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].value;
        a[i].alive = true;
    }
    sort(a+1,a+1+n,cmp);
    int s = 1;
    for(int i = 2;i <= n;i++){
        if(a[i].value > a[s].value){
            a[s].alive = false;
            s++;
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i].alive) sum++;
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
