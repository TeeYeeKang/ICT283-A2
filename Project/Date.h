#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

    /**
     * @class Date
     * @brief Represent the date of marks were obtained
     *
     * Date class contains 3 different variables.
     * m_day, m_month and m_year are all int type variable.
     * This class also contains appropriate get/set functions and operator.
     * Inside the constructor and set functions also contains appropriate validation
     * check to ensure the user enter valid date.
     *
     * @author Tee Yee Kang
     * @version 01
     * @date 25/10/2021 Tee Yee Kang, Started
     *
     *
     * @bug There is no bug in this program.
     */

class Date
{
public:

        /**
         * @brief Default Date class constructor
         *
         * This is the default constructor. Inside the constructor will set the
         * member variables to default value when creating an Unit object.
         */
    Date();

        /**
         * @brief Date class constructor with parameters
         *
         * This is the constructor for Date class. Which will takes
         * in 3 parameters. The constructor will then set the actual parameters
         * to the member variables of Date class object.
         *
         * @param d - Day
         * @param m - Month
         * @param y - Year
         */
    Date(const int day, const int month, const int year);

        /**
         * @brief Set all the member variables of Date object to the default value.
         *
         * This function is used to clear/set default value for Date object.
         *
         * @return void
         */
    void Clear();

        /**
         * @brief Get the final output of Date object
         *
         * This constant function is used to return the date of the marks were obtained
         * No input parameter is required and it is constant function. Therefore, no
         * modification is allowed.
         *
         * @return void
         */
    void GetDate() const;

        /**
         * @brief Set a new date for Date class object
         *
         * This function is used to set a new date for the Date class object.
         * Takes in 3 int values to set the date of the Date class object.
         *
         * @param d - New day of date
         * @param m - New month of date
         * @param y - New year of date
         * @return void
         */
    void SetDate(int day, int month, int year);

        /**
         * @brief Get the day of the date when the marks were obtained
         *
         * This constant function is used to return the day of the marks were obtained
         * No input parameter is required.
         *
         * @return int
         */
    int GetDay() const;

        /**
         * @brief Set a new day for Date class object
         *
         * This function is used to set a new day for the Date class object.
         * Takes in an int value.
         *
         * @param newDay - New day of date
         * @return void
         */
    void SetDay(int newDay);

        /**
         * @brief Get the month of the date when marks were obtained
         *
         * This constant function is used to return the month of the marks were obtained.
         * No input parameter is required.
         *
         * @return int
         */
    int GetMonth() const;

        /**
         * @brief Set a new month for Date class object
         *
         * This overload function is used to set a new month
         * for the Date class object. Only takes in a new month with int value.
         *
         * @param newMonth - New month of date
         * @return void
         */
    void SetMonth(int newMonth);

        /**
         * @brief Get the year of the date when marks were obtained
         *
         * This constant function is used to return the year of the marks were obtained.
         * No input parameter is required.
         *
         * @return int
         */
    int GetYear() const;

        /**
         * @brief Set a new year for Date class object
         *
         * This function is used to set a new year for the Date class object.
         * Takes in an int value.
         *
         * @param newYear - New year of date
         * @return void
         */
    void SetYear(int newYear);

        /**
         * @brief Get the description of specific month
         *
         * This function is used to return the month in English word form.
         *
         * @return string
         */
    string GetMonthInString() const;

        /**
         * @brief Check for valid date
         *
         * This boolean function is used to check if the date of Date class object is valid or not.
         *
         * @param day - day of date
         * @param month - month of date
         * @param year - Year of date
         * @return bool
         */
    bool ValidDate(int day, int month, int year);

        /**
         * @brief Check for leap year
         *
         * This boolean function is used to check is the year of Date class object is leap year or not.
         *
         * @param year - Year of date
         * @return bool
         */
    bool IsLeapYear(int year);

        /**
         * @brief Get the Date object
         *
         * This constant function is used to return the Date class object
         * No input parameter is required.
         *
         * @return Date
         */
    Date GetDateObj() const;

private:
    int m_day;
    int m_month;
    int m_year;
};

    /**
     * @brief Output file operator
     *
     * This operator will output some information into a output file.
     *
     * @param os - Name of output file
     * @return Date
     */
ostream & operator <<( ostream & os, const Date & D );

    /**
     * @brief Input file operator
     *
     * This operator will read some information from a output file.
     *
     * @param input - Name of input file
     * @return Date
     */
istream & operator >>( istream & input, Date & D );

    /**
     * @brief Overload operator
     *
     * This operator is used to compare 2 Date class objects and
     * return true if the first Date class object is smaller than
     * the second Date class object.
     *
     * @param first - First Date class object
     * @param second - Second Date class object
     * @return bool
     */
bool operator<(const Date & first, const Date & second);

    /**
     * @brief Overload operator
     *
     * This operator is used to compare 2 pass in Date class objects and check
     * whether there are same.
     *
     * @param first - First Date class object
     * @param second - Second Date class object
     * @return bool
     */
bool operator==(const Date & first, const Date & second);

#endif // DATE_H
