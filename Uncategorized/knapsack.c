#include<stdio.h>
#include<stdlib.h>
int main(){
    float profit[5]={15,10,24,30,6};
    float weight[5]={3,2,4,6,3};
    float pd[5]={0.0};  //pd = profit density or profit/weight
    int i,j;
    float w=12.0;
    float tw=0.0,tp=0.0;
    for(i=0;i<5;i++){
        pd[i]=profit[i]/weight[i];
    }
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(pd[i]<pd[j]){
                float temp = pd[i];
                pd[i]=pd[j];
                pd[j]=temp;

                temp = profit[i];
                profit[i]=profit[j];
                profit[j]=temp;

                temp = weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
            }
        }
    }
    for(i=0;i<5;i++){
        if(tw+weight[i]<=w){
            tp=tp+profit[i];
            tw+=weight[i];
        }
        else{
            tp=tp+((w-tw)*pd[i]);
            tw+=w-tw;
            break;
        }
    }
    printf("Total profit:%f\tTotal weight:%f\n",tp,tw);

    return 0;
}
