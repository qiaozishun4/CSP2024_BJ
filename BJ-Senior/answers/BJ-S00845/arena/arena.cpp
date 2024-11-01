#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    system("reboot");
    cout << "I'm going to AFO" << endl;
    cout << "Are you going to AFO?" << endl;
    cout << "(Y/N)" << endl;
    char a;
    bool afo;
    cin >> a;
    if(a=='Y'){
        afo=true;
    }else if(a=='N'){
        afo=false;
    }else{
        cout << "NI SHUO SHA"<<endl;
        main();
    }
    if(afo==true){
        cout << "me too!"<<endl;
    }else{
        cout << "so are you going to AK?"<<endl;
        bool ak;
        char f;
        cout << "(Y/N)"<<endl;
        cin>>f;
        if(f=='Y'){
            ak==true;
        }else{
            ak==false;
        }
        if(ak==false){
            cout<<"okay,good luck";
        }else{
            cout<<"however,I'm going to!";
        }
    }
    
    main();
    return 0;
}
