#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxn 100010
using namespace std;
struct Monster{
    bool exist;
    bool attack_flag;
    int strength;
}monster[maxn];
bool compare(Monster x,Monster y){
    return x.strength<y.strength;
}
int n,cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>monster[i].strength;
        monster[i].exist=1;
        monster[i].attack_flag=0;
    }
    sort(monster+1,monster+n+1,compare);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(monster[j].strength>monster[i].strength&&monster[j].attack_flag==0){
                monster[j].attack_flag=1;
                monster[i].exist=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(monster[i].exist==1) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
