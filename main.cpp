#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;
int k=0, pola=0, broj=0, a=0;
char rijeci;

int iznos_osvojen(){
    if(k==1){
        cout<<k<<". pitanje,  imate 100kn"<<endl;

    }
    else if(k==2){
        cout<<k<<". pitanje, imate 200kn"<<endl;

    }
    else if(k==3){
        cout<<k<<". pitanje, imate 300kn"<<endl;

    }
    else if(k==4){
        cout<<k<<". pitanje, imate 500kn"<<endl;

    }
    else if(k==5){
        cout<<k<<". pitanje, imate 1000kn"<<endl;

    }
    else if(k==6){
        cout<<"Dosli ste do prvog praga!"<<endl;
        cout<<k<<". pitanje, imate 2000kn"<<endl;

    }
    else if(k==7){
        cout<<k<<". pitanje, imate 4000kn"<<endl;

    }
    else if(k==8){
        cout<<k<<". pitanje, imate 8000kn"<<endl;

    }
    else if(k==9){
        cout<<k<<". pitanje, imate 16000kn"<<endl;

    }
    else if(k==10){
        cout<<k<<". pitanje, imate 32000kn"<<endl;

    }
    else if(k==11){
        cout<<"Dosli ste do drugog praga!"<<endl;
        cout<<k<<". pitanje, imate 64000kn"<<endl;

    }
    else if(k==12){
        cout<<k<<". pitanje, imate 125000kn"<<endl;

    }
    else if(k==13){
        cout<<k<<". pitanje, imate 250000kn"<<endl;

    }
    else if(k==14){
        cout<<k<<". pitanje, imate 500000kn"<<endl;

    }
    else if(k==15){
        cout<<k<<". pitanje, imate 1000000kn"<<endl;
        cout<<"Cestitamo, postali ste Milijunas iz EMSE!!"<<endl;

    }
    else if(k==0){
        cout<<"Nazalost, niste nista osvojili, vise srece drugi put!"<<endl;
    }
}

int idk(){
    cout<<"Hvala sto ste sudjelovali!"<<endl;
}

int joker(){
    pitanje:
    cout<<"[1] 50/50"<<endl;
    cin>>a;
    if(a>1){
        cout<<"Krivi unos!"<<endl;
    }
    else if(a==1&&pola==0){

        char c;
        int r;
        srand (time(NULL));
        r = rand() % 4;
        c = 'a' + r;
        while (c==rijeci){
            srand (time(NULL));
            r = rand() % 4;
            c = 'a' + r;
        }
        cout<<"Odgovor je: "<<c<<" ili "<<rijeci<<endl;
        pola++;
        broj++;
    }
    else if(broj==1){
        cout<<"Nemate vise jokera"<<endl;
    }

          else if(pola==1){
        cout<<"Iskoristili ste taj joker"<<endl;
        goto pitanje;
    }
}


int main()
{
    cout<<"Dobar dan, dobro dosli u kviz Milijunas iz EMSE!"<<endl;
    cout<<"Pripazite na to da tocno napisete odgovor. "<<endl;
    cout<<"Zapocnimo! "<<endl;
    char jok, n ,f;
    ifstream mil("milijunas.txt");
    string recenice;
    while(!mil.eof()){
nastaviti: for(int j=1;j=15;j++){
            cout<<"Nastaviti? (Y,N):";
            cin>>f;
            if(f=='Y'){
                for(int i=1;i<90;i++){
                    if(i%6==0){
                        getline(mil,recenice);
                        cout<<"Unesite vas odgovor. [a,b,c,d]:";
                        cin>>n;
                        if(rijeci==n){
                            cout<<"To je tocan odgovor, cestitamo. "<<endl;
                            k++;
                            iznos_osvojen();
                            goto nastaviti;
                        }
                        else if(rijeci!=n){
                            cout<<"Nazalost, to je netocan odgovor"<<endl;
                            if(k>=6&&k<11){
                                k=6;
                                cout<<"Dosli ste do ";
                                iznos_osvojen();
                                cout<<"Cestitamo!"<<endl;
                                idk();
                                return 0;
                            }
                            else if(k>=11&&k<14){
                                k=11;
                                cout<<"Dosli ste do ";
                                iznos_osvojen();
                                cout<<"Cestitamo!"<<endl;
                                idk();
                                return 0;
                            }
                            else if(k<6){
                                cout<<"Nazalost vracate se kuci s 0 kuna"<<endl;
                                idk();
                                return 0;
                            }
                        }

                    }
                    else {
                        getline(mil,recenice);
                        cout<<recenice<<endl;
                    }
                    if(i%5==0){
                        cout<<"Zelite li iskoristiti jokera? (Y,N)"<<endl;
                        cin>>jok;
                        mil>>rijeci;
                        if (jok=='Y'){
                            joker();
                        }
                    }
                }
            }
            else if(f=='N'){
                cout<<"Cestitamo dosli ste do ";
                iznos_osvojen();
                idk();
                return 0;
            }
        }
    }

}


