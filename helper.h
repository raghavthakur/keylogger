#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper
{
    template <class T>

    std::string ToString(const T &);

    struct DateTime
    {
        DateTime()
        {
            time_t sec;
            time(&sec);

            struct tm *info = localtime(&sec);

            day = info->tm_mday;
            month = info->tm_mon + 1;
            year = 1900 + info->tm_year;
            hour = info->tm_hour;
            minute = info->tm_min;
            second = info->tm_sec;
        }

        DateTime(int day, int month, int year, int hour, int minute, int second) : day(day), month(month), year(year), hour(hour), minute(minute), second(second) {}
        DateTime(int day, int month, int year) : day(day), month(month), year(year), hour(0), minute(0), second(0) {}

        DateTime Now() const
        {
            return DateTime();
        }

        int day, month, year, hour, minute, second;

        std::string GetDateString() const
        {
            return std::string(day < 10 ? "0" : "") + ToString(day)
                + std::string(month < 10 ? ".0" : ".") + ToString(month) + "." + ToString(year);
        }

        std::string GetTimeString(const std::string &sep = ":") const
        {
            return std::string(hour < 10 ? "0" : "") + ToString(hour) + sep
                + std::string(minute < 10 ? "0" : "") + ToString(minute) + sep
                + std::string(second < 10 ? sep : "") + ToString(second);
        }

        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }
    };

    template <class T>

    std::string ToString(const T &e)
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    // Debug functions
    void WriteAppLog(const std::string &s)
    {
        std::ofstream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" << "\n" << s << std::endl << "\n";
        file.close();
    }


}

#endif // HELPER_H
