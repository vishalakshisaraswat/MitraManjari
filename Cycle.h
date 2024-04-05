#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

namespace MenstrualCycle {
    class Cycle
    {
    protected:
        std::string lastDate;
        std::string currentPeriodStart;
        int cycleDuration;

    public:
        void readDates()
        {
            std::cout << "Enter the last date of menstruation (YYYY-MM-DD): ";
            std::cin >> lastDate;
            std::cout << "Enter the start date of the current period (YYYY-MM-DD): ";
            std::cin >> currentPeriodStart;
        }

        std::string calculateNextPeriodDate() {
            int year, month, day;
            sscanf(currentPeriodStart.c_str(), "%d-%d-%d", &year, &month, &day);

            std::tm currentPeriodTm = { 0 };
            currentPeriodTm.tm_year = year - 1900;
            currentPeriodTm.tm_mon = month - 1;
            currentPeriodTm.tm_mday = day;

            sscanf(lastDate.c_str(), "%d-%d-%d", &year, &month, &day);

            std::tm lastDateTm = { 0 };
            lastDateTm.tm_year = year - 1900;
            lastDateTm.tm_mon = month - 1;
            lastDateTm.tm_mday = day;

            std::time_t currentPeriodTime = mktime(&currentPeriodTm);
            std::time_t lastDatePeriodTime = mktime(&lastDateTm);

            cycleDuration = (currentPeriodTime - lastDatePeriodTime) / (24 * 60 * 60);

            currentPeriodTime += cycleDuration * 24 * 60 * 60;

            std::tm* nextPeriodTm = localtime(&currentPeriodTime);
            char buffer[11];
            strftime(buffer, 11, "%Y-%m-%d", nextPeriodTm);

            return (buffer);
        }

        void display() {
            std::cout << "Last cycle: " << lastDate << std::endl;
            std::cout << "Current cycle: " << currentPeriodStart << std::endl;
            std::cout << "Duration: " << cycleDuration << " days" << std::endl;
        }

        void saveToFile(const std::string& filename) {
            std::ofstream file(filename);
            if (file.is_open()) {
//                file << "Last cycle: " << lastDate << std::endl;
//                file << "Current cycle: " << currentPeriodStart << std::endl;
                file << "Expected Date: " << calculateNextPeriodDate() << std::endl;
//                file << "Duration: " << cycleDuration << " days" << std::endl;
                file.close();
            }
            else {
                std::cerr << "Unable to open file for writing." << std::endl;
            }
        }

    };

    int main()
    {
        Cycle m;
        m.readDates();
        std::string next = m.calculateNextPeriodDate();
        m.display();
        std::cout << "Next expected date: " << next << std::endl;

        // Save data to file
        m.saveToFile("D:/cycle.txt");

        return 0;
    }
}
