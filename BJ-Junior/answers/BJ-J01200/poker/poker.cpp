#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    char c;
    int n1=n;
    for(int i=0;i<n;i++){
        cin>>c;
        v.push_back(c);
    }
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]) n1--;
    }

    cout<<52-n1;
    return 0;
}
