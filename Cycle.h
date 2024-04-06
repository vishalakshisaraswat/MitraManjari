#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;
namespace MenstrualCycle {
    class Cycle
    {
    protected:
        string lastDate;
        string currentPeriodStart;
        int cycleDuration;

    public:
        void readDates()
        {
            cout << "Enter the last date of menstruation (YYYY-MM-DD): ";
            cin >> lastDate;
            cout << "Enter the start date of the current period (YYYY-MM-DD): ";
            cin >> currentPeriodStart;
        }

        string calculateNextPeriodDate() {
            int year, month, day;
            sscanf(currentPeriodStart.c_str(), "%d-%d-%d", &year, &month, &day);

            tm currentPeriodTm = { 0 };
            currentPeriodTm.tm_year = year - 1900;
            currentPeriodTm.tm_mon = month - 1;
            currentPeriodTm.tm_mday = day;

            sscanf(lastDate.c_str(), "%d-%d-%d", &year, &month, &day);

            tm lastDateTm = { 0 };
            lastDateTm.tm_year = year - 1900;
            lastDateTm.tm_mon = month - 1;
            lastDateTm.tm_mday = day;

            time_t currentPeriodTime = mktime(&currentPeriodTm);
            time_t lastDatePeriodTime = mktime(&lastDateTm);

            cycleDuration = (currentPeriodTime - lastDatePeriodTime) / (24 * 60 * 60);

            currentPeriodTime += cycleDuration * 24 * 60 * 60;

            tm* nextPeriodTm = localtime(&currentPeriodTime);
            char buffer[11];
            strftime(buffer, 11, "%Y-%m-%d", nextPeriodTm);

            return (buffer);
        }

        void display() {
            cout << "Last cycle: " << lastDate << endl;
            cout << "Current cycle: " << currentPeriodStart << endl;
            cout << "Duration: " << cycleDuration << " days" << endl;
        }

        void saveToFile(const string& filename) {
            ofstream file(filename);
            if (file.is_open()) {
//                file << "Last cycle: " << lastDate << std::endl;
//                file << "Current cycle: " << currentPeriodStart << std::endl;
                file << "Expected Date: " << calculateNextPeriodDate() << endl;
//                file << "Duration: " << cycleDuration << " days" << std::endl;
                file.close();
            }
            else {
                cerr << "Unable to open file for writing." << endl;
            }
        }

    };

    int main()
    {
        Cycle m;
        m.readDates();
        string next = m.calculateNextPeriodDate();
        m.display();
        cout << "Next expected date: " << next << endl;

        // Save data to file
        m.saveToFile("D:/cycle.txt");

        return 0;
    }
}
