#include<iostream>
#define MAX 10
using namespace std;
class Sort{
    int a[MAX];
    int n,s;
public:
    Sort();
    void merge(int a[],int,int);
    void Mergesort(int a[],int,int,int);
    void display();
};
Sort::Sort(){
    int i;
    s=1;
    cout<<"Enter the no. of elements you want to store : ";
    cin>>n;
    cout<<"\nEnter any "<<n<<" elements"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    merge(a,0,n-1);
}
void Sort::merge(int a[],int lb,int ub){
    int m;
    if(lb<ub){
        m=(lb+ub)/2;
        merge(a,lb,m);
        merge(a,m+1,ub);
        Mergesort(a,lb,m,ub);
    }
}
void Sort::Mergesort(int a[],int lb,int m,int ub){
    int i=lb,k=lb,j=m+1;
    int b[MAX];
    while((i<=m)&&(j<=ub)){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=ub)
        b[k++]=a[j++];
    for(int p=lb;p<k;p++)
        a[p]=b[p];
    cout<<"\n\nThe sorted array after "<<s<<" iteration is as follows"<<endl;
    display();
    s++;
}
void Sort::display(){
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t\t";
}
int main(){
    Sort s;
    return 0;
}
