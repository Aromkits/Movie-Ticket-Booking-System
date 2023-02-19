#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 256

typedef struct{
    char id[20],pass[20];
}member;

typedef struct{
    int price,code,seat;
    char name[60],date[20],time[20],theater[2],fromfile[20];
}movie;

FILE *fptr,*fp,*fp1,*fp2,*fptr1,*fptr2,*fptr3,*fptr4;
int count,count1,count2,vcount = 0,code1 = 1000;
int i,j,q,k;
int choice,a=0,b=0;
char ch;

member signin;
movie data[100],fromS[300];

int countline(){
    fp = fopen("login.txt","r");
    int ch1;
    count=0;
    do{
        ch1 = fgetc(fp);
        if(ch1 == '\n')
            count++;
    }while( ch1 != EOF );
    fclose(fp);
    return count;
}

int countline1(){
    fp1 = fopen("movie.txt","r");
    int ch2;
    count1 = 0;
    do{
        ch2 = fgetc(fp1);
        if(ch2 == '\n')
            count1++;
    }while( ch2 != EOF );
    fclose(fp1);
    return count1;
}

int countline2(){
    fp1 = fopen("sales.txt","r");
    int ch3;
    count2 = 0;
    do{
        ch3 = fgetc(fp1);
        if(ch3 == '\n')
            count2++;
    }while( ch3 != EOF );
    fclose(fp1);
    return count2;
}

int readmovie(){
    countline1();
    fp2 = fopen("movie.txt","r");
    for(i=0;i<count1;i++){
        fscanf(fp2,"%s %s %s %s %d\n",data[i].name,data[i].theater,data[i].date,data[i].time,&data[i].price);
    }
    fclose(fp2);
}

char creatid(){
    system("cls");
    countline();
    member checkid[count];
    printf("\n\n");
    printf("     __________________________________________________\n\n");
    printf("     ||                CREATE ACCOUNT               ||\n");
    printf("     __________________________________________________\n\n");
    printf(" \n                   ENTER USERNAME: ");
    scanf("%s",signin.id);
    printf(" \n\n                   ENTER PASSWORD: ");
    scanf("%s",signin.pass);

    fp = fopen("login.txt","r");
    if(fp == NULL){
        fprintf(fp,"%s %s\n",signin.id,signin.pass);
    }
    for(i=0;i<count;i++){
        fscanf(fp,"%s %s",checkid[i].id),checkid[i].pass;
    }
    fclose(fp);


    countline();
    for(i=0;i<count;i++){
        if(strcmp(signin.id,checkid[i].id) == 0){
            return printf("\n  user id already exist plz enter another user id\n\n");
        }
    }
        fptr = fopen("login.txt","a");
        fprintf(fptr,"%s %s\n",signin.id,signin.pass);
        fclose(fptr);
        countline();
        printf("  \n\n                     SUCCESS!!!!!!!\n\n");
}

char login(){
    system("cls");
    countline();
    member readid[count];
    fp = fopen("login.txt","r");

    if(fp == NULL){
        creatid();
        return 0;

    }

    for(i=0;i<count;i++){
        fscanf(fp,"%s %s",readid[i].id,readid[i].pass);
    }
    fclose(fp);

    printf("\n\n");
    printf("     =====================================================\n");
    printf("     ||                      LOGIN                      ||\n");
    printf("     =====================================================\n");
    printf(" \n\n                  ENTER USERNAME: ");
    scanf("%s",signin.id);
    printf(" \n\n                  ENTER PASSWORD: ");
    scanf("%s",signin.pass);

    for(i=0;i<count;i++){
        if(strcmp(signin.id,readid[i].id) == 0 && strcmp(signin.pass,readid[i].pass) == 0){
            a = 1;
            return printf("  \n\n                  LOGIN IS SUCCESS!!\n\n");
        }
        else{
            a = 2;

        }
    }

    if(a==2){
        return printf("  \n\n                SORRY LOGIN IS UNSUCCESS!!\n\n");
    }
}

int firtsmenu(){
    system("cls");
	printf("\n\n");
	printf("     =====================================================\n");
    printf("     ||           Movie Ticket Booking System           ||\n");
    printf("     =====================================================\n");
    printf("     ||     1- Only admin:                              ||\n");
	printf("     ||     2- Sign in to puchase ticket:               ||\n");
	printf("     ||     3- Create Account:                          ||\n");
	printf("     ||     0- Exit system:                             ||\n");
    printf("     =====================================================\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
    system("cls");

	return choice;
}

int secondmenu(){
    system("cls");
    printf("\n\n");
    printf(" ====================================================================\n");
    printf(" ||                 Movie Ticket Booking System                    ||\n");
	printf(" ====================================================================\n");
	printf(" ||             1- To puchase ticket:                              ||\n");
	printf(" ||             2- To cancel the seat:                             ||\n");
	printf(" ||             0- Sign Out:                                       ||\n");
	printf(" ||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	system("cls");

	return choice;
}

int admin(){
    system("cls");
    char pass[10],setpass[10]= "1234";
    printf("\n\n");
    printf("     =====================================================\n");
    printf("     ||                      ADMIN                       ||\n");
    printf("     =====================================================\n");
    printf(" \n\n                  ENTER PASSWORD: ");
    scanf("%s",&pass);

    if (strcmp(pass,setpass)==0){
        b = 1;
        return printf("\n\n                      SUCCESSFUL!!\n\n");
    }
    else{
        b = 2;
        return printf("\n               The entered password is wrong!\n\n");
    }
	system("cls");
}

int menuforadmin(){
    system("cls");
    printf("\n\n");
    printf(" ====================================================================\n");
    printf(" ||                            ADMIN                               ||\n");
	printf(" ====================================================================\n");
	printf(" ||             1- Add Movie:                                      ||\n");
	printf(" ||             2- Delete Movie:                                   ||\n");
	printf(" ||             3- Change detail of movie:                         ||\n");
	printf(" ||             4- Revenue:                                        ||\n");
	printf(" ||             0- Sign Out:                                       ||\n");
	printf(" ||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	system("cls");

	return choice;
}

int addmovie(){
    system("cls");
    int num = 0;
    char yn[2];

    printf("\n\n");
    printf(" ====================================================================\n");
    printf(" ||                          ADD MOVIE                             ||\n");
	printf(" ====================================================================\n");
    do{
       printf("\nEnter Name Movie: ");
       scanf("%s",data[num].name);
       printf("\nEnter Name Theater: ");
       scanf("%s",data[num].theater);
       printf("\nEnter Name Date: ");
       scanf("%s",data[num].date);
       printf("\nEnter Name Time: ");
       scanf("%s",data[num].time);
       printf("\nEnter Name Price: ");
       scanf("%d",&data[num].price);
       printf("\nAdd more movies?(y,n): ");
       scanf("%s",&yn);
       num++;
    }while(strcmp(yn,"y") == 0 || strcmp(yn,"Y") == 0);

    FILE *fpt = fopen("movie.txt","a");
    for(i=0; i<num; i++){
        fprintf(fpt,"%s %s %s %s %d\n",data[i].name,data[i].theater,data[i].date,data[i].time,data[i].price);
    }
    fclose(fpt);
}

int deletemovie(){
    int lno, ctr = 0; q = 1;
    char fname[] = "movie.txt";
    char str[MAX], temp[] = "temp.txt";
    printf("\n\n");
    printf(" ====================================================================\n");
    printf(" ||                         Delete Movie                           ||\n");
	printf(" ====================================================================\n");
	readmovie();
    printf("\n Before You Delete  \n\n");

    for(i=0;i<count1;i++){
        printf("%d %s %s %s %s %d\n",q,data[i].name,data[i].theater,data[i].date,data[i].time,data[i].price);
        q++;
    }

    fptr1 = fopen(fname, "r");
    if (!fptr1){
            printf(" File not found or unable to open the input file!!\n");
        }

    fptr2 = fopen(temp, "w");
        if (!fptr2){
            printf("Unable to open a temporary file to write!!\n");
            fclose(fptr1);
        }

    printf("\n Delete A Line Of Movie: ");
    scanf("%d", &lno);

    while (!feof(fptr1)){
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1)){
            ctr++;
            if (ctr != lno){
                fprintf(fptr2, "%s", str);
            }
        }
    }

    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(temp, fname);

    fptr1=fopen(fname,"r");
    ch=fgetc(fptr1);
    printf("\n After You Delete : \n\n");

    while(ch!=EOF){
        printf("%c",ch);
        ch=fgetc(fptr1);
    }

    fclose(fptr1);
    printf("\n");
}

int modiflymovie(){
    int line; q = 1;
	printf("\n\n");
    printf(" ====================================================================\n");
    printf(" ||                        MODIFLY MOVIE                           ||\n");
	printf(" ====================================================================\n");
	printf(" ||             1- Modifly Name:                                   ||\n");
	printf(" ||             2- Modifly Theater:                                ||\n");
	printf(" ||             3- Modifly Date:                                   ||\n");
	printf(" ||             4- Modifly Price:                                  ||\n");
	printf(" ||             0- End Modifly:                                    ||\n");
	printf(" ||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);

	readmovie();

	while(1){
        for(i=0;i<count1;i++){
            printf("%d %s %s %s %s %d\n",q,data[i].name,data[i].theater,data[i].date,data[i].time,data[i].price);
            q++;
        }
        if(choice == 1){
            printf("\n  Enter Line Of Movie: ");
            scanf("%d",&line); line -= 1;
            printf("\n  Enter Name: ");
            scanf("%s",data[line].name);
            break;
        }
        else if(choice == 2){
            printf("\n  Enter Line Of Movie: ");
            scanf("%d",&line); line -= 1;
            printf("\n  Enter Theater: ");
            scanf("%s",data[line].theater);
            break;
        }
        else if(choice == 3){
            printf("\n  Enter Line Of Movie: ");
            scanf("%d",&line); line -= 1;
            printf("\n  Enter Date: ");
            scanf("%s",data[line].date);
            break;
        }
        else if(choice == 4){
            printf("\n  Enter Line Of Movie: ");
            scanf("%d",&line); line -= 1;
            printf("\n  Enter Price: ");
            scanf("%d",&data[line].price);
            break;
        }
        else if(choice == 0){
            break;
        }
        else{
            printf("\n\n      Choice not available\n\n");
            break;
        }
	}

	FILE *fpt = fopen("movie.txt","w");
    for(i=0; i<count1; i++){
        fprintf(fpt,"%s %s %s %s %d\n",data[i].name,data[i].theater,data[i].date,data[i].time,data[i].price);
    }

    fclose(fpt);
}

int showmovie(){
    readmovie(); q = 1;
    countline1();
    for(i=0;i<count1;i++){
        printf("\n\n");
        printf(" __________________________________________________\n\n");
        printf("                    ALL MOVIE                      \n");
        printf(" __________________________________________________\n\n");
        printf("  Enter %d                                     \n",q);
        printf("  Movie: %s                                    \n",data[i].name);
        printf("  Details: Theater%s                           \n",data[i].theater);
        printf("         : %s                                  \n",data[i].date);
        printf("         : %s                                  \n",data[i].time);
        printf("         : %d BATH                             \n",data[i].price);
        printf(" __________________________________________________\n");
        q++;
    }
	printf("  Enter your choice: ");
	scanf("%d",&choice);

	return choice;

}
void reservation(int *array,int slection){
    system("cls");
    printf("\n\nYou Choose: %s\n",data[slection-1].name);
    printf("\n                                SCREEN\n\n\n");
    for (k=1;k<=100;k++){
        if (array[k]==0){
            printf("%d\t",k);
        }
        else{
            printf("*\t",k);
        }
        if(k%10==0){
            printf("\n\n");
        }
    }

    printf("Which seat number you want?: ");
    scanf("%d",&j);
    if(j>100||j<1){
        printf("seat1 number is unavailable in this theater\n");
        printf("Please re-enter seat number: ");
        scanf("%d",&j);
    }
    if(array[j]==1){
        printf("Sorry, this ticket is already booked! Please choose another seat: ");
        scanf("%d",&j);
    }
    else{
        array[j]=1;
    }

    data[vcount].seat =j ;
    data[vcount].code = code1;
    code1++;

    data[slection-1].code = data[vcount].code;
    data[slection-1].seat = data[vcount].seat;
    readmovie();
    fptr4 = fopen("sales.txt","a");
    fprintf(fptr4,"%s %d %s %s %s %s %d %d\n",signin.id,data[slection-1].code,data[slection-1].name,data[slection-1].theater,data[slection-1].date,data[slection-1].time,data[slection-1].seat,data[slection-1].price);
    fclose(fptr4);

    printf("\n\n");
    printf(" __________________________________________________\n\n");
    printf("                     Your Ticket                     \n");
    printf(" __________________________________________________\n\n");
    printf("  Booking ID: %d                                     \n",data[slection-1].code);
    printf("  Username: %s                                    \n",signin.id);
    printf("  Movie Title: %s                                    \n",data[slection-1].name);
    printf("  Theater   : Theater%s                           \n",data[slection-1].theater);
    printf("  Date      : %s                                  \n",data[slection-1].date);
    printf("  Time      : %s                                  \n",data[slection-1].time);
    printf("  Seats No. : %d                                  \n",data[slection-1].seat);
    printf("  Price     : %d BATH                             \n",data[slection-1].price);
    printf(" __________________________________________________\n");
}

void cancel(int *array,int slection){
    int w = 0;
    int ctr = 0; q = 1;
    char fname[] = "sales.txt";
    char str[MAX], temp[] = "temp.txt";
    system("cls");
    readmovie();
    countline2();
    fp = fopen("sales.txt","r");
    for(i=0;i<count1;i++){
        fscanf(fp,"%s %d %s %s %s %s %d %d\n",fromS[i].fromfile,&fromS[i].code,fromS[i].name,fromS[i].theater,fromS[i].date,fromS[i].time,&fromS[i].seat,&fromS[i].price);
    }
    fclose(fp);

    int Cseat,stop;
    printf("\n\nYou Choose: %s\n",data[slection-1].name);
    printf("Please enter ID number of ticket: ");
    scanf("%d",&Cseat);
    for (i=0;i<300;i++){
        if(Cseat == fromS[i].code && strcmp(signin.id,fromS[i].fromfile) == 0){
            stop=5;
            system("cls");
            printf("\n\n your seat is %d cancelled\n",fromS[i].seat);
            array[fromS[i].seat]=0;
            i = 300;
        }
    w++;
    }
    if (stop!=5){
        printf("\n\nTicket ID number is incorrect please enter right one to cancel ticket: \n");
    }
    else if(stop == 5){
        fptr1 = fopen(fname, "r");
        if (!fptr1){
            printf(" File not found or unable to open the input file!!\n");
        }

        fptr2 = fopen(temp, "w");
        if (!fptr2){
            printf("Unable to open a temporary file to write!!\n");
            fclose(fptr1);
        }

        while (!feof(fptr1)){
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)){
                ctr++;
                if (ctr != w){
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);
    }
}

int Revenue(){
    countline2();
    int total = 0; q = 1;
    fptr = fopen("sales.txt","r");
    for(i=0;i<count2;i++){
        fscanf(fptr," %s %d %s %s %s %s %d %d\n",fromS[i].fromfile,&fromS[i].code,fromS[i].name,fromS[i].theater,fromS[i].date,fromS[i].time,&fromS[i].seat,&fromS[i].price);
        total += fromS[i].price;
    }
    fclose(fptr);

        printf("\n\n");
        printf(" __________________________________________________\n\n");
        printf("                     REVENUE                       \n");
        printf(" __________________________________________________\n\n");
        for(i=0;i<count2;i++){
        printf(" %d %s %d %s %s %s %s %d %d\n",q,fromS[i].fromfile,fromS[i].code,fromS[i].name,fromS[i].theater,fromS[i].date,fromS[i].time,fromS[i].seat,fromS[i].price);
        q++;
    }
    printf("\n A total of %d tickets are sold.\n",q-1);
    printf(" Total Amount Is %d Bath\n\n",total);
}

int main(){
    int frommenu,x = -1,x1 = -1,x2 = -1;
    int **seat,slection;
	seat=(int **)calloc(101,sizeof(int *));
	countline1();
	for (i=0;i<count1;i++){
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	}

    while(x != 0){
        frommenu = firtsmenu();
		switch(frommenu){
			case 1:
			    while(1){
				admin();
                    if(b == 1){
                        system("PAUSE");
                        break;
                    }
                    else{
                        system("PAUSE");
                        continue;
                    }
			    }
			    while(x2 != 0){
                    frommenu = menuforadmin();
                    switch(frommenu){
                        case 1:
                            frommenu = addmovie();
                            break;
                        case 2:
                            deletemovie();
                            system("PAUSE");
                            break;
                        case 3:
                            modiflymovie();
                            system("PAUSE");
                            break;
                        case 4:
                            Revenue();
                            system("PAUSE");
                            break;
                        case 0:
                            x2 = 0;
                            break;
                        default:
                        printf("\n\n      Choice not available\n\n");
                        system("PAUSE");
                        break;
                    }
			    }
			    x2 = -1;
				break;
			case 2:
			    while(1){
                    login();
                    if(a == 1){
                        system("PAUSE");
                        break;
                    }
                    else{
                        system("PAUSE");
                        continue;
                    }
			    }
			    while(x1 != 0){
                    frommenu = secondmenu();
                    switch(frommenu){
                        case 1:
                            frommenu = showmovie();
                            if(frommenu > count1){
                                printf("\n  Movie Have %d !!!\n\n",count1);
                                system("PAUSE");
                                continue;
                            }
                            else{
                                reservation(seat[frommenu-1],frommenu);
                                vcount++;
                                system("PAUSE");
                                break;
                            }
                        case 2:
                            frommenu=showmovie();
                            if(frommenu > count1){
                                printf("\n  Movie Have %d !!!\n\n",count1);
                                system("PAUSE");
                                continue;
                            }
                            else{
                                cancel(seat[frommenu-1],frommenu);
                                system("PAUSE");
                                break;
                            }
                        case 0:
                            x1 = 0;
                            break;
                        default:
                        printf("\n\n      Choice not available\n\n");
                        system("PAUSE");
                        break;
                    }
			    }
			    x1 = -1;
				break;
			case 3:
				creatid();
				system("PAUSE");
				break;
			case 0:
				x = 0;
				break;
			default:
				printf("\n\n     Choice not available\n\n");
				system("PAUSE");
				break;
		}
    }
    return 0;
}
