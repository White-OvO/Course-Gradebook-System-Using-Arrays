#include<string> 
#include<iomanip> 
#include<iostream> 

using namespace std; 
void gradeChecker(int& examScore) {
    while (cin.fail() || examScore < 0 || examScore > 100) {

        cin.clear();                // reset fail state
        cin.ignore(1000, '\n');     // remove bad input

        cout << "Invalid grade. Please enter a grade between 0 and 100: " << endl;
        cin >> examScore;
    }
};


//assign grade letters 

  char letterGrade (int average){
 
   if(average >= 90)  return 'A'; 
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if(average >= 60) return 'D'; 
        else return 'F';
};

    int main () {   

    int inputChoice =0;
    string searchingForName = " " ; 
     string names[10] = {"chris","Lance","jake","ashly","Jose","Christian","Gaby","ron","kat","frank"}; 

    cout << setw(20)<< setprecision(30)  << "-" << endl;
  
    cout << "\n------- Menu -------\n";
    cout << "Option 1: Search for a student  " << endl; 
    cout << "Option 2: View the top student  " << endl; 
    cout << "Option 3: View the full GradeBook for all students " << endl; 
    cout << "Option 4: Exit" << endl;
    cin >> inputChoice ;  
    switch(inputChoice) { 
    case 1:
    cout << "enter a student name :"; 
    cin >> searchingForName; 
    bool found = false; 
    for (int i = 0; i < 10; i++) {
        if (names[i] == searchingForName) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found." << endl;
    
    }
    break;
    case 2: 
    cout << "Highest Score :" << endl; 
    break;
    case 3: 
    cout << "Full GradeBook:" << endl;
    break;
    case 4:
    cout << "Exiting program." << endl;
    break;
}
        /* TIPS 
        first storename 
        then input exam sxore 
        then calculate totals and averages 
        then assign letter grades 
        then find the top student 
        finally build the menu */


        // step 1 creating the array of 10 names and storing them   


        // --------------------------
        // removed to make the process quicker ( uncomment for the input of the names of the students )
        // 
        //string names[10]; 

        // --------------------------

       
        // ----------------------------
       // string studentsName[10];
        // for (int i =0; i < 10; i++) { 
        //     cout<<"Enter the student name : ";
        //     cin >> names;
        //     studentsName[i] = names;
        // } 
        // removed to make the process quicker ( uncomment for the input of the names of the students )
        // ------------------------


        //--------------------
        // display the name
        // ----------------- 
        cout << "Student list[]: " << endl; 
        for (int i = 0; i <10; i++) { 
            // -------------------------------- correct format ( uncomment for final section ) 

               //  cout << "\nStudent " << i + 1 << " name " << studentsName[i]; 
             // ------------------------------------  
               cout << "Students names: " << names[i] << endl;
        }




        // step 2 declaring a 2D double array with 10 rows and 6 colums 
        int examScores[10][6];

        // total out of 400
        const int TotalScore = 400;

        // for each student enter the exam 1, exam 2, exam 3 , and exam 4
        for (int i = 0; i < 10; i++) {

    cout << "Enter the score for student " << names[i] << "\nExam 1: ";
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

    // Calculate total
    examScores[i][4] = examScores[i][0] +
                       examScores[i][1] +
                       examScores[i][2] +
                       examScores[i][3];

    // Calculate average
    examScores[i][5] = examScores[i][4] / 4.0;
}

 // --------------------------------------------
 // Total for the students total exam scores 
 // --------------------------------------------       
        //calculate the total out of 400 for the exam score per student 
// looping through the exams total 
cout << " --- Grade book ----- \n" << endl; 

for ( int i = 0 ; i < 10; i ++ ) { 
    cout << "\nStudent: " << names[i]; 
    cout << "\nExam 1: " << examScores[i][0]; 
    cout << "\nExam 2: " << examScores[i][1]; 
    cout << "\nExam 3: " << examScores[i][2]; 
    cout << "\nExam 4: " << examScores[i][3]; 
    cout << "\nTotal: " << examScores[i][4] << " / 400"; 
    cout << "\nAverage: " << examScores[i][5]; 
    cout << "\nLetter Grade: " << letterGrade(examScores[i][5]) << endl;
}
 // --------------------------------------------
 // Average for the students total exam scores 
 // --------------------------------------------       




    return 0; 
}