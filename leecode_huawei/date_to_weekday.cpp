#include "header_file.h"

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        //1971-1-1 星期五
        int month_days[] = {31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};
        int yearsSum = 0;
        //年份计算
        for(int i = 1971; i < year; i++) {
            if (i % 4 == 0) {
                yearsSum += 366;
            }
            yearsSum += 365;
            yearsSum %= 7;
        }//year
        int monthsSum = 0;
        for (int i = 0; i < month - 1; i++) {
            if (year % 4 == 0)
                month_days[1] = 29;
            monthsSum += month_days[i];
            monthsSum %= 7;
        }
        int daysSum = day - 1;
        int sum_days = yearsSum + monthsSum + daysSum;
        int sw = (sum_days) % 7;
        string strRet;
        switch(sw) {
            case 0 : strRet= "Friday";break;
            case 1 : strRet= "Saturday";break;
            case 2 : strRet= "Sunday";break;
            case 3 : strRet= "Monday";break;
            case 4 : strRet= "Tuesday";break;
            case 5 : strRet= "Wednesday";break;
            case 6 : strRet= "Thursday";break;
        }
        return strRet;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int day = stringToInteger(line);
        getline(cin, line);
        int month = stringToInteger(line);
        getline(cin, line);
        int year = stringToInteger(line);
        
        string ret = Solution().dayOfTheWeek(day, month, year);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}