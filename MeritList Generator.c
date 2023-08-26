#include<stdio.h>
#include<string.h>

//for calculating percentage
float percentage(float a, float b){
    float per= (a/b)*100;
    return per;
}

//for counting
int count_digit(long long EN){

   int count=0;
   while(EN>0){
   EN/=10;
   count++;
   }

    return count;

}

//to store ssc details
struct ssc{
    float eng;
    float maths;
    float science;
    float ss;
    float hindi;
    float marathi;
    float total;
};

//to store hsc details
struct hsc{
    float eng;
    float physics;
    float chemistry;
    float maths;
    float vocational;
    float total;
};

//to store mhtcet details
struct mhtcet{

    float physics;
    float chemistry;
    float maths;
    float total;
};

//to store DOB
struct dob{
    int day;
    int month;
    int year;
};

//to store percentile
struct mhtcet_percentile{

    double physics;
    double chemistry;
    double maths;
    double total;
};

//to store details of student
struct detail{

    long long EN;
    long long ph;
    char name[50];
    char email[50];
    char category[50];
    char gender[10];
    char pwd_def[5];
    char ews[5];
    char tfws[5];
    char orphan[5];
    char minority[50];
    struct ssc ssc;
    float ssc_per;
    struct hsc hsc;
    float hsc_per;
    float hsc_pcm;
    struct mhtcet mhtcet;
    struct dob dob;
    struct mhtcet_percentile per;
    int no; //test purpose

};

//to sort and assign Total Percentile
void sorttotal(int n, struct detail stud[]){

    //sorting according to total marks
    struct detail tempT;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.total)<(stud[j+1].mhtcet.total)){
                tempT=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempT;
            }
        }
    }

    //assigning Percentile for Total
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.total)==(stud[i+1].mhtcet.total)){
            stud[i].per.total = stud[i+1].per.total = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.total = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

//to sort and assign Maths Percentile
void sortmaths(int n, struct detail stud[]){

    //sorting according to maths marks
    struct detail tempM;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.maths)<(stud[j+1].mhtcet.maths)){
                tempM=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempM;
            }
        }
    }

    //assigning Percentile for maths
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.maths)==(stud[i+1].mhtcet.maths)){
            stud[i].per.maths = stud[i+1].per.maths = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.maths = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

//to sort and assign Physics Percentile
void sortphysics(int n, struct detail stud[]){

    //sorting according to Physics marks
    struct detail tempP;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.physics)<(stud[j+1].mhtcet.physics)){
                tempP=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempP;
            }
        }
    }

    //assigning Percentile for Physics
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.physics)==(stud[i+1].mhtcet.physics)){
            stud[i].per.physics = stud[i+1].per.physics = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.physics = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

//to sort and assign Chemistry Percentile
void sortchemistry(int n, struct detail stud[]){

    //sorting according to Chemistry marks
    struct detail tempC;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.chemistry)<(stud[j+1].mhtcet.chemistry)){
                tempC=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempC;
            }
        }
    }

    //assigning Percentile for Chemistry
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.chemistry)==(stud[i+1].mhtcet.chemistry)){
            stud[i].per.chemistry = stud[i+1].per.chemistry = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.chemistry = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

void sortpermaths(int a,int b, struct detail stud[]){

    //sorting according to Maths Percentile
    struct detail tempPerM;
    if((stud[a].per.maths)<(stud[b].per.maths)){
        tempPerM=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPerM;
    }

}

void sortperphysics(int a,int b, struct detail stud[]){

    //sorting according to Physics Percentile
    struct detail tempPerP;
    if((stud[a].per.physics)<(stud[b].per.physics)){
        tempPerP=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPerP;
    }

}

void sortperchemistry(int a,int b, struct detail stud[]){

    //sorting according to chemistry Percentile
    struct detail tempPerC;
    if((stud[a].per.chemistry)<(stud[b].per.chemistry)){
        tempPerC=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPerC;
    }

}

//to sort according to HSC PCM
void sortPCM(int a, int b, struct detail stud[]){

    //sorting according to HSC PCM marks
    struct detail tempPCM;
    if((stud[a].hsc_pcm)<(stud[b].hsc_pcm)){
        tempPCM=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPCM;
    }
}

//to sort according to HSC Maths
void sorthscmaths(int a, int b, struct detail stud[]){

    //sorting according to HSC Maths marks
    struct detail temphscmaths;
    if((stud[a].hsc.maths)<(stud[b].hsc.maths)){
        temphscmaths=stud[a];
        stud[a]=stud[b];
        stud[b]=temphscmaths;
    }
}

//to sort according to HSC Physics
void sorthscphysics(int a, int b, struct detail stud[]){

    //sorting according to HSC Physics marks
    struct detail temphscphysics;
    if((stud[a].hsc.physics)<(stud[b].hsc.physics)){
        temphscphysics=stud[a];
        stud[a]=stud[b];
        stud[b]=temphscphysics;
    }
}

//to sort according to HSC Total
void sorthsctotal(int a, int b, struct detail stud[]){

    //sorting according to HSC Total marks
    struct detail temphsctotal;
    if((stud[a].hsc.total)<(stud[b].hsc.total)){
        temphsctotal=stud[a];
        stud[a]=stud[b];
        stud[b]=temphsctotal;
    }
}

//to sort according to SSC Total
void sortssctotal(int a, int b, struct detail stud[]){

    //sorting according to SSC Total marks
    struct detail tempssctotal;
    if((stud[a].ssc.total)<(stud[b].ssc.total)){
        tempssctotal=stud[a];
        stud[a]=stud[b];
        stud[b]=tempssctotal;
    }
}

//to sort according to SSC Maths Marks
void sortsscmaths(int a, int b, struct detail stud[]){

    //sorting according to SSC Maths marks
    struct detail tempsscmaths;
    if((stud[a].ssc.maths)<(stud[b].ssc.maths)){
        tempsscmaths=stud[a];
        stud[a]=stud[b];
        stud[b]=tempsscmaths;
    }
}

//to sort according to SSC Science Marks
void sortsscscience(int a, int b, struct detail stud[]){

    //sorting according to SSC Science marks
    struct detail tempsscscience;
    if((stud[a].ssc.science)<(stud[b].ssc.science)){
        tempsscscience=stud[a];
        stud[a]=stud[b];
        stud[b]=tempsscscience;
    }
}

//to sort according to SSC English Marks
void sortsscenglish(int a, int b, struct detail stud[]){

    //sorting according to SSC English marks
    struct detail tempsscenglish;
    if((stud[a].ssc.eng)<(stud[b].ssc.eng)){
        tempsscenglish=stud[a];
        stud[a]=stud[b];
        stud[b]=tempsscenglish;
    }
}

//to sort according to Year
void sortyear(int a, int b, struct detail stud[]){

    //sorting according to year
    struct detail tempdobyear;
    if((stud[a].dob.year)<(stud[b].dob.year)){
        tempdobyear=stud[a];
        stud[a]=stud[b];
        stud[b]=tempdobyear;
    }
}

//to sort according to Month
void sortmonth(int a, int b, struct detail stud[]){

    //sorting according to month
    struct detail tempdobmonth;
    if((stud[a].dob.month)<(stud[b].dob.month)){
        tempdobmonth=stud[a];
        stud[a]=stud[b];
        stud[b]=tempdobmonth;
    }
}

//to sort according to Day
void sortday(int a, int b, struct detail stud[]){

    //sorting according to day
    struct detail tempdobday;
    if((stud[a].dob.day)<(stud[b].dob.day)){
        tempdobday=stud[a];
        stud[a]=stud[b];
        stud[b]=tempdobday;
    }
}

int main(){

    int n,c,ssc_arry[6], min=ssc_arry[0], hsc_arry[5];
    char A,B,C,D,E,F,G;
    struct detail s[1000];
    printf("---------------- WELCOME TO MHT-CET C PROGRAM ----------------\n");
    printf("\nEnter the Number of Students: ");
    scanf("%d", &n);
    s[n];
    printf("\nEnter the Details of %d Student(s): ", n);

    for(int i=0; i<n; i++){
        s[i].no=i;
        float ssctotal=0, hsctotal=0;
        printf("\n\n- - - - Student %d/%d - - - -\n\n", i+1, n);
        ENenter:
        printf("EN Number (EN12345678): EN");
        scanf("%lli", &s[i].EN);

        // Consume the newline character left in the input buffer after scanf
        getchar();

        if(count_digit(s[i].EN)==8){

            printf("\nI. Personal Details\n");
            printf("1. Name (Surname_Name_LastName): ");
            gets(s[i].name);

            phenter:

            printf("2. Contact Number: ");
            scanf("%lli", &s[i].ph);
            getchar();

            if(count_digit(s[i].ph)==10){
                printf("3. Email: ");
                gets(s[i].email);

                categoryenter:
                printf("\n   a. Open   b. SC   c. ST   d. OBC   e. SBC\n4. Category: ");
                scanf(" %c", &A);

                getchar();

                switch(A){

                case 'a':
                strcpy(s[i].category, "Open");
                break;

                case 'b':
                strcpy(s[i].category, "SC");
                break;

                case 'c':
                strcpy(s[i].category, "ST");
                break;

                case 'd':
                strcpy(s[i].category, "OBC");
                break;

                case 'e':
                strcpy(s[i].category, "SBC");
                break;

                default:
                printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                goto categoryenter;

                }

                printf("   %s\n", s[i].category);

                genderenter:
                printf("\n   a. Male   b. Female   c. Other\n5. Gender: ");
                scanf(" %c", &B);

                getchar();

                switch(B){

                case 'a':
                strcpy(s[i].gender, "Male");
                break;

                case 'b':
                strcpy(s[i].gender, "Female");
                break;

                case 'c':
                strcpy(s[i].gender, "Other");
                break;

                default:
                printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                goto genderenter;

                }

                printf("   %s\n", s[i].gender);

                pwd_defenter:
                printf("\n   y. Yes   n. No   \n6. PWD/Def: ");
                scanf(" %c", &C);

                getchar();

                switch(C){

                case 'y':
                strcpy(s[i].pwd_def, "Yes");
                break;

                case 'n':
                strcpy(s[i].pwd_def, "No");
                break;

                default:
                printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                goto pwd_defenter;
                }

                printf("   %s\n", s[i].pwd_def);

                ewsenter:
                printf("\n   y. Yes   n. No   \n7. EWS: ");
                scanf(" %c", &D);

                getchar();
                switch(D){

                case 'y':
                strcpy(s[i].ews, "Yes");
                break;

                case 'n':
                strcpy(s[i].ews, "No");
                break;

                default:
                printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                goto ewsenter;
                }

                printf("   %s\n", s[i].ews);

                if(strcmp((s[i].ews),"Yes")){

                    tfwsenter:
                    printf("\n   y. Yes   n. No   \n8. TFWS: ");
                    scanf(" %c", &E);

                    getchar();
                    switch(E){

                    case 'y':
                    strcpy(s[i].tfws, "Yes");
                    break;

                    case 'n':
                    strcpy(s[i].tfws, "No");
                    break;

                    default:
                    printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                    goto tfwsenter;
                    }

                    printf("   %s\n", s[i].tfws);

                }

                else if(strcmp((s[i].ews), "No")){
                    printf("\n8. TFWS: Not Elligible\n");
                    }

                orphanenter:
                    printf("\n   y. Yes   n. No   \n9. Orphan: ");
                    scanf(" %c", &F);

                    getchar();
                    switch(F){

                    case 'y':
                    strcpy(s[i].orphan, "Yes");
                    break;

                    case 'n':
                    strcpy(s[i].orphan, "No");
                    break;

                    default:
                    printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                    goto orphanenter;
                    }

                    printf("   %s\n", s[i].orphan);

                    minorityenter:
                    printf("\n    r. Religious Minority   l. linguistic Minority   n. No\n10. Minority: ");
                    scanf(" %c", &G);

                    getchar();
                    switch(G){

                    case 'r':
                    strcpy(s[i].minority, "Religious Minority");
                    break;

                    case 'l':
                    strcpy(s[i].minority, "Linguistic Minority");
                    break;

                    case 'n':
                    strcpy(s[i].minority, "No");
                    break;

                    default:
                    printf("! ! ! Invalid Selection. Enter Again ! ! !\n\n");
                    goto minorityenter;
                    }

                    printf("    %s\n", s[i].minority);
                    printf("\nII. SSC Marks\n");
                    ssc_engenter:
                    printf("1. English: ");
                    scanf("%f", &s[i].ssc.eng);
                    ssc_arry[0]=s[i].ssc.eng;
                    if((s[i].ssc.eng)<0 || (s[i].ssc.eng)>100){
                        printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                        goto ssc_engenter;
                    }
                    else{
                        ssc_mathsenter:
                        printf("2. Maths: ");
                        scanf("%f", &s[i].ssc.maths);
                        ssc_arry[1]=s[i].ssc.maths;
                        if((s[i].ssc.maths)<0 || (s[i].ssc.maths)>100){
                            printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                            goto ssc_mathsenter;
                        }
                        else{
                            ssc_scienter:
                            printf("3. Science: ");
                            scanf("%f", &s[i].ssc.science);
                            ssc_arry[2]=s[i].ssc.science;
                            if((s[i].ssc.science)<0 || (s[i].ssc.science)>100){
                                printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                goto ssc_scienter;
                                }
                            else{
                                ssc_ssenter:
                                printf("4. Social Science: ");
                                scanf("%f", &s[i].ssc.ss);
                                ssc_arry[3]=s[i].ssc.ss;
                                if((s[i].ssc.ss)<0 || (s[i].ssc.ss)>100){
                                    printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                    goto ssc_ssenter;
                                }
                                else{
                                    ssc_hindienter:
                                    printf("5. Hindi: ");
                                    scanf("%f", &s[i].ssc.hindi);
                                    ssc_arry[4]=s[i].ssc.hindi;
                                    if((s[i].ssc.hindi)<0 || (s[i].ssc.hindi)>100){
                                        printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                        goto ssc_hindienter;
                                    }
                                    else{
                                        ssc_marathienter:
                                        printf("6. Marathi: ");
                                        scanf("%f", &s[i].ssc.marathi);
                                        ssc_arry[5]=s[i].ssc.marathi;
                                        if((s[i].ssc.marathi)<0 || (s[i].ssc.marathi)>100){
                                            printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                            goto ssc_marathienter;
                                        }
                                        else{
                                            for(int i=0; i<6; i++){
                                                if(ssc_arry[i]<min){
                                                    min=ssc_arry[i];
                                                    c=i;
                                                }
                                            }
                                            ssc_arry[c]=0;
                                            for(int i=0; i<6; i++){
                                                ssctotal+=ssc_arry[i];
                                            }
                                            s[i].ssc.total=ssctotal;
                                            printf("7. Total (Best of 5): %0.2f", s[i].ssc.total);
                                            printf("\n8. Percentage: %0.2f%%\n", percentage(s[i].ssc.total, 500));
                                            s[i].ssc_per=percentage(s[i].ssc.total, 500);


                                            printf("\nIII. HSC Marks\n");
                                            hsc_engenter:
                                            printf("1. English: ");
                                            scanf("%f", &s[i].hsc.eng);
                                            hsc_arry[0]=s[i].hsc.eng;
                                            if((s[i].hsc.eng)<0 || (s[i].hsc.eng)>100){
                                                printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                goto hsc_engenter;
                                            }
                                            else{
                                                hsc_physicsenter:
                                                printf("2. Physics: ");
                                                scanf("%f", &s[i].hsc.physics);
                                                hsc_arry[1]=s[i].hsc.physics;
                                                if((s[i].hsc.physics)<0 || (s[i].hsc.physics)>100){
                                                    printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                    goto hsc_physicsenter;
                                                }
                                                else{
                                                    hsc_chemistryenter:
                                                    printf("3. Chemistry: ");
                                                    scanf("%f", &s[i].hsc.chemistry);
                                                    hsc_arry[2]=s[i].hsc.chemistry;
                                                    if((s[i].hsc.chemistry)<0 || (s[i].hsc.chemistry)>100){
                                                        printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                        goto hsc_chemistryenter;
                                                    }
                                                    else{
                                                        hsc_mathsenter:
                                                        printf("4. Maths: ");
                                                        scanf("%f", &s[i].hsc.maths);
                                                        hsc_arry[3]=s[i].hsc.maths;
                                                        if((s[i].hsc.maths)<0 || (s[i].hsc.maths)>100){
                                                            printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                            goto hsc_mathsenter;
                                                        }
                                                        else{
                                                            hsc_vocationalenter:
                                                            printf("5. Vocational: ");
                                                            scanf("%f", &s[i].hsc.vocational);
                                                            hsc_arry[4]=s[i].hsc.vocational;
                                                            if((s[i].hsc.vocational)<0 || (s[i].hsc.vocational)>200){
                                                                printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                                goto hsc_vocationalenter;
                                                            }
                                                            else{
                                                                s[i].hsc_pcm = percentage(s[i].hsc.physics+s[i].hsc.chemistry+s[i].hsc.maths,300);
                                                                printf("6. PCM: %0.2f%%", s[i].hsc_pcm);
                                                                for(int i=0; i<5; i++){
                                                                    hsctotal+=hsc_arry[i];
                                                                }
                                                                s[i].hsc.total=hsctotal;
                                                                printf("\n7. Total: %0.2f", s[i].hsc.total);
                                                                printf("\n8. Percentage: %0.2f%%\n", percentage(s[i].hsc.total, 600));
                                                                s[i].hsc_per=percentage(s[i].hsc.total, 600);
                                                                printf("\nIV. MHT-CET Marks\n");
                                                                cet_physicsenter:
                                                                printf("1. Physics: ");
                                                                scanf("%f", &s[i].mhtcet.physics);
                                                                if((s[i].mhtcet.physics)<0 || (s[i].mhtcet.physics)>50){
                                                                    printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                                    goto cet_physicsenter;
                                                                }
                                                                else{
                                                                    cet_chemistryenter:
                                                                    printf("2. Chemistry: ");
                                                                    scanf("%f", &s[i].mhtcet.chemistry);
                                                                    if((s[i].mhtcet.chemistry)<0 || (s[i].mhtcet.chemistry)>50){
                                                                        printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                                        goto cet_chemistryenter;
                                                                    }
                                                                    else{
                                                                        cet_mathsenter:
                                                                        printf("3. Maths: ");
                                                                        scanf("%f", &s[i].mhtcet.maths);
                                                                        if((s[i].mhtcet.maths)<0 || (s[i].mhtcet.maths)>100){
                                                                            printf("! ! ! Invalid Marks. Enter Again ! ! !\n\n");
                                                                            goto cet_mathsenter;
                                                                        }
                                                                        else{
                                                                            s[i].mhtcet.total = s[i].mhtcet.physics + s[i].mhtcet.chemistry + s[i].mhtcet.maths;
                                                                            printf("4. Total: %0.2f", s[i].mhtcet.total);

                                                                            //Enter DOB
                                                                            printf("\n\nV. Date of Birth\n");
                                                                            printf("1. Year: ");
                                                                            scanf("%d", &s[i].dob.year);
                                                                            if(((s[i].dob.year)%4==0 || (s[i].dob.year)%400==0 ) && (s[i].dob.year)%100!=0){
                                                                                monthenter:
                                                                                printf("2. Month: ");
                                                                                scanf("%d", &s[i].dob.month);
                                                                                if(s[i].dob.month<1  || s[i].dob.month>12){
                                                                                    printf("! ! ! Invalid Month. Enter Again ! ! !\n\n");
                                                                                    goto monthenter;
                                                                                }
                                                                                else if(s[i].dob.month==2){
                                                                                    dayenter:
                                                                                    printf("3. Day: ");
                                                                                    scanf("%d", &s[i].dob.day);
                                                                                    if(s[i].dob.day<1 || s[i].dob.day>29){
                                                                                        printf("! ! ! Invalid Day. Enter Again ! ! !\n\n");
                                                                                        goto dayenter;
                                                                                    }
                                                                                }
                                                                                else if(s[i].dob.month%2!=0){
                                                                                    dayenter1:
                                                                                    printf("3. Day: ");
                                                                                    scanf("%d", &s[i].dob.day);
                                                                                    if(s[i].dob.day<1 || s[i].dob.day>31){
                                                                                        printf("! ! ! Invalid Day. Enter Again ! ! !\n\n");
                                                                                        goto dayenter1;
                                                                                    }
                                                                                }
                                                                                else if(s[i].dob.month%2==0){
                                                                                    dayenter2:
                                                                                    printf("3. Day: ");
                                                                                    scanf("%d", &s[i].dob.day);
                                                                                    if(s[i].dob.day<1 || s[i].dob.day>30){
                                                                                        printf("! ! ! Invalid Day. Enter Again ! ! !\n\n");
                                                                                        goto dayenter2;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else{
                                                                                monthenter1:
                                                                                printf("2. Month: ");
                                                                                scanf("%d", &s[i].dob.month);
                                                                                if(s[i].dob.month<1  || s[i].dob.month>12){
                                                                                    printf("! ! ! Invalid Month. Enter Again ! ! !\n\n");
                                                                                    goto monthenter1;
                                                                                }
                                                                                else if(s[i].dob.month==2){
                                                                                    dayenter3:
                                                                                    printf("3. Day: ");
                                                                                    scanf("%d", &s[i].dob.day);
                                                                                    if(s[i].dob.day<1 || s[i].dob.day>28){
                                                                                        printf("! ! ! Invalid Day. Enter Again ! ! !\n\n");
                                                                                        goto dayenter3;
                                                                                    }
                                                                                }
                                                                                else if(s[i].dob.month%2!=0){
                                                                                    dayenter4:
                                                                                    printf("3. Day: ");
                                                                                    scanf("%d", &s[i].dob.day);
                                                                                    if(s[i].dob.day<1 || s[i].dob.day>31){
                                                                                        printf("! ! ! Invalid Day. Enter Again ! ! !\n\n");
                                                                                        goto dayenter4;
                                                                                    }
                                                                                }
                                                                                else if(s[i].dob.month%2==0){
                                                                                    dayenter5:
                                                                                    printf("3. Day: ");
                                                                                    scanf("%d", &s[i].dob.day);
                                                                                    if(s[i].dob.day<1 || s[i].dob.day>30){
                                                                                        printf("! ! ! Invalid Day. Enter Again ! ! !\n\n");
                                                                                        goto dayenter5;
                                                                                    }
                                                                                }
                                                                            }
                                                                            printf("%d/%d/%d", s[i].dob.day, s[i].dob.month, s[i].dob.year);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                         }
                                        }
                                    }
                                }
                            }

                        }
                }
            else{
                printf("! ! ! Invalid Contact Number. Enter Again ! ! !\n\n");
                goto phenter;
            }
        }

        else{
            printf("! ! ! Invalid EN Number. Enter again ! ! !\n\n");
            goto ENenter;
        }

    }

    sortchemistry(n,s);
    sortphysics(n,s);
    sortmaths(n,s);
    sorttotal(n,s);

    for(int i=0; i<n-1; i++){
        if((s[i].per.total)==(s[i+1].per.total)){
            sortpermaths(i,i+1,s);
            if((s[i].per.maths)==(s[i+1].per.maths)){
                sortperphysics(i,i+1,s);
                if((s[i].per.physics)==(s[i+1].per.physics)){
                    sortperchemistry(i,i+1,s);
                    if((s[i].per.chemistry)==(s[i+1].per.chemistry)){
                        sortPCM(i,i+1,s);
                        if((s[i].hsc_pcm)==(s[i+1].hsc_pcm)){
                            sorthscmaths(i,i+1,s);
                            if((s[i].hsc.maths)==(s[i+1].hsc.maths)){
                                sorthscphysics(i,i+1,s);
                                if((s[i].hsc.physics)==(s[i+1].hsc.physics)){
                                    sorthsctotal(i,i+1,s);
                                    if((s[i].hsc.total)==(s[i+1].hsc.total)){
                                        sortssctotal(i,i+1,s);
                                        if((s[i].ssc.total)==(s[i+1].ssc.total)){
                                            sortsscmaths(i,i+1,s);
                                            if((s[i].ssc.maths)==(s[i+1].ssc.maths)){
                                                sortsscscience(i,i+1,s);
                                                if((s[i].ssc.science)==(s[i+1].ssc.science)){
                                                    sortsscenglish(i,i+1,s);
                                                    if((s[i].ssc.eng)==(s[i+1].ssc.eng)){
                                                        sortyear(i,i+1,s);
                                                        if((s[i].dob.year)==(s[i+1].dob.year)){
                                                            sortmonth(i,i+1,s);
                                                            if((s[i].dob.month)==(s[i+1].dob.month)){
                                                                sortday(i,i+1,s);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("\n---------------- WELCOME TO MHT-CET MERIT LIST ----------------\n");
        printf("MERIT NO\t\tAPPLICATION ID\t\t\CANDIDATE'S FULL NAME\t\tCATEGORY\t\tGENDER\t\tPWD/DEF\t\tEWS\t\tTFWS\t\tORPHAN\t\tMINORITY(LM/RM)\t\t\tTOTAL PERCENTILE\t\tMATHS PERCENTILE\t\tPHYSICS PERCENTILE\t\tCHEMISTRY PERCENTILE\t\tHSC PCM\t\t\tHSC MATHS\t\tHSC PHYSICS\t\tHSC TOTAL\t\tSSC TOTAL\t\tSSC MATHS\t\tSSC SCIENCE\t\tSSC ENGLISH\t\tDOB\n");


        for(int i=0; i<n; i++){
            printf("%d\t\t\tEN%lli\t\t%s\t\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%llf\t\t%llf\t\t%llf\t\t\t%llf\t\t\t%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t%d/%d/%d\n", i+1, s[i].EN, s[i].name, s[i].category, s[i].gender, s[i].pwd_def, s[i].ews, s[i].tfws, s[i].orphan, s[i].minority, s[i].per.total, s[i].per.maths, s[i].per.physics, s[i].per.chemistry, s[i].hsc_pcm, s[i].hsc.maths, s[i].hsc.physics, s[i].hsc.total, s[i].ssc.total, s[i].ssc.maths, s[i].ssc.science, s[i].ssc.eng, s[i].dob.day, s[i].dob.month, s[i].dob.year);
        }


}
