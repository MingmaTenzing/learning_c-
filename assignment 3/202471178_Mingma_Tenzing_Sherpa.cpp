#include <iostream> //including all the necessary headers
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// function declaration
void welcome_user();
int task_starter();

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

    int provide_id() // function returns the student id of the current instance;
    {
        return id;
    }

    int provide_score() // function return student's score
    {
        return score;
    }

    string provide_name() // function returns the student name
    {
        return name;
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
        international_student mingma(1, "Mingma", 55); // creates a international student class
        international_student bagus(2, "Bagus", 100);
        international_student wina(3, "Wina", 23);
        international_student ero(4, "Ero", 65);

        students_database.push_back(mingma); // here we are adding the student details to students_database
                                             // using the .push_back() method available in vector data structure.
        students_database.push_back(bagus);
        students_database.push_back(wina);
        students_database.push_back(ero);
    }

    void add_new_student(int student_id, string name, float score)
    // this memeber function adds a new student by accepting three parameter(id, name and score)
    {
        international_student student_details(student_id, name, score); // creating the object
        students_database.push_back(student_details);                   // adding it to vector by using push_back method
        cout << "----------------------------------------" << "\n";

        cout << "New Student has been added successfully" << "\n";
        cout << "----------------------------------------" << "\n";
    };

    void show_all_students() // the function displays all students;
    {

        for (
            international_student &student : students_database)
        // this is a for each loop where we are referencing to international student class
        // and loopgin through students_database
        {
            student.show_student_details();
        }
    }

    void update_student_score(int student_id, float new_score)
    {
        for (international_student &student : students_database)
        // here we are looping through students_database
        {
            if (student.provide_id() == student_id)
            // if student id matches with passed argument it will update score;
            {
                student.update_score(new_score); // calling update score method
            }
        }
    }

    void search_student(int student_id)
    {
        for (international_student &student : students_database)
        // this function searches through students_database using id and prints the
        // student detail if found;

        {
            if (student.provide_id() == student_id)
            {
                return student.show_student_details();
            }
        }
        cout << "Student doesn't exist with id :" << student_id << " \n";
    }

    void sort_and_display_by_score()
    {
        // Copy students to sort without modifying the original order
        vector<international_student> sorted_students = students_database;

        // Sort in descending order of scores
        sort(sorted_students.begin(), sorted_students.end(), [](international_student &a, international_student &b)
             { return a.provide_score() > b.provide_score(); });
        // here we are using lambda expression to sort the data

        cout << "Students sorted by score (highest to lowest):\n";
        for (international_student &student : sorted_students)
        {
            student.show_student_details();
        }
    }

    void show_total_and_average_score()
    {
        float total = 0;                      // declared total as 0
        int count = students_database.size(); // provides the size of the vector

        for (international_student &student : students_database) // looping through students_datbase
        {
            total += student.provide_score(); // every loop will add the score to total;
        }

        float average = (count > 0) ? total / count : 0; // calculating the average;

        cout << "Total score: " << total << "\n";
        cout << "Average score: " << average << "\n";

        cout << "----------------------------------\n";
        cout << "Difference between each student's score and the average:\n";

        for (international_student &student : students_database)
        // here using a foor loop to print the total and average and difference;
        {
            float difference = student.provide_score() - average;
            cout << "Student ID: " << student.provide_id() << " | Name: " << student.provide_name()
                 << " | Score Difference: " << difference << "\n";
        }
        cout << "----------------------------------\n";
    }
};

int main()
{
    student_administration admin; // creating an instance of student_administration

    welcome_user(); // calling the welcome_user() function first

    bool program_running = true; // program_running is a boolean type used in the while loop below

    while (program_running) // the program will keep running as long as the value is true
    {
        int user_choice = task_starter();
        // task_starter function provides multiple tasks options and returns
        //  the choice as an integer type which is used below in switch case

        switch (user_choice) // using switch case
        {
        case 1:
        {
            admin.show_all_students(); // prints all students

            break;
        }

        case 2:
        {
            // here program takes the student details to add a new student;
            // we are using the standar cin/cout here and calling the add_new_student method
            int student_id;
            string student_name;
            float student_score;

            cout << "enter student id : ";
            cin >> student_id;
            cout << "\n";
            cout << "enter student name : ";
            cin >> student_name;
            cout << "\n";
            cout << "enter student score : ";
            cin >> student_score;

            admin.add_new_student(student_id, student_name, student_score);
            break;
        }
        case 3:
        {
            // this case searches for individual student using id;

            int id;

            cout << "enter student id : ";
            cin >> id;

            admin.search_student(id); // search_student(id) is a student_administration class member function

            break;
        }
        case 4:
        { // here we are taking the id of the target student for updating the score;
            int id;
            float new_score;
            cout << "Enter student ID to update score: ";
            cin >> id;
            cout << "Enter new score: ";
            cin >> new_score;
            admin.update_student_score(id, new_score); // update_student_score() take id and new score, finds the student and updates the score.
            break;
        }

        case 5:
        {
            admin.sort_and_display_by_score(); // this function sorts and displays the students by score.
            break;
        }
        case 6:
        {
            admin.show_total_and_average_score(); // shows the total, average score and the difference of each student from the average.
            break;
        }

        case 0:
        {
            // if user provides 0 as an task option then it will end the switch case, set the programming_running to false
            // which closes the while loop;
            program_running = false;
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        default:
        {
            // if none of the optioned value is passed then it will automatcially break the switch and start again .
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        };
    }
    return 0;
}

void welcome_user() // this function welcomes the user;
{
    //
    cout << "-------------------------------------------------------------------------------------" << "\n";

    cout << "Welcome To Mingma's Student Information Management System" << "\n";

    cout << "Student Id: 202471178" << " \n";
    cout << "Assignment: 3" << "\n";

    cout << "-------------------------------------------------------------------------------------" << "\n";
}

int task_starter() // this function shows the tasks that can be completed with the task number, and returns that input which is used in the switch case above.
{

    int task_number;
    cout << "----------------------------------------" << "\n";

    cout << "What would you like to do today:" << "\n";
    cout << "(1) Show all students" << "\n";
    cout << "(2) Add new student" << "\n";
    cout << "(3) Find student details" << "\n";
    cout << "(4) Update student's score" << "\n";
    cout << "(5) Display student information based on score" << "\n";
    cout << "(6) Show difference between student's score and the average" << "\n";
    cout << "(0) Exit the program" << "\n";

    cout << " Please enter the task number : ";
    cin >> task_number;
    cout << "\n";
    return task_number;
}