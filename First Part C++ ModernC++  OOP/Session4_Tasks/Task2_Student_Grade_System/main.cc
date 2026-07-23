/**
 * @file main.cpp
 * @brief Implementation of a simple Student Grade Calculator.
 *
 * This program allows the user to:
 * - Enter a student's name.
 * - Input marks for Mathematics, Physics, and English.
 * - Calculate the student's average.
 * - Determine the corresponding letter grade.
 * - Display a formatted student report.
 * - Update marks or recalculate the average through a bonus menu.
 *
 * The program validates all numeric input and terminates after
 * three consecutive invalid attempts.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */


#include "main.hh"

int main()
{
    std::string name;
    int math, physics, english, choice;
    double average = 0;
    char grade = 0;
    int attempts = 0;

    std::cout<<"Student Number: ";
    std::getline(std::cin,name);
    inputMarks(&math, &physics, &english);
    printReport(name,&math, &physics, &english);

    std::cout<<"\n================== Bonus Menu ====================\n";
    std::cout<<"1.Update a Mark.\n";
    std::cout<<"2.Recalculate the average.\n";
    std::cout<<"3.Print the report again\n";

    do
    {
        if(!(std::cin>>choice))
        {
            clearError();
            attempts++;
            if(attempts == 3)
                return 0;
        }
    } while((choice<=0) || (choice > 3));

    switch (choice)
    {
        case 1: 
            inputMarks(&math, &physics, &english);
            printReport(name,&math, &physics, &english);
            break;
        case 2: 
           average = calculateAverage(&math, &physics, &english); 
           std::cout<<"New Average: "<<average<<std::endl;
           break;
        case 3:
            printReport(name,&math, &physics, &english);
            break;
        default:
            break;
    }
    
    return(0);
}

void clearError()
{
    std::cout<<"Invalid Input!.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void inputMarks(int *math, int *physics, int *english)
{
    int attempts = 0;

    std::cout<<"Math: ";
    do{
        if(!(std::cin>>*math))
        {
            clearError();
        }
        attempts++;
        if(attempts == 3)
            exit(0);
    }while((*math <0) || (*math > 100));

    attempts=0;
    std::cout<<"Physics: ";
    do{
        if(!(std::cin>>*physics))
        {
            clearError();
        }
        attempts++;
        if(attempts == 3)
            exit(0);
    }while((*physics <0) || (*physics > 100));

    attempts=0;
    std::cout<<"English: ";
    do{
        if(!(std::cin>>*english))
        {
            clearError();
        }
        attempts++;
        if(attempts == 3)
            exit(0);
    }while((*english <0) || (*english > 100));
}

double calculateAverage(int *math, int *physics, int *english)
{
    int total = (*math + *physics + *english);
    double avarage = (total / 3.0);
    return avarage;
}

char calculateGrade(double average)
{
    char grade = 0;
    if(average >= 90.0)
    {
        grade = 'A';
    }
    else if (average >= 80.0)
    {
        grade = 'B';
    }
    else if (average >= 70.0)
    {
        grade = 'C';
    }
    else if (average >= 60.0)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    return(grade);
}

void printReport(std::string name, int *math, int *physics, int *english)
{
    double average = 0;
    char grade;
    
    average = calculateAverage(math, physics, english); 
    grade = calculateGrade(average);

    std::cout<<"\n=============================================================\n";
    std::cout<<"\nStudent Name: "<<name<<std::endl;
    std::cout <<"Average: "<<average<<std::endl;
    std::cout<<"Grade: "<<grade<<std::endl;
}