//File Name: Source.cpp
//Author: Miranda Millington
//Email Address: mrmillington@my.milligan.edu
//Class Assignment for EENG221 Spring 2021
//Description: Program to organize college assignments by due date and significance to students grade.
//Last Changed: March 11th, 2021


#include <iostream>
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

int main()
{
	int num; 
	num = 0;
	string name, plannername, coursecode[10];
	char course[10];
	char grade[10];
	char gradecat1[4];
	double catpercent[100];
	char gradeinfo[3][10];
	double gradevalue;
	double newgrade;
	gradevalue = 0;
	newgrade = 0;
	//can this array be indexed to the number of classes user inputs


	cout << "Enter your first name. \n";
	cin >> name;

	cout << "Get started on ";
	cout << name << "'s Grade Saver Planner" << endl;

	double credithours[10],totalcredithours = 0; 
	char ans;
	const int maxcourses = 10;
	cout << "Enter the number of courses you are taking this semester. (max of 10) \n";
	cin >> num; 
	cout << name << " is taking " << num << " courses this semester." << endl;

	if (num <= maxcourses) {

		for (int i = 0; i < num; i++)
		{
			cout << "Enter the course code for course " << i + 1 << " with no spaces. \n";
			cin >> coursecode[i];
			cout << "Enter the credit hours for course " << i + 1 << ". \n";
			cin >> credithours[i];
			cout << "Course " << i + 1 << ":" << coursecode[i] << endl;
			cout << "Course " << i + 1 << " Credit Hours:" << credithours[i] << endl;
		}

		totalcredithours = 0;
		for (int i = 0; i < num; i++) {
			totalcredithours += credithours[i];
		}
		// Totals the number of credit hours student is taking.

		cout << "Total credit hours: " << totalcredithours << "\n";
	}

	for (int i = 0; i < num; i++) 
	{

		cout << "Enter current letter grade in " << coursecode[i] << ".\n";
		cin >> grade[i];
		double gradevalue = gradenum(grade, coursecode, num);
		
	}

	double gpa;
	gpa = 0;
	for (int i = 0; i < num; i++) {
		credithours[i] = 0;
		gpa += (grade[i] * credithours[i]) / totalcredithours;
	}

		const double perfectgpa = 4.0;
		cout << "Your GPA on a " << perfectgpa << " point scale is " << gpa << "\n";

		int choice;
		
		do
		{
			cout << "Let's begin entering assignments for each course. \n";
			for (int i = 0; i < num; i++) {
			
			
				cout << "Choose " << i + 1 << " for " << coursecode[i] << "\n";
			}
			cout << "Enter your choice and press return: \n";
			cin >> choice;
			switch (choice)
			{
				double aweight[10], qweight[10], tweight[10], fweight[10];
				case 1:
					//code to start entering assignments for course[0]
					//% of category, 4 types, # of assignments in each category
					// make categories, % array, # of assign. array, grade [2,5] (2D array)
					// need some way to check that all the percents add up to 100
					
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[0];
					cout << "Quizzes: ";
					cin >> qweight[0];
					cout << "Tests: ";
					cin >> tweight[0];
					cout << "Final Exam: ";
					cin >> fweight[0];
					break;
				case 2:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[1];
					cout << "Quizzes: ";
					cin >> qweight[1];
					cout << "Tests: ";
					cin >> tweight[1];
					cout << "Final Exam: ";
					cin >> fweight[1];
					break;
				case 3:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[2];
					cout << "Quizzes: ";
					cin >> qweight[2];
					cout << "Tests: ";
					cin >> tweight[2];
					cout << "Final Exam: ";
					cin >> fweight[2];
					break;
				case 4:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[3];
					cout << "Quizzes: ";
					cin >> qweight[3];
					cout << "Tests: ";
					cin >> tweight[3];
					cout << "Final Exam: ";
					cin >> fweight[3];
					break;
				case 5:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[4];
					cout << "Quizzes: ";
					cin >> qweight[4];
					cout << "Tests: ";
					cin >> tweight[4];
					cout << "Final Exam: ";
					cin >> fweight[4];
					break;
				case 6:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[5];
					cout << "Quizzes: ";
					cin >> qweight[5];
					cout << "Tests: ";
					cin >> tweight[5];
					cout << "Final Exam: ";
					cin >> fweight[5];
					break;
				case 7:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[6];
					cout << "Quizzes: ";
					cin >> qweight[6];
					cout << "Tests: ";
					cin >> tweight[6];
					cout << "Final Exam: ";
					cin >> fweight[6];
					break;
				case 8:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[7];
					cout << "Quizzes: ";
					cin >> qweight[7];
					cout << "Tests: ";
					cin >> tweight[7];
					cout << "Final Exam: ";
					cin >> fweight[7];
					break;
				case 9:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[8];
					cout << "Quizzes: ";
					cin >> qweight[8];
					cout << "Tests: ";
					cin >> tweight[8];
					cout << "Final Exam: ";
					cin >> fweight[8];
					break;
				case 10:
					cout << "Enter the grade weight for assignments, quizzes, tests, and the final exam in percent form. Then press return. \n";
					cout << "Assignments: ";
					cin >> aweight[9];
					cout << "Quizzes: ";
					cin >> qweight[9];
					cout << "Tests: ";
					cin >> tweight[9];
					cout << "Final Exam: ";
					cin >> fweight[9];
					break;
				default:
					cout << "Not a valid choice. \n"
						<< "Choose again. \n";
			
			}
		} while (choice < num);

		// putting a predefined function here unrelated to my program. 
		// have not found a place where I need a predefined function yet
		
		int x;
		srand(22);
		x = rand();
		cout << x;

	
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
	double gradevalue;
	gradevalue = 0;
	for (int i = 0; i < num; i++)
	{
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
			grade[i] = 0.7;
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
	}
	//need to loop back up, while loop
	return gradevalue;
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