#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string names[5];
    int marks[5][3], total[5], top = 0;
    double avg[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter student name: ";
        getline(cin >> ws, names[i]);

        total[i] = 0;
        for (int j = 0; j < 3; j++) {
            do {
                cout << "Enter mark " << j + 1 << " (0-100): ";
                cin >> marks[i][j];
                
                if (marks[i][j] < 0 || marks[i][j] > 100) {
                    cout << "Invalid mark! Please enter between 0 and 100.\n";
                }
            } while (marks[i][j] < 0 || marks[i][j] > 100);

            total[i] += marks[i][j];
        }

        avg[i] = total[i] / 3.0;
        cout << endl; // Adds a blank line after one student is completed
    }

    for (int i = 1; i < 5; i++)
        if (total[i] > total[top])
            top = i;
            
    cout << "\n" << left << setw(18) << "Name"
         << setw(7) << "M1" << setw(7) << "M2"
         << setw(7) << "M3" << setw(8) << "Total"
         << "Average\n";

    for (int i = 0; i < 5; i++) {
        cout << left << setw(18) << names[i];
        for (int j = 0; j < 3; j++)
            cout << setw(7) << marks[i][j];

        cout << setw(8) << total[i]
             << fixed << setprecision(1) << avg[i] << '\n';
    }
    cout << "\nTop student: " << names[top] << '\n';

    return 0;
}
