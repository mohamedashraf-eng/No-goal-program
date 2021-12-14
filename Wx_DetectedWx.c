/*
  Author: Mohamed Wx
  Code: Detect Wx.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>

// DEC: (97 -> 122) a-z
// HEX: (61 -> 7A) a-z

char upo(char *);
char loo(char *);
char map(char *);
char cpt(char *);

int main(void)
{
  char input[10];
  printf("\n Enter: ");
  scanf("%s",input);
  map(input);
  cpt(input);

  return 0;
}


char upo(char *ptr)
{

  //printf("\n Upper: ");
  for(int i = 0; (*(ptr+i) != '\0'); i++)
  {
    if(i >= 0 && i < 10)
      {
      if( (*(ptr+i)  >= 97) && (*(ptr+i)  <= 122) )
      {
        //printf("\n L-L: %c ,\n U-L: %c \n",(input[i]),(input[i]-32));
        //printf("%c",(*(ptr+i)  - 32));
      }

      else
      {
        //printf("%c",*(ptr+i) );
        continue;
      }
    }
  }

  return *(ptr);
}

char loo(char *ptr)
{

  //printf("\n Lower: ");
  for(int i = 0; (*(ptr+i) != '\0'); i++)
  {
    if(i >= 0 && i < 10)
      {
      if( (*(ptr+i)  >= 65) && (*(ptr+i)  <= 90) )
      {
        //printf("\n L-L: %c ,\n U-L: %c \n",(input[i]),(input[i]-32));
        //rintf("%c",(*(ptr+i)  + 32));
      }

      else
      {
        //printf("%c",*(ptr+i) );
        continue;
      }
    }
  }

  return *(ptr);
}

// CAP W: (DEC: 87)::LOW W: (DEC: 119)
// CAP x: (DEC: 88)::LOW x: (DEC: 120)
// CAP M: (DEC: 77)::LOW M: (DEC: 109)
#define W 87
#define w 119
#define X 88
#define x 120
#define M 77
#define m 109

char map(char *ptr)
{
  //uint8_t c = 0;
  char upW;
  char loX;

  if(ptr[0] == W || ptr[0] == w)
  {
    printf("\n Mapping: ");
    if(ptr[0] == w)
    {
      upW = upo(&ptr[0]);
      ptr[0] = upW;
      ptr[0] = W - (W-x);
    }

    else if(ptr[0] == W)
    {
      ptr[0] = W - (W-x);
    }
    else return -1;

    if(ptr[1] == X)
    {
      loX = loo(&ptr[1]);
      ptr[1] = loX;
      ptr[1] = x - (x-M);
    }
    else if(ptr[1] == x)
    {
      ptr[1] = x - (x-M);
    }
    else return -1;
    printf("%c%c \n",ptr[0],ptr[1]);
    exit(1);
  }
  printf("\n Not What expected :( \n");

  return (*ptr);
}

char cpt(char *ptr)
{


  return (*ptr);
}
