#include <iostream>
using namespace std;
int main(){
    int weeks, months, hoursPerDay, days;
    float totalDays = 0;
    cin >> hoursPerDay;
    for(int i = 0; i<1000; i+= hoursPerDay){
        totalDays++;
    }
    months = totalDays/22.5;
    weeks = (totalDays - (months * 22.5))/5;
    days =totalDays - (months * 22.5) - (weeks * 5);
    cout << months << " meses, " << weeks << " semanas e " << days << " dias" << endl;
}