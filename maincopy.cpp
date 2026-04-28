#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int NUM_STUDENTS = 10;
const int NUM_EXAMS = 4;

int getValidatedScore(const string &prompt) {
    int score;
    while (true) {
        cout << prompt;
        if (!(cin >> score)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer between 0 and 100." << endl;
            continue;
        }
        if (score < 0 || score > 100) {
            cout << "Score must be between 0 and 100. Try again." << endl;
            continue;
        }
        return score;
    }
}

char letterGrade(double avg) {
    if (avg >= 90.0) return 'A';
    if (avg >= 80.0) return 'B';
    if (avg >= 70.0) return 'C';
    if (avg >= 60.0) return 'D';
    return 'F';
}

void fillSampleScores(vector<vector<int> > &scores) {
    // A small set of sample scores for quick testing/demo
    int sample[NUM_STUDENTS][NUM_EXAMS] = {
        {88, 92, 79, 85},
        {95, 90, 93, 98},
        {72, 70, 68, 75},
        {60, 62, 58, 65},
        {84, 80, 82, 86},
        {100, 99, 98, 97},
        {55, 60, 58, 53},
        {77, 79, 75, 80},
        {90, 88, 92, 94},
        {69, 70, 68, 66}
    };
    for (int i = 0; i < NUM_STUDENTS; ++i)
        for (int j = 0; j < NUM_EXAMS; ++j)
            scores[i][j] = sample[i][j];
}

void inputScores(vector<vector<int> > &scores, const vector<string> &names) {
    cout << "Would you like to enter scores manually? (y/n): ";
    char c; cin >> c;
    if (c == 'n' || c == 'N') {
        fillSampleScores(scores);
        cout << "Sample scores loaded.\n";
        return;
    }

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Entering scores for " << names[i] << ":\n";
        for (int j = 0; j < NUM_EXAMS; ++j) {
            string prompt = "  Exam " + to_string(j+1) + ": ";
            scores[i][j] = getValidatedScore(prompt);
        }
        cout << '\n';
    }
}

void printStudentReport(const string &name, const vector<int>& sc) {
    int total = 0;
    for (size_t idx = 0; idx < sc.size(); ++idx) total += sc[idx];
    double avg = total / static_cast<double>(NUM_EXAMS);
    cout << left << setw(12) << name;
    for (size_t idx = 0; idx < sc.size(); ++idx) cout << right << setw(6) << sc[idx];
    cout << right << setw(8) << total << setw(10) << fixed << setprecision(2) << avg << setw(6) << letterGrade(avg) << '\n';
}

int findTopStudent(const vector<vector<int> > &scores) {
    int bestIdx = 0;
    double bestAvg = -1.0;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int total = 0;
        for (int j = 0; j < NUM_EXAMS; ++j) total += scores[i][j];
        double avg = total / static_cast<double>(NUM_EXAMS);
        if (avg > bestAvg) {
            bestAvg = avg;
            bestIdx = i;
        }
    }
    return bestIdx;
}

int main() {
    const char *namesArr[NUM_STUDENTS] = {"chris","Lance","jake","ashly","Jose","Christian","Gaby","ron","kat","frank"};
    vector<string> names(namesArr, namesArr + NUM_STUDENTS);
    vector<vector<int> > scores(NUM_STUDENTS, vector<int>(NUM_EXAMS, 0));

    inputScores(scores, names);

    while (true) {
        cout << "\n------- GradeBook Menu -------\n";
        cout << "1. Search for a student\n";
        cout << "2. View the top student\n";
        cout << "3. View the full gradebook\n";
        cout << "4. Re-enter scores\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        int choice; if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (choice == 1) {
            cout << "Enter student name to search: ";
            string q; cin >> q;
            bool found = false;
            for (int i = 0; i < NUM_STUDENTS; ++i) {
                if (names[i] == q) {
                    cout << "\nName   ";
                    for (int e = 1; e <= NUM_EXAMS; ++e) cout << setw(6) << (string("E") + to_string(e));
                    cout << setw(8) << "Total" << setw(10) << "Average" << setw(6) << "Ltr" << '\n';
                    printStudentReport(names[i], scores[i]);
                    found = true; break;
                }
            }
            if (!found) cout << "Student not found.\n";
        } else if (choice == 2) {
            int idx = findTopStudent(scores);
            cout << "\nTop student: " << names[idx] << "\n";
            cout << "Name   ";
            for (int e = 1; e <= NUM_EXAMS; ++e) cout << setw(6) << (string("E") + to_string(e));
            cout << setw(8) << "Total" << setw(10) << "Average" << setw(6) << "Ltr" << '\n';
            printStudentReport(names[idx], scores[idx]);
        } else if (choice == 3) {
            cout << "\nFull Gradebook:\n";
            cout << left << setw(12) << "Name";
            for (int e = 1; e <= NUM_EXAMS; ++e) cout << right << setw(6) << (string("E") + to_string(e));
            cout << right << setw(8) << "Total" << setw(10) << "Average" << setw(6) << "Ltr" << '\n';
            for (int i = 0; i < NUM_STUDENTS; ++i) printStudentReport(names[i], scores[i]);
        } else if (choice == 4) {
            inputScores(scores, names);
        } else if (choice == 5) {
            cout << "Exiting.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
