//Date class implementation file

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date()
{
    Clear();
}

Date::Date(const int day, const int month, const int year)
{
    if(ValidDate(day, month, year))
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
    else
    {
        Clear();
    }
}

void Date::Clear()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

void Date::GetDate() const
{
    cout <<m_day << "/" << m_month << "/" << m_year << endl;
}

Date Date::GetDateObj() const
{
    Date d(m_day, m_month, m_year);
    return d;
}

void Date::SetDate(int day, int month, int year)
{
    if(ValidDate(day, month, year))
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
    else
    {
        cout<<"Invalid date "<<endl;
    }
}

void Date::SetDay(int newDay)
{
    if(ValidDate(newDay, m_month, m_year))
    {
        m_day = newDay;
    }
    else
    {
        cout<<"Invalid day "<<endl;
    }
}

void Date::SetMonth(int newMonth)
{
    if(ValidDate(m_day, newMonth, m_year))
    {
        m_month = newMonth;
    }
    else
    {
        cout<<"Invalid month "<<endl;
    }
}

void Date::SetYear(int newYear)
{
    m_year = newYear;
}

int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}

string Date::GetMonthInString() const
{
    string monthDesc;

    switch(m_month)
    {
    case 1:
        monthDesc = "January";
        break;
    case 2:
        monthDesc = "February";
        break;
    case 3:
        monthDesc = "March";
        break;
    case 4:
        monthDesc = "April";
        break;
    case 5:
        monthDesc = "May";
        break;
    case 6:
        monthDesc = "June";
        break;
    case 7:
        monthDesc = "July";
        break;
    case 8:
        monthDesc = "August";
        break;
    case 9:
        monthDesc = "September";
        break;
    case 10:
        monthDesc = "October";
        break;
    case 11:
        monthDesc = "November";
        break;
    case 12:
        monthDesc = "December";
        break;
    default:
        monthDesc = "Invalid date";
    }
    return monthDesc;
}

bool Date::ValidDate(int day, int month, int year)
{
    bool valid = false;

    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 ||month==12)
    {
        if(day >=0 && day<=31)
        {
            valid = true;
        }
    }
    else if(month==4 || month==6 || month==9 || month==11)
    {
        if(day >=0 && day<=30)
        {
            valid = true;
        }
    }
    else if(month==2)
    {
        if(IsLeapYear(year))
        {
            if(day >=0 && day<=29)
            {
                valid = true;
            }
        }else
        {
            if(day >=0 && day<=28)
            {
                valid = true;
            }
        }
    }

    return valid;

}

bool Date::IsLeapYear(int year)
{
    bool leapYear = false;

    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        leapYear = true;
    }

    return leapYear;
}

istream & operator >>( istream & input, Date & D )
{
    int day, month, year;
    char slash;

    if(input.peek() != '\n')
    {
        input >> day >> slash >> month >> slash >> year;
    }
    else
    {
        input.ignore(1); //ignore '\n'
        input >> day >> slash >> month >> slash >> year;
    }

    D.SetDate(day, month, year);

    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os <<"Date: "<<D.GetDay()<< " " << D.GetMonthInString()<< " " << D.GetYear()<<'\n';

    return os;
}


bool operator<(const Date & first, const Date & second)
{
    if(first.GetDateObj()==second.GetDateObj())
    {
        return false;
    }

    if(first.GetYear() > second.GetYear())
    {
        return false;
    }

    if(first.GetYear() == second.GetYear())
    {
        if(first.GetMonth() > second.GetMonth())
        {
            return false;
        }
    }

    if(first.GetYear() == second.GetYear() && first.GetMonth() == second.GetMonth())
    {
        if(first.GetDay() > second.GetDay())
        {
            return false;
        }
    }

    return true;
}


bool operator==(const Date & first, const Date & second)
{
    if(first.GetYear() == second.GetYear())
    {
        if(first.GetMonth()==second.GetMonth())
        {
            if(first.GetDay()==second.GetDay())
            {
                return true;
            }
        }
    }
    return false;
}

