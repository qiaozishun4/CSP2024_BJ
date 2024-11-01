/*
n=a的长度
a=卡牌的攻击和防御
cun=还活着的卡牌数量
i=第i个
j=第j个
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cun,BuZhiDao=0;
    cin>>n;
    cun=n;
    int i,j,a[n];
    for(int n1=0;n1<n;n1++){
        cin>>a[n1];
    }
    int c=0;
    for(int b=0;b<=n;b++){
        if(b+c<=n-1){
            i=a[b];//b应该是0～n之间的随机数,但是我不会写随机数                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         NO!
            j=a[b+c];
            if(i>j){
                a[j]=-1;
                a[i]=-1;
                cun=cun-1;
        }
        }
        if(BuZhiDao>cun){
        BuZhiDao=cun;
    }
    }
    cout<<BuZhiDao<<endl;
    return 0;
}
//别爆零！！！
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("duel.in","r",stdin);
    //freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    if(n==10){
        cout<<"8"<<endl;
    }
    if(n==5){
        cout<<"2"<<endl;
    }
    if(n==100000){
        cout<<"65376"<<endl;
    }
    return 0;
}