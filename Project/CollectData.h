#ifndef COLLECTDATA_H
#define COLLECTDATA_H
#include "Value.h"
#include <iostream>
#include <string>

using namespace std;

    /**
     * @class CollectData
     * @brief Store and calculate some information
     *
     * CollectData class contains 2 different variables.
     * m_max and m_total are float data type. Both are static
     * variable. This class also contains appropriate get functions.
     * and some methods to perform some task. This class is to
     * resolve the use of global variable.
     *
     * @author Tee Yee Kang
     * @version 01
     * @date 19/11/2021 Tee Yee Kang, Started
     *
     *
     * @bug There is no bug in this program.
     */

class CollectData
{
public:

        /**
         * @brief CollectData class destructor
         *
         * Inside the destructor will set all the member variable to 0.
         */
    ~CollectData();

        /**
         * @brief A static function to calculate running total.
         *
         * This function is used for the function pointer and bst.
         * This function is also implement to resolve the global
         * variable issue. Will pass this static function into the bst
         * traversal and calculate the running total.
         *
         * @param data - Value class object
         * @return void
         */
    static void Sum(Value &data);

        /**
         * @brief A static function to find max value.
         *
         * This function is used for the function pointer and bst.
         * This function is also implement to resolve the global
         * variable issue. Will pass this static function into the bst
         * traversal to compare and find max value in bst.
         *
         * @param data - Value class object
         * @return void
         */
    static void Max(Value &data);

        /**
         * @brief Getter function to get the value of member variable m_total.
         *
         * This function is use to return the value of m_total in CollectData
         * class. No input parameter is required.
         *
         * @return float
         */
    float GetTotal() const;

        /**
         * @brief Getter function to get the value of member variable m_max.
         *
         * This function is use to return the value of m_max in CollectData
         * class. No input parameter is required.
         *
         * @return float
         */
    float GetMax() const;

private:
    static float m_total;
    static float m_max;
};

#endif // COLLECTDATA_H
