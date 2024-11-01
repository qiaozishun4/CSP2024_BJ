#include<bits/stdc++.h>
using namespace std;
int sum=52,n;
bool a[256][256];
string pk;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>pk;
        if(a[pk[0]][pk[1]]==false){
            a[pk[0]][pk[1]]=true;
            sum--;
        }
    }
    printf("%d\n",sum);
    return 0;
}
