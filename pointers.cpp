// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <stdio.h>


typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    //ID
    /*student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    //FIRST LAST NAME
    student.f_name = new char[128];
    student.l_name = new char[128];
    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name, 128);
    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name, 128);
    */
    //NUM ASSIGNMENTS
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);

    //GRADES
    student.grades = new double[student.n_assignments];
    std::string temp = "Please enter grade for assignment ";
    for (int i=0; i<student.n_assignments; i++){
        temp += std::to_string(i);
        temp += ": ";
        student.grades[i] = promptDouble(temp, 0.0, 1000.0);
        temp = "Please enter grade for assignment ";
    }

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(student.grades, &average);
    // Output `average`
    std::cout << average << std::endl;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    char *charStr = new char[9];
    int complete = -1;
    int invalid = 0;
    int result;
    while (complete != 1){
        std::cout << message;
        std::cin.getline(charStr, 9);
        std::string str(charStr);

        //check for non numeric digits
        for (int i=0; i<str.length(); i++){
            if (!isdigit(charStr[i])){
                invalid = 1;
            }
        }
        
        ///casting str to integer and check for min max
        result = atoi(charStr);
        //std::cout << result;
        if (invalid || result < min || result > max) {
            std::cout << "Sorry, I cannot understand your answer\n";
            invalid = 0;
        }else {
            complete = 1;
        }
    }
    
    return result;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    char *charStr = new char[10];
    int complete = -1;
    int invalid = 0;
    double result;
    while (complete != 1){
        std::cout << message;
        std::cin.getline(charStr, 10);
        std::string str(charStr);

        for (int i=0; i<str.length(); i++) {
            if (!isdigit(charStr[i]) && charStr[i] != '.'){
                invalid = 1;
                //std::cout << "fails on: " << charStr[i] << "\n";
            }
        }

        sscanf(charStr, "%lf", &result);

        if (invalid == 1 || result < min || result > max) {
            std::cout << "Sorry, I cannot understand your answer\n";
            invalid = 0;
        }else {
            complete = 1;
        }
    }

    
    return result;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    
}
