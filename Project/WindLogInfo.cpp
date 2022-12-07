//WindLogInfo class implementation file

#include "WindLogInfo.h"
#include <iostream>

using namespace std;

WindLogInfo::WindLogInfo()
{
    Clear();
}

WindLogInfo::WindLogInfo(const float speed, const float solar, const float air)
{
    m_speed = speed;
    m_solar = solar;
    m_air = air;
}

void WindLogInfo::Clear()
{
    m_speed = 0;
    m_solar = 0;
    m_air = 0;
}

float WindLogInfo::GetSpeed() const
{
    return m_speed;
}

void WindLogInfo::SetSpeed(float newSpeed)
{
    m_speed = newSpeed;
}

float WindLogInfo::GetSolar() const
{
    return m_solar;
}

void WindLogInfo::SetSolar(float newSolar)
{
    m_solar = newSolar;
}

float WindLogInfo::GetAir() const
{
    return m_air;
}

void WindLogInfo::SetAir(float newAir)
{
    m_air = newAir;
}

istream & operator >>( istream & input, WindLogInfo & W )
{
    float speed, solar, air;
    char comma;

    if(input.peek() != '\n')
    {
        input >> speed >> comma >> solar >> comma >> air;
    }
    else
    {
        input.ignore(1); //ignore '\n'
        input >> speed >> comma >> solar >> comma >> air;
    }

    W.SetSpeed(speed);
    W.SetSolar(solar);
    W.SetAir(air);

    return input;
}

ostream & operator <<( ostream & os, const WindLogInfo & W )
{
    os << "Speed: " << W.GetSpeed() << '\n'
       << "Solar radiation: " << W.GetSolar() <<'\n'
       << "Ambient air temperature: " << W.GetAir() << '\n';

    return os;
}
