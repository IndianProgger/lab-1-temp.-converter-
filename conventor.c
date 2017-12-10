#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

char Flag = 1, FlagA = 0; 
float temp;
char *scales[]={"C", "F", "K"}; 
float min[]={273.15, 459.67, 0.0}; 

float * converter(float t, int num) 
{ 
if (t < -min[num])  /*Checking exisence of inputed temperature*/
{ 
printf("\n%.2f %s:\nThis temperature does not exist\n", t, scales[num]); 
return NULL; 
} 
else 
if (Flag == 1) /*Checking if converter have already converted everything we need*/
{ 
Flag = 0; 
if (FlagA == 0) 
printf("\n$ tconvert "); 
else 
printf("\n$ tconvert %.2f\n", t); 
} 

switch(num) 
{ 
case 0: /*case when inputed temp is in cel*/
printf("%.2f C:\n", t); 
printf("%.2f F:\n", (t * 9.0 / 5.0 + 32.0)); 
printf("%.2f K:\n\n", (t + min[0])); 
break; 
case 1: /*case when inputed temp is in fah*/
printf("%.2f F:\n", t); 
printf("%.2f C:\n", ((t - 32.0) * 5.0 / 9.0)); 
printf("%.2f K:\n\n", ((t + min[1])* 5.0 / 9.0)); 
break; 
case 2: /*case when inputed temp is in kel*/
printf("%.2f K:\n", t); 
printf("%.2f C:\n", (t - min[0])); 
printf("%.2f F:\n", (t * 9.0 / 5.0 - min[1])); 
break; 
} 
return 0; 
} 

int main(int argc, char *argv[]) 
{ 
switch(argc) /*Checking for number of incerted data values and desiding what to do with data*/
{ 
case 1: /*case when there is no data inputed*/
{ 
printf("\nNo input data\n"); 
break; 
} 
case 2: /*case when inputed data is only temp value*/
{ 
FlagA = 1; 
temp = atof(argv[1]); 
int i = 0; 
while (i <= 2) 
{ 
converter(temp, i); 
++i; 
} 
break; 
} 
case 3: /*case when inputed data is temp value and temp type*/
{ 
temp = atof(argv[1]); 
int i=0; 
while (i <= 2) 
{ 
if (strcmp(scales[i], argv[2]) == 0) 
{ 
converter(temp, i); 
return 0; 
} 
++i; 
} 
FlagA = 1; 
i = 0; 
while (i <= 2) 
{ 
converter(temp, i); 
++i; 
} 
break; 
} 
} 
return 0; 
}