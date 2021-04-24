//File Name: Source.cpp
//Author: Miranda Millington
//Email Address: mrmillington@my.milligan.edu
//Class Assignment for EENG221 Spring 2021
//Description: Program to organize college assignments by due date and significance to students grade.
//Last Changed: April 22nd, 2021


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
	using namespace std;


	//Class for student information
	class Student
	{
	public:
		string name;
		void nameoutput();
		//Preconditions: Reads name variable
		//Postconditions: Outputs sentence using name
		string getName();
		//accessor function for name variable
		string setName();
		//mutator function for name variable
	};

	//structure for course information
	struct Courses
	{
		int numofcourses = 0;
		string coursename[10];
		double hours[10] = { 0 };
		string grade[10];
		double totalcredithours = 10;
		const int maxcourses = 10;
	};

	//structure for assignment information
	struct Assignments
	{

	};

	void getCourseInfo(Courses& theCourse);
	//Precondition: Prompts user to enter course information
	//Postcondition: theCourse.numofcourses, theCourse.prefix, theCourse.coursenum, theCourse.hours, and theCourse.grade 
	//have been given values that the user entered at the keyboard

	double TotalHours(Courses& theCourse);

	string GradeConverter(Courses& theCourse);


	int main()
	{
		//Variable Declarations
		int i;

		//Begin main program
		Student firstname;
		cout << "Enter student's first name. \n";
		cin >> firstname.name;
		firstname.nameoutput();

		Courses course;
		getCourseInfo(course);

		

		ofstream outStream;

		outStream.open("outfile.csv");
		if (outStream.fail())
		{
			cout << "Out file opening failed. \n";
			exit(1);
		}

		outStream << firstname.name << "\n";
		outStream << course.numofcourses << " courses" << "\n";


		for(i=0; i < 10; i++)
		{
			outStream << course.coursename[i] << "," << course.hours[i] << "," << course.grade[i] << "\n";
		}

		TotalHours(course);
		//not getting the correct sum for total hours
			
		outStream << "Total Credit Hours = " << course.totalcredithours << "\n";

		GradeConverter(course);

		/*double gpa;
		gpa = 0;
		for (int i = 0; i < course.numofcourses; i++)
		{
			gpa += (course.grade[i]  course.hours[i]) / course.totalcredithours;
		}
		

		const double perfectgpa = 4.0;
		cout << "Your GPA on a " << perfectgpa << " point scale is " << gpa << "\n";
		*/

		return 0;
	}

		void Student::nameoutput()
		{
			cout << "Get Started on " << name << "'s Grade Saver Planner." << endl;
		}


		void getCourseInfo(Courses & theCourse)
		{
			cout << "Enter how many courses is taking this term. \n";
			Number:
			cin >> theCourse.numofcourses;
			if (theCourse.numofcourses <= theCourse.maxcourses)
				cout << theCourse.numofcourses << " courses \n";
			else
			{
				cout << "Maximum of ten courses may be entered. \n";
				goto Number;
			}

			int i;
			for (i = 0; i < theCourse.numofcourses; i++)
			{
				cout << "Begin entering course information for course " << i + 1 << ". \n";
				cout << "Course Prefix and Number (no spaces): \n";
				cin >> theCourse.coursename[i];
				cout << "Credit Hours: \n";
				cin >> theCourse.hours[i];
				cout << "Current letter grade: \n";
				cin >> theCourse.grade[i];
			}

		}

		string Student::getName()
		{
			return name;
		}

		string Student::setName()
		{
			name = name;
			return name;
		}

		double TotalHours(Courses& theCourse)
		{
			for (int k = 0; k < theCourse.numofcourses; k++)
			{
				theCourse.totalcredithours += theCourse.hours[k];
			}

			cout << "Total Hours: " << theCourse.totalcredithours << ".\n";
			return theCourse.totalcredithours;
		}

		/*
		string GradeConverter(Courses& theCourse)
		{
			int i;
			
			for (i = 0; i < theCourse.numofcourses; i++)
			{
				double a = 4.0;
				double b = 3.7;
				double c = 3.33;
				double d = 3.0;
				double e = 2.7;
				double f = 2.33;
				double g = 2.0;
				double h = 1.7;
				double l = 1.33;
				double m = 1.0;
				double n = 0.7;
				double o = 0.0;
				switch(grade)
				{
				case 'A':
				case 'a':
					theCourse.grade[i] = a;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << a << "\n";
					break;
				case 'A-':
				case 'a-':
					theCourse.grade[i] = b;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << b << "\n";
					break;
				case 'B+':
				case 'b+':
					theCourse.grade[i] = c;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'B':
				case 'b':
					theCourse.grade[i] = d;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'B-':
				case 'b-':
					theCourse.grade[i] = e;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'C+':
				case 'c+':
					theCourse.grade[i] = f;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'C':
				case 'c':
					theCourse.grade[i] = g;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'C-':
				case 'c-':
					theCourse.grade[i] = h;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'D+':
				case 'd+':
					theCourse.grade[i] = l;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'D':
				case 'd':
					theCourse.grade[i] = m;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'D-':
				case 'd-':
					theCourse.grade[i] = n;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				case 'F':
				case 'f':
					theCourse.grade[i] = o;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.grade[i] << "\n";
					break;
				default:
					cout << "That is not a possible grade. \n";
				}
			}
		}
		*/
