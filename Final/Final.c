/*
 Joshua Wood
 Final Project
 Dr. Boustique
 COP 3223
 04/27/2019
*/

/*                              Final Project
                               READ CAREFULLY!

  Learning Outcomes:
  1) Everything (up to and including structures)!

  It’s time to consider more than one student! The purpose of this project is to
  create a fee invoice application for students attending Valence Community College.
  The main menu for your application must have the following options.

  1- Add a new student
  2- Add/Delete a course for a student
  3- Search for a student
  4- Print fee invoice

  For every option, you must have a separate function. Feel free to add helper functions as needed.

  Additional Information
  It costs 120.25 dollars per credit hour in addition to $35.00 charged for health and id services.

  CRN           Course            Credit Hours
  4587          MAT 236           4
  4599          COP 220           3
  8997          GOL 124           1
  9696          COP 100           3
  1232          MAC 531           5
  9856          STA 100           2
  8520          TNV 400           5
  8977          CMP 100           1

  Note that we are considering the names of the students in this project.
  Furthermore, a student can take up to 4 courses this time!

  A fee invoice should look like:

  VALENCE COMMUNITY COLLEGE
  ORLANDO FL 10101
  ---------------------
  Fee Invoice Prepared for Student:
  5959-DANIEL TAZI

  1 Credit Hour = $120.25

  CRN     CR_PREFIX   CR_HOURS
  4599    COP 220            3      $ 360.75
  4587    MAT 236            4      $ 481.00

                     Health& id fees$  35.00
      --------------------------------------
                     Total Payments$  876.75
*/

    // Pre-processor directives

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    // Define the constants

#define CREDIT_COST 120.25
#define HEALTH_ID 35.00

    // Define the structure Courses.

struct Courses
{
    // Declare the member variables
    int id;
    int credit_Hrs;
    char name[50];
};

    //Define the structure student.

struct student
{
    // declare the member variables
    int id;
    char name[100];
    int totalCourses;
    // create an array of 4 Course objects
    struct Courses courseList[4];
};

    /*
     definition of the function displayMenu()
     prints the menu and reads the users option
     and returns the option value.
    */

int displayMenu()
{
    int option = 0;

    printf("Choose from the following options:\n");
    printf("\t1- Add a new student\n");
    printf("\t2- Add/Delete a Courses\n");
    printf("\t3- Search for a student\n");
    printf("\t4- Print fee invoice\n");
    printf("\t0- Exit program\n");
    printf("\nEnter your selection: ");
    scanf("%d", &option);
    return option;
}

    /*
     definition of the function courseCreation()
     takes the details of the course.
     return a Courses object
    */

struct Courses courseCreation(int id, char* name, int credit_Hrs)
{
    struct Courses course;
    /*
     assign the values to the
     members of the struct Courses
    */
    course.id = id;
    strcpy(course.name, name);
    course.credit_Hrs = credit_Hrs;
    return course;
}

    /*
     definition of the function printCourses()
     prints the details of a Course
    */

void printCourses(struct Courses c)

{
    printf("\t\t%d\t %s\t %d\n", c.id, c.name, c.credit_Hrs);
}

    /*
     definition of the function displayStudents()
     takes student object and prints the details of the student and the courses.
    */

void displayStudents(struct student s)
{
    int i = 0;
    printf("The details of the students are as follows:\n");
    printf("Name: %s\n", s.name);
    printf("\nCourses: \n");

    for (i = 0;i < s.totalCourses;i++)
    {
     // call the function printCourses() to print the courses
     printCourses(s.courseList[i]);
    }
}

    /*
     definition of the function displayStudents()
     takes student object and prints the details of the invoice
    */

void displayInvoice(struct student s)
{
    float totalHours = 0;
    float total = 0;
    printf("\n\tVALENCE COMMUNITY COLLEGE\n");
    printf("\tORLANDO FL 10101\n");
    printf("\t-------------------\n\n");
    printf("\tFee Invoice prepared for Student: \n");
    printf("\t%d-%s\n\n", s.id, s.name);
    printf("\t1 Credit hour = $ 120.25\n\n");
    printf("\tCRN\tCR_PREFIX\tCR_HOURS\n");

    for (int i = 0;i<s.totalCourses;i++)
    {
        totalHours =(float) s.courseList[i].credit_Hrs*(CREDIT_COST);
        // print the course details and total credit hours
        printf("\t%d\t %s\t %d\t $ %.2f\n", s.courseList[i].id, s.courseList[i].name, s.courseList[i].credit_Hrs, totalHours);
        total = total + totalHours;
    }

        printf("\n\t\tHealth & id fees\t $ 35.00\n");
        // calculate and print the total payment.
        total = total + HEALTH_ID;
        printf("\t---------------------------------------\n");
        printf("\t\tTotal Payments\t\t $ %.2f\n", total);
}

    /*
     definition of the function search_student()
     function takes array of student objects and its size
    */

void search_student(struct student s[], int size)
{
    int id, i, found = 0;
    // read the student id to search
    printf("Enter the id of the student: ");
    scanf("%d", &id);
    // search the student
    for (i = 0;i < size; i++)
    {
    // if the student is present,
    if (s[i].id == id)
    {
        // then print the details using displayStudents()
        displayStudents(s[i]);
        found = 1;
        break;
    }
}
    // if the student is not found print the message.
    if (found == 0)
    {
        printf("\nNo Student Found!\n");
    }
}
    /*
     definition of the function checkForNewInvoice()
     function takes array of student objects reads the users choice and displays the invoice.
    */

void checkForNewInvoice(struct student s)
{
    char ch = 'n';
    printf("\nWant to display the new invoice(Y/N): ");
    scanf("%c", &ch);

    if (ch == 'Y' || ch == 'y')
    {
        displayInvoice(s);
    }
}

    /*
    definition of the function add_del_course()
    this function takes array of student objects, array of Courses object and their sizes
    adds or deletes the courses of the student
    */

void add_del_course(struct student studentList[], int size_s, struct Courses course_list[], int size_c)
{
    int sid, k;
    int i = 0;
    printf("\nEnter the student's id: ");
    scanf("%d", &sid);
    // get the index value i of the student with the id
    for (i = 0;i<size_s;i++)
    {
        if (studentList[i].id == sid)
        {
            break;
        }
    }
    // print the courses of the student

    printf("\nHere are the courses [%s] is taking:", studentList[i].name);
    printf("\n\t\tCRN\tPREFIX\tCR. HOURS\n");

    for (k = 0; k<studentList[i].totalCourses;k++)
    {
        printCourses(studentList[i].courseList[k]);
    }

    int numOfCourses = studentList[i].totalCourses;
    char choice = 'C';

     // read the choice from the user
    scanf("%c", &choice);
    printf("\nChoose from:\n");
    printf("A. Add a new Courses for [%s] \n", studentList[i].name);
    printf("D. Delete a Courses from [%s]'s schedule\n", studentList[i].name);
    printf("C. Cancel operation\n");
    printf("\nEnter your selection: ");
    choice = getchar();
    // declare the variables
    int c_id,l = 0, j = 0;
    switch (choice)
    {
        // if the user want to add a course
        case 'A':
        case 'a':
        if (studentList[i].totalCourses < 4)
        {
            // read the course id
            printf("\nEnter the Courses id: ");
            scanf("%d", &c_id);

            for (l = 0; l<size_c; l++)
            {
                // if the course are present, then add the course to the course list of the student
                if (course_list[l].id == c_id)
                {
                    studentList[i].courseList[numOfCourses] = course_list[l];
                    studentList[i].totalCourses++;
                    break;
                }
            }
        /*
         check whether the user want to print a new invoice
         use the function checkForNewInvoice()
        */

        checkForNewInvoice(studentList[i]);
        }
        else
        {
            printf("\nNo more courses can be added.\n");
        }
        break;
        // if the user want to delete a course
        case 'D':
        case 'd':
        // read the course id
        printf("Enter Courses number to delete: ");
        scanf("%d", &c_id);
        getchar();
        // search for the course in the list
        for (l = 0;l<numOfCourses;l++)
        {
            // if present,
            if (studentList[i].courseList[l].id == c_id)
            {
                // print the deleted course id and name.
                printf("\n[%d %s] ", studentList[i].courseList[l].id, studentList[i].courseList[l].name);

                for (j = l;j<numOfCourses - 1;j++)
                {
                    studentList[i].courseList[j] = studentList[i].courseList[j + 1];
                }
                break;
            }
        }
        //decreament the count of the courses
        studentList[i].totalCourses--;
        printf("is deleted Sucessfully!\n\n");
        //check whether the user want to print a new invoice using the function checkForNewInvoice()
        checkForNewInvoice(studentList[i]);
        break;
        //cancel operation
        case 'C':
        case 'c':
        break;
        default:
        printf("\nInvalid choice.\n");
    }
}

    /*
     definition of the function addStudent()
     function takes array of student objects, array of Courses object and their sizes
     adds a student to the list.
    */
struct student addStudent(struct student studentList[], int size, struct Courses course_list[], int size_c)
{
    //create and allocate memory to a student object
    struct student* newStudent = (struct student*)malloc(sizeof(struct student));
    //declare the variables
    int i,found = 1;
    int no_courses = 0;
    char c;
    //read the student id.
    printf("\nEnter the student's id: ");
    scanf("%d", &newStudent->id);
    //Check if the student is already present in the list
    while (found == 1 && size != 0)
    {
        int j = 0;

        for (j = 0; j< size; j++)
        {
            if (studentList[j].id == newStudent->id)
            {
                printf("The id already exists.");
                printf("Enter the student's id: ");
                scanf("%d", &newStudent->id);
                found = 1;
                break;
            }
            found = 0;
        }
    }
    scanf("%c", &c);
    // read the student name
    printf("Enter student's name: ");
    c = getchar();
    i = 0;
    // assign the name to the student
    while (c != '\n')
    {
        newStudent->name[i] = c;
        c = getchar();
        i++;
    }
    newStudent->name[i] = '\0';
    //read number of courses the student want
    printf("\nEnter how many courses (%s) is taking (upto 4 courses)?\n\t", newStudent->name);
    scanf("%d", &no_courses);
    while (no_courses > 4 || no_courses < 0)
    {
        printf("\nPlease enter a valid number (0-4)\n\t");
        scanf("%d", &no_courses);
    }
    // assign the number of courses
    newStudent->totalCourses = no_courses;
    int wrongCourse = 0;
    int courseIds[4];

    while (wrongCourse == 0)
    {
        i = 0;
        printf("\nEnter the %d Courses numbers\n\t", no_courses);
        // read the course
        while (i < no_courses)
        {
            scanf("%d", &(courseIds[i]));
            i++;
        }
        int p;
        for (p = 0;p<no_courses;p++)
        {
            wrongCourse = 0;
            int q;
            // check the courses
            for (q = 0;q<size_c;q++)
            {
                // if the course is present, add the course to the list
                if (courseIds[p] == course_list[q].id)
                {
                    newStudent->courseList[p] = course_list[q];
                    wrongCourse = 1;
                    break;
                }
            }
            // if the course is not present.
            if (wrongCourse == 0)
            {
                printf("Wrong Courses CRN(s) entered.\n");
                break;
            }
        }
    }
    return *newStudent;
}

// definition of the main() function.

int main()
{
    // create the object arrays of the structures Courses and student

    struct Courses c_List[8];

    struct student students[100];

    int numOfStudents = 0;

    int id;

    // create 8 course using the courseCreation() function

    c_List[0] = courseCreation(4587, "MAT 236", 4);

    c_List[1] = courseCreation(4599, "COP 220", 3);

    c_List[2] = courseCreation(8997, "GOL 124", 1);

    c_List[3] = courseCreation(9696, "COP 100", 3);

    c_List[4] = courseCreation(1232, "MAC 531", 5);

    c_List[5] = courseCreation(9856, "STA 100", 2);

    c_List[6] = courseCreation(8520, "TNV 400", 5);

    c_List[7] = courseCreation(8977, "CMP 100", 1);

    int i = 0;

    // print the menu using the displayMenu() function

    printf("Welcome!\n");

    int choice = displayMenu();

    while (choice != 0)
    {
        switch (choice)
        {
            case 0:
            break;
            // add the student using addStudent() function
            case 1:
            students[numOfStudents] = addStudent(students, numOfStudents, c_List, 7);
            numOfStudents++;
            printf("\nStudent added successfully!\n");
            break;
            // add or deleted the course using add_del_course() function
            case 2:
            add_del_course(students, numOfStudents, c_List, 7);
            break;
            case 3:
            // add the search using search_student() function
            search_student(students, numOfStudents);
            break;
            case 4:
            // print the fee invoice of the student using the function displayInvoice()
            printf("Enter the id of the student: ");
            scanf("%d", &id);

            for (i = 0;i<numOfStudents;i++)
            {
                if (id == students[i].id)
                {
                    displayInvoice(students[i]);
                }
            }
            break;
            default:
            printf("\nPlease enter a valid choice.\n");
        }
            printf("\n--------------------\n\n");
            choice = displayMenu();
    }
    printf("\nGoodbye!\n");
    return 0;
}
