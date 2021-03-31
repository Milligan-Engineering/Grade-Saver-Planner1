//File Name: Source.cpp
//Author: Miranda Millington
//Email Address: mrmillington@my.milligan.edu
//Class Assignment for EENG221 Spring 2021
//Description: Program to organize college assignments by due date and significance to students grade.
//Last Changed: March 23rd, 2021


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
double gpacalc(const double grade[], const double credithours[], double totalcredithours, int num);
//Preconditions: Grade of each class is multiplied by credit hours of the class then divided by total credit hours
//Postconditions: Calculates students GPA
double gradenum(char grade[], string coursecode[], int num);
//Preconditions: Converts character grade to equivalent numerical grade
//Postconditions: returns the numerical grade of each class
double currentgrade(string gradeinfo[], double aweight[], double qweight[], double tweight[], double fweight[], int num);
//Preconditions: Multiplies the grade for each assignment by its grade weight for every class
//Postconditions: Returns the updated grade of student
void listprint(string course[10], int num, const int maxcourses);
//Preconditions: reads input of course codes
//Postconditions: Prints out courses
void listprint(string course[10], int num, string assignment[10][10], int numofassign);
//Precondition: reads input of assignments for each course
//Postconditions: Displays the assignments for each class

/*Class for ......
class Example
{
public:
	Example(x,y,z)
	Example(a,b)
*/

// Course course[max]  course[2].prefix
			
//Structure for displaying courses and their credithours
struct Course
{
	char prefix;
	string coursenum;
	string hours;
	string coursecode;
	int num;
};

int main()
{
	int num;
	num = 0;
	string name, plannername, courseprefix[10], coursecode[10], coursenum[10];
	string prefix, coursenum, course, credithours;
	double aweight[10], qweight[10], tweight[10], fweight[10];
	char course[10];
	char grade[10];
	char gradecat1[4];
	double catpercent[100];
	char gradeinfo[3][10];
	double gradevalue[10];
	double newgrade;
	newgrade = 0;
	//can this array be indexed to the number of classes user inputs


	cout << "Enter your first name. \n";
	cin >> name;

	cout << "Get started on ";
	cout << name << "'s Grade Saver Planner" << endl;

	double credithours[10], totalcredithours = 0;
	char ans;
	const int maxcourses = 10;
	cout << "Enter the number of courses you are taking this semester. (max of 10) \n";
	cin >> num;
	cout << name << " is taking " << num << " courses this semester." << endl;

	ofstream outStream;

	outStream.open("outfile.csv");
	if (outStream.fail())
	{
		cout << "Outout file opening failed. \n";
		exit(1);
	}

	outStream << name << "," << num << " courses" << "\n";

	Course course[10];
	int i;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the course prefix for course " << i + 1 << " with no spaces. \n";
		cin >> course[i].prefix;
		cout << "Enter the course number for course " << i + 1 << " with no spaces. \n";
		cin >> course[i].coursenum;
		cout << "Enter the credit hours for course " << i + 1 << ". \n";
		cin >> course[i].hours;
		cout << "Course " << i + 1 << ":" << course[i].prefix + course[i].num << endl;
	}

	if (num <= maxcourses) {

		for (int i = 0; i < num; i++)
		{
			
			cout << "Enter the course prefix for course " << i + 1 << " with no spaces. \n";
			cin >> courseprefix[i];
			cout << "Enter the course number for course " << i + 1 << " with no spaces. \n";
			cin >> coursenum[i];
			cout << "Enter the credit hours for course " << i + 1 << ". \n";
			cin >> credithours[i];
			cout << "Course " << i + 1 << ":" << courseprefix[i] << coursenum[i] << endl;
			cout << "Course " << i + 1 << " Credit Hours:" << credithours[i] << endl;
		}

		

		

		for (int i = 0; i < num; i++)
		{
			coursecode[i] = courseprefix[i] + coursenum[i];
			cout << "Enter current letter grade in " << coursecode[i] << ".\n";
			cin >> grade[i];
			gradenum(grade, coursecode, num);
			cout << grade[i];
			//Issue where it says input isnt a possible grade every time
			outStream << courseprefix[i] << "," << coursenum[i] << "," << credithours[i] << "," << gradevalue[i] << "\n";
			//trying the get the gradevalue to be out streamed but wont display correct conversion
		}

		totalcredithours = 0;
		for (int i = 0; i < num; i++)
		{
			totalcredithours += credithours[i];
		}
		// Totals the number of credit hours student is taking.

		cout << "Total credit hours: " << totalcredithours << "\n";
		outStream << "Total Credit Hours = " << totalcredithours << "\n";
	}


	double gpa;
	gpa = 0;
	for (int i = 0; i < num; i++)
	{
		credithours[i] = 0;
		gpa +=  (grade[i]* credithours[i]) / totalcredithours;
		//grade[i] isn't working anymore, stuck at 0 and not converting to a number
	}

	const double perfectgpa = 4.0;
	cout << "Your GPA on a " << perfectgpa << " point scale is " << gpa << "\n";
	
	int choice;
	{
		do
		{
			cout << "Let's begin entering assignments for each course. \n";
			for (int i = 0; i < num; i++)
			{


				cout << "Choose " << i + 1 << " for " << coursecode[i] << "\n";
			}
			cout << "Enter your choice and press return: \n";
			cin >> choice;
			switch (choice)
				choice = 0;
			
			cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
			cout << "Assignments: ";
			cin >> aweight[choice];
			cout << "Quizzes: ";
			cin >> qweight[choice];
			cout << "Tests: ";
			cin >> tweight[choice];
			cout << "Final Exam: ";
			cin >> fweight[choice];

		} while (choice < num);

		for (int choice = 0; choice < num; choice++);
		{
			outStream << aweight[choice] << "," << qweight[choice] << "," << tweight[choice] << "," << fweight[choice] << "\n";
		}
	} 

	
		return 0;
}


double gpacalc(double grade[], double credithours[], double totalcredithours, int num)
{
	double gpa;
	gpa = 0;
	for (int i = 0; i < num; i++)
	{
		gpa = +(grade[i] * credithours[i]);
	}
	return (gpa / totalcredithours);
}

double gradenum(char grade[], string coursecode[], int num)
{
	double gradevalue[10];
	
	for (int i = 0; i < num; i++)
	{
		gradevalue[i] = 0;
		switch (grade[i])
		{
		case 'A':
		case 'a':
			grade[i] = 4.0;
			cout << " Current grade in " << coursecode[i] << ": 4.0\n";
			break;
		case 'A-':
		case 'a-':
			grade[i] = 3.7;
			cout << " Current grade in " << coursecode[i] << ": 3.7\n";
			break;
		case 'B+':
		case 'b+':
			grade[i] = 3.33;
			cout << " Current grade in " << coursecode[i] << ": 3.33\n";
			break;
		case 'B':
		case 'b':
			grade[i] = 3.0;
			cout << " Current grade in " << coursecode[i] << ": 3.0\n";
			break;
		case 'B-':
		case 'b-':
			grade[i] = 2.7;
			cout << " Current grade in " << coursecode[i] << ": 2.7\n";
			break;
		case 'C+':
		case 'c+':
			grade[i] = 2.33;
			cout << " Current grade in " << coursecode[i] << ": 2.33\n";
			break;
		case 'C':
		case 'c':
			grade[i] = 2.0;
			cout << " Current grade in " << coursecode[i] << ": 2.0\n";
			break;
		case 'C-':
		case 'c-':
			grade[i] = 1.7;
			cout << " Current grade in " << coursecode[i] << ": 1.7\n";
			break;
		case 'D+':
		case 'd+':
			grade[i] = 1.33;
			cout << " Current grade in " << coursecode[i] << ": 1.33\n";
			break;
		case 'D':
		case 'd':
			grade[i] = 1.0;
			cout << " Current grade in " << coursecode[i] << ": 1.0\n";
			break;
		case 'D-':
		case 'd-':
			gradevalue[i] = 0.7;
			cout << " Current grade in " << coursecode[i] << ": 0.7\n";
			break;
		case 'F':
		case 'f':
			grade[i] = 0.0;
			cout << " Current grade in " << coursecode[i] << ": 0.0\n";
			break;
		default:
			cout << "That is not a possible grade. \n";
		}
		return gradevalue[i];
	}
}

double currentgrade(string gradeinfo[], double aweight[], double qweight[], double tweight[], double fweight[], int num)
{
	double newgrade;
	newgrade = 0;
	for (int i = 0; i < num; i++)
	//Function to compute the grade in a class including all assignments, tests, etc
	return newgrade;
}

void listprint(string course[10], int num)
//once this works I can implement it in the program
{
		for (int i = 0; i < num; i++)
		{
			cout << "Enter the course code for course " << i + 1 << " with no spaces. \n";
			cin >> course[i];
			cout << "Course " << i + 1 << ":" << course[i] << endl;
			
		}

	for (int i = 0; i < num; i++)
	{
		cout << course[i] << "\n";
	}
}

void listprint(string course[10], int num, string assignment[10][10], int numofassign)
{
	for (int i = 0; i < num; i++)
	{

		cout << "How many assignments are you entering for " << course[i] << "? (max of 10) \n";
		cin >> numofassign;
		cout << "Enter all assignments for " << course[i] << ". \n";
		cout << "Enter assignments one at a time. \n";
		for (int j = 0; j < numofassign; j++)
		{
			cin >> assignment[j][i];
			cout << "These are all the assignments for " << course[i] << ". \n";
			cout << assignment[j][i];
		}
		//still working on this to make it just a print function and have the info entered in main
		
	}
	
}