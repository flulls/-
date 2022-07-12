#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <conio.h>
#include "Functgithub.c"
#define _CRT_SECURE_NO_WARNINGS
#define M1 256
#define M2 128
char println();
char search();
void Display();
void Display()
{
 printf("+----------------------------------------------------------+\n");
 printf("|                     Меню                                 | \n");
 printf("|           Введите номер опции:                           | \n");
 printf("|       1. Вывод списка                                    | \n");
 printf("|       2. Вывод суммарной длины рек,                      | \n|
глубина которых меньше 50 метров         | \n");
 printf("|       3. Очистить                                        | \n");
 printf("|       4. Выход                                           | \n");
 printf("+----------------------------------------------------------|\n");
}
int main(void)
{
  setlocale(LC_ALL, "rus");
  char opts;
  bool Complete = false;
  for (;;)
  {
     Display();
     printf("\nВведите Ваш выбор: ");
     scanf_s(" %c", &opts);
     printf("\n");
     switch (opts)
    {
    case '1':
         system("CLS");
         println();
         printf("\n");
         Complete = true;
         break;
    case '2':
          system("CLS");
          search();
          printf("\n");
          Complete = true;
          getchar();
          break;
    case '3':
          system("CLS");
          Complete = false;
          break;
   case '4':
         system("pause");
         return 0;
         break;
         default:
              system("cls");
              printf("Повторите свой ввод!\n");
           }
      }
      printf("\n");
}
