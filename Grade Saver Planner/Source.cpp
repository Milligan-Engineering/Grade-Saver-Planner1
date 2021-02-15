//FIle Name: Source.cpp
//Author: Miranda Millington
//Email Address: mrmillington@my.milligan.edu
//Class Assignment for EENG221 Spring 2021
//Description: Program to organize college assignments by due date and significance to students grade.
//Last Changed: February 11th, 2021


#include <iostream>
using namespace std;
int main()
{
	string name, plannername, coursecode1, coursecode2, coursecode3;

	cout << "Enter your first name. \n";
	cin >> name;

	cout << "Get started on ";
	cout << name << "'s Grade Saver Planner" << endl;

	double credithours1 = 0, credithours2 = 0, credithours3 = 0, totalcredithours = 0; 
	char ans;

		cout << "Enter the course code for first course with no spaces. \n";
		cin >> coursecode1;
		cout << "Enter the credit hours for this course. \n";
		cin >> credithours1;
		cout << "Course 1:" << coursecode1 << endl;
		cout << "Course 1 Credit Hours:" << credithours1 << endl;
		
		cout << "Add another course? \n"
			<< "Press y for yes, n for no,\n";
		cin >> ans;

		if (ans == 'y' || ans == 'Y') {

			cout << "Enter the course code for your second class with no spaces. \n";
			cin >> coursecode2;
			cout << "Enter the credit hours for this course. \n";
			cin >> credithours2;
			cout << "Course 2:" << coursecode2 << endl;
			cout << "Course 2 Credit Hours:" << credithours2 << endl;
		}

		
		cout << "Add another course? \n"
			<< "Press y for yes, n for no,\n"
			<< "and then press return:";
		cin >> ans;

		if (ans == 'y' || ans == 'Y') {

			cout << "Enter the course code for your third class with no spaces. \n";
			cin >> coursecode3;
			cout << "Enter the credit hours for this course. \n";
			cin >> credithours3;
			cout << "Course 3:" << coursecode3 << endl;
			cout << "Course 3 Credit Hours:" << credithours3 << endl;
		}

		
		totalcredithours = credithours1 + credithours2 + credithours3;
		// Totals the number of credit hours student is taking.
		
		cout << "Total credit hours: " << totalcredithours;
 

		char grade1, grade2, grade3;
		double pv1 = 0, pv2, pv3, gpa;

	
		cout << "Enter current letter grade in " << coursecode1 << ".\n";
		cin >> grade1;
		
		if ((grade1 == 'A') || (grade1 == 'a'))
			pv1 = 4.0;
		else if ((grade1 == 'A-') || (grade1 =='a-'))
			pv1 = 3.7;
		else if ((grade1 == 'B+') || (grade1 == 'b+'))
			pv1 = 3.33; 
		else if ((grade1 == 'B') || (grade1 == 'b'))
			pv1 = 3.0;
		else if ((grade1 == 'B-') || (grade1 =='b-'))
			pv1 = 2.7;
		else if ((grade1 == 'C+') || (grade1 =='c+'))
			pv1 = 2.33;
		else if ((grade1 == 'C') || (grade1 =='c'))
			pv1 = 2.0;
		else if ((grade1 == 'C-') || (grade1 =='c-'))
			pv1 = 1.7;
		else if ((grade1 == 'D+') || (grade1 =='d+'))
			pv1 = 1.3;
		else if ((grade1 == 'D') || (grade1 == 'd'))
			pv1 = 1.0;
		else if ((grade1 == 'D-') || (grade1 == 'd-'))
			pv1 = 0.7;
		else if ((grade1 == 'F') || (grade1 == 'f'))
			pv1 = 0.0;

		cout << "Enter current letter grade in " << coursecode2 << ".\n";
		cin >> grade2;

		if ((grade2 == 'A') || (grade2 == 'a'))
			pv2 = 4.0;
		else if ((grade2 == 'A-') || (grade2 == 'a-'))
			pv2 = 3.7;
		else if ((grade2 == 'B+') || (grade2 == 'b+'))
			pv2 = 3.33;
		else if ((grade2 == 'B') || (grade2 == 'b'))
			pv2 = 3.0;
		else if ((grade2 == 'B-') || (grade2 == 'b-'))
			pv2 = 2.7;
		else if ((grade2 == 'C+') || (grade2 == 'c+'))
			pv2 = 2.33;
		else if ((grade2 == 'C') || (grade2 == 'c'))
			pv2 = 2.0;
		else if ((grade2 == 'C-') || (grade2 == 'c-'))
			pv2 = 1.7;
		else if ((grade2 == 'D+') || (grade2 == 'd+'))
			pv2 = 1.3;
		else if ((grade2 == 'D') || (grade2 == 'd'))
			pv2 = 1.0;
		else if ((grade2 == 'D-') || (grade2 == 'd-'))
			pv2 = 0.7;
		else if ((grade2 == 'F') || (grade2 == 'f'))
			pv2 = 0.0;

		cout << "Enter current letter grade in " << coursecode3 << ".\n";
		cin >> grade3;

		if ((grade3 == 'A') || (grade3 == 'a'))
			pv3 = 4.0;
		else if ((grade3 == 'A-') || (grade3 == 'a-'))
			pv3 = 3.7;
		else if ((grade3 == 'B+') || (grade3 == 'b+'))
			pv3 = 3.33;
		else if ((grade3 == 'B') || (grade3 == 'b'))
			pv3 = 3.0;
		else if ((grade3 == 'B-') || (grade3 == 'b-'))
			pv3 = 2.7;
		else if ((grade3 == 'C+') || (grade3 == 'c+'))
			pv3 = 2.33;
		else if ((grade3 == 'C') || (grade3 == 'c'))
			pv3 = 2.0;
		else if ((grade3 == 'C-') || (grade3 == 'c-'))
			pv3 = 1.7;
		else if ((grade3 == 'D+') || (grade3 == 'd+'))
			pv3 = 1.3;
		else if ((grade3 == 'D') || (grade3 == 'd'))
			pv3 = 1.0;
		else if ((grade3 == 'D-') || (grade3 == 'd-'))
			pv3 = 0.7;
		else if ((grade3 == 'F') || (grade3 == 'f'))
			pv3 = 0.0;

		cout << "Your grade for course 1: " << pv1;
		cout << "Your grade for course 2: " << pv2;
		cout << "Your grade for course 3: " << pv3;

		gpa = (pv1 + pv2 + pv3) / totalcredithours;
		// I do not think this calculation is correct

		const double perfectgpa = 4.0;
		cout << "Your GPA on a " << perfectgpa << "scale is " << gpa;

		int a = 0;
		cout << a++;
		cout << a++; 

	return 0; 
}