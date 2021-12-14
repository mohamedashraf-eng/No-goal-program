#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
//=======================================

// IMPORTANT KEYBOARD KEYS(ASCII):
// BACKSPACE:
#define BKSP 8
// ENTER:
#define ENTER 13
// ESCAPE:
#define ESC 27
// SPACE:
#define SPACE 32
// TAB:
#define TAB 9

//=======================================

typedef struct
{
  char Fav_Color[6];
  char Fav_Name[15];
  char Fav_Gift[15];
  uint8_t Age;
  uint16_t Birth_Date[3];

} __attribute__((packed)) Info;

static Info Malak_Info;

//=======================================

void INPUT(char *);
void intro(void);
void Outro(void);
void Info_Collector(void);
void SavingData(void);
void test_purpose(void);
void PEACE_PATTERN(void);

//=======================================

int main()
{
  system("COLOR 0B");

  intro();
  Info_Collector();
  SavingData();
  Outro();
  test_purpose();

  printf("\n");
  printf("\n!  Wx !\n");
  printf("\n");
  return 0;
}

//======================================

void INPUT(char *input)
{
  uint8_t tracker = 0;
  char temp;

  while(1)
  {
    temp = getch();

    if(temp == ENTER)
    {
      if(tracker > 0)
      {
        input[tracker] = '\0';
        break;
      }
    }

    else if(temp == BKSP)
    {
      if(tracker > 0)
      {
        tracker--;
        input[tracker] = '\0';
        printf("\b \b");
      }
    }

    else if(temp == SPACE || temp == TAB || temp == ESC || tracker >= 15)
    {
      continue;
    }

    else
    {
      input[tracker] = temp;
      printf("%c", temp);
      tracker++;
    }
  }
  //printf("\n Input collected successfully.\n");
}

void intro(void)
{
  char malak_condition;
  uint8_t chances = 0;

  while(1)
  {
    system("cls");

    printf("\n Hi Malak, I am helper bot so i am here to help you!\n");
    printf(" But first i want information about you to start with it.\n");
    printf(" So help me plese! :D\n Want to start?\n");
    printf(" (y for yes), (n for NO)\n");
    printf(" [ > ]: ");
    scanf(" %c", &malak_condition);

    if(malak_condition == 'y' || malak_condition == 'Y')
    {
      system("cls");
      printf("\n OK Let's go! :DD\n");
      break;
    }

    else if(malak_condition == 'n' || malak_condition == 'N')
    {
      while(chances <= 2)
      {
        system("cls");
        chances += 1;
        printf("\n Please Think 1 more time. :(\n");
        sleep(1);
      }

      if(chances >= 2)
      {
        system("cls");
        printf("\n Ok as you like! :'( \n");
        printf("\n (:'<) (:'<)! \n");
        PEACE_PATTERN();
        exit(-1);
      }
    }

    else
    {
      system("cls");
      printf("\n Invalid input please try again. I am waiting (^_^)\n ");
      sleep(1);
    }
  }
}

void PEACE_PATTERN(void)
{
  printf("\n");
  printf("\n________________________________________________\n\n");
  printf(" ****\t*****\t   *\t  ****\t*****\t\n");
  printf(" *   *\t*\t  * *\t *\t*\t\n");
  printf(" ****\t*****\t *****\t *\t*****\t\n");
  printf(" *\t*\t*     *\t *\t*\t\n");
  printf(" *\t*****  *       *  ****\t*****\t\n");
  printf("________________________________________________");
  printf("\n");
}

void Outro(void)
{
  system("cls");
  printf("\n Now I am happy. I will help you forever now! (^_^)");
  printf("\n Thanks Malak for playing this game with me!. \n");
  printf("\n Good luck in your programming lab! Cya soon dude. \n");
  printf("\n [PEACE OUT] \n");
  printf("\n*****************************************");
  PEACE_PATTERN();
  printf("\n*****************************************");
}
void Info_Collector(void)
{
  sleep(1);
  system("cls");

  printf("\n What is your favorite color?\n");
  printf(" [ > ]: ");
  INPUT(Malak_Info.Fav_Color);
  printf("\n");
  printf("\n What is your favorite name?\n");
  printf(" [ > ]: ");
  INPUT(Malak_Info.Fav_Name);
  printf("\n");

  printf("\n How old are you now?\n");
  printf(" [ > ]: "); //INPUT(&Malak_Info.Age);
    scanf("%d", (int *) &Malak_Info.Age);
  printf("\n");
  printf("\n Oh really! What is your birth date then?\n");
  printf("\n Day: ");   //INPUT(&Malak_Info.Birth_Date[0]);
    scanf("%d", (int *) &Malak_Info.Birth_Date[0]);
  printf("\n Month: "); //INPUT(&Malak_Info.Birth_Date[1]);
    scanf("%d", (int *) &Malak_Info.Birth_Date[1]);
  printf("\n Year: ");  //INPUT(&Malak_Info.Birth_Date[2]);
    scanf("%d", (int *) &Malak_Info.Birth_Date[2]);

  printf("\n");
  printf("\n What is your favorite gift?\n");
  printf(" [ > ]: ");
  INPUT(Malak_Info.Fav_Gift);
}

void SavingData(void)
{
  FILE *FPTR;

  FPTR = fopen("MALAK_DATA.txt", "w");

  if(FPTR == NULL)
  {
    printf("\n FAIL[1]_ADDRESS$NOT$FOUND\n");
    exit(0);
  }

  else
  {
    fprintf(FPTR, "Favorite gift: %s" ,   Malak_Info.Fav_Gift);
    fprintf(FPTR, "\nFavorite name: %s" , Malak_Info.Fav_Name);
    fprintf(FPTR, "\nFavorite color: %s", Malak_Info.Fav_Color);
    fprintf(FPTR, "\nBirthdate %d/%d/%d", Malak_Info.Birth_Date[0],
                                          Malak_Info.Birth_Date[1],
                                          Malak_Info.Birth_Date[2]);
    fprintf(FPTR, "\nAge: %d",            Malak_Info.Age);
  }

  fclose(FPTR);
}


void test_purpose(void)
{
  printf("\n DATA COLLECTED: \n");
  printf("\n %s", Malak_Info.Fav_Color);
  printf("\n %s", Malak_Info.Fav_Gift);
  printf("\n %s", Malak_Info.Fav_Name);
  printf("\n");
  for(uint8_t i = 0; i < 3; i++)
  {
    printf(" %d", Malak_Info.Birth_Date[i]);
  }
  printf("\n %d", Malak_Info.Age);

}
