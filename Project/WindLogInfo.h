#ifndef WINDLOGINFO_H
#define WINDLOGINFO_H

#include <iostream>

using namespace std;

    /**
     * @class WindLogInfo
     * @brief Represent some historical data recorded by sensors
     *
     * Date class contains 3 different variables,
     * m_speed, m_solar and m_air are all float type variable.
     * This class also contains appropriate get/set functions and operator.
     *
     * @author Tee Yee Kang
     * @version 01
     * @date 25/10/2021 Tee Yee Kang, Started
     *
     *
     * @bug There is no bug in this program.
     */

class WindLogInfo
{

public:

        /**
         * @brief Default WindLogInfo class constructor
         *
         * This is the default constructor. Inside the constructor will set the
         * member variables to default value when creating an WindLogInfo object.
         */
    WindLogInfo();

        /**
         * @brief WindLogInfo class constructor with parameters
         *
         * This is the constructor for WindLogInfo class. Which will takes
         * in 3 parameters. The constructor will then set the actual parameters
         * to the member variables of Date class object.
         *
         * @param speed - Speed
         * @param solar - Solar radiation
         * @param air - Ambient air temperature
         */
    WindLogInfo(const float speed, const float solar, const float air);

        /**
         * @brief Set all the member variables of WindLogInfo object to the default value.
         *
         * This function is used to clear/set default value for WindLogInfo object.
         *
         * @return void
         */
    void Clear();

        /**
         * @brief Get the speed of WindLogInfo object
         *
         * This constant function is used to return the recorded speed of WindLogInfo object
         * No input parameter is required and it is constant function. Therefore,
         * modification is not allowed.
         *
         * @return float
         */
    float GetSpeed() const;

        /**
         * @brief Set a new speed for WindLogInfo class object
         *
         * This function is used to set a new speed value for the WindLogInfo class object.
         *
         * @param newSpeed - New value of speed
         * @return void
         */
    void SetSpeed(float newSpeed);

        /**
         * @brief Get the solar radiation of WindLogInfo object
         *
         * This constant function is used to return the value solar radiation of
         * the WindLogInfo object. No input parameter is required.
         *
         * @return float
         */
    float GetSolar() const;

        /**
         * @brief Set a new solar radiation for WindLogInfo class object
         *
         * This function is used to set a new value of solar radiation for the WindLogInfo class object.
         *
         * @param newSolar - New value of solar radiation
         * @return void
         */
    void SetSolar(float newSolar);

        /**
         * @brief Get the ambient air temperature of WindLogInfo object
         *
         * This constant function is used to return the ambient air temperature of the
         * WindLogInfo object. No input parameter is required.
         *
         * @return float
         */
    float GetAir() const;

        /**
         * @brief Set a new ambient air temperature for WindLogInfo class object
         *
         * This function is used to set a new value of ambient air temperature for the WindLogInfo class object.
         *
         * @param newAir - New value of ambient air temperature
         * @return void
         */
    void SetAir(float newAir);

private:
    float m_speed;
    float m_solar;
    float m_air;

};

    /**
     * @brief Output file operator
     *
     * This operator will output some information into a output file.
     *
     * @param os - Name of output file
     * @return WindLogInfo
     */
ostream & operator <<( ostream & os, const WindLogInfo & W );

    /**
     * @brief Input file operator
     *
     * This operator will read some information from a output file.
     *
     * @param input - Name of input file
     * @return WindLogInfo
     */
istream & operator >>( istream & input, WindLogInfo & W );


#endif // WINDLOGINFO_H
