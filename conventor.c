#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

char Fl = 1, FlA = 0; 
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
if (Fl == 1) /*Checking if converter have already typed entered values back*/
{ 
Fl = 0; 
if (FlA == 0) /*Checking if converter have made convertion from raw temp*/
printf("\n$ tconvert ");
else 
printf("\n$ tconvert %.2f\n", t); /*or temp with temp type*/
} /*here ends the part of code, which is typing data about process user have started and data he have entered*/

switch(num) 
{ 
case 0: /*case when inputed temp is in cel*/
printf("%.2f :C\n", t); 
printf("%.2f :F\n", (t * 9.0 / 5.0 + 32.0)); 
printf("%.2f :K\n\n", (t + min[0])); 
break; 
case 1: /*case when inputed temp is in fah*/
printf("%.2f :F\n", t); 
printf("%.2f :C\n", ((t - 32.0) * 5.0 / 9.0)); 
printf("%.2f :K\n\n", ((t + min[1])* 5.0 / 9.0)); 
break; 
case 2: /*case when inputed temp is in kel*/
printf("%.2f :K\n", t); 
printf("%.2f :C\n", (t - min[0])); 
printf("%.2f :F\n", (t * 9.0 / 5.0 - min[1])); 
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
FlA = 1; 
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
while (i <= 2) /*checking throught all types of temperature for cases of equalities to the entered type*/
{ 
if (strcmp(scales[i], argv[2]) == 0) /*when inputed data is temp value and temp type, and type is recognised*/
{ 
converter(temp, i); 
return 0; 
} 
++i; 
}
FlA = 1; /
i = 0; /*case when inputed data is temp value and temp type, but type is not recognised*/
printf("Entered type of temperature is not supported.\n Results for every other supported type: \n");
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
