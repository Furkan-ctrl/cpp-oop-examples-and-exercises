#include <iostream>
#include <vector>

using namespace std;

/*
    Exercise:
    Implement a program to store and manage the information of students in a class. 
    Each student should have the following attributes: name, roll number, 
    and marks in three subjects (Maths, Physics, and Chemistry).

    1. Define a struct called Student that holds the attributes mentioned above.

    2. Implement a class called Classroom that represents a class of students. 
    The class should have the following functionalities:
        Add a new student to the class.
        Display the details of all students in the class.
        Calculate and display the average marks of each student.
        
    3. In the main() function, create an instance of the Classroom class. 
    Prompt the user to enter the details of multiple students and add them to the class. 
    After adding the students, display the details of all students and their average marks.
*/


/* Solution */
struct Student {
    // Complete the code
    string name;
    int rollNumber;
    float mathMarks;
    float physicsMarks;
    float chemistryMarks;
};

class Classroom {
    private:
        vector<Student> students;

    public:
        // Complete the code
         void addStudent(const Student& student) {
           students.push_back(student);
       }  
        void displayStudents() {
         for (const auto& student : students) {
            cout << "Name: " << student.name 
                 << ", Roll Number: " << student.rollNumber 
                 << ", Maths: " << student.mathMarks 
                 << ", Physics: " << student.physicsMarks 
                 << ", Chemistry: " << student.chemistryMarks << endl;
           }
        }
        void displayAverageMarks() {
        for (const auto& student : students) {
            float average = (student.mathMarks + student.physicsMarks + student.chemistryMarks) / 3.0;
            cout << "Name: " << student.name 
                 << ", Average Marks: " << average << endl;
        }
    }
};



int main() {

    /*      Example usage:     */
    Classroom classroom;

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << endl;

        Student student;
        cout << "Name: ";
        cin >> student.name;
        cout << "Roll Number: ";
        cin >> student.rollNumber;
        cout << "Maths Marks: ";
        cin >> student.mathMarks;
        cout << "Physics Marks: ";
        cin >> student.physicsMarks;
        cout << "Chemistry Marks: ";
        cin >> student.chemistryMarks;

        classroom.addStudent(student);
        cout << endl;
    }

    cout << "Details of all students:" << endl;
    classroom.displayStudents();

    cout << "Average marks of each student:" << endl;
    classroom.displayAverageMarks();
    
    return 0;
}