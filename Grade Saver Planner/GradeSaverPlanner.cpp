//File Name: GradeSaverPlanner.cpp
//Author: Miranda Millington
//Email Address: mrmillington@my.milligan.edu
//Class Assignment for EENG221 Spring 2021
//Description: Program to organize college assignments by due date and significance to students grade.
//Last Changed: April 29th, 2021


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
	using namespace std;


	//Class for student information
	class Student
	{
	public:
		string getName();
		//accessor function for name variable
		string setName(string name);
		//mutator function for name variable
		string name;
	};

	class FullName : public Student
	{
		public:
			string lastname;
			string getLast();
			//accessor function for lastname variable
			string setLast(string theLast);
			//mutator function for lastname variable
			string Full(string theName, string theLast);
			//Preconditions: Uses first name and last name variable to create full name of student
			//Postconditions: Outputs sentence using student's full name
	private:
		string fullname;
	};

	//structure for course information
	struct Courses
	{
		int numofcourses = 0;
		string coursename[10];
		typedef string* StrPtr;
		StrPtr c;
		double hours[10] = { 0 };
		char grade[10] = { 'z' };
		string gradenum[10];
		double totalcredithours = 0;
		const int maxcourses = 10;
	};

	//structure for assignment information
	struct Assignments
	{
		//begin entering code for assignments
	};

	void getCourseInfo(Courses& theCourse);
	//Precondition: Prompts user to enter course information
	//Postcondition: theCourse.numofcourses, theCourse.prefix, theCourse.coursenum, theCourse.hours, and theCourse.grade 
	//have been given values that the user entered at the keyboard

	double TotalHours(Courses& theCourse);
	//Precondition: Adds the hours for each course together
	//Postcondition: Stores the total credit hours student is taking

	string GradeConverter(Courses& theCourse);
	//Precondition: Converts letter grade to numerical value
	//Postcondition: Stores grade array as numerical value



	int main()
	{
		//Variable Declarations
		int i;
		
		//Begin main program

		ifstream inStream;
		inStream.open("infile.txt");
		//Opens text file containing program name 

		if (inStream.fail())
		{
			cout << "Input file opening failed. \n";
			exit(1);
		}

		else
		{
			string word;
			while (inStream >> word)
			{
				cout << word << " ";
			}
			cout << "\n";
		}

		Student firstname;
		string theName;
		firstname.setName(theName);

		FullName full;
		string theLast;
		full.setLast(theLast);
		
		full.Full(theName, theLast);
		cout << "Get Started on " << firstname.name << "'s Grade Saver Planner." << endl;

		Courses course;
		getCourseInfo(course);

		course.c = course.coursename;


		ofstream outStream;

		outStream.open("outfile.csv");
		if (outStream.fail())
		{
			cout << "Out file opening failed. \n";
			exit(1);
		}

		
		outStream << firstname.getName() << "\n";
		outStream << course.numofcourses << " courses" << "\n";


		for(i=0; i < course.numofcourses; i++)
		{
			outStream << course.c[i] << "," << course.hours[i] << "," << course.grade[i] << "\n";
		}

		TotalHours(course);
			
		outStream << "Total Credit Hours = " << course.totalcredithours << "\n";

		GradeConverter(course);

		int h = 0;
		double gpa1 = 0;
		double gpa = 0;

		while (h < course.numofcourses);
		{
			gpa1 =+ (course.grade[h] * course.hours[h]);
			h++;
			gpa = gpa1 / course.totalcredithours;
		} 

		const double perfectgpa = 4.0;
		cout << "Your GPA on a " << perfectgpa << " point scale is " << gpa << "\n";
		
		//Not getting correct gpa
		
		outStream.close();

		return 0;
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

		string Student::setName(string theName)
		{
			cout << "Enter student's first name. \n";
			cin >> name;
			return name;
		}

		string FullName::getLast()
		{
			return lastname;
		}

		string FullName::setLast(string theLast)
		{
			cout << "Enter student's last name. \n";
			string lastname;
			cin >> lastname;
			return lastname;
		}

		string FullName::Full(string theName, string theLast)
		{
			fullname = name + lastname;
			cout << "Student's Name: " << fullname << "\n";
			return fullname;
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
				switch(theCourse.grade[i])
				{
				case 'A':
				case 'a':
					theCourse.gradenum[i] = 4.0;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 4.0 << "\n";
					break;
				case 'A-':
				case 'a-':
					theCourse.gradenum[i] = b;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 3.7 << "\n";
					break;
				case 'B+':
				case 'b+':
					theCourse.gradenum[i] = c;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 3.33 << "\n";
					break;
				case 'B':
				case 'b':
					theCourse.gradenum[i] = d;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 3.0 << "\n";
					break;
				case 'B-':
				case 'b-':
					theCourse.gradenum[i] = e;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 2.7 << "\n";
					break;
				case 'C+':
				case 'c+':
					theCourse.gradenum[i] = f;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 2.33 << "\n";
					break;
				case 'C':
				case 'c':
					theCourse.gradenum[i] = g;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 2.0 << "\n";
					break;
				case 'C-':
				case 'c-':
					theCourse.gradenum[i] = h;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 1.7 << "\n";
					break;
				case 'D+':
				case 'd+':
					theCourse.gradenum[i] = l;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << 1.33 << "\n";
					break;
				case 'D':
				case 'd':
					theCourse.gradenum[i] = m;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.gradenum[i] << "\n";
					break;
				case 'D-':
				case 'd-':
					theCourse.gradenum[i] = n;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.gradenum[i] << "\n";
					break;
				case 'F':
				case 'f':
					theCourse.gradenum[i] = o;
					cout << " Current grade in " << theCourse.coursename[i] << ": " << theCourse.gradenum[i] << "\n";
					break;
				default:
					cout << "That is not a possible grade. \n";
				}
				return theCourse.gradenum[i];
			}
		}
		
		
