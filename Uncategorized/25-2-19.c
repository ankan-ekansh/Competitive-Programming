#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long int cd[50][100]={{526412,2305,1234,10000},{123456,2207,7321,4000},{459134,2006,9534,20000},{432512,2401,1234,3000},{345211,2209,3421,50000}};
    char name[50][100]={"ROHAN","SHIRISH","AMIT","PRANITH","REHAN"};
    int nc=5,nd=4;
    int i,j;
    char w=0;
    while(1){
        int choice;
        printf("\nEnter\n1 To insert new card number,\n2 To display all details of card holder having amount more than 10000 \n3 To delete records of entered name\n4 To find names of all customers who has amount less than 20000\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter your card number\n");
            long int cno;
            scanf("%ld",&cno);
            int found = 0;
            for(i=0;i<nc;i++){
                if(cd[i][0]==cno){
                    found = 1;
                    break;
                }
            }
            if(found == 1){
                printf("Card already exists!!\n");
                exit(0);
            }
            else{
                printf("Card does not exist. Please enter your card details as prompted\n");
                cd[nc][0]=cno;
                printf("Enter expiry date, pin, amount and name\n");
                scanf("%ld %ld %ld %s",&cd[nc][1],&cd[nc][2],&cd[nc][3],&name[nc]);
                nc++;
                printf("Card details added successfully\n");
            }
            break;
        case 2:
            printf("\nS.No.\tName\tCard Number\tExpiry Date\tPIN\tAmount\n\n");
            for(i=0;i<nc;i++){
                if(cd[i][3]<10000){
                    printf("%d\t%s\t%ld\t\t%ld\t\t%ld\t%ld\n",i+1,name[i],cd[i][0],cd[i][1],cd[i][2],cd[i][3]);
                }
            }
            break;
        case 3:
            printf("Enter name of the card holder whose record is to be deleted\n");
            char delName[100];
            scanf("%s",&delName);
            int delPos=-1;
            for(i=0;i<nc;i++){
                if(!strcmpi(delName,name[i])){
                    delPos = i;
                    break;
                }
            }
            if(delPos == -1){
                printf("Name does not exist\n");
            }
            else{
                for(i=delPos;i<nc;i++){
                    long int temp;

                    temp = cd[i][0];
                    cd[i][0]=cd[i+1][0];
                    cd[i+1][0]=temp;

                    temp=cd[i][1];
                    cd[i][1]=cd[i+1][1];
                    cd[i+1][1]=temp;

                    temp=cd[i][2];
                    cd[i][2]=cd[i+1][2];
                    cd[i+1][2]=temp;

                    temp = cd[i][3];
                    cd[i][3]=cd[i+1][3];
                    cd[i+1][3]=temp;

                    char ctemp[100];

                    strcpy(ctemp,name[i]);
                    strcpy(name[i],name[i+1]);
                    strcpy(name[i+1],ctemp);
                }
                nc--;
            }
            break;
        case 4:
            printf("The names of customers having amount less than 20000 are: \n");
            for(i=0;i<nc;i++){
                if(cd[i][3]<20000){
                    printf("%s \n",name[i]);
                }
            }
            break;
        case 5:
            printf("\nS.No.\tName\tCard Number\tExpiry Date\tPIN\tAmount\n\n");
            for(i=0;i<nc;i++){
                printf("%d\t%s\t%ld\t\t%ld\t\t%ld\t%ld\n",i+1,name[i],cd[i][0],cd[i][1],cd[i][2],cd[i][3]);
            }
            break;
        }
        printf("\n");
        printf("Do you wish to go to the menu again?(Y/N)?");
        fflush(stdin);
        scanf("%c",&w);
        if(w=='Y'||w=='y')
            continue;
        else if(w=='N'||w=='n')
            break;
    }
    return 0;
}
