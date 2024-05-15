#include<iostream>
#define MAX 12
using namespace std;
class Sort{
    int a[MAX];
    int n,
    j=1;
public:
    Sort();
    int Partition(int a[],int,int);
    void QuickSort(int a[],int,int);
    void display();
};
Sort::Sort(){
    int i;
    cout<<"Enter the no. of terms you want : ";
    cin>>n;
    cout<<"\nEnter any "<<n<<" elements"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    QuickSort(a,0,n-1);
}
void Sort::QuickSort(int a[],int lb,int ub){
    int p;
    if(lb<ub){
        p=Partition(a,lb,ub);
        QuickSort(a,lb,p-1);
        QuickSort(a,p+1,ub);
    }
}
int Sort::Partition(int a[],int lb,int ub){
    int s=lb,e=ub;
    int p=a[lb],t;
    while(s<e){
        while(a[s]<=p)
            s++;
        while(a[e]>p)
            e--;
        if(s<e){
            t=a[e];
            a[e]=a[s];
            a[s]=t;
        }
    }
    t=a[lb];
    a[lb]=a[e];
    a[e]=t;

    return e;
}
void Sort::display(){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main(){
    int c;
    Sort s;
    s.display();
    return 0;
}
