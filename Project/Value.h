#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

    /**
     * @class Value
     * @brief Temporarily store data
     *
     * Value class contains 1 different variable.
     * m_value is float data type.
     * This class also contains appropriate get/set functions.
     *
     * @author Tee Yee Kang
     * @version 01
     * @date 19/11/2021 Tee Yee Kang, Started
     *
     *
     * @bug There is no bug in this program.
     */

class Value
{
public:

        /**
         * @brief Value class destructor
         *
         * Inside the destructor will set all the member variable to 0.
         */
    ~Value();

        /**
         * @brief Getter function to get the value of member variable m_value.
         *
         * This constant function is use to return the value of m_value in Value
         * class. No input parameter is required.
         *
         * @return float
         */
    float GetValue() const;

        /**
         * @brief Setter function to set a new m_value for Value class object
         *
         * This function is used to set a new m_value for the Value class object.
         * Takes in an float number.
         *
         * @param number - New value to set
         * @return void
         */
    void SetValue(float number);

private:
    float m_value;
};

#endif // VALUE_H_INCLUDED
