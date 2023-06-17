#include<iostream>
#include<unordered_map>
using namespace std;



int gradetopoint(string st){                        //function to change grade to points
    unordered_map<string,int> mp;
    mp["A+"]=9;
    mp["A"]=8;
    mp["A-"]=7;
    mp["B+"]=6;
    mp["B"]=5;
    mp["B-"]=4;
    mp["C+"]=3;
    mp["C"]=2;
    mp["C-"]=1;
    mp["F"]=0;

    return mp[st];

}

class sem;                                      //declaring as I am using in students class

class student{                                  //for basic details of a student
    string fname;
    string lname;
    string enroll;
    public:
    student(){                                  //taking input
        cout<<"Enter first name : ";
        cin>>fname;
        cout<<"Enter last name : ";
        cin>>lname;
        cout<<"Enter enrollment number : ";
        cin>>enroll;
    }

    friend void display(student &s,sem *sem,int n);                 //friend function for displaying the complete result

};


class sem{                                                          //class for storing records of each sem
    string subject[6];                                              //subjects 
    int credit[6];                                                  //credits for each subject
    int grade[6];                                                   //grade points for each subject
    float sg;                                                         //sgpa of this sem

    public:
    static float totalcredits;                  
    static float obtaipoints;
    sem(){                                                          //constructors
        sg=0;
    }

    void getdata(int s){                                                            //getting data for each sem
        cout<<"------GETTING DETAILS FOR SEM "<<s+1<<"------"<<endl;
        for(int i=0;i<6;i++){
            cout<<"Subject "<<i+1<<" : ";
            cin>>subject[i];
            cout<<"Credits "<<i+1<<" : ";
            cin>>credit[i];
            cout<<"Grade "<<i+1<<" : ";
            string temp;
            cin>>temp;
            grade[i]=gradetopoint(temp);
        }
        return ;
    }

    void sgpa(){
        float currcred=0;
        float currppoint=0;
        for(int i=0;i<6;i++){
            currppoint+=credit[i]*grade[i];
            currcred+=credit[i];
        }
        obtaipoints+=currppoint;
        totalcredits+=currcred;
        sg=currppoint/currcred;
        cout<<"------YOUR SGPA IS "<<sg<<" ------\n\n";
        cout<<"------YOUR CGPA IS "<<obtaipoints/totalcredits<<" ------\n\n\n";
        cout<<"-------------------------------------------------------------\n\n";
        
    }
friend void display(student &s,sem *sem,int n);
};


void display(student &s,sem *sem,int n){
    cout<<"\n\n-----------RESULT-------------\n\n";
    cout<<"Name : "<<s.fname<<" "<<s.lname;
    cout<<"\nEnrollment No : "<<s.enroll<<"\n";
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Sgpa of Sem "<<i+1<<" is : "<<sem[i].sg<<endl;
    }
    cout<<"YOUR CGPA IS ------"<<sem[0].obtaipoints/sem[0].totalcredits<<" ------\n\n\n";
}

float sem::obtaipoints=0;
float sem::totalcredits=0;

int main(){
    
    student st;                                                                         //creating a student
    sem sem[10];                                                                       //declaring max sem a student can have

    int i=0;                                                                           //for tracking the semester
    char response;                                                                      //taking response 
    while(1){
        cout<<"Wants to add details for sem "<<i+1<<" ? (Y,N)";
        cin>>response;
        if(response=='N'){
            break;
        }

        sem[i].getdata(i);                                                          //taking details for sem 
        sem[i].sgpa();                                                              //displaying sgpa of each sem
        i++;


    }

    display(st,sem,i);                                                               //displaying the final result
    
    return 0;
}