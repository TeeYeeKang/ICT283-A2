#include "Value.h"
#include <iostream>
#include <string>

using namespace std;

Value::~Value()
{
    m_value=0;
}

float Value::GetValue() const
{
    return m_value;
}

void Value::SetValue(float number)
{
    m_value = number;
}
