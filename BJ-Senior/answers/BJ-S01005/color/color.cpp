#include<bits/stdc++.h>
using namespace std;
string str[10000010];
long long c[1000010],n,n2,last;
int color(string str){
    for(int i=1;i<=str.length();i++){
        if(str[i]==false&&str[i-1]==false||str[i]==true&&str[i-1]==true){
            if(str[i]==str[i-1]){
                c[i]+=str[i];
            }
        }
        else{
            for(int j=i-1;j>=1;j--){
                if(str[i]==false&&str[j]==false||str[i]==true&&str[j]==true){
                    if(str[i]==str[j]){
                        c[i]+=str[i];
                    }
                }
            }
        }
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>n2;
        for(int i=1;i<=n2;i++){
            cin>>str[i];
            if(str[i]==false){
                if(color(str)>last){
                    last=color(str);
                }
            }
        }
        cout<<last<<endl;
    }
    return 0;
}
