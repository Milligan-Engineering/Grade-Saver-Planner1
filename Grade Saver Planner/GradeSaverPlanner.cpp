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
		int numofcourses;
		string coursename[10];
		double hours[10];
		char grade[10];
		double totalcredithours;
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


	int main()
	{
		//Variable Declarations
		double totalcredithours;

		//Begin main program
		Student firstname;
		cout << "Enter student's first name. \n";
		cin >> firstname.name;
		firstname.nameoutput();

		Courses course;
		getCourseInfo(course);

		int i;
		for(i=0; i < 10; i++)
		{
			if (course.grade[i] == (('a' || 'A' || 'a-' || 'A-' || 'b+' || 'B+' || 'b' || 'B' || 'b-' || 'B-' || 'c+' || 'C+' || 'c' || 'C' || 'c-' || 'C-' || 'd+' || 'D+' || 'd' || 'D' || 'd-' || 'D+' || 'f' || 'F')))
			{
				switch (course.grade[i])
				{
				case 'A':
				case 'a':
					course.grade[i] = 4.0;
					cout << " Current grade in " << course.coursename[i] << ": 4.0\n";
					break;
				case 'A-':
				case 'a-':
					course.grade[i] = 3.7;
					cout << " Current grade in " << course.coursename[i] << ": 3.7\n";
					break;
				case 'B+':
				case 'b+':
					course.grade[i] = 3.33;
					cout << " Current grade in " << course.coursename[i] << ": 3.33\n";
					break;
				case 'B':
				case 'b':
					course.grade[i] = 3.0;
					cout << " Current grade in " << course.coursename[i] << ": 3.0\n";
					break;
				case 'B-':
				case 'b-':
					course.grade[i] = 2.7;
					cout << " Current grade in " << course.coursename[i] << ": 2.7\n";
					break;
				case 'C+':
				case 'c+':
					course.grade[i] = 2.33;
					cout << " Current grade in " << course.coursename[i] << ": 2.33\n";
					break;
				case 'C':
				case 'c':
					course.grade[i] = 2.0;
					cout << " Current grade in " << course.coursename[i] << ": 2.0\n";
					break;
				case 'C-':
				case 'c-':
					course.grade[i] = 1.7;
					cout << " Current grade in " << course.coursename[i] << ": 1.7\n";
					break;
				case 'D+':
				case 'd+':
					course.grade[i] = 1.33;
					cout << " Current grade in " << course.coursename[i] << ": 1.33\n";
					break;
				case 'D':
				case 'd':
					course.grade[i] = 1.0;
					cout << " Current grade in " << course.coursename[i] << ": 1.0\n";
					break;
				case 'D-':
				case 'd-':
					course.grade[i] = 0.7;
					cout << " Current grade in " << course.coursename[i] << ": 0.7\n";
					break;
				case 'F':
				case 'f':
					course.grade[i] = 0.0;
					cout << " Current grade in " << course.coursename[i] << ": 0.0\n";
				}
			}
			else
			{
				cout << "That is not a possible grade. \n";
			}
			//printing the default every time
			
			
		}
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
			

		return 0;
	}

		void Student::nameoutput()
		{
			cout << "Get Started on " << name << "'s Grade Saver Planner." << endl;
		}


		void getCourseInfo(Courses & theCourse)
		{
			cout << "Enter how many courses is taking this term. \n";
			cin >> theCourse.numofcourses;
			cout << theCourse.numofcourses << " courses \n";

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
			int k;
			for (int k = 0; k < theCourse.numofcourses; k++)
			{
				theCourse.totalcredithours+=theCourse.hours[k];
			}

			cout << "Total Hours: " << theCourse.totalcredithours << ".\n";
			return theCourse.totalcredithours;
		}