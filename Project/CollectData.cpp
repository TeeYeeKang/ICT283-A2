#include "CollectData.h"
#include <iostream>
#include <string>

using namespace std;

CollectData::~CollectData()
{
    m_total=0;
    m_max=0;
}

void CollectData::Sum(Value &data)
{
    m_total+=data.GetValue(); //calculate running total
}

void CollectData::Max(Value &data)
{
    if (data.GetValue() > m_max)
    {
        m_max = data.GetValue(); //compare and find max value
    }
}

float CollectData::GetTotal() const
{
    return m_total;
}

float CollectData::GetMax() const
{
    return m_max;
}



