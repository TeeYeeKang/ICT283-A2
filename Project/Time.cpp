//Time class implementation file

#include "Time.h"
#include<string>
#include <iostream>

using namespace std;

Time::Time()
{
    Clear();
}

Time::Time(const int hour, const int minute)
{
    if(hour>=0 && hour<=24 && minute>=0 && minute<=59)
    {
        m_hour = hour;
        m_minute = minute;
    }else
    {
        Clear();
        cout<<"Invalid time"<<endl;
    }
}

void Time::Clear()
{
    m_hour = 0;
    m_minute = 00;
}

int Time::GetHour() const
{
    return m_hour;
}

void Time::SetHour(int hour)
{
    if(hour>=0 && hour<=23)
    {
        m_hour = hour;
    }else
    {
        cout<<"There is invalid hour"<<endl;
    }
}

int Time::GetMinute() const
{
    return m_minute;
}

void Time::SetMinute(int minute)
{
    if(minute>=0 && minute<=59)
    {
        m_minute = minute;
    }else
    {
        cout<<"There is invalid minute"<<endl;
    }
}

ostream & operator <<( ostream & os, const Time & T )
{
    os << T.GetHour() << ":" << T.GetMinute() << '\n';
    return os;
}

istream & operator >>( istream & input, Time & T )
{
    int hour, minute;
    char colon;

    if(input.peek() != '\n')
    {
        input >> hour >> colon >> minute;
    }
    else
    {
        input.ignore(1); //ignore '\n'
        input >> hour >> colon >> minute;
    }

    //set the Time object
    T.SetHour(hour);
    T.SetMinute(minute);

    return input;
}

bool operator<(const Time& first, const Time& second)
{
    if(first == second)
    {
        return false;
    }

    if(first.GetHour() < second.GetHour())
    {
        return true;
    }
    else if(first.GetHour() == second.GetHour())
    {
        if(first.GetMinute() < second.GetMinute())
        {
            return true;
        }
    }

    return false;
}

bool operator==(const Time& first, const Time& second)
{
    if(first.GetHour()==second.GetHour() && first.GetMinute()==second.GetMinute())
    {
        return true;
    }

    return false;
}


