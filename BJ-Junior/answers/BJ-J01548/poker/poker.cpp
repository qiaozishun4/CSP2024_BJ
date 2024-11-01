#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n,s=52;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        s++;
        cin>>a[i];
        for(int j=0;j<i;j++){
            if(a[i]==a[j]) s--;
        }
    }

    cout<<104-s;

    fclose(stdout);
    fclose(stdin);


    return 0;
}
