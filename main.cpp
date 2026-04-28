#include<string> 
#include<iomanip> 
#include<iostream> 

using namespace std; 
void gradeChecker(double& examScore) {
    while (cin.fail() || examScore < 0 || examScore > 100) {

        cin.clear();                // reset fail state
        cin.ignore(1000, '\n');     // remove bad input

        cout << "Invalid grade. Please enter a grade between 0 and 100: " << endl;
        cin >> examScore;
    }
};


//assign grade letters 
/*

Part 3: Letter Grades
Declare a 1D character array to store the letter grade of each student. Calculate the letter grade
on average score.
Use this grading scale:
• 90 and above → A
• 80 and above → B
• 70 and above → C
• 60 and above → D
• Below 60 → F

*/
char letterGrade(double average)
{
  
   if(average >= 90)  return 'A'; 
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if(average >= 60) return 'D'; 
        else return 'F';
};

string toLower(const string& str)
{
    string result = str;
    for (int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
};
/*
You will create a program for a class gradebook containing 10 students.
Part 1: Student Names
Declare a 1D string array and read the names of 10 students into it
*/
void printStudentDetails(const string& name, const double scores[6], char letter)
{
    cout << fixed << setprecision(2);
    cout << "\nStudent: " << name;
    cout << "\nExam 1: " << scores[0];
    cout << "\nExam 2: " << scores[1];
    cout << "\nExam 3: " << scores[2];
    cout << "\nExam 4: " << scores[3];
    cout << "\nTotal: " << scores[4] << " / 400";
    cout << "\nAverage: " << scores[5];
    cout << "\nLetter Grade: " << letter << "\n";
}

void printGradebook()
{
    cout << left
    << setw(12) << "Name"
    << setw(8) << "Exam1"
    << setw(8) << "Exam2"
    << setw(8) << "Exam3"
    << setw(8) << "Exam4"
    << setw(10) << "Total"
    << setw(10) << "Average"
    << setw(8) << "Grade"
    << endl;
    cout << string(72, '-') << endl;
}
/*
Part 2: Grades Table
Declare a 2D double array with:
• 10 rows for the 10 students
• 6 columns for the following data:

*/
void gradeTable(const string& name, const double scores[6], char letter)
{
    cout << fixed << setprecision(2);
    cout << left
    << setw(12) << name
    << setw(8) << scores[0]
    << setw(8) << scores[1]
    << setw(8) << scores[2]
    << setw(8) << scores[3]
    << setw(10) << scores[4]
    << setw(10) << scores[5]
    << setw(8) << letter
    << endl;
}

int main ()
{
    const int studentCount = 10;
    const int examColumns = 6;

    // string names[studentCount] = {
    //     "chris", "Lance", "jake", "ashly", "Jose",
    //     "Christian", "Gaby", "ron", "kat", "frank"
    // };
string names[studentCount];
for(int i = 0; i < studentCount; i++ ) {
    cout << "Enter name of student " << i + 1 << ": ";
    getline(cin, names[i]);
}


    double examScores[studentCount][examColumns];
    char letterGrades[studentCount];

    cout << "Student list:" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "Student " << i + 1 << ": " << names[i] << endl;
    }
/*

Part 2: Grades Table
Declare a 2D double array with:
 10 rows for the 10 students
 6 columns for the following data:
Column Meaning
0 Exam 1 score
1 Exam 2 score
2 Exam 3 score
3 Exam 4 score
4 Total score
5 Average score
For each student:
 input the scores for Exam 1, Exam 2, Exam 3, and Exam 4
 calculate the total out of 400
 calculate the average out of 100

*/
    for (int i = 0; i < studentCount; i++) {
    cout << "\nEnter scores for " << names[i] << endl;

    cout << "Exam 1: ";
        cin >> examScores[i][0];
        gradeChecker(examScores[i][0]);

    cout << "Exam 2: ";
        cin >> examScores[i][1];
        gradeChecker(examScores[i][1]);

    cout << "Exam 3: ";
        cin >> examScores[i][2];
        gradeChecker(examScores[i][2]);

    cout << "Exam 4: ";
        cin >> examScores[i][3];
        gradeChecker(examScores[i][3]);

    examScores[i][4] = examScores[i][0] + examScores[i][1] + examScores[i][2] + examScores[i][3];
    examScores[i][5] = examScores[i][4] / 4.0;
    letterGrades[i] = letterGrade(examScores[i][5]);
    }

    int HighestScore = 0;
    for (int i = 1; i < studentCount; i++) {
        if (examScores[i][4] > examScores[HighestScore][4]) {
            HighestScore = i;
        }
    }
/*
Menu Requirements:
Create a menu with the following options:
1. View the gradebook of a particular student
2. View the gradebook of the top student only
3. View the full gradebook of all students
4. Exit
The menu should repeat until the user selects Exit
*/
    int inputChoice = 0;
    while (inputChoice != 4) {
    cout << "\n------- Menu -------\n";
    cout << "Option 1: View the gradebook of a particular student" << endl;
    cout << "Option 2: View the gradebook of the top student only" << endl;
    cout << "Option 3: View the full gradebook of all students" << endl;
    cout << "Option 4: Exit" << endl;
    cout << "Enter choice: ";
    cin >> inputChoice;

    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option." << endl;
            continue;
        }

        switch (inputChoice) {
            /*
            Option 1: View a Particular Student
        When the user selects this option:
         ask the user to enter a student name
            search for that name in the StudentNames array
            if the name is found, display:
            student name
            exam 1 score
            exam 2 score
            exam 3 score
            exam 4 score
            total       
            average
            letter grade
            */
            case 1: {
               string searchingForName;
              int studentIndex = -1;

              cout << "Enter a student name: ";
              cin >> searchingForName;

              string searchLower = toLower(searchingForName);
              for (int i = 0; i < studentCount; i++) {
                if (toLower(names[i]) == searchLower) {
                        studentIndex = i;
                        break;
                    }
                }
                if (studentIndex == -1) {
                   cout << "Student not found." << endl;
                } else {
                    cout << "\nParticular Student Gradebook" << endl;
                    printStudentDetails(names[studentIndex], examScores[studentIndex], letterGrades[studentIndex]);

                    cout << "\nTop Student Summary" << endl;
                    cout << "Name: " << names[HighestScore] << endl;
                    cout << fixed << setprecision(2);
                    cout << "Total: " << examScores[HighestScore][4] << endl;
                    cout << "Average: " << examScores[HighestScore][5] << endl;
                    cout << "Letter Grade: " << letterGrades[HighestScore] << endl;
                }
                break;
            }

            case 2: {
                cout << "\nTop Student (Highest Total Score)" << endl;
                printStudentDetails(names[HighestScore], examScores[HighestScore], letterGrades[HighestScore]);
                break;
            }

            case 3: {
                cout << "\nFull Gradebook" << endl;
                printGradebook();
                for (int i = 0; i < studentCount; i++) {
                    gradeTable(names[i], examScores[i], letterGrades[i]);
                }
                break;
            }

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }
    }

    return 0;
}
