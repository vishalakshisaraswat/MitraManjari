#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;
namespace cycletracker {

    class Timer {
    private:
        int countdownStart;
        int countdownEnd;
        string ans;

    public:
        Timer() {}

        void setCountdownStart(const string& expectedDate) {
            // Get current date
            time_t currentTime = time(nullptr);
            tm* currentTm = localtime(&currentTime);

            // Parse expectedDate from cycle.txt
            tm expectedTm = { 0 };
            sscanf(expectedDate.c_str(), "%d-%d-%d", &expectedTm.tm_year, &expectedTm.tm_mon, &expectedTm.tm_mday);
            expectedTm.tm_year -= 1900; // years since 1900
            expectedTm.tm_mon -= 1; // months are 0-based

            // Calculate absolute difference in days
            countdownStart = difftime(mktime(&expectedTm), currentTime) / (60 * 60 * 24);
            if (countdownStart < 0) {
                countdownStart = 0; // If the expected date is in the past, set countdownStart to 0
            }
        }

        void startCountdown() {
            int f;
            do {
                for (int i = countdownStart; i >= 0; i--) {
                    system("cls");
                    cout << " --------------------------------------" << endl;
                    cout << " |                 " << i << "                  |" << endl;
                    cout << " | more days until your next period...|" << endl;
                    cout << " --------------------------------------" << endl;
                    Sleep(1500);
                }
				int k=0;
                do {
                    system("cls");
                    cout << "-------------------------------------" <<endl;
                    cout << " | Your period may start tomorrow... |" <<endl;
                    cout << "-------------------------------------" << endl;
                    cout << "Did your period start? (yes/no): ";
                    cin >> ans;
                    k++;
                } while (ans != "yes" && ans == "no");
				
                if (ans == "yes") {
                    for (int i = 5; i >= 0; i--) {
                        system("cls");
                        cout << "-------------------------------------" <<endl;
                        cout << "|               " << i << "                  |" <<endl;
                        cout << "| more days of your period...      |" <<endl;
                        cout << "-------------------------------------" <<endl;

                        Sleep(1500);
                    }
                }
                cout<<"Your periods were delayed by: "<<k<<" days";
                cout << "\n\tKnow more... 1" <<endl;
                cout << "\tExit 0" <<endl;
                cin >> f;
            } while (f);
        }
    };

    string readExpectedDateFromFile() {
        ifstream file("D:/cycle.txt");
        string line;
        if (file.is_open()) {
            // Read the first line containing the expected date
            if (getline(file, line)) {
                size_t pos = line.find(":");
                if (pos != string::npos && pos + 1 < line.length()) {
                    return line.substr(pos + 2); // Extract the expected date
                }
            }
            file.close();
        }
        return ""; // Return empty string if the file couldn't be opened or the expected date couldn't be extracted
    }

    int main() {
        Timer t;
        string expectedDate = readExpectedDateFromFile();
        t.setCountdownStart(expectedDate);
        t.startCountdown();
        return 0;
    }

}  // namespace cycletracker
