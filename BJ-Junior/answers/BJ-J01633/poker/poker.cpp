#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int sum;
char b[53];
long long n;
char a[53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    sum=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        for(int j=1;j<i;j++){
            if(a[j]==a[i]&&b[j]==b[i]){
                sum--;
                break;
            }
        }
    }
   cout<<52-sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
