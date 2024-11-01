#include <bits/stdc++.h>

using namespace std;

int n;
bool poker[53];

int get_poket_index(char type,char m){
    /*
    01 02 03 04 05 06 07 08 09 10 11 12 13
    14 15 16 17 18 19 20 21 22 23 24 25 26
    27 28 29 30 31 32 33 34 35 36 37 38 39
    40 41 42 43 44 45 46 47 48 49 50 51 52
    */
    //cout << type << m << endl;
    int index;
    if(type=='D'){
        index=0;
    }
    if(type=='C'){
        index=13;
    }
    if(type=='H'){
        index=26;
    }
    if(type=='S'){
        index=39;
    }

    int num;
    if(m=='A'){
        num=1;
    }
    else if(m=='T'){
        num=10;
    }
    else if(m=='J'){
        num=11;
    }
    else if(m=='Q'){
        num=12;
    }
    else if(m=='K'){
        num=13;
    }
    else{
        num=m-'0';
    }
    //cout << index << ' ' << num << endl;
    index+=num;

    return index;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i=0;i<n;i++){
        char type,m;
        cin >> type >> m;
        //cout << get_poket_index(type,m) << endl;
        poker[get_poket_index(type,m)]=true;
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(poker[i]==false){
            ans++;
        }
    }
    cout << ans;

    return 0;
}
