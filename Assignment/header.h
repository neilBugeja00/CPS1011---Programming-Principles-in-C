
// Created by neilb on 08/01/2020.
#ifndef ASSIGNMENT_1_HEADER_H
#define ASSIGNMENT_1_HEADER_H
#define  N 10

//Task using INT
int gen[N]; //array of int containing sequence
int storage; //storage for shoot value

//Task using STRING
char numbers[10][10] = {"ONE",
                        "TWO",
                        "THREE",
                        "FOUR",
                        "FIVE",
                        "SIX",
                        "SEVEN",
                        "EIGHT",
                        "NINE",
                        "TEN"};
char generated[10][10] = {}; //STRING GENERATED
char userStringNum[10]; //user's input for number
int match = 22; //used to know if match found or not
char stringStorage[10] = {}; //storage for stringShoot value
int counter = 0; //used for shuffle in order to know the genString's length

//menu
int userChoice = 0;
int userChoice2 = 0;
int userChoice3 = 0;
int userGen;

void generate(int sequence);
void shuffle(int arr[]);
void sort(int arr[]);
void shoot(int arr[]);
void target();
void stringGenerate();
void stringShuffle(char arr [counter][10]);
void stringSort(char arr[counter][10]);
void stringShoot(char arr[][10]);
void stringTarget();
int menu();
int menuInt();
char menuString();
#endif //ASSIGNMENT_1_HEADER_H
