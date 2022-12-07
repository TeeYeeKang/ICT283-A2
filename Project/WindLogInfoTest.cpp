#include <iostream>
#include <fstream>
#include "WindLogInfo.h"
#include "CollectData.h"
#include "Value.h"
#include "CollectData.h"
#include "Value.h"

using namespace std;

float CollectData::m_total;
float CollectData::m_max;

int main()
{
    cout<<"Testing for reading and writing file\n"<<endl;

    ifstream infile( "WindLogFile.txt" );
    if( !infile ) return -1;

    WindLogInfo w1;
    WindLogInfo w2;
    WindLogInfo w3;

    infile>> w1 >> w2 >> w3;

    ofstream ofile( "output.txt" );

    ofile << w1 << w2 << w3;

    cout<<w1<<endl;
    cout<<w2<<endl;
    cout<<w3<<endl;

    cout<<"Result also printed in output.txt file"<<endl;

//---------------------------------------------------------------------------

    cout<<"\n\nTesting for manually set up Date class object\n"<<endl;

    cout<<"Testing for getter and setter functions"<<endl;
    WindLogInfo wObject;
    cout<<wObject<<endl;

    wObject.SetSpeed(5);
    wObject.SetSolar(10);
    wObject.SetAir(15);

    cout<<wObject.GetSpeed()<<endl;
    cout<<wObject.GetSolar()<<endl;
    cout<<wObject.GetAir()<<endl;

    return 0;
}
