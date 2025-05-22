#include <iostream>
#include <string>
#include <vector>

using namespace std;

class international_student // created internationa_student class;
{

private: // used private access specifier to keep the student details safe
    int id;
    string name;
    float score;

public:
    international_student(int student_id, string student_name, float student_score)
    // this is a constructor method where i'm initializing the object declaring the parameters
    //  and assigning it to the class.
    {
        id = student_id;
        name = student_name;
        score = student_score;
    }

    void show_student_details() // this function prints the student details including name, id ,and score
    {
        cout << "----------------------------------" << "\n";
        cout << "Student Name is : " << name << "\n";
        cout << "Student Id : " << id << "\n";
        cout << "Student Score : " << score << "\n";
        cout << "----------------------------------" << "\n";
    }

    void update_score(float newScore) // update_score accepts accepts an agrument named newScore which updates the initial score of student

    {
        score = newScore;
        cout << "student score updated " << name << score;
    }

    int provide_id()
    {
        return id;
    }
};

class student_administration // initialization of student_administration class.
{
public:
    // here we have used vector data type to store the student details;
    // array could have been used but we have to set a static size of array which doesn't suit our requirements
    // whereas vector's are just like array but they are dynamic and it doesn't require to define the size as it can handle it automatically.
    vector<international_student> students_database;

    student_administration() // here the constructor method is called to add some default student details;

    {
        international_student mingma(1, "Mingma", 200); // creates a international student class
        international_student bagus(2, "Bagus", 20001);
        international_student wina(3, "Wina", 200);
        international_student ero(4, "Ero", 20001);

        students_database.push_back(mingma); // here we are adding the student details to students_database
                                             // using the .push_back() method available in vector data structure.
        students_database.push_back(bagus);
        students_database.push_back(wina);
        students_database.push_back(ero);
    }

    void add_student_info(international_student student_details)
    {
        students_database.push_back(student_details);
    };

    void show_all_students()
    {
        for (
            international_student &student : students_database)
        {
            student.show_student_details();
        }
    }

    void update_student_score(int student_id, float new_score)
    {
        for (international_student &student : students_database)
        {
            if (student.provide_id() == student_id)
            {
                student.update_score(new_score);
            }
        }
    }
};

int main()
{

    student_administration admin;

    admin.show_all_students();
    admin.update_student_score(1, 399);
    admin.show_all_students();
    return 0;
}