#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<string> a(N);
int main(){
    int n,i;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w+",stdout);
    cin>>n;
    int k=0;
    for(i=0;i<n;i++,k++){
        cin>>a[k];
        if(i!=0){
            for(int j=i-1;j>=0;j--){
                if(a[j]+"0"==a[i]+"0"){
                    k--;
                }else{
                    continue;
                }
            }
        }else{
            continue;
        }
    }
    cout<<52-k;
    fclose(stdout);
    fclose(stdin);
    return 0;
    }
