#include <iostream>
#include <cstdio>
using namespace std;
int num_sources[10]={6,2,5,5,4,5,6,3,7,6};
bool str_a_bigger_than_str_b(string a,string b){
    if(a.length()>b.length()){
        return true;
    }else if(a.length()<b.length()){
        return false;
    }else return a>b;
}
string creat_number(int n,bool use_0,string order_num){
    if(n==0){
        //正好摆放完成了
        return order_num;
    }
    if(n<2){
        //不可能摆出任何数字了
        return "-1";
    }
    string idea,min_idea="";
    for(int i=1;i<=26;i++){
        min_idea+="9";
    }
    if(use_0==false){//如果不让使用0
        int min_=100000000;
        for(int i=1;i<=9;i++){
            idea=creat_number(n-num_sources[i],true,order_num+char('0'+i));
            if(str_a_bigger_than_str_b(idea,min_idea)==false&&idea!="-1"){
                min_idea=idea;
            }
        }
    }else{
        for(int i=0;i<=9;i++){
            idea=creat_number(n-num_sources[i],true,order_num+char('0'+i));
            if(str_a_bigger_than_str_b(idea,min_idea)==false&&idea!="-1"){
                min_idea=idea;
            }
        }
    }
    return min_idea;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<creat_number(n,false,"")<<endl;
    }
    return 0;
}
