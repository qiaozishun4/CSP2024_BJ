#include<bits/stdc++.h>

using namespace std;

const int N=52;
unordered_map<string,int> dym;
int cnt[60];

void init(){
    //D,C,H,S
    //A 2 3 4 5 6 7 8 9 T J Q K
    string A[]={"D","C","H","S"};
    string B[]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
    int cnt1=0;
    for(auto i:A){
        for(auto j:B){
            dym[i+j]=++cnt1;
        }
    }
    return ;
}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string pkp;
        cin>>pkp;
        cnt[dym[pkp]]++;
    }
    int cntless=0;
    for(int i=1;i<=N;i++){
        if(cnt[i]==0){
            cntless++;
        }
    }
    cout<<cntless<<endl;
    return 0;
}
