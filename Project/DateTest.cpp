#include <iostream>
#include "Date.h"
#include <string>
#include <fstream>
#include "CollectData.h"
#include "Value.h"

using namespace std;

float CollectData::m_total;
float CollectData::m_max;

int main()
{

    cout<<"Testing for manually set up Date class object"<<endl;

    //test for both constructors
    Date date01;
    cout<<"\nTest for default constructor"<<endl;
    date01.GetDate();

    cout<<endl;
    cout<<"date02:"<<endl;
    Date date02(3,1,1999);
    date02.GetDate();

    cout<<"\nTest for set and get function"<<endl;
    cout<<"date01:"<<endl;
    date01.SetDate(5,2,2021);
    date01.GetDate();
    cout<<endl;

    date01.SetDay(11);
    date01.GetDate();
    cout<<endl;

    date01.SetMonth(12);
    date01.GetDate();
    cout<<endl;

    date01.SetYear(1890);
    date01.GetDate();
    cout<<endl;

    cout<<"date02:"<<endl;
    date02.GetDate();

    cout<<"\nTest for << operator"<<endl;
    cout<<date01<<endl;

    cout<<"Test for invalid"<<endl;
    date02.SetDay(99);
    date02.SetMonth(20);
    date02.GetDate();

    cout<<"\nTest for leap year"<<endl;
    Date date03(29,2,2024);
    date03.GetDate();

    cout<<"\nTest for non-leap year"<<endl;
    cout<<"Result should be 0/0/0 because 2020 is not leap year. Therefore, February cannot have 29 days"<<endl;
    Date date04(29,2,2022);
    date04.GetDate();


//-----------------------------------------------------------------------------------------


    cout<<"\nTesting for reading and writing file"<<endl;

    ifstream infile( "dateFile.txt" );
    if( !infile ) return -1;

    Date dObject1;
    Date dObject2;

    infile>> dObject1 >> dObject2;

    ofstream ofile( "output.txt" );

    ofile << dObject1 << dObject2;

    cout<<"Check the output.txt file for result"<<endl;

    cout<<dObject1<<endl;
    cout<<dObject2<<endl;

    return 0;
}



