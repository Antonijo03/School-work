#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
    cout<< "1. zadatak: Gljive"<<endl;
    cout.precision(3);
    srand(time(NULL));
    double gljive[31];
    float suma=0, zarada=0;
    for (int i=0; i<31; i++)
    {
        gljive[i]=(float(rand()%2000))/1000;
        cout<<fixed<<float(gljive[i])<<endl;
        suma+=gljive[i];
    }

    zarada=suma*50;

    cout<<fixed<< "Ukupno je sakupljeno "<<suma<<" kg gljiva, od cega je moguce zaraditi "<<zarada-250<<" kn . "<<endl;



    cout<< "2. zadatak: Kesteni"<<endl;

    int kesteni[31], suma_kesteni=0, zarada_kesteni=0;
    for (int i=0; i<31; i++)
    {
        kesteni[i]=rand()%10;
        suma_kesteni+=kesteni[i];
    }
    cout<< "Nestortirano polje: "<<endl;
    for (int i=0; i<31; i++)
    {
       cout<<kesteni[i]<<endl;
    }
cout<<endl;
    zarada_kesteni=suma_kesteni*30;
    cout<< "Prikupljeno je "<<suma_kesteni<<" kg kestena, a zarada je "<<zarada_kesteni<<" kn. "<<endl;

    int temp=0, najmanji=0, najveci=0;
    for (int i=0; i<31; i++)
    {
        for (int j=0; j<31; j++)
        {
            if (kesteni[j]>kesteni[j+1])
            {
                temp=kesteni[j];
                kesteni[j]=kesteni[j+1];
                kesteni[j+1]=temp;
            }
        }
    }
    cout<<endl;
    cout<<endl;
    cout<< "Sortirano polje: "<<endl;
    for (int i=0; i<31; i++)
    {
        cout<<kesteni[i+1]<<endl;
    }
    cout<<endl;
    cout<< "Najmanje je prodano "<<kesteni[1]<<" kg kestena, a najvise "<<kesteni[31]<<" kg kestena. "<<endl;
    return 0;
}
