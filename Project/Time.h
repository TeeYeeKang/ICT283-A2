#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

    /**
     * @class Time
     * @brief Represent the Time of marks were obtained
     *
     * Time class contains 2 different member variables,
     * both m_hour and m_minute are all int type variable.
     * This class also contains appropriate get/set functions and operator.
     * The time in this class is 24 hours time.
     * Inside the constructor and set functions also contains appropriate validation
     * check to ensure the user enter valid time.
     *
     * @author Tee Yee Kang
     * @version 01
     * @date 25/10/2021 Tee Yee Kang, Started
     *
     *
     * @bug There is no bug in this program.
     */

class Time
{

public:

        /**
         * @brief Create Time object with default value
         *
         * This is the default constructor. Inside the constructor will set the
         * member variables to default value by using the Clear() method.
         */
    Time(); //default constructor

        /**
         * @brief Time class constructor with parameters
         *
         * This is the constructor of Time class. Which will takes
         * in 2 parameters. The constructor will then set the actual parameters
         * to the member variables of Time class object.
         *
         * @param h - Hours
         * @param m - Minutes
         */
    Time(const int hour, const int minute);

        /**
         * @brief Set all the member variables of Time object to default value.
         *
         * This function is used to set default value for Time object.
         *
         * @return void
         */
    void Clear();

        /**
         * @brief Get the hour of Time object
         *
         * This const function is used to return the time object's hour
         * No input parameter is required.
         *
         * @return int
         */
    int GetHour() const;

       /**
         * @brief Set a new hour for Time class object
         *
         * This function is used to set a new value for the hour of the Time class object.
         *
         * @param hour - New hour of Time object
         * @return void
         */
    void SetHour(int hour);

        /**
         * @brief Get the minute of Time object
         *
         * This const function is used to return the time object's minute
         * No input parameter is required.
         *
         * @return int
         */
    int GetMinute() const;

       /**
         * @brief Set a new minute for Time class object
         *
         * This function is used to set a new value for the minute of the Time class object.
         *
         * @param minute - New minute of Time object
         * @return void
         */
    void SetMinute(int minute);

private:
    int m_hour;
    int m_minute;

};

    /**
     * @brief Output file operator
     *
     * This operator will output some information into a output file.
     *
     * @param os - Name of output file
     * @return Time
     */
ostream & operator <<( ostream & os, const Time & T );

    /**
     * @brief Input file operator
     *
     * This operator will read some information from a output file.
     *
     * @param input - Name of input file
     * @return Time
     */
istream & operator >>( istream & input, Time & T );

    /**
     * @brief Overload operator
     *
     * This operator is used to compare 2 Time class objects and
     * return true if the first Time class object is smaller than
     * the second Time class object.
     *
     * @param first - First Time class object
     * @param second - Second Time class object
     * @return bool
     */
bool operator<(const Time& first, const Time& second);

    /**
     * @brief Overload operator
     *
     * This operator is used to compare 2 pass in Time class objects and check
     * whether there are same Time.
     *
     * @param first - First Time class object
     * @param second - Second Time class object
     * @return bool
     */
bool operator==(const Time& first, const Time& second);


#endif // TIME_H
