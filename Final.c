#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{

	int pt_id;
	int pt_age;
	char pt_reservation[20];
	char pt_name[40];
	char pt_gender;
}ptdata;


// take admin password
int TakeAdminPassword(void)
{
    int correctPasswardFlag=0;
    int pernum,pass,attemps=1;
		while (attemps<=3)
		{
            printf("you choosed Admin Permissions.\nto return to the privois menu Enter '0'\nPlease enter the password : ");
			scanf("%d",&pass);

			 if (attemps > 3)
			{
				printf("you ran out of attemps , \nRESTRATING PROGRAM.......");
				break;
			}
			if (pass == 0)
                {
                     printf("\nYou are Out of Admine mode\n");
                    break;
                }
           else if (pass!=1234)
                {
                    printf("\nWrong password , please try again.\n ");
                    attemps++;
                }
            else if (pass == 1234)
                {
                    printf("\nyou got Admin Permissions.\n");
                    correctPasswardFlag=1;
                    break;
                }
		}
    return correctPasswardFlag;
}



//  Admin operation "select"
int AdminOperationSelector(void)
{
    int oper=0;
    do{
	printf("\n1-Add\n2-Edit\n3-Reseiving\n4-Cancel\nPriss '0' to calcle\nChoose what you want? ");
	scanf("%d",&oper);
    if (oper == 0)
    {
        break;
    }
    }while(oper<1 || oper>4);
    return oper;
}



// 1-Add
void addInfo(ptdata *ptr, int i )
{
	printf("\nID of patient no#%d : ",i+1);
	scanf(" %d",&ptr[i].pt_id);
	printf("\nAge of patient no#%d : ",i+1);
	scanf(" %d",&ptr[i].pt_age);
	printf("\nName of patient no#%d : ",i+1);
	scanf(" %s",&ptr[i].pt_name);
	printf("\nGender of patient no#%d (enter 'm' for Male, 'f' for female : ",i+1);
	scanf("%s",&ptr[i].pt_gender);

}



// Linear Search
int l_s(ptdata *ptr,int input_ID, int size )
{
	int index= -1;
	for(int i=0; i < size; i++)
	{
		if(input_ID == ptr[i].pt_id)
		{
			index= i;
			break;
		}
	}
	return index;
}



//2-Edit
void editInfo(ptdata *ptr,int input_ID)
{
	int edc;

do {
		printf("what you wanna edit? \n1-ID\n2-Name\n3-Age\n4-Gender\n5-Cancle\n");
		scanf("%d",&edc);
		switch (edc)
		{
			case 1:
			{

				printf("\nEnter the NEW ID : ");
				scanf("%d",&ptr[input_ID].pt_id);
				break;
			}
			case 2:
			{
				printf("\nEnter the NEW Name : ");
				scanf("%s",&ptr[input_ID].pt_name);
				break;
			}
			case 3:
			{
				printf("\nEnter the NEW Age : ");
				scanf("%d",&ptr[input_ID].pt_age);
				break;
			}
			case 4:
			{
				printf("\nEnter the NEW Gender : ");
				scanf("%s",&ptr[input_ID].pt_gender);
				break;
			}
			default:
			printf("\nINCORRECT CHOISE\n");
			break;
		}
	}while(edc!=5);
}




//3-Reseiving
void TimeReservatoin(ptdata *ptr,int size ,int *copy_Aintreservation)
{
    int TimeSelector= -1;
    int ID ,IdIndex;
    do{
         printf("\nEnter the ID: ");
         scanf("%d",&ID);
        IdIndex=l_s(ptr,ID,size);
        if(IdIndex== -1)
        {
            printf("\nWrong ID Please Entre a correct ID\n");
        }

    }while(IdIndex== -1);
    char pp1[20]= "2pm to 2:30pm";
    char pp2[20]= "2:30pm to 3pm";
    char pp3[20]= "3pm to 3:30pm";
    char pp4[20]= "4pm to 4:30pm";
    char pp5[20]= "4:30pm to 5pm";
	
    printf( "5 available slots:\n1- 2pm to 2:30pm\n2- 2:30pm to 3pm\n3- 3pm to 3:30pm\n4- 4pm to 4:30pm\n5- 4:30pm to 5pm\n");
    scanf("%d",&TimeSelector);
    if(TimeSelector>0 && TimeSelector<=5)
    {
       switch(TimeSelector)
        {
           case 1:
		   {
		        strcpy(ptr[IdIndex].pt_reservation,pp1);
		        break;
		   }
           case 2:
		   {
		      strcpy(ptr[IdIndex].pt_reservation,pp2);
		       break;
		   }
           case 3:
		   {
		      strcpy(ptr[IdIndex].pt_reservation,pp3);
		      break;
		   }
           case 4:
		   {
		      strcpy(ptr[IdIndex].pt_reservation,pp4);
		      break;
		   }
           case 5:
		   {
			   strcpy(ptr[IdIndex].pt_reservation,pp5);
		       break;
		   }
            default :
			{
				break;
			}

        }

        copy_Aintreservation[TimeSelector-1]=ID;

    }
}



//4-Cancel // edit
void DeleteReservatoin(ptdata *ptr,int size ,int *copy_Aintreservation)
{
    int IdIndex;
    int ID ;
    do{
         printf("\nEnter the ID: ");
         scanf("%d",&ID);
         IdIndex=l_s(ptr,ID,size);
        if(IdIndex== -1)
        {
            printf("\nWrong ID Please Entre a correct ID\n");
        }
        else
        {
			for (int j=0 ; j<5 ; j++)
			{
		      if( copy_Aintreservation[j] == ptr[IdIndex].pt_id)
			  {
				  copy_Aintreservation[j] =0;
				  break;
			  }
			}

              *ptr[IdIndex].pt_reservation =0;
        }
    }while(IdIndex == -1);

}



// user operation "select"
int userOperationSelector()
{
    int oper=0;
    do{
	printf("you got User Permissions.\n");
	printf("\n1- View patient record\n2-View today’s reservations\nPriss '0' to calcle\nChoose what you want? ");
	scanf("%d",&oper);
    if (oper == 0)
    {
        break;
    }
    }while(oper<1 || oper>2);
    return oper;

}


// View patient record
void ViewPatientRecord(ptdata *ptr,int size)
{
    int ID ,IdIndex;
    if (size !=0)
    {
        do{
            printf("\nEnter the ID: ");
            scanf("%d",&ID);
            IdIndex=l_s(ptr,ID,size);
            if(IdIndex== -1)
            {
                printf("\nWrong ID Please Entre a correct ID\n");
            }
        }while(IdIndex== -1);

        printf("\nID of patient no# %d : ",ptr[IdIndex].pt_id);
        printf("\nAge of patient no# %d : ",ptr[IdIndex].pt_age);
        printf("\nName of patient no# %s : ",ptr[IdIndex].pt_name);
        printf("\nGender of patient no# %c : ",ptr[IdIndex].pt_gender);
        printf("\nReservation of patient no# %s : ",ptr[IdIndex].pt_reservation);
    }
    else{
        printf("\nThere are no Data\n");
    }

}


//View today’s reservations
void ViewTodayResservation(int *copy_inputReservations)
{
    int i ,IdIndex;
    for(i=0; i<5; i++)
    {
        if(copy_inputReservations[i] !=0)
        {
            switch(i)
            {
                case 0:
                        printf("\n2pm to 2:30p ---> Patient ID %d\n",copy_inputReservations[i]);
                        break;
                case 1:
                        printf("\n2:30pm to 3pm ---> Patient ID %d\n",copy_inputReservations[i]);
                        break;
                case 2:
                        printf("\n3pm to 3:30pm ---> Patient ID %d\n",copy_inputReservations[i]);
                        break;
                case 3:
                        printf("\n4pm to 4:30pm ---> Patient ID %d\n",copy_inputReservations[i]);
                        break;
                case 4:
                        printf("\n4:30pm to 5pm ---> Patient ID %d\n",copy_inputReservations[i]);
                        break;
                        default:
                        break;

            }
        }
    }
}



// print data
void printStructure(ptdata *ptr,int size)
{
    for(int i=0;i<size; i++)
    {
        printf("\nID of patient :  %d\n",ptr[i].pt_id);
        printf("\nAge of patient:  %d\n",ptr[i].pt_age);
        printf("\nName of patient: %s\n",ptr[i].pt_name);
        printf("\nGender of patient: %c\n",ptr[i].pt_gender);
        
    }
}





int main ()
{
    int  i=0 , n=0 ;
    int pernum , reservaion[5]={0} ,userOprSelValue=0;
	int passFlagValue=0 , operationSelectorValue=0 ,  reEnterFlag =0 ;
	int inptuSearchID=0, SearchIDIndex=0;
	ptdata *ptr;
    ptr = (ptdata*) malloc(n*sizeof(ptdata));


while(1)
{

printf("\nwhat persmissions you wanna use ?\nType '0' for Admin ,type '1' for User\n ");
scanf("%d",&pernum);

	if (pernum==1)
	{

        userOprSelValue=userOperationSelector();
		switch(userOprSelValue)
        {
            case 1 :
                    ViewPatientRecord(ptr,i);
            break;

            case 2:
                    ViewTodayResservation(reservaion);
            break;

            default:
            printf("\nWrong Selection\n");
            break;

        }
	}
	else if (pernum== 0)
	{
		passFlagValue = TakeAdminPassword();
        if(passFlagValue ==1)
        {  operationSelectorValue = AdminOperationSelector();
            switch (operationSelectorValue)
            {
               case 1:
			  {
                    do{
                        addInfo(ptr,i);
                        i++;
                        printf("\nDo you want to add anther data press '1'\nif not press '0'\n");
                        scanf(" %d",&reEnterFlag);
                        }while(reEnterFlag != 0);

                        printStructure(ptr,i);
                break;
			  }

			  case 2:
			  {
                        do{
                            printf("\nPlease Enter the ID :- \n");
                            scanf("%d",&inptuSearchID);
                           SearchIDIndex = l_s(ptr,inptuSearchID,i);
                        }while(SearchIDIndex >= i);
                        if (SearchIDIndex < i)
                        {
                            editInfo(ptr,SearchIDIndex);
                        }
                    break;
			  }

			  case 3:
			  {
                    printf("\nYou are in the reservation mode\n");
                    TimeReservatoin(ptr,i,reservaion);
                    break;
			  }

              case 4:
			  {
                    printf("\nYou are in the Delete reservation mode\n");
                    DeleteReservatoin(ptr,i,reservaion);
                    break;
			  }

              default:
			  {
                break;
			  }

            }

		}


	}

	else
    {
        printf("\nyou entered wrong number.\n");
    }


}

}
















