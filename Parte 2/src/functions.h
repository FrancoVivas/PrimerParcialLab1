#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int requestDate(int* day,int* month,int* year);
int validateDate(int day, int month);
int isNumberNoSigns(char* string);
int requestNumberPhone(char* string,char* message,char* messageError,int max);
int systemPause(char* message);
int isNumberWhitSigns(char* string);
int validateSpace(char* string);
int requestNumber(int* num,char* message,char* messageError,int min, int max);
int requestString(char* string,char* message,char* messageError,int max);
int requestNumberFloat(float* num, char* message,char* messageError,int min,int max);
int requestCharacterAnswer(char* message);
int requestCharacter(char* character, char* message);
int divideFloat(float* result,float num1,int num2);
int requestNameOrLastName(char* chain,char* message,char* messageError,int max);
int validateSigns(char* string);
int tolowerString(char* string);
int upperFirstLetter(char* string);


#endif /* FUNCTIONS_H_ */
