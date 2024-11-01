#include<bits/stdc++.h>
using namespace std;
int a;
int b[100001];
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        b[a]++;
    }
    int sum=0;
    for(int i=1;i<=100001;i++){
        if(b[i]>sum){
            sum=b[i];
        }
    }
    cout<<sum;
fclose(stdin);
fclose(stdout);
    return 0;
}
