#include <iostream>
using namespace std;
int main()
{
	string name, plannername, coursecode1; 

	cout << "Enter your first name. \n";
		cin >> name;

	cout << "Get started on ";
	cout << name << "'s Grade Saver Planner" << endl;

	int number0fCourses;
	double credithours0fcourse1;

	cout << "Enter the course code for your first class with no spaces. \n";
	cin >> coursecode1; 
	cout << "Enter the credit hours for this course. \n";
	cin >> credithours0fcourse1; 
	cout << "Course 1:" << coursecode1;
	cout << "Course 1 Credit Hours:" << credithours0fcourse1;

	return 0; 
}