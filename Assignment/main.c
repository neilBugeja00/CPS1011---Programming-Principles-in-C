#include <stdio.h>
#include <stdlib.h>
#include <string.h> //used for string compare
#include <time.h>
#include "header.h"

int main(){
    srand(time(0)); //for random number to be different each time

    menu();

    return 0;
}

int menu(){
    do{
        printf("GREETINGS\n");
        printf("====================================\n");
        printf("1. To use numbers press          :1\n");
        printf("2. to use letters (string) press :2\n");
        printf("3. To quit press                 :3\n");
        printf("INPUT: ");
        scanf(" %d", &userChoice);


        switch (userChoice) {
            case 1: menuInt();
                break;

            case 2: menuString();
                break;

            case 3: printf("BYE");
                break;

            default: printf("WRONG INPUT\n");
                break;
        }
    }while(userChoice !=3); //repeats until user quits program

}

int menuInt(){
    do{
        printf("====================================\n");
        printf("To generate a new sequence press: 1 \n");
        printf("To shuffle the sequence press   : 2 \n");
        printf("To sort the sequence press      : 3 \n");
        printf("To shoot the sequence press     : 4 \n");
        printf("To target the shot value press  : 5 \n");
        printf("To exit press                   : 6 \n");
        scanf(" %d",&userChoice2);


        switch (userChoice2) {
            case 1: printf("Enter a number (min 1) to generate a sequence: ");
                scanf("%d", &userGen);
                generate(userGen);
                break;
            case 2:
                shuffle(gen);
                break;
            case 3:
                sort(gen);
                break;
            case 4:
                shoot(gen);
                break;
            case 5:
                target(gen);
                break;
            case 6:
                printf("EXITING STAGE 1\n");
                break;
            default: printf("WRONG INPUT");
                break;
        }
    }while(userChoice2 != 6); //repeats until user quits program
}

char menuString(){
    do{
        printf("====================================\n");
        printf("To generate a new sequence press: 1 \n");
        printf("To shuffle the sequence press   : 2 \n");
        printf("To sort the sequence press      : 3 \n");
        printf("To shoot the sequence press     : 4 \n");
        printf("To target the shot value press  : 5 \n");
        printf("To exit press                   : 6 \n");
        scanf(" %d",&userChoice3);

        switch (userChoice3) {
            case 1: printf("Enter a number (min ONE) to generate a sequence: ");
                scanf("%s", userStringNum);
                stringGenerate();
                break;
            case 2: stringShuffle(generated);
                break;
            case 3: stringSort(generated);
                break;
            case 4: stringShoot(generated);
                break;
            case 5: stringTarget(generated);
                break;
            case 6: printf("EXITING STAGE 2\n");
                break;
            default: printf("WRONG INPUT");
                break;
        }
    }while(userChoice3 != 6); //repeats until user quits program
}

//INCREMENTED SEQUENCE GENERATED
void generate(int sequence){

    for(int i=0; i<N; i++, sequence++){
        gen[i]=sequence;

        printf("%d \n",gen[i]);
    }
}

void shuffle(int arr[]){
    int temp = 0; //temp value
    int randIndex = 0; // random number

    for(int i=0; i<N; i++){
        randIndex = rand() % N; //random number with limit of N
        temp = arr[i]; //swapping values of array
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }

    for(int i=0; i<N; i++){ //printing shuffled array
        printf("%d \n",arr[i]);
    }
}

void sort(int arr[]){
    int swapped = 0; //indicates if array is sorted or not later
    int temp = 0; //temp value

    while(1){
        swapped = 0; //setting value of swapped to 0

        for(int i=0; i<N; i++){ //repeating for the entire array
            if(arr[i]>arr[i+1]){ //if number a > number b (therefore not in order)
                temp = arr[i]; //swapping values of array
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0){ // for swap to be 0 this means that no sorting has taken place
            break;
        }
    }
    for(int i=1; i<N+1; i++){ //prints out sorted array
        printf("%d \n",arr[i]);
    }
}

void shoot(int arr[]){
    int shoot = 0;
    int shootValue = rand() % N; //used to shoot random element

    for(int i=0; i<N; i++){ //checks if shoot has been done before in the given sequence
        if(arr[i] == 0){  //checks if an element has the value of 0
            shoot = 1; //sets the value of shoot to 1 if yes

        }
    }

    if(shoot == 1){ //shoot already done
        printf("ERROR: SHOOT ALREADY DONE ONCE\n");
    }
    else{ //shoot not done
        storage = arr[shootValue];
        arr[shootValue] = 0;
        printf("DONE\n");
    }
}

void target(){
    printf("TARGET: %d \n",storage); //shoot's original value has been placed in storage
}

void stringGenerate(){
    counter = 0; //Had to be done to refresh counter when generating new sequence mid program
    int gener;

    for(int i=0; i<10; i++) {
        gener = strcmp(userStringNum, numbers[i]); //cmp user input with numbers list, becomes 0 if match

        if(gener == 0) { //match found
            match = i; //match's value is that of the position of the starting num
        }
    }

    if(match == 22){ //MATCH NOT FOUND
        printf("MATCH NOT FOUND (USE CAPS)\n");
    }else { //MATCH FOUND
        printf("SEQUENCE: \n");

        for (int i = 0; i + match < 10; i++) {    //(i+match) done to stop when "TEN"" is shown
            strcpy(generated[i], numbers[match + i]); //fills up new array "generated"
            printf("%s \n", generated[i]); //prints the new array generated
            counter++; //counter gives a value to how many elements are in the new array generated

        }
    }
}

void stringShuffle(char arr [][10]){
    char temp[10]; //temp value
    int randIndex = 0; //random number

    for(int i=0; i<counter; i++){
        randIndex = rand() % counter; //random number with limit of counter
        strcpy(temp , arr[i]); //swapping array elements around
        strcpy(arr[i] , arr[randIndex]);
        strcpy(arr[randIndex] , temp);
    }

    for(int i=0; i<=counter; i++){ //printing out shuffled list
        printf("%s \n",arr[i]);
    }
}

void stringSort(char arr[][10]) { //sorts array in ASCENDING order
    int swapped = 0; //indicates if array is sorted or not later
    char temp[10];

    while(1){
        swapped = 0; //setting value of swapped to 0

        for(int i=0; i<counter; i++){ //repeat for the entire array
            if(strcmp(arr[i],arr[i+1]) > 0){ //if number a > number b (therefore not in order)
                strcpy(temp , arr[i]); //swapping array elements around
                strcpy(arr[i] , arr[i+1]);
                strcpy(arr[i+1] , temp);
                swapped = 1; //When ever we swapped a number we change the value of swapped to 1
            }
        }

        if(swapped == 0){ // for swapped to be 0 this means that no sorting has taken place
            break;
        }
    }
    for(int i=1; i<counter+1; i++){ //prints out sorted array
        printf("%s \n",arr[i]);
    }
}

void stringShoot(char arr[][10]){
    int shoot = 0;
    int shootValue = rand() % counter;

    for(int i=0; i<=counter; i++){ //Checking if array has been shot already
        if((strcmp(arr[i],"ZERO"))== 0){ //Checks array for presence of zero
            shoot = 1; //means has been shot
            break;
        }
    }

    if(shoot == 1){
        printf("ERROR\n");
    }
    else{
        strcpy(stringStorage , arr[shootValue]); //swaps a random element with "ZERO"
        strcpy(arr[shootValue] , "ZERO");
        printf("DONE!\n");
    }
}

void stringTarget(){
    printf("TARGET: %s \n",stringStorage);
}
