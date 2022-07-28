#include<bits/stdc++.h>

using namespace std;

void show();

struct Student
{

    string student_name;
    string student_id;
    string father_name;
    string mother_name;
    string date_of_birth;

    Student(string _student_name,string _student_id,string _father_name,string _mother_name,string _date_of_birth)
    {
        student_name=_student_name;
        student_id=_student_id;
        father_name=_father_name;
        mother_name=_mother_name;
        date_of_birth=_date_of_birth;

    }
};

vector<Student*>details;

void write_student_file()
{
    ofstream file;

    file.open("Student record.text");

    for(int i=0;i<details.size();i++)
    {
        Student* s1=details[i];

        file<<s1->student_name<<" "<<s1->student_id<<" "
        <<s1->father_name<<" "<<s1->mother_name<<" "<<s1->date_of_birth<<endl;
    }
    file.close();

}
void read_student_file()
{
    ifstream file;

    file.open("Student record.text");

    string a,b,c,d,e;

    while(file>>a>>b>>c>>d>>e)
    {
        Student* s1=new Student(a,b,c,d,e);
        details.push_back(s1);
    }

    file.close();
}


void search_a_student()
{
    system("Cls");
    cout<<"\n\t\t\tEnter The Student Id You Want To See : ";
    string id;
    cin>>id;
    int x=0;

     for(int i=0;i<details.size();i++)
     {
         Student* nasif=details[i];
         if(nasif->student_id==id)
         {
             x=1;
             cout<<"\n  Student name :" <<nasif->student_name<<"\n  Student id :"<<nasif->student_id<<"\n  Father name : "<<nasif->father_name<<"\n  Mother name : "<<nasif->mother_name<<"\n  Date of birth : "<<nasif->date_of_birth<<endl;
            break;

         }
     }
     if(x==0)cout<<"\n\t\t\tNot Found\n\n";
     system("PAUSE");
}

void remove_a_account()
{
    system("Cls");
    show();
    vector<Student*>temp;
    bool iExist=false;
    cout<<"\n\t\t\tEnter The Student Id Which You Want To Remove : ";
    string id;
    cin>>id;
    for(int i=0;i<details.size();i++)
    {
        Student* n1=details[i];
        if(n1->student_id==id)
        {
            iExist=true;
        }
        else
        {
            temp.push_back(n1);
        }
    }
    if(iExist)
    {
        details=temp;
        cout<<"\n\t\t\tRemove Succesfully!!\n\n\n";
    }
    else
    {
        cout<<"\n\t\t\tNot Found.....\n\n";
    }
}

void show()

    system("Cls");
    cout<<"\n\t\t\t\t\t-----------------";
    cout<<"\n\t\t\t\t\tALl Students Data";
    cout<<"\n\t\t\t\t\t-----------------\n\n";
    for(int i=0; i<details.size(); i++)
    {
        Student* rafee=details[i];
        cout<<i+1<<".\n\t\t\t  Student name : " <<rafee->student_name<<"\n\t\t\t  Student id : "<<rafee->student_id<<"\n\t\t\t  Father name : "<<rafee->father_name<<"\n\t\t\t  Mother name : "<<rafee->mother_name<<"\n\t\t\t  Date of birth : "<<rafee->date_of_birth<<endl;


    }
    system("PAUSE");

}
void add()
{
    system("Cls");
    string name,id,fatherName,motherName,dateOfBirth;
    cout<<"\nEnter your name : ";
    cin>>name;
    cout<<"\nEnter your Id : ";
    cin>>id;
    cout<<"\nEnter your father name : ";
    cin>>fatherName;
    cout<<"\nEnter your mother name : ";
    cin>>motherName;
    cout<<"\nEnter your date of birth : ";
    cin>>dateOfBirth;

    Student* ob = new Student(name,id,fatherName,motherName,dateOfBirth);
    details.push_back(ob);
    cout<<"\n\t\t\tSuccesfully Saved Data!! ";
    system("PAUSE");

}

bool isLogIn()
{
    system("Cls");
    cout<<"\n\t\t\t\tLog In";
    cout<<"\n\t\t\t\t------ \n";
    cout<<"\n\t\t\tEnter User Name :: ";
    string userName;
    cin>>userName;
    cout<<"\n\t\t\tEnter Password :: ";
    string passWord;
    cin>>passWord;
    if(userName=="af_rafi" && passWord=="123")
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main ()
{
    while(1){

     cout<<"\n\t\t\t\t\t--------------------------";
     cout<<"\n\t\t\t\t\tWelcome To Student Record";
     cout<<"\n\t\t\t\t\t--------------------------\n";
     cout<<"\n\t\t\t\t\t\t1.Log In\n";
     cout<<"\n\t\t\t\t\t\t0.Exit\n";
      cout<<"\n\t\t\t\t\tInput : ";

     int n;
     cin>>n;

     if(n==1){

    bool LogIn=isLogIn();
    if(LogIn)
        {
     read_student_file();
     system("Cls");
     cout<<"\n\t\t\tLog In Succesfully\n";
    while(1){
            system("Cls");
        cout<<"\n\t\t\t---------------";
        cout<<"\n\t\t\tChoose a option";
        cout<<"\n\t\t\t---------------\n\n";
        cout<<"\n\t\t\t\t1.Add A Student Record";
        cout<<"\n\t\t\t\t2.See All Records ";
        cout<<"\n\t\t\t\t3.Remove A Student Record";
        cout<<"\n\t\t\t\t4.Search A Student By Id\n";
        cout<<"\n\t\t\t0.Log Out\n";
        cout<<"\n\t\t\t\tEnter A Option : ";
        int input;
        cin>>input;
        if(input==0)break;
        switch(input)
        {
        case 1:
            add();
            write_student_file();
            break;
        case 2:
            show();
            break;
        case 3:
            remove_a_account();
            write_student_file();
            break;
        case 4:
            search_a_student();
        default:
            cout<<"wrong code : ";

        }
    }
    }
    else
        cout<<"\n\t\t\tWrong  Try Again \n";
        system("PAUSE");


    }

    else if(n==0)
        break;
    }

    return 0;
}

