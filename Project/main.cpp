#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //convert string to numerical value
#include <iomanip> //decimal point
#include <map>
#include "Date.h"
#include "Time.h"
#include "WindLogInfo.h"
#include "bst.h"
#include "CollectData.h"
#include "Value.h"

using namespace std;

typedef struct
{
    Date d;
    Time t;
} dateTime;

//function & operator prototype

int Menu();
void Controller(const map<dateTime, WindLogInfo> &mp);
void ReadDataFromFile(map<dateTime, WindLogInfo> &mp);
float GetAverageSpeed(const map<dateTime, WindLogInfo> &mp, int year, int month);
float GetAverageAir(const map<dateTime, WindLogInfo> &mp, int year, int month);
float GetTotalSolar(const map<dateTime, WindLogInfo> &mp, int year, int month);
void Option1(const map<dateTime, WindLogInfo> &mp);
void Option2(const map<dateTime, WindLogInfo> &mp);
void Option3(const map<dateTime, WindLogInfo> &mp);
void Option4(const map<dateTime, WindLogInfo> &mp);
void Option5(const map<dateTime, WindLogInfo> &mp);
int GetUserYear();
int GetUserMonth();
Date GetUserDate();
bool isNumeric(string input);
bool operator<(const dateTime& first, const dateTime& second);
bool operator==(const dateTime& first, const dateTime& second);
bool operator<( const CollectData &L, const CollectData &R);
float CollectData::m_total;
float CollectData::m_max;

int main()
{
        map<dateTime, WindLogInfo>Map;

        ReadDataFromFile(Map);

        cout<<fixed<<showpoint<<setprecision(1)<<endl; //set to only one decimal point

        Controller(Map);

    return 0;
}

//All functions & operators

int Menu()
{
    string input;
    int choice;
    bool isNumerical;

    do
    {
        cout << "\n------------------ Task to perform ------------------\n" << endl;
        cout << "[1]: The average wind speed and average ambient air temperature for a specified month and year" << endl;
        cout << "[2]: Average wind speed and average ambient air temperature for each month of a specified year" << endl;
        cout << "[3]: Total solar radiation in kWh/m2 for each month of a specified year" << endl;
        cout << "[4]: Output avg wind speed, avg ambient air temperature and total solar radiation for each month of year to a file" << endl;
        cout << "[5]: The time for the highest solar radiation for a specific date" << endl;
        cout << "[6]: Exit the program " << endl;
        cout << "\nEnter the option you want to perform: ";
        cin >> input ;

        if(!isNumeric(input))
        {
            cout << "\nPlease enter a numerical value !" << endl;
            isNumerical = false;
        }
        else
        {
            isNumerical = true;
        }
    }
    while(!isNumerical);

    choice = atoi(input.c_str()); //convert to int
    return choice;
}

bool isNumeric(string input)
{
    bool valid = true;
    for(int idx=0; idx<input.length(); idx++)
    {
        if(!isdigit(input[idx]))
        {
            valid = false;
        }
        return valid;
    }
}

void Controller(const map<dateTime, WindLogInfo> &mp)
{
    int userChoice = 0;

    do
    {
        userChoice = Menu(); //get user's choice

        switch (userChoice)
        {
        case 1:
            Option1(mp);
            break;
        case 2:
            Option2(mp);
            break;
        case 3:
            Option3(mp);
            break;
        case 4:
            Option4(mp);
            break;
        case 5:
            Option5(mp);
            break;
        case 6:
            cout<<"\nThank you bye ~"<<endl;
            break;
        default:
            printf("\nInvalid option !\n");
            break;
        }
    }
    while (userChoice != 6);
}

void ReadDataFromFile(map<dateTime, WindLogInfo> &mp)
{
    //working variables
    float theSpeed, theSolar, theAir;
    string name, day, month, year, hour, minute, speedInString, solarInString, airInString, dummy, fileToRead, fileName, strDate;
    string NA = "N/A";
    int err=0, invalidFile = 0, numOfFileRead;
    dateTime dt;
    WindLogInfo wObject;

    BinaryTreePointer<string> fileTree;

    ifstream dataFile("data/met_index.txt");

    while(true)
    {
        getline(dataFile,fileToRead,'\n');
        fileName="data/"+fileToRead;

        if(dataFile.eof()) //check if there is anymore file to read
        {
            break;
        }

        ifstream infile(fileName);

        if(infile.is_open())
        {
            if(!fileTree.SearchItem(fileName))//check is the file is exist/read before
            {
                numOfFileRead++;
                fileTree.InsertItem(fileName);//if the file not exist in the bst, then store into bst

                infile.ignore(1000,'\n'); //skip the header line

                while(true)
                {
                    //read Date and Time
                    getline(infile, day, '/');
                    getline(infile, month, '/');
                    getline(infile, year, ' ');
                    getline(infile, hour, ':');
                    getline(infile, minute, ',');

                    //convert string to int value
                    int d = atoi(day.c_str());
                    int m = atoi(month.c_str());
                    int y = atoi(year.c_str());
                    int h = atoi(hour.c_str());
                    int mi = atoi(minute.c_str());

                    //set Date and Time objects
                    dt.d.SetDate(d,m,y);
                    dt.t.SetHour(h);
                    dt.t.SetMinute(mi);

                    //read speed
                    for(int idx=0; idx<10; idx++)
                    {
                        getline(infile, speedInString, ',');
                    }

                    //read solar radiation
                    getline(infile, solarInString, ',');

                    //read unused date
                    for(int idx=0; idx<5; idx++)
                    {
                        infile.ignore(1000,',');  //skip unused data
                    }

                    getline(infile, airInString); //read air

                    if(infile.eof())  //check if reach the end of line
                    {
                        break;
                    }
                    else
                    {
                        //convert speedInString and solarInString to float
                        if(!speedInString.compare(NA)==0)
                        {
                            theSpeed = stof(speedInString.c_str());
                        }
                        else
                        {
                            theSpeed = 0;
                        }

                        if(!solarInString.compare(NA)==0)
                        {
                            theSolar = stof(solarInString.c_str());
                        }
                        else
                        {
                            theSolar = 0;
                        }

                        if(!airInString.compare(NA)==0)
                        {
                            theAir = stof (airInString.c_str());
                        }
                        else
                        {
                            theAir = 0;
                        }

                        //set speed, solar and air
                        wObject.SetSpeed(theSpeed);
                        wObject.SetAir(theAir);
                        wObject.SetSolar(theSolar);

                        mp[dt] = wObject; //store into map
                    }
                }
            }
        }
        else
        {
            err++;
        }
        infile.close();
    }
    cout<<"Total file read: " << numOfFileRead <<endl;
    cout<<"Reading file error: "<<err<<endl;

    dataFile.close();
}

int GetUserYear()
{
    int year;
    cout<<"Enter the year to search: ";
    cin>>year;

    return year;
}
int GetUserMonth()
{
    int month;
    cout<<"Enter the month to search: ";
    cin>>month;

    return month;
}

Date GetUserDate()
{
    Date date;
    string slash;
    cout<<"Enter the date to search in the format of (d/m/yyyy): ";
    cin>>date;

    return date;
}

float GetAverageSpeed(const map<dateTime, WindLogInfo> &mp, int year, int month)
{
    //working variables
    float sumOfSpeed=0, speedAvg=0;
    int counter = 0;
    BinaryTreePointer<Value> valueTree;
    Value v;
    CollectData c;

    for(auto temp:mp)
    {
        if(temp.first.d.GetYear()==year && temp.first.d.GetMonth()==month)
        {
            v.SetValue(temp.second.GetSpeed()*3.6);
            valueTree.InsertItem(v);
            counter++;
        }
    }

    valueTree.InorderTraversal(CollectData::Sum);
    speedAvg = c.GetTotal()/counter; //calculation of average
    valueTree.DestroyTree();

    return speedAvg;
}

float GetAverageAir(const map<dateTime, WindLogInfo> &mp, int year, int month)
{
    //working variables
    float sumOfAir=0, airAvg=0;
    int counter = 0;
    BinaryTreePointer<Value> valueTree;
    Value v;
    CollectData c;

    for(auto temp:mp)
    {
        if(temp.first.d.GetYear()==year && temp.first.d.GetMonth()==month)
        {
            v.SetValue(temp.second.GetAir());
            valueTree.InsertItem(v);
            counter++;
        }
    }

    valueTree.InorderTraversal(CollectData::Sum);
    airAvg = c.GetTotal()/counter;
    valueTree.DestroyTree();
    return airAvg;
}

float GetTotalSolar(const map<dateTime, WindLogInfo> &mp, int year, int month)
{
    //working variables
    float sumOfSolarRadiation=0, hourlySolarRadiation=0, finalSolarRadiation=0;
    BinaryTreePointer<Value> valueTree;
    Value v;
    CollectData c;

    for(auto temp:mp)
    {
        if(temp.first.d.GetYear()==year && temp.first.d.GetMonth()==month)
        {
            if(temp.second.GetSolar()>100)
            {
                v.SetValue(temp.second.GetSolar());
                valueTree.InsertItem(v);
            }
        }
    }

    valueTree.InorderTraversal(CollectData::Sum);
    hourlySolarRadiation = c.GetTotal()/6;
    finalSolarRadiation = hourlySolarRadiation/1000;
    valueTree.DestroyTree();

    return finalSolarRadiation;
}

void Option1(const map<dateTime, WindLogInfo> &mp)
{
    //working variables
    int year = GetUserYear();    //get year from user
    int month = GetUserMonth();  //get month from user
    float speedAvg = GetAverageSpeed(mp, year, month);
    float airAvg = GetAverageAir(mp, year, month);
    Date dateToDisplay;
    dateToDisplay.SetMonth(month);

    //display output
    cout<<endl;
    if((speedAvg >0) && (airAvg >0))
    {
        cout << dateToDisplay.GetMonthInString() << " " << year << ": "
             << speedAvg << " km/h, " << airAvg << " degrees C" << endl;
    }
    else
    {
        cout << dateToDisplay.GetMonthInString() << " " << year << ": No Data" << endl;
    }
}

void Option2(const map<dateTime, WindLogInfo> &mp)
{
    int year = GetUserYear(); //get year from user
    Date dateToDisplay;
    int month;

    cout << "\n" << year << endl;

    for(month=1; month<13; month++)
    {
        float speedAvg = GetAverageSpeed(mp, year, month);
        float airAvg = GetAverageAir(mp, year, month);
        dateToDisplay.SetMonth(month);

        if((speedAvg >0) && (airAvg >0))
        {
            cout << dateToDisplay.GetMonthInString() << ": " << speedAvg
                 << " km/h, " << airAvg << " degrees C" << endl;
        }
        else
        {
            cout << dateToDisplay.GetMonthInString() << ": No Data" << endl;
        }
    }
}

void Option3(const map<dateTime, WindLogInfo> &mp)
{
    int year = GetUserYear(); //get year from user
    Date dateToDisplay;
    int month;

    cout << "\n" << year << endl;

    for(month=1; month<13; month++)
    {
        float solarRadiation = GetTotalSolar(mp, year, month);
        dateToDisplay.SetMonth(month);

        if(solarRadiation>0)
        {
            cout << dateToDisplay.GetMonthInString() << ": " << solarRadiation << " kWh/m^2" << endl;
        }
        else
        {
            cout << dateToDisplay.GetMonthInString() << ": No Data" << endl;
        }
    }
}

void Option4(const map<dateTime, WindLogInfo> &mp)
{
    const string outputFile = "WindTempSolar.csv";
    ofstream ofile(outputFile);
    ofile<<fixed<<showpoint<<setprecision(1); //set to only one decimal point

    int year = GetUserYear(); //get year from user
    Date dateToDisplay;
    int month;
    bool hasData = false;

    ofile << year << endl;

    for(auto temp:mp)
    {
        if(temp.first.d.GetYear()==year)
        {
            hasData = true;
        }
    }

    if(hasData)
    {
        for(month=1; month<13; month++)
        {
            float speedAvg = GetAverageSpeed(mp, year, month);
            float airAvg = GetAverageAir(mp, year, month);
            float solarRadiation = GetTotalSolar(mp, year, month);
            dateToDisplay.SetMonth(month);

            if(speedAvg > 0 && airAvg > 0 && solarRadiation > 0)
            {
                ofile << dateToDisplay.GetMonthInString() << "," << speedAvg
                      << "," << airAvg << "," << solarRadiation <<endl;
            }
        }
    }
    else
    {
        ofile << "No data" << endl;
    }

    ofile.close();
    cout << "\nAll data has been successfully output to the csv file" << endl;
}

void Option5(const map<dateTime, WindLogInfo> &mp)
{
    Time t;
    bool exist = false;
    Date theDate = GetUserDate(); //get date from user
    BinaryTreePointer<Value> solarRadiationTree;
    Value v;
    CollectData c;

    for(auto temp:mp)
    {
        if(temp.first.d.GetYear()==theDate.GetYear() && temp.first.d.GetMonth()==theDate.GetMonth() &&
           temp.first.d.GetDay()==theDate.GetDay())
        {
            if(temp.second.GetSolar()>100)
            {
                v.SetValue(temp.second.GetSolar());
                solarRadiationTree.InsertItem(v);
            }
        }
    }

    solarRadiationTree.InorderTraversal(CollectData::Max);
    cout<<"\nDate: " ;
    theDate.GetDate();
    int largestSolar = (int)c.GetMax();
    cout<<"High solar radiation for the day: "<<largestSolar<<" W/m2" <<endl;
    cout<<"\nTime:"<<endl;

    for(auto temp:mp)
    {
        if(temp.first.d.GetYear()==theDate.GetYear() && temp.first.d.GetMonth()==theDate.GetMonth() &&
           temp.first.d.GetDay()==theDate.GetDay() && temp.second.GetSolar()==largestSolar)
        {
            cout<<temp.first.t.GetHour() << ":" << temp.first.t.GetMinute() << endl;
            exist=true;
        }
    }

    if(!exist)
    {
        cout<<"No record"<<endl;
    }

    //reset tree and maxSolarRadiation
    solarRadiationTree.DestroyTree();
}

bool operator<(const dateTime& first, const dateTime& second)
{
    bool smaller=false;

    if(first.d < second.d)
    {
        smaller = true;
    }
    else if(first.d == second.d)
    {
        if(first.t < second.t)
        {
            smaller = true;
        }
    }

    return smaller;
}

bool operator==(const dateTime& first, const dateTime& second)
{
    bool same=false;

    if(first.d==second.d && first.t == second.t)
    {
        same=true;
    }

    return same;
}

bool operator<(const Value &L, const Value &R)
{
    float a = L.GetValue();
    float b = R.GetValue();

    return a < b;
}




