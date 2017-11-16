/**
File I/O Ranking System
FILE	ranking.c
DATE	2017-10-30
AUTHOR Lee Young Hyun
*/
#include <stdio.h>
#include <string.h>

#define LENGTH 10

typedef struct person
{
char name[LENGTH];
int score;
}Ranker;

void SelectSorting(Ranker *person, int max);
int UpdateAdder(Ranker* person, int num, Ranker temp);

int main()
{
Ranker person[LENGTH];
Ranker temp;
FILE *fp = NULL;
int num, i, j;
int x=0;

fp = fopen("rank", "a");
fclose(fp);

fp = fopen("rank", "r+");

for(i=0; i<10; i++)
{
strcpy(person[i].name, "NULL");
person[i].score = NULL;
}

while(!feof(fp))
{
fscanf(fp, "%s %d", person[x].name, &person[x].score);
if(person[x].score == NULL)
{
break;
}
x++;
}

while(1)
{
printf("====================\n");
printf("2013154021 LeeYoungHyun\n");
printf("1. Adder Name, Score\n");
printf("2. Ranking Print\n");
printf("3. Stored Ranking\n");
printf("4. Quit\n");
printf("====================\n");
printf("Input Number : ");
scanf("%d", &num);

switch(num)
{
case 1:
printf("Adder Name and Score : ");
scanf("%s %d", temp.name, &temp.score);
if(temp.score == NULL)
{
printf("Error! Adder Score 0~\n");
break;
}
j = UpdateAdder(person,x,temp);
if(person[9].score != NULL && person[9].score < temp.score)
person[9] = temp;
else
{
if(j==0 && x < LENGTH)
person[x++] = temp;
}
SelectSorting(person, LENGTH);
break;
case 2:
for(i=0; i<10; i++)
printf("%d. \t  name : %s \t score : %d\n", i+1, person[i].name, person[i].score);
break;
case 3:
fseek(fp, 0, SEEK_SET);
for(i=0; i<10; i++)
fprintf(fp, "%s %d\n", person[i].name, person[i].score);
break;
case 4:
exit(1);
break;
default:
printf("Error!! Enter number 1~4\n");
break;
}
}
return 0;
}

void SelectSorting(Ranker *person, int max)
{
int i,j, least;
Ranker temp;

for(i=0; i<max-1; i++)
{
least = i;
for(j=i+1; j<max; j++)
if(person[j].score > person[least].score)
least = j;
temp = person[i];
person[i] = person[least];
person[least] = temp;
}
}

int UpdateAdder(Ranker *person, int num, Ranker temp)
{
int i=0;
for(i=0; i<num; i++)
{
if(!strcmp(person[i].name, temp.name))
{
if(person[i].score < temp.score)
person[i].score = temp.score;
return 1;
}
}
return 0;
}
