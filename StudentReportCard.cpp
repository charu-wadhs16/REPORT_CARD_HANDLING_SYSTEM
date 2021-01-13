#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Report_Card                           // class
{
int Roll_No;                                //to store Student Roll Number
int Adm_No;                                 //to store Student Admission Number
char Sec;                                   //to store section
float cgpa;                                 //to store grade point average
float Subject_1,Subject_2;                  //variables to store subject marks
float Subject_3,Subject_4,Subject_5;        //variables to store subject marks
string Username;                            //stores user name
string Password;                            //stores password
string Student_name;                        //store student name
string Parent_name;                         // store guardian name
string Designation;                         //to store T for teacher and S for student
float percent;                              //to store percent
char grade;                                 //to store grade
public:
Report_Card();                             //constructor
void view_Report_Card(int);                //function to show report card of a student taking roll number as argument
void show_Card();                          //function to show student result in a card format
void show_Status();                        //to show whether student is pass or fail
void show_Report();                        //function to show result
void view_Class_Report();                  //function to show the class report
void search_Record(int);                   //function to search details of a student taking roll number as argument
void student_Status(int);                  //function to check student status
void display_Record();                     //function to display details of a student
void edit_Record(int);                     //function to modify student record taking roll number as argument in a binary file
void calculate_Grade();                    //function to calculate grade and percentage of a student
int  get_Roll_No();                        //function which returns the roll number of a student
void set_student_Data();                   //function to set student details
void insert_Record();                      //function to write student record in binary file
void delete_Record(int);                   //function to delete student record from aT binary file
void Introduction();                       //function to choose the mode (editor/viewer)
void welcome_Screen();                     //function to introduce the project
void editor_Menu();                        //function to show editor menu
void viewer_Menu();                        //function to show viewer menu
void detail_viewer_Menu();                 //function to show detailed viewer menu
void detail_editor_Menu();                 // function to show detailed editor menu
};
//ending of class

// DEFINITION OF CLASS FUNCTIONS OUTSIDE THE CLASS USING :: OPERATOR

Report_Card::Report_Card()                             //constructor
{
 Roll_No=0;
 Adm_No=0;
 Sec='A';
 cgpa=0.0;
 percent=0.0;
}
void Report_Card::show_Card()     // function definition outside class using :: operator
{
  system("cls");
  cout<<"\n\t\t\t\t---------------------REPORT CARD-------------------------\n\n";
  cout<<"\n\n--------------------------------------------------------------------";
  cout<<"----------------------------------------------------";
  cout<<"\n\n\nADMISSION NO : "<<Adm_No<<" || ROLL NO: "<<Roll_No;
  cout<<" || STUDENT'S NAME : " <<Student_name<<" || GUARDIAN'S NAME : "<<Parent_name;
  cout<<" || SEC : "<<Sec;
  cout<<"\n------------------------------------------------------------------------";
  cout<<"------------------------------------------------";
  cout<<"\n\nSUBJECT        |      MARKS(M.M. 100) ";
  cout<<"\nSubject 1      |      "<<Subject_1;
  cout<<"\nSubject 2      |      "<<Subject_2;
  cout<<"\nSubject 3      |      "<<Subject_3;
  cout<<"\nSubject 4      |      "<<Subject_4;
  cout<<"\nSubject 5      |      "<<Subject_5;
  cout<<"\n-------------------------------------------------------------------------";
  cout<<"-----------------------------------------------";
  cout<<"\n\nOVERALL PERCENTAGE : "<<percent<<"\t\tOVERALL GRADE : "<<grade;
  cout<<"\t\tCGPA : "<<cgpa;
  if(grade=='F')
  cout<<"\n\nSTATUS::FAIL ";
  else
  cout<<"\n\nSTATUS::PASS ";
  cout<<"\n-------------------------------------------------------------------------";
  cout<<"-----------------------------------------------";
}
void Report_Card::show_Status()
{
    cout<<"\n\nSTUDENT STATUS:";
    if(grade=='F')
    cout<<" Fail";
    else
    cout<<" Pass";
}
void Report_Card::show_Report()    // function definition outside class using :: operator
{
  cout<<"\n\n--------------------------------------------------------------------";
  cout<<"----------------------------------------------------";
  cout<<"\n\n\nADMISSION NO : "<<Adm_No<<" || ROLL NO: "<<Roll_No;
  cout<<" || STUDENT'S NAME : " <<Student_name<<" || GUARDIAN'S NAME : "<<Parent_name;
  cout<<" || SEC : "<<Sec;
  cout<<"\n------------------------------------------------------------------------";
  cout<<"------------------------------------------------";
  cout<<"\n\nSUBJECT        |      MARKS(M.M. 100)  ";
  cout<<"\nSubject 1      |      "<<Subject_1;
  cout<<"\nSubject 2      |      "<<Subject_2;
  cout<<"\nSubject 3      |      "<<Subject_3;
  cout<<"\nSubject 4      |      "<<Subject_4;
  cout<<"\nSubject 5      |      "<<Subject_5;
  cout<<"\n-------------------------------------------------------------------------";
  cout<<"-----------------------------------------------";
  cout<<"\n\nOVERALL PERCENTAGE : "<<percent<<"\t\tOVERALL GRADE : "<<grade;
  cout<<"\t\tCGPA : "<<cgpa;
  if(grade=='F')
  cout<<"\n\nSTATUS::FAIL ";
  else
  cout<<"\n\nSTATUS::PASS ";
  cout<<"\n--------------------------------------------------------------------------";
  cout<<"----------------------------------------------";
}
void Report_Card::view_Report_Card(int n)
{
 ifstream obj ;                                         //file object
 obj.open("Result.dat",ios::binary|ios::in);           //opening a file
 if(!obj)
 {
 cout<<"There was some issue while opening the file !! Press Enter Key...";
 cin.ignore();
 cin.get();
 }
 else
 {
 int c=0;
 while(obj.read((char*) (this), sizeof(*this)))  //reading a file
 {
 if(get_Roll_No()==n)
 {
     show_Card();
     c=1;
 }
 }
 obj.close();                         //closing a file
 if(c==0)
 cout<<"\n\nOOPS!...STUDENT RECORD NOT FOUND...";
 cout<<"\nPRESS ENTER!";
 cin.ignore();
 cin.get();
 }
}
void Report_Card::view_Class_Report()
{
 ifstream obj;                        //file object
 obj.open("Result.dat",ios::binary);
 if(!obj)                            //checking the existence of a file
 {
 cout<<"There was some issue while opening the file !! Press Enter Key...";
 cin.ignore();
 cin.get();
 return;
 }
 cout<<"\n\t\t\t\t\t\tCLASS REPORT\n";
 int c=0;
 while(obj.read((char*) (this), sizeof(*this)))           //reading a file
 {
 show_Report();                                           //displaying result
 c=1;
 }
 if(c==0)
 cout<<"\n\nOOPS!...NO RECORD FOUND...";
 cout<<"\nPRESS ENTER!";
 cin.ignore();
 cin.get();
 obj.close();                                          //closing a file
}
void Report_Card::search_Record(int n)
{
 ifstream obj;                                        // file object
 obj.open("Result.dat",ios::binary|ios::in);        //  opening a file
 if(!obj)
 {
 cout<<"There was some issue while opening the file !! Press Enter Key...";
 cin.ignore();
 cin.get();
 }
 else
 {
 int c=0;
 while(obj.read((char*) (this), sizeof(*this))) //reading a file
 {
 if(get_Roll_No()==n)
 {
     display_Record();
     c=1;
 }
 }
 obj.close();                                             //closing a file
 if(c==0)
 cout<<"\n\nOOPS!...STUDENT RECORD NOT FOUND...";
 cout<<"\n\nPRESS ENTER!";
 cin.ignore();
 cin.get();
}
}
void Report_Card::display_Record()
{
 system("cls");
 cout<<"\nSTUDENT DETAILS:";
 cout<<"\n\nStudent Roll Number :";
 cout<<Roll_No;
 cout<<"\n\nStudent Section :";
 cout<<Sec;
 cout<<"\n\nStudent Admission Number :";
 cout<<Adm_No;
 cout<<"\n\nStudent Name :";
 cout<<Student_name;
 cout<<"\n\nGuardian Name :";
 cout<<Parent_name;
 cout<<"\n\nThe marks in subject 1 out of 100 : ";
 cout<<Subject_1;
 cout<<"\n\nThe marks in subject 2 out of 100 : ";
 cout<<Subject_2;
 cout<<"\n\nThe marks in subject 3 out of 100 : ";
 cout<<Subject_3;
 cout<<"\n\nThe marks in subject 4 out of 100 : ";
 cout<<Subject_4;
 cout<<"\n\nThe marks in subject 5 out of 100 : ";
 cout<<Subject_5;
 cout<<"\n\nPercentage of student : "<<percent;
 cout<<"\n\nGrade of student : "<<grade;
 if(grade=='F')
 cout<<"\n\nStatus:Fail";
 else
 cout<<"\n\nStatus:Pass";
}
void Report_Card::student_Status(int n)
{
 ifstream obj;                                       // file object
 obj.open("Result.dat",ios::binary|ios::in);        //  opening a file
 if(!obj)
 {
 cout<<"There was some issue while opening the file !! Press Enter Key...";
 cin.ignore();
 cin.get();
 }
 else
 {
 int c=0;
 while(obj.read((char*) (this), sizeof(*this))) //reading a file
 {
 if(get_Roll_No()==n)
 {
     show_Status();
     c=1;
 }
 }
 obj.close();                                             //closing a file
 if(c==0)
 cout<<"\n\nOOPS!...STUDENT STATUS NOT FOUND...";
 cout<<"\n\nPRESS ENTER!";
 cin.ignore();
 cin.get();
}
}
int Report_Card::get_Roll_No()               //function to get the roll number
{
   return Roll_No;
}
void Report_Card::delete_Record (int n)
{
   fstream obj;                                                         //file object
   obj.open("Result.dat",ios::binary|ios::in);                         //opening file
   if(!obj)
   {
   cout<<"There was some issue while opening the file !! Press Enter Key...";
   cin.ignore();
   cin.get();
   }
   else
   {
   fstream obj2;                                                         //file object
   obj2.open("Temp.dat",ios::binary|ios::out);                          //opening a temporary file
   while(obj.read((char*)(this),sizeof(*this)))                        //reading from original file
   {
     if(get_Roll_No()!=n)
     {
      obj2.write((char*)(this),sizeof(*this));                        // writing in a temporary file
     }
   }
   obj2.close();                                                      //closing temporary file
   obj.close();                                                       //closing original file
   remove("Result.dat");                                              //removing the original file
   rename("Temp.dat","Result.dat");                                   //renaming the temporary file as original file
   cout<<"\n\n\t Student Record has been Deleted ..";
   cout<<"\n\nPRESS ENTER!";
   cin.ignore();
   cin.get();
   }
}
void Report_Card::edit_Record(int n)
{
 int c=0;
 fstream obj;                                        //file object
 obj.open("Result.dat",ios::binary|ios::in|ios::out); //opening file
 if(!obj)
 {
 cout<<"There was some issue while opening the file !! Press Enter Key...";
 cin.ignore();
 cin.get();
 }
 else
 {
 while(!obj.eof()&&c==0)
 {
 obj.read((char*)(this),sizeof(*this));               //reading a file
 if(get_Roll_No()==n)                                 //matching the student roll number with the one present in record
 {
 display_Record();                                   //display record
 cout<<"\n\nPLEASE ENTER THE NEW DETAILS OF STUDENT"<<endl;
 set_student_Data();
 obj.seekp(-1*sizeof(*this),ios::cur);               //to set the position of the file pointer
 obj.write((char *)(this), sizeof(*this));          //writing in a file
 cout<<"\n\n\t Record Modified!";
 c=1;
 }
 }
 obj.close();                                       //closing a file
 if(c==0)
 cout<<"\n\nOOPS!...STUDENT RECORD NOT FOUND...";
 cout<<"\nPRESS ENTER!";
 cin.ignore();
 cin.get();
 }
}
void Report_Card::set_student_Data()         //function to input student data
{
 cout<<"\nEnter the Roll number of Student(INTEGER) :";
 cin>>Roll_No;
 cout<<"\nEnter the Section of Student(CHARACTER) :";
 cin>>Sec;
 cout<<"\nEnter the Admission number of Student(INTEGER) :";
 cin>>Adm_No;
 cout<<"\nEnter the Name of Student(STRING) :";
 cin.ignore();
 getline(cin,Student_name);
 cout<<"\nEnter the Name of Guardian(STRING) :";
 getline(cin,Parent_name);
 cout<<"\nEnter the marks in subject 1 out of 100 : ";
 cin>>Subject_1;
 cout<<"\nEnter the marks in subject 2 out of 100 : ";
 cin>>Subject_2;
 cout<<"\nEnter the marks in subject 3 out of 100 : ";
 cin>>Subject_3;
 cout<<"\nEnter the marks in subject 4 out of 100 : ";
 cin>>Subject_4;
 cout<<"\nEnter the marks in subject 5 out of 100 : ";
 cin>>Subject_5;
 calculate_Grade();                         //calling function to calculate grade, cgpa and percentage
}
void Report_Card::calculate_Grade()
{
    percent=(Subject_1+Subject_2+Subject_3+Subject_4+Subject_5)/5.0;
    cgpa=percent/10.0;
    if(percent>=85)
    grade='A';
    else if(percent>=75)
    grade='B';
    else if(percent>=65)
    grade='C';
    else if(percent>=55)
    grade='D';
    else if(percent>=45)
    grade='E';
    else
    grade='F';
}
void Report_Card::insert_Record()
{
    fstream obj;                                            //object to write or read file
    obj.open("Result.dat",ios::binary|ios::app|ios::out);  //opening a file in binary, read and write mode
    set_student_Data();                                   //function call to set student data
    obj.write((char*)(this),sizeof(*this));              //writing in a file in binary file
    obj.close();                                        //closing a file
    cout<<"\n\nStudent record has Been Inserted";
    cout<<"\nPRESS ENTER!";
    cin.ignore();
    cin.get();
}

void Report_Card::detail_viewer_Menu()
{
int ch,n;
system("cls");
cout<<"\n ENTER 1 TO VIEW CLASS REPORT";
cout<<"\n ENTER 2 TO DISPLAY STUDENT REPORT CARD";
cout<<"\n ENTER 3 TO SEARCH STUDENT RECORD";
cout<<"\n ENTER 4 TO CHECK STATUS OF STUDENT ";
cout<<"\n ENTER 5 TO GET BACK TO INTRODUCTION MENU OR TO EXIT";
cout<<"\n\n\n ENTER CHOICE: ";
cin>>ch;
switch(ch)
{
case 1: view_Class_Report();
        break;
case 2: cout<<"\nEnter the Roll no of student whose report card is to be viewed:";
        cin>>n;
        view_Report_Card(n);
        break;
case 3: cout<<"\nEnter the Roll no of student whose record is to be searched:";
        cin>>n;
        search_Record(n);
        break;
case 4: cout<<"\nEnter the Roll no of student whose status is to be checked:";
        cin>>n;
        student_Status(n);
        break;
case 5: break;
default:cout<<"\a Wrong Choice!";
}
}
void Report_Card::viewer_Menu()
{
system("cls");
cout<<"\n WELCOME TO THE VIEWER MENU :(You can only view the records!)";
cout<<"\n\n ENTER 1 FOR DETAILED MENU";
cout<<"\n ENTER 2 TO GET BACK TO INTRODUCTION MENU OR TO EXIT";
cout<<"\n\n ENTER YOUR CHOICE:";
char ch;
cin>>ch;
switch(ch)
{
   case '1':detail_viewer_Menu();
            break;
   case '2':break;
   default:cout<<"\a Wrong Choice!";
}                                                       //end of switch
}
void Report_Card::detail_editor_Menu()
{
int n;
int ch;
system("cls");
cout<<"\n\t\t\t\t\tENTER 1 TO ADD/INSERT STUDENT RECORD";
cout<<"\n\t\t\t\t\tENTER 2 TO EDIT/MODIFY STUDENT RECORD";
cout<<"\n\t\t\t\t\tENTER 3 TO DELETE STUDENT RECORD ";
cout<<"\n\t\t\t\t\tENTER 4 TO VIEW CLASS REPORT";
cout<<"\n\t\t\t\t\tENTER 5 TO DISPLAY STUDENT REPORT CARD ";
cout<<"\n\t\t\t\t\tENTER 6 TO SEARCH STUDENT RECORD ";
cout<<"\n\t\t\t\t\tENTER 7 TO CHECK STATUS OF STUDENT ";
cout<<"\n\t\t\t\t\tENTER 8 TO GET BACK TO INTRODUCTION MENU OR TO EXIT";
cout<<"\n\n\nENTER CHOICE: ";
cin>>ch;
system("cls");
switch(ch)
{
case 1: insert_Record();
        break;
case 2: cout<<"\nEnter the Roll no of student whose record is to be modified:";
        cin>>n;
        edit_Record(n);
        break;
case 3: cout<<"\nEnter the Roll no of student whose record is to be deleted:";
        cin>>n;
        delete_Record(n);
        break;
case 4: view_Class_Report();
        break;
case 5: cout<<"\nEnter the Roll no of student whose report card is to be viewed:";
        cin>>n;
        view_Report_Card(n);
        break;
case 6: cout<<"\nEnter the Roll no of student whose record is to be searched:";
        cin>>n;
        search_Record(n);
        break;
case 7: cout<<"\nEnter the Roll no of student whose status is to be checked:";
        cin>>n;
        student_Status(n);
        break;
case 8: break;
default:cout<<"\a Wrong Choice!";
}
}
void Report_Card::editor_Menu()
{
system("cls");
int c=0;
char ch,choice;
do
{
cout<<"\nYOUR DEFAULT USERNAME IS USER";
cout<<"\n\n\nEnter Username :";
cin>>Username;
cout<<"\nYOUR DEFAULT PASS-CODE IS 1234";
cout<<"\n\n\nEnter Pass code :";
cin>>Password;
if(Password=="1234"&&Username=="USER")
{
system("cls");
cout<<"\n YOU ARE LOGGED IN AS ADMIN";
cout<<"\n\n WELCOME TO THE EDITOR MENU : (You have rights to edit the records!)\n";
cout<<"\n\n ENTER 1 FOR DETAILED MENU";
cout<<"\n ENTER 2 TO GET BACK TO INTRODUCTION MENU OR TO EXIT";
cout<<"\n\n ENTER YOUR CHOICE:";
cin>>ch;
switch(ch)
{
   case '1':detail_editor_Menu();
            break;
   case '2':break;
   default:cout<<"\a Wrong Choice!";
}                                                       //end of switch
}
else
{
cout<<"\nWrong Passcode....Try again!\n";
cout<<"\nWANT TO TRY AGAIN(Y/N)?";
cin>>choice;
}
}while((Password!="1234"||Username!="USER")&&(choice=='y'||choice=='Y'));   //end of while
}
void Report_Card::Introduction()
{
char ch;
do
{
  system("cls");
  cout<<"\n\n\t\t\t\t\tWHICH MENU WOULD YOU LIKE TO VIEW?";
  cout<<"\n\n\t\t\t\t\tPRESS T : Administrator or Teacher(Editor/Viewer) Menu";
  cout<<"\n\n\t\t\t\t\tPRESS S : Student(Viewer) Menu";
  cout<<"\n\n\t\t\t\t\tPRESS ANY OTHER KEY : Exit";           //asking for user's choice of menu
  cout<<"\n\n\n\nENTER YOUR CHOICE:";
  cin>>Designation;                                          //asking designation from the user
  if(Designation=="S"||Designation=="s")
  viewer_Menu();
  else if(Designation=="T"||Designation=="t")
  editor_Menu();
  else
  cout<<"\n\nYou are trying to exit!";
  cout<<"\n\n\nDO YOU WANT TO CONTINUE WITH THE PROGRAM ? (Y/N):";
  cin>>ch;
  cin.ignore();
}while(ch=='y'||ch=='Y');                              //end of while
}
void Report_Card::welcome_Screen()
{
    cout<<"\n\n\n\n\t\t\t-----------STUDENT REPORT CARD HANDLING SYSTEM------------";         //Introduction
    cout<<"\n\n\n\t\t\t\t\tSUBMITTED BY:";
    cout<<"\n\n\n\t\t\t\t\tNAME:CHARU WADHWA";
    cout<<"\n\n\t\t\t\t\tSEC:A";
    cout<<"\n\n\t\t\t\t\tUNIVERSITY ROLL NO:2014620";
    cout<<"\n\n\t\t\t\t\tADMISSION NO:190221250";
    cout<<"\n\n\n\n\nPRESS ENTER KEY TO PROCEED....";
    cin.get();
    Introduction();
}
int main()                                             //driver of the program main() function
{
    Report_Card S;
    S.welcome_Screen();
}
