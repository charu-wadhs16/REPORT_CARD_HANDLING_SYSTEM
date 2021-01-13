# REPORT_CARD_HANDLING_SYSTEM


INTRODUCTION:
Student report card handling system project is a simple project built using the basic concepts of C++ like class, loops, array etc. In this project, there are facilities to add, modify, display, search and delete student records. File handling has been effectively used to perform all these functions. Student Records are stored in a binary file. There is no usage of global variables in this project. It is a solution to organize, manage and retrieve student records and maintain report cards of students. It can be used in schools to maintain student report cards.

OBJECTIVE:
	To calculate percentage, grade, and cgpa of student.
	To create, modify, search, delete, and display student records.
	To reduce manual work of managing student records

FACILITIES PROVIDED:
	Search Student Records
	Check Student Status
	Create Student Record
	Generate Report Card

METHODOLOGY:
The features of this program are:
	INTRODUCTION MENU: In this menu user will be asked to enter designation-T for editor menu, S for viewer menu and any other to exit.
	ADMINISTRATOR OR EDITOR MENU:  In this menu user has both editor as well as viewer rights by just entering the username and passcode visible on the screen. User can create, modify, search, delete, view class report and the report card of particular student using roll number as it is built at administrative end.
	STUDENT OR VIEWER MENU: In this menu user just has the viewing rights and can only search, display class report and the report card of particular student using roll number.


IMPLEMENTATION:

HEADER FILES USED:

#include<iostream>
#include<string>
#include<fstream>
CLASS USED:
  
class Report_Card                                                                                                                                   {
};               
MODULES:
  
	welcome_Screen() : This function is used to display the title of the project and brief introduction about the doer of the project.

	Introduction (): This function will ask the user about his/her designation i.e. student or teacher and which menu would he like to view administrator menu or viewer menu and if the designation entered by user is neither ‘S’ nor ‘T’ then the function will ask the user if he wants to exit the program.

	editor_Menu(): This function will ask user to enter the username and passcode and if it matches then ask user if he want to view the detailed editor menu or want to exit.     ENTER 1 FOR DETAILED MENU                                                                                                                             
ENTER 2 TO GET BACK TO INTRODUCTION MENU OR TO EXIT

	 viewer_Menu():This function will ask user if he want to view the detailed viewer menu  or want to exit.  
ENTER 1 FOR DETAILED MENU                                                                                                                             
ENTER 2 TO GET BACK TO INTRODUCTION MENU OR TO EXIT 
   
	detail_editor_Menu(): This function displays the detailed viewer menu and ask user what would he like to do.                                                                    ENTER 1 TO ADD/INSERT STUDENT RECORD      
ENTER 2 TO EDIT/MODIFY STUDENT RECORD                                                                                                    
ENTER 3 TO DELETE STUDENT RECORD 
ENTER 4 TO VIEW CLASS REPORT
ENTER 5 TO DISPLAY STUDENT REPORT CARD 
ENTER 6 TO SEARCH STUDENT RECORD 
ENTER 7 TO GET BACK TO INTRODUCTION MENU OR TO EXIT            
                                                                                                                 
	detail_viewer_Menu():This function displays the detailed viewer menu and ask user what would he like to view.                                                                                                       
ENTER 1 TO VIEW CLASS REPORT
ENTER 2 TO DISPLAY STUDENT REPORT CARD
ENTER 3 TO SEARCH STUDENT RECORD
ENTER 4 TO GET BACK TO INTRODUCTION MENU OR TO EXIT.

	insert_Record():This function creates and add a new student record containing his marks. For this the information to be provided are the name, admission no., roll no. of the student, and the marks obtained by him/her in 5 subjects.   

	set_student_Data(): This function  takes input such as name, guardian name, marks, roll no., admission no., etc. from the user  and sets student record. 

	get_Roll_No(): This function returns the roll number of the student.

	calculate_Grade():This function calculates the grade, percent and the cgpa.                                                          
	view_Report_Card(int): This function shows the progress report and relevant data related to a particular student. It first asks for the roll number of student whose report card is to be viewed.

	show_Card(): This function shows the report card in a card format when called from view_Report_Card(int) function.

	view_Class_Report():This function shows the progress report of all the students (whole class) added in file.                                                                                                                                                                                                                                                                                             
	show_Report():This function shows the report card in a card format when called from view_Class_Report() function. 

	search_Record(int): This function is used to search the record of a particular student. For this, the roll no. of the student is searched, if found the program displays the record .If no record of student is found in file, it displays the message “Record not found”.

	display_Record():This function shows the details of a student.

	edit_Record(int): This function is used to edit the report card record of a particular student. For this, the name and roll no. of the student is sought. Upon successful modification, the program displays the message “Record Modified”. If no record of student is found in file, it displays the message “Record not found”.

	delete_Record(int): This function deletes the report card record of a particular student; it first of all asks for the name and roll no. of the student whose record is to be deleted.      

	student_Status(int): This function is used to check status of student whether pass or fail.

	show_Status(): This function is used to show status of student whether pass or fail.  

	main() : This is the driver function of the program and will have an object of class Report_Card which will call welcome_Screen() function.
           
