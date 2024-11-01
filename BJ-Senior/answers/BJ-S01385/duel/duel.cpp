#include<bits/stdc++.h>
using namespace std;
int sum=0;
bool cmp(int x,int y){
    return x<y;
}
int a[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        a[t]++;
    }
    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=100001;i++){
        if(a[i]>sum){
            sum=a[i];
        }
    }

    cout << sum;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

