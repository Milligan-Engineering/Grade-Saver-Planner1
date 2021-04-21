//File Name: Source.cpp
//Author: Miranda Millington
//Email Address: mrmillington@my.milligan.edu
//Class Assignment for EENG221 Spring 2021
//Description: Program to organize college assignments by due date and significance to students grade.
//Last Changed: April 18th, 2021


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
	using namespace std;

	int numofcourses = 0;

	//Class for student information
	class Student
	{
	public:
		string name;
		void nameoutput();
	};

	struct Courses
	{
		int numofcourses;
		string prefix[10];
		string coursenum[10];
		double hours[10];
		char grade[10];

	};

	struct Assignments
	{

	};

	void getCourseInfo(Courses& theCourse);
	//Postcondition: theCourse.numofcourses, theCourse.prefix, theCourse.coursenum, theCourse.hours, and theCourse.grade 
	//have been given values that the user entered at the keyboard

	int main()
	{
		Student firstname;
		cout << "Enter student's first name. \n";
		cin >> firstname.name;
		firstname.nameoutput();

		Courses course;
		getCourseInfo(course);

		return 0;
	}

	void Student::nameoutput()
	{
		cout << "Get Started on " << name << "'s Grade Saver Planner." << endl;
	}


	void getCourseInfo(Courses& theCourse)
	{
		cout << "Enter how many courses is taking this term. \n";
		cin >> theCourse.numofcourses;
		cout << theCourse.numofcourses << " courses \n";

		int i;
		for (i = 0; i < theCourse.numofcourses; i++)
		{
			cout << "Begin entering course information for course " << i + 1 << ". \n";
			cout << "Course Prefix: \n";
			cin >> theCourse.prefix[i];
			cout << "Course Number: \n";
			cin >> theCourse.coursenum[i];
			cout << "Credit Hours: \n";
			cin >> theCourse.hours[i];
			cout << "Current letter grade: \n";
			cin >> theCourse.grade[i];
		}

	}
	/*
	//page 393 passing arrays as functions
			//page 428 using 2D array in function
	strcpy(coursename[i], prefix);
	strcat(coursename[i], coursenumber);
	cout << "Course Name: " << coursename[i] << endl;
	*/