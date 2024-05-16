#include <iostream> 
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Book{

    private:
        static int count;
        int bookID;


    public :
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


        bool operator<(const Book& lhs)const {
                return title < lhs.title;
            }


        bool operator==(const Book& other) const {
                return title == other.title;
            }


    };




class Member{

    private:
        static int count1;
        int memberID;


    public:

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

        bool operator<(const Member& other) const {
                return name < other.name;
            }

        bool operator==(const Member& other) const {
                return name == other.name;
            }



    };


int Member::count1=2000;
int Book::count=1000;

class Library{

    private:
        vector<Book> books;
        vector<Member> members;
        map<Member,vector<Book>> records;
        string library_name;


    public:
        

        Library(string name){
                this->library_name=name;
            }


        void addBook(Book b){
                this->books.push_back(b);
            }


        void removeBook(Book b){   

                vector<Book>::iterator cur_book;
                cur_book=find(books.begin(),books.end(),b);

                auto it = this->books.begin(); 
                
                while (it != this->books.end()) {

                        if (it == cur_book) {

                                books.erase(it);
                                cout<<"Book removed from the Library"<<endl;
                                break;
                            
                        }else 
                                ++it; 
                            
                    } 

            }

        void issueBook(Member m ,Book b) {
        

            vector<Book>::iterator cur_book;
            cur_book = find(books.begin(),books.end(), b);

            vector<Member>::iterator cur_mem;
            cur_mem=find(members.begin(),members.end(),m);


            if (cur_book != books.end() && cur_mem!=members.end()) {               
                    if(cur_book->isIssued==true)
                            cout<<"sorry book is alredy issued "<<endl;
                    else
                        {
                            this->records[m].push_back(b);
                            cout<<"Book is successfully issued "<<endl;
                            cur_book->isIssued=true;
                        }
                }
            else if(cur_book != books.end() && cur_mem==members.end())
                cout<<"you are not a member "<<endl;
            else if (cur_book == books.end() && cur_mem!=members.end())
                cout<<"book is not available in this libarary "<<endl;
            else 
                cout<<"neither book nor you are part of this libarary"<<endl;
            
        }

        void returnBook(Member m, Book b){

            vector<Book>::iterator cur_book;
            cur_book = find(books.begin(),books.end(), b);


            for(auto& pair : records) {
                    auto& vec = pair.second;
                    vec.erase(std::remove(vec.begin(), vec.end(), b), vec.end());
                    cout<<"Book Returned Successfully"<<endl;
                    cur_book->isIssued=false;

                }

            }

        void displayBooks(){
            for (const auto& book : this->books)            
                    cout<<book.title<<" "<<book.author<<" "<<book.isIssued<<endl;       
            }

        void displayRecords(){


                    map<Member, vector<Book>>::iterator pair = records.begin();
                
                    while (pair != records.end()) {
                
                            cout<<"Member name : "<<pair->first.name<<" , Books owned : ";
                            vector<Book>::iterator pair1=pair->second.begin();

                            while(pair1!= pair->second.end()){

                                    cout<<pair1->title<<"  ";
                                    pair1++;

                                }

                            cout <<endl;
                            pair++;
                }
            }

        void addMember(Member m){
                this->members.push_back(m);
            }

        void displayMembers(){
                for (const auto& member : this->members)            
                    cout<<member.name<<endl;               
            }


    };


int main(){

  Library l1("South District Library");

    Book b1("DBMS", "Korth", "Delhi");
    Book b2("Computer Networks", "Tannenbaum", "USA");
    Book b3("Irodov", "Bansal", "Kota");
    Book b4("Maths", "RD Sharma", "Punjab");
    Book b5("Data Structures", "Cormen", "Boston");
    Book b6("Operating Systems", "Silberschatz", "New York");
    Book b7("Algorithms", "Knuth", "California");

 // b4.displayInfo();

 Member m1("vaibhav","curtorim");
 Member m2("Sachin","navelim");
 Member m3("srujana","panjim");
 Member m4("sahil","margao");

//  m1.displayMemberInfo();

l1.addBook(b1);
l1.addBook(b2);
l1.addBook(b3);
l1.addBook(b4);
l1.addBook(b5);
l1.addBook(b6);

// l1.displayBooks();

l1.addMember(m1);
l1.addMember(m2);

// l1.displayMembers();

l1.issueBook(m1,b2);
l1.issueBook(m1,b1);
l1.issueBook(m1,b3);
l1.issueBook(m2,b6);
l1.issueBook(m2,b5);

//l1.displayRecords();

// l1.removeBook(b1);
// l1.removeBook(b2);

// l1.displayBooks();

// l1.returnBook(m1,b3);

// l1.displayRecords();

// l1.issueBook(m2,b3);

// l1.displayRecords();

Library l2("North District Libarary");

l2.addBook(b1);
l2.addBook(b2);
l2.addBook(b3);
l2.addBook(b4);
l2.addBook(b5);
l2.addBook(b6);

l2.addMember(m3);
l2.addMember(m4);

l2.issueBook(m4,b2);
l2.issueBook(m4,b1);
l2.issueBook(m4,b3);
l2.issueBook(m4,b6);
l2.issueBook(m4,b5);
    
l2.issueBook(m3,b1);
l2.displayRecords();
cout<<"wait"<<endl;
l2.returnBook(m3,b1);
l2.returnBook(m4,b1);
cout<<"wait"<<endl;
l2.issueBook(m3,b2);
l2.displayRecords();

    //bug even if x member doesnt own y book , it is returning it 
    return 1;
}