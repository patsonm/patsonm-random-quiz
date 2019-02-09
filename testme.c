#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    //generate a random character
    /*original try, took way too long to run
    char c;
    c=(char)rand()%127;//covers standard ascii range http://www.asciitable.com/
    return c;
    */
    
    char c;
    c= (char)(rand() % (126 - 32 + 1)) + 32;
    return c;
    
}

char *inputString()
{
    // TODO: rewrite this function
    int x;
    char randomString[6];
    
    for (x=0; x< 5; x++)
    {
        //orinigal try took took long
        //char c =(char)rand()%127;
        
       char c=(char) (rand() % (116 - 101 + 1)) + 101;
        randomString[x]=c;
    }
    
    //add the string end
    randomString[5]='\0';
    
    char *returnString=randomString;
    
   return returnString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
