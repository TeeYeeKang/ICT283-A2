#include <iostream>
#include <fstream>
#include "Time.h"
#include "CollectData.h"
#include "Value.h"

using namespace std;

float CollectData::m_total;
float CollectData::m_max;

int main()
{
    cout<<"Test for manually set up Time class object"<<endl;
    Time t1;
    cout<<t1<<endl;

    Time t2(5, 25);
    cout<<t2<<endl;

    t1.SetHour(12);
    t1.SetMinute(35);

    cout<<"\nTest for operator"<<endl;
    cout<<t1<<endl;
    cout<<t2<<endl;

    cout<<"Test for get functions"<<endl;
    cout<<t1.GetHour()<<endl;
    cout<<t1.GetMinute()<<endl;

    cout<<"\nTest for invalid"<<endl;
    Time t3(30,99);
    cout<<t3<<endl;

//-----------------------------------------------------------------

    cout<<"\nTest for reading and writing file"<<endl;
    ifstream infile( "TimeFile.txt" );
    if( !infile ) return -1;

    Time object1;
    Time object2;
    Time object3;

    infile >> object1 >> object2 >> object3;

    ofstream ofile( "output.txt" );

    ofile << object1 << object2 << object3 << '\n';

    cout<<"Go to output.csv file to examine the output"<<endl;

    return 0;
}

