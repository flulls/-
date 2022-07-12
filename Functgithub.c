#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#define M1 256
#define M2 128
char println();
char search();
char split_for_depth(char& line);
char split_line(char& line);
const char delimetr = ';';
const char* filename1 = "D://data2.txt";
FILE* fp;
int summ;
char println() {
 char line[M2][M1];
 int k = 0;
 fp = fopen(filename1, "r");
 // чтение из файла
 if (fp == NULL)
{
  perror("Ошибка");
  return 1;
}
else
{
   while (fgets(line[k], M1, fp) != NULL)
{
   k++;
  }
}
 fclose(fp);
 printf("+----------------------------------------------------------+\n");
 printf("|   Название реки  |   Длина реки  |   Средняя глубина     |\n");
 printf("+----------------------------------------------------------+\n");
 for (int i = 0; i < k; ++i)
 {
    split_line(*line[i]);
 }
 return 0;
}
char split_line(char& line)
{
   char* lines[3];
   int i = 0;
   char* piece = strtok(&line, ";");
   while (piece != NULL)
  {
       lines[i] = piece;
       piece = strtok(NULL, ";");
       i++;
 }
 for (int k = 0; k < i; ++k)
 {
        printf(" %13s", lines[k]);
  }
    return 0;
}
char search()
{
   char line[M2][M1];
   int k = 0;
   char* lines[3];
   int i = 0;
   fp = fopen(filename1, "r");
 // чтение из файла
 if (fp == NULL)
 {
     perror("Ошибка");
     return 1;
 }
 else
 {
    while (fgets(line[k], M1, fp) != NULL)
 {
 k++;
 }
 }
 fclose(fp);
 for (int i = 0; i < k; ++i)
 {
 split_for_depth(*line[i]);
 }
 printf("+----------------------------------------------------------+\n");
 printf("| Сумма = %i \n", summ);
 printf("+----------------------------------------------------------+\n");
 return 0;
}
char split_for_depth(char& line)
{
 char* lines[3];
 int a, b;
 int i = 0, k = 0, max = 3;
 char* size[M1];
 char* depth[M1];
 char* piece = strtok(&line, ";");
 while (piece != NULL)
{
 lines[i] = piece;
 piece = strtok(NULL, ";");
 i++;
 if (i == 2)
{
 depth[k] = piece;
 k++;
 for(int j = 0; j < k; j++)
{
 a = atoi(depth[j]);
 if (a < 50)
{
    b = atoi(lines[k]);
    summ += b; }

   }

  }

 }
 return summ;
}
