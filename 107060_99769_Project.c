//107060 and 99769 

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define NUM 3
//functions of the project
void menu(int *choice);
void login(char ID[NUM][10],char password[NUM][20], char question[NUM][10], char answer[NUM][10], int *std, int *flag);
void enroll(char mail[NUM][30], char number[NUM][12], int *index);
void payfess(int *Total);
void change(char ID[], char mail[], char fname[], char lname[], char password[], char number[], char question[], char answer[]);
void Supply(double *cash_wallet);
void sortie(char ID[NUM][10], char mail[NUM][30], char fname[NUM][20], char lname[NUM][30], char password[NUM][20], char number[NUM][12], int balance[NUM], double cash_wallet[NUM], char question[NUM][10], char answer[NUM][10]);
void logout(int *choice);

int main(void){

    FILE *inp;

    inp = fopen("input.txt","r");

    int i, choice, flag, index, std=0, log;
    int Total;
    int type;
    int balance[NUM];
    double wallet;
    double cash_wallet[NUM];
    char ID[NUM][10],mail[NUM][30],fname[NUM][20],lname[NUM][30],password[NUM][20],number[NUM][12],question[NUM][10],answer[NUM][10];
    char line[300];
    //reading the content of the input file
    for(i=0;i<3;i++){
        fgets(line,300,inp);
        sscanf(line,"%s %s %s %s %s %s %d %lf %s %s", &ID[i], &mail[i], &fname[i], &lname[i], &password[i], &number[i], &balance[i], &cash_wallet[i], &question[i], &answer[i]);

    }


    fclose(inp);
    //calling the function menu to specify the student choice
    menu(&choice);
    switch(choice){
        case 1://the student choose to log in to AUI(his or her account)
            login ://using this log in (user defined) or identifier has a purpose to jump to it while using goto function in another part of the program
                login(ID,password,question,answer,&std,&flag);
                if(flag==0){//in case the user enter a correct ID but a wrong password
                    printf("You entered a incorrect password: \n");
                    menu(&choice);
                    switch(choice){
                        case 1:
                            goto login;//if the student choose to log in he or she will be directly jump to log in part(log in:)
                        break;
                        case 2:
                            goto enroll;//if the student choose to enroll he or she will be directly jump to enroll part (enroll:)
                        break;
                        case 3:
                            goto exit;//if the studemt choose to exit he or she will be directly jump to exit part (exit:)
                        break;
                    }
                }
                else if(flag==1){
                    printf("\nThe ID you entered doesn't exist!! \n");
                    // we used goto in this program as an unconditional jump from a part of the program to the another part of the program 
                    //here below the student will be jumped to enroll part
                    goto enroll;
                    //once the user enter a wrong ID he or she be moved to the enroll part
                    //goto function helps the directly movement or jump to enroll part after entering a wrong ID
                }   
                else if(flag==2){//the user enter both the correct ID and correct password
                    connection ://using this connection: (user defined) or identifier has a purpose to jump to it while using goto function in another part of the program
                        printf("\n                 Hello %s %s \n", fname[std], lname[std]);
                        printf("-------------------Welcome to Aui Portal-------------------\n");
                        printf("1. Change Information\n2. Pay fess\n3. Supply Cash Wallet\n");      
                        printf("------------------------------------------------------------\n");
                        printf("please choose your option : \n");
                        scanf("%d", &type);
                        switch(type){//the student enters the choice to peform a specific action
                            case 1://the student choose to change his or her information
                            //the function change apply the changes according to the student choice on which kind of information he or she would like to change
                                change(ID[std], mail[std], fname[std], lname[std], password[std], number[std], question[std], answer[std]);
                                printf("Do you want to log out :\n");
                                printf("Enter 1 if Yes\nEnter 2 if No \n");
                                scanf("%d", &log);
                                if(log==1){
                                    logout(&choice);
                                    switch(choice){
                                        case 1:
                                            goto login;//if the student choose to log in he or she will be directly jump to log in part(log in:)
                                        break;
                                        case 2:
                                            goto enroll;//if the student choose to enroll he or she will be directly jump to enroll part(enroll:)
                                        break;
                                        case 3:
                                            goto exit;//if the student choose to exit he or she will be directly jump to exit part(exit:)
                                        break;
                                    }
                                }
                                else{
                                    goto connection;
                                }
                            break;
                            case 2://the student choose to pay fess
                                payfess(&Total);
                                if(balance[std]>Total){//in case the amount in the balance is greater than the total price that the student should pay,//in this case:the students is not obliges to pay more 
                                    balance[std]=balance[std]-Total;
                                    printf("\nThank you !!!");
                                    printf("Do you want to log out :\n");
                                    printf("Enter 1 if Yes\nEnter 2 if No \n");
                                    scanf("%d", &log);
                                    if(log==1){
                                        logout(&choice);
                                        switch(choice){
                                            case 1:
                                                goto login;//if the student choose to log in he or she will be directly jump to log in part(log in:)
                                            break;
                                            case 2:
                                                goto enroll;//if the student choose to enroll he or she will be directly jump to enroll part(enroll:)
                                            break;
                                            case 3:
                                                goto exit;//if the student choose to exit he or she will be directly jump to exit part(exit:)
                                            break;
                                        }
                                    }
                                    else{
                                        goto connection;
                                    }
                                }
                                else{
                                    //the case where the total is superior than the amount in the balance
                                    balance[std]=balance[std]-Total;
                                    printf("\nYou still need to pay %d before the first day of classes to avoid getting a financial hold", balance[std]);
                                    printf("Do you want to log out :\n");
                                    printf("Enter 1 if Yes\nEnter 2 if No \n");
                                    scanf("%d", &log);
                                    if(log==1){
                                        logout(&choice);
                                        switch(choice){
                                            case 1:
                                                goto login;//if the student choose to log in he or she will be directly jump to log in part(log in:)
                                            break;
                                            case 2:
                                                goto enroll;//if the student choose to enroll he or she will be directly jump to enroll part(enroll:)
                                            break;
                                            case 3:
                                                goto exit;//if the student choose to exit he or she will be directly jump to exit part(exit:)
                                            break;
                                        }
                                    }
                                    else{
                                        goto connection;
                                    }
                                }
                            break;
                            case 3:
                            //the opportunity to supply the amount in the cashwallet
                                Supply(&wallet);  
                                cash_wallet[std]=cash_wallet[std] + wallet;
                                printf("Here is the new amount in the cash wallet %.2lf\n", cash_wallet[std]);
                                printf("Do you want to log out :\n");
                                printf("Enter 1 if Yes\nEnter 2 if No \n");
                                scanf("%d", &log);
                                if(log==1){
                                    logout(&choice);
                                    switch(choice){
                                        case 1:
                                            goto login;//if the student choose to log in he or she will be directly jump to log in part(log in:)
                                        break;
                                        case 2:
                                            goto enroll;//if the student choose to enroll he or she will be directly jump to enroll part(enroll:)
                                        break;
                                        case 3:
                                            goto exit;//if the student choose to exit he or she will be directly jump to exit part(exit:)
                                        break;
                                    }
                                }
                                else{
                                    goto connection;
                                }
                            break;
                        }
                
                }   
        break;
        case 2://the student choose to enroll to the university
            enroll ://using this enroll: (user defined) or identifier has a purpose to jump to it while using goto function in another part of the program
                enroll(mail,number,&index);
                if(index==1){
                    goto login;
                }
                printf("Thank you for the enrollement!!! \n");
                menu(&choice);
                switch(choice){
                    case 1:
                        goto login;//if the student choose to log in he or she will be directly jump to log in part(log in:)
                    break;
                    case 2:
                        goto enroll;//if the student choose to enroll he or she will be directly jump to enroll part (enroll:)
                    break;
                    case 3:
                        goto exit;//if the student choose to exit he or she will be directly jump to exit part(exit:)
                    break;
                }
        break;
        case 3://the student choose to exit
            exit ://using this exit: (user defined) or identifier has a purpose to jump to it while using goto function in another part of the program
                sortie(ID,mail,fname,lname,password,number,balance,cash_wallet,question,answer);
        break;
        default:
            printf("Invalid choice try again");
        break;
    }

    return 0;
}

//the menu function based on student choice 
void menu(int *choice){

    int type;
    printf("-------------------Welcome to Aui Portal-------------------\n");
    printf("1. Log in\n2. Enroll\n3. Exit\n");      
    printf("------------------------------------------------------------\n");
    printf("please choose your option : \n");
    scanf("%d",&type);
    *choice=type;
}

//the logout function:a menu will be displayed once being login out from the AUI account
void logout(int *choice){

    int type;
    printf("\n You have just logout from your acount\n");
    printf("\n What do you want to do\n");
    printf("------------------------------------------------------------\n");
    printf("1. Log in\n2. Enroll\n3. Exit\n");      
    printf("------------------------------------------------------------\n");
    printf("please choose your option : \n");
    scanf("%d",&type);

    *choice=type;
}

//the log in function: once the menu is displayed and the user choose log in
void login(char ID[NUM][10],char password[NUM][20], char question[NUM][10], char answer[NUM][10], int *std, int *flag){

    int comp1, comp2, comp3;
    int passes;
    char ch, ch1;
    char IDs[7];
    char passwords[30], answers[20], ans[20];
    int comp[NUM];
    int pass[NUM];
    int flags, i;

    printf("Please enter Your ID: ");
    scanf("%s", &IDs);
    printf("Please enter your password: ");
    scanf("%s", &passwords);
    comp[0]=strcmp(IDs,ID[0]);
    comp[1]=strcmp(IDs,ID[1]);
    comp[2]=strcmp(IDs,ID[2]);
    pass[0]=strcmp(passwords,password[0]);
    pass[1]=strcmp(passwords,password[1]);
    pass[2]=strcmp(passwords,password[2]);

//checking the reliability of the ID and password entered by the student
    if(comp[0]!=0 && comp[1]!=0 && comp[2]!=0){
        *flag=1;//the IDs entered are not correct
    }
    else{
        //the ID and password entered by the first student are correct
        if(comp[0]==0 && pass[0]==0){
            *flag=2;
            *std=0;  
        }
        //the ID and password entered by the second student are correct
        else if(comp[1]==0 && pass[1]==0){
            *flag=2;
            *std=1;  
        }
        //the ID and password entered by the third student are correct
        else if(comp[2]==0 && pass[2]==0){
            *flag=2;
            *std=2;  
        }
        else{
            for(i=0; i<NUM; i++){
                if(comp[i]==0 && pass[i]!=0 ){
                    for(int a = 0; a < strlen(passwords)-1; a++){
                        //the student mistyped the password by entering the same character twice consecutively
                        if(passwords[a]==password[i][a] && passwords[a]==passwords[a+1]){
                            //choosing the secret question as an option to reslove entering the same character twice consecutively for the password
                            printf("Please answer the following secret question : %s ", question[i]);
                            scanf("%s", &answers);
                            strcpy(ans,answer[i]);
                            passes=strcmp(answers,ans);
                            //the answer of the secret question is correct
                            if(passes==0){
                                *flag=2;
                                *std=i;
                            }
                            //the answer of the secret question is not correct
                            else{
                                *flag=0;
                            }
                        }
                        
                    }
                }

            }
        }
        
    }
    
}

void enroll(char mail[NUM][30], char number[NUM][12], int *index){

    FILE *enroll;

    enroll = fopen("enroll.txt", "a");

    char first_NAME[20];
    char last_NAME[20];
    char email_new[30];
    char date_of_birth[20];
    char gender[10];
    char city[15];
    char phone_new[15];
    char ch;
    int res2, ind;

    printf("---------Welcome to Enrollement---------\n");
    printf("please enter your first name\n-->");
    ch=getchar();
    gets(first_NAME);
    printf("please enter your last name\n-->");
    gets(last_NAME);
    printf("please enter your email\n-->");
    gets(email_new);
    //checking if the email entered is the same as the one in the input file
    for(int a=0;a<3;a++){
        if(strcmp(email_new,mail[a])==0){
            printf("you have enter an existing email available in the database of the university\n");
            printf("you are already enrolled in the university\n1-do you want to enter another email\nOR\n2-login to your account\nplease choose either 1 or 2");
            scanf("%d",&res2);
            switch(res2){
                case 1:
                   printf("please enter another email");
                   gets(email_new);
                break;
                case 2:
                    ind=1;
                break;
            }
        }  
    }
   printf("please enter your date of birth\n-->");
   gets(date_of_birth);
   printf("please enter your gender\n-->");
   gets(gender);
   printf("please enter your city\n-->");
   gets(city);
   printf("please enter your phone number\n-->");
   gets(phone_new);
   //checking if the phone number entered is the same as the one in the input file
    for(int a=0;a<3;a++){
        if(strcmp(phone_new,number[a])==0){
            printf("This phone number already exist in the university Database\n");
            printf("you are already enrolled in the university\n1-do you want to enter another phone number\nOR\n2-login to your account\nplease choose either 1 or 2");
            scanf("%d",&res2);
            switch(res2){
                case 1:
                   printf("please enter another phone number");
                   gets(phone_new);
                break;
                case 2:
                    ind=1;
                break;
            }
        }  
    }

    //showing the information added by the student while choosing to enroll to AUI
    printf("here is the information added by the student\n");
    printf("\n%s %s %s %s %s %s %s\n",first_NAME,last_NAME,email_new,date_of_birth,gender,city,phone_new);
    
    fprintf(enroll,"%s %s %s %s %s %s %s \n", first_NAME, last_NAME, email_new, date_of_birth, gender,city, phone_new);

    fclose(enroll);


   *index=ind;

}
//the supply function based on the cashwallet
void Supply(double *cash_wallet){

    //supply cash wallet
    int res3, flag;
    double amount1;
    double amount2;
    printf("you have the opportunity to supply your current amount in your cashwallet\nyou have the right to supply it with an amount between 50 and 1000 MAD\n");
    printf("please enter the amount to supply\n");
    scanf("%lf",&amount1);
    if(amount1<50){//if the student enters an amount less than 50
    printf("The amount that you entered is less than then minimum required amount of money to supply your cash wallet");
    flag=1;
    }
    else if(amount1>10000){//if the student enters an amount greater than 10000
    printf("The amount that you entered is more than then maximum allowed amount of money to supply your cash wallet");
    flag=2;  
    }
    else{//the amount entered is between 50 and 10000
    printf("the amount that you enter is between 50 and 1000\nyou have the right to supply your cashwallet\n");
    flag=0;
    }
    //the function money to test the reliability of the amount entered by the user
    switch(flag){//supplying the amount in the cashwallet
        case 0:
        *cash_wallet=(amount1 + *cash_wallet);
        printf("here is the new amount in your cashwallet: %.2lf\n", *cash_wallet);
        break;
        case 1:
        printf("please enter a higher amount\n");
        scanf("%lf",&amount2);
        *cash_wallet=(amount2 + *cash_wallet);
        printf("here is the new amount in your cashwallet: %.2lf\n", *cash_wallet);
        break;
        case 2:
        printf("please enter a lower amount\n");
        scanf("%lf",&amount2);
        *cash_wallet=(amount2 + *cash_wallet);
        break;
    }

}
//the change function:changing the information according to the student choice
void change(char ID[], char mail[], char fname[], char lname[], char password[], char number[], char question[], char answer[]){


    int comp, i, n;
    int modif;
    int index=0, index1=0, index2=0, index3=0;
    char passwords[40], new_password[30];
    char IDs[10], mails[30],fnames[20], lnames[30], numbers[12], questions[10], answers[10];


    printf("Please enter the type of modification you want : \n");
    printf("-------------------Categories-------------------\n");
    printf("1. Password\n2. E-Mail\n3. Phone Number\n4. First Name\n5. Last Name\n6. Secret Question\n7. Answer\n");      
    printf("------------------------------------------------\n");
    scanf("%d", &modif);
    printf("Please enter your password to verify your identity : ");
    scanf("%s", passwords);
    comp=strcmp(passwords,password);
    if(comp==0){//if the passwrod entered is correct
        if(modif==1){//changing the password
            password:
            printf("Please enter your new password :");
            scanf("%s", &new_password);
            for(i=0; i<strlen(new_password)-1 ;i++){
                if(isdigit(new_password[i])){
                    index1=index1+1;//checking how many digit
                }
                else if(isupper(new_password[i])){
                    index2=index2+1;//checking how many uppercase letters
                }
                else if(islower(new_password[i])){
                    index3=index3+1;//checking how many lower case letters
                } 
                else{
                    index=index+1;//calculating how many characters in the new password
                }
            }
            for(int p=0; p<strlen(new_password)-1 ;p++){
                //in case the student enteres prohibited characters in the new password
                if(new_password[p]=='@' || new_password[p]==';' || new_password[p]==(char)92){
                    printf("you are not allowed to have these characters\t(@, \\, ; \n");
                    goto password; 
                }
            }
            //checking the requirement of a new password
            if(index>=2 && index1>=3 && index2>=2 && index3>=2){
                strcpy(password,new_password);
                printf("Thank you for your modification ! \n");
            }
            else{
                printf("Please for security process you should enter at least 9 characters that include at least each of the following:\n2 lowercase letters\n2 uppercase letters\n3 digits\n2 characters\n");
                goto password;      
            }
        }
        else if(modif==2){//changing the email
            printf("Please enter your new email : ");
            scanf("%s", &mails);
            strcpy(mail,mails);
        }
        else if(modif==3){//changing the phone number
            printf("Please enter your new phone number : ");
            scanf("%s", &numbers);
            strcpy(number,numbers);
        }
        else if(modif==4){//changing the first name
            printf("Please enter your new first name : ");
            scanf("%s", &fnames);
            strcpy(fname,fnames);
        }
        else if(modif==5){//changing the last name
            printf("Please enter your new last name : ");
            scanf("%s", &lnames);
            strcpy(lname,lnames);
        }
        else if(modif==6){//changing the question
            printf("Please enter your new secret question : ");
            scanf("%s", &questions);
            strcpy(question,questions);
        }
        else if(modif==7){//changing the answer
            printf("Please enter your new answer : ");
            scanf("%s", &answers);
            strcpy(answer,answers);
        }
    }
    else{
        //the case in which the password does not match the requirement
        printf("Incorrect password\n");
    }

}
//the payfess fucntion
void payfess(int *Total){

    int credits, type, scholar, price, Totals, balance, room, percentage;

    printf("Please enter the number of credits you are enrolled for : ");
    scanf("%d", &credits);
    price=credits*2100;//the price of the course fess without applying scholarship
    printf("-------------------Categories-------------------\n");
    printf("1. Double room: 5880 MAD\n2. Single room: 12800 MAD\n3. Triple room: 3570 MAD\n");      
    printf("------------------------------------------------\n");
    printf("Please enter the type of room you booked for the semester : ");
    scanf("%d", &type);
    if(type==1||type==2||type==3){
        switch(type){//the price of each room depending on student preferable type
            case 1 :
                room=5880;
            break;
            case 2 :
                room=12800;
            break;
            case 3 :
                room=3570;
            break;
        }
    }
    else{ 
        printf("Please you entered the wrong room type");
    }
    printf("If you benefit from a scholarship enter 1, if not enter 2 : ");
    scanf("%d", &scholar);
    if(scholar==2){
        Totals=room+price;//the total price if the student does not have a scholarship
    }
    else if(scholar==1){
        printf("What the scholarship you bennefit from :");
        scanf("%lf", &percentage);
        percentage=(100-percentage)/100;
        price=price*percentage;
        Totals=room+price;//the total price if the student has a scholarship
    }
    printf("%d", Totals);

    *Total=Totals;
}

//sortie function:from the exit part
void sortie(char ID[NUM][10], char mail[NUM][30], char fname[NUM][20], char lname[NUM][30], char password[NUM][20], char number[NUM][12], int balance[NUM], double cash_wallet[NUM], char question[NUM][10], char answer[NUM][10]){

    FILE *out;

    out = fopen("output.txt","w");

    char temp[50];
    int temp1;
    double temp2;

    for (int i=0; i<NUM; i++){
        for (int j=i+1; j<NUM-1-j; j++){
            if (strcmp(ID[i], ID[j]) > 0) {
                // swapping the first name
                strcpy(temp, fname[i]);
                strcpy(lname[i], fname[j]);
                strcpy(lname[j], temp);

                // swapping the last name
                strcpy(temp, lname[i]);
                strcpy(lname[i], lname[j]);
                strcpy(lname[j], temp);

                // swapping the email
                strcpy(temp, mail[i]);
                strcpy(mail[i], mail[j]);
                strcpy(mail[j], temp);


                // swapping the password
                strcpy(temp, password[i]);
                strcpy(password[i], password[j]);
                strcpy(password[j], temp);

                // swapping the phone number
                strcpy(temp, number[i]);
                strcpy(number[i], number[j]);
                strcpy(number[j], temp);

                // swapping the balance
                temp1 = balance[i];
                balance[i] = balance[j];
                balance[j] = temp1;

                // swapping the cash wallet
                temp2 = cash_wallet[i];
                cash_wallet[i] = cash_wallet[j];
                cash_wallet[j] = temp2;

                // swapping the secret question
                strcpy(temp, question[i]);
                strcpy(question[i], question[j]);
                strcpy(question[j], temp);

                // swapping the answer of the secret question
                strcpy(temp, answer[i]);
                strcpy(answer[i], answer[j]);
                strcpy(answer[j], temp);
            }
        }
    }
    
   
    for(int p=0; p<3; p++){
        fprintf(out,"%s %s %s %s %s %s %d %.2lf %s %s \n", ID[p], mail[p], fname[p], lname[p], password[p], number[p], balance[p], cash_wallet[p], question[p], answer[p]);
    }

    fclose(out);

}