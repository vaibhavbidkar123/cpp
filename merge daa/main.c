#include <stdio.h>

#define max 10
int arr[max];
void merge (int lb1,int mid1,int ub1){
    int i=lb1,k=mid1,j=ub1;
    int b[max];
    while(i<=mid1&&j<=ub1)
    {
        if(arr[i]<arr[j])
            b[k++]=arr[i++];
        else
            b[k++]=arr[j++];
    }
    while(i<=mid1)
        b[k++]=arr[i++];
    while(j<=ub1)
        b[k++]=arr[j++];
    for(int p=lb1;p<k;p++)
        arr[p]=b[p];
}



void mergesort(int array,int lb,int ub){
int mid;
mid=(lb+ub)/2;
mergesort(lb,mid);
mergesort(mid+1,ub);
merge(lb,mid,ub);
}

int main(){


printf("enter the elements \n");
for(int i=0;i<max;i++){

    scanf("%d",&arr[i]);


}
mergesort(arr,0,max)



return 0;
}
