#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

class Book{

     
    public :

        static int count;
        int bookID;
        string title;
        string author;
        string publisher;
        bool isIssued;

        Book(string t,string a ,string p){
            this->title=t;
            this->author=a;
            this->publisher=p;
            this->isIssued=false;
            count++;
            this->bookID=count;
        }

        void displayInfo() const{
            cout<<"book ID "<<this->bookID
            <<endl<<"Title "<<this->title
            <<endl<<"Author "<<this->author
            <<endl<<"Publisher "<<this->publisher
            <<endl<<"Is Issued "<<this->isIssued
            <<endl;
        }


};

int Book::count=1000;


class Member{


public:
static int count1;
int memberID;
string name;
string address;
Member(string n,string a){
    this->name=n;
    this->address=a;
    count1++;
    this->memberID=count1;

}
void displayMemberInfo()const {
        cout<<"Member Name "<<this->name
        <<endl<<"Adress "<<this->address<<endl;
}


};
int Member::count1=2000;

class Library{

    public:
        vector<Book> books;
        vector<Member> members;
        string library_name;

        Library(string name){
            this->library_name=name;

        }

    void addBook(Book b){
        this->books.push_back(b);
    }

    void removeBook(string name){   

    auto it = this->books.begin(); 
    while (it != this->books.end()) {
        if (it->title == name) {
          
            cout<<"removed the book with bookID "<<it->bookID<<endl;
            it = this->books.erase(it);
            
            break;
        } else {
            ++it; 
        }
    }    
    }

    void issueBook(string name) {

    auto it = this->books.begin(); 
    while (it != this->books.end()) {
        if (it->title == name) {
          
            
            if(it->isIssued){
                cout<<"Book is already issued"<<endl;
            }else {
                cout<<"Book issued in your Name "<<endl;
                it->isIssued=true;
            }
            break;
        } else {
            ++it; 
        }
    } 

    }

    void returnBook(string name){


    auto it = this->books.begin(); 
    while (it != this->books.end()) {
        if (it->title == name) {
          
            
            cout<<"Book is returned"<<endl;
            it->isIssued=false;
            
            break;
        } else {
            ++it; 
        }
    } 



    }

    void displayBooks(){
         for (const auto& book : this->books) {
        
        cout<<book.title<<" "<<book.author<<" "<<book.isIssued<<endl;
    }
    }

    void addMember(Member m){
        this->members.push_back(m);
    }

    void displayMembers(){
         for (const auto& member : this->members) {
        
        cout<<member.name<<endl;
    }
    }


};


int main(){

  
    Book b1("Computer Networks","tannanbaun","delhi");
    Book b2("DBMS","korth","usa");
    b1.displayInfo();
    b2.displayInfo();

    Library l1("south district library");
    l1.addBook(b1);
    l1.addBook(b2);
    l1.displayBooks();
    l1.issueBook("DBMS");
    l1.displayBooks();
    l1.issueBook("DBMS");
    l1.returnBook("DBMS");
    l1.displayBooks();
    Member m1("vaibhav", "davorlim");
    m1.displayMemberInfo();
    l1.addMember(m1);
    l1.displayMembers();
    
    return 1;
}