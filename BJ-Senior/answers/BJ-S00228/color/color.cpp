#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
void print(__int128 x,bool f=true){
    if(x>1145141919810){cout<<"INF";return;}
    if(x==0&&f)cout<<0;
    if(x==0)return;
    int t=x%10;
    print(x/10,false);
    cout<<t;
}
ll get_cnt(__int128 x){
    if(!x)return 1;
    int ans=0;
    while(x)ans++,x/=10;
    return ans;
}
ll get_1st(__int128 x){
    if(!x)return 1;
    int ans=0;
    while(x)ans=x%10,x/=10;
    return ans;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    //ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    srand(time(0));

    string s;
    cout<<"Your name:";cin>>s;

    //luogu:533708
    getchar();
    __int128 Bright12077_RP=0;
    if(s=="1")s="Bright12077",Bright12077_RP=1145141919000;
    while(true){
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        if(Bright12077_RP>1145141919810){
            cout<<"**************************\n";
            cout<<"*  Achievement:RP+=inf!  *\n";
            cout<<"*    RP>1145141919810    *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>114514191981){
            cout<<"**************************\n";
            cout<<"*Achievement:RP+=Tree(3)!*\n";
            cout<<"*    RP>114514191981     *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>11451419198){
            cout<<"**************************\n";
            cout<<"* Achievement:RP+=G(64)! *\n";
            cout<<"*     RP>11451419198     *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>1145141919){
            cout<<"**************************\n";
            cout<<"* Achievement:RP+=G(63)! *\n";
            cout<<"*     RP>1145141919      *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>114514191){
            cout<<"**************************\n";
            cout<<"*Achievmnt:RP+=10^10^10)!*\n";
            cout<<"*      RP>114514191      *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>11451419){
            cout<<"**************************\n";
            cout<<"*Achievement:RP+=10^100! *\n";
            cout<<"*      RP>11451419       *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>1145141){
            cout<<"**************************\n";
            cout<<"*Achvmt:RP+=4294964266ll!*\n";
            cout<<"*       RP>1145141       *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>114514){
            cout<<"**************************\n";
            cout<<"* Achievement:  AK CTSC! *\n";
            cout<<"*       RP>114514        *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>11451){
            cout<<"**************************\n";
            cout<<"*  Achievement: AK IOI!  *\n";
            cout<<"*        RP>11451        *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>1145){
            cout<<"**************************\n";
            cout<<"*  Achievement: AK NOI!  *\n";
            cout<<"*        RP>1145         *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>114){
            cout<<"**************************\n";
            cout<<"*  Achievement: AK CSP!  *\n";
            cout<<"*         RP>114         *\n";
            cout<<"**************************\n";
        }else if(Bright12077_RP>11){
            cout<<"**************************\n";
            cout<<"* Achievement: AK DIV.4! *\n";
            cout<<"*          RP>11         *\n";
            cout<<"**************************\n";
        }
        cout<<"《Bright12077's 电子木鱼模拟器——RP++》\n你可以不断按下Enter键以增加RP，增加的RP值全看你的RP！\n"<<s<<"'s RP=";print(Bright12077_RP);
        char c=getchar();
        if(c!='\n')return 0;
        Bright12077_RP+=rand()%(get_cnt(Bright12077_RP)*get_cnt(Bright12077_RP)*get_cnt(Bright12077_RP)*get_cnt(Bright12077_RP)*get_cnt(Bright12077_RP)*get_cnt(Bright12077_RP)\
                                *(rand()%10+10)*get_1st(Bright12077_RP));
    }
    return 0;
}
