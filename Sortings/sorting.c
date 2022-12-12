#include <stdlib.h>
 #include <string.h>
 
 int isSorted(char **lines)
 {
   /* Array contains 0 or 1 strings, it's guaranteed to be sorted. */
   if ((*lines == NULL) || (*(lines + 1) == NULL))
     return 1;
 
   lines++;
   for ( ; *lines; lines++)
   {
     if (strcmp(*lines, *(lines-1)) < 0)
       return 0;
   }
   return 1; /* True if nothing fails. */
 }
 
 size_t arrLen(char **lines)
 {
   int i=0;
   for ( ; *lines; lines++, i++) ;
   return i;
 }
 
 void shuffle(char **lines)
 {
   size_t length = arrLen(lines);
   size_t randN;
   size_t i;
   char *temp;
 
   for (i = 0; i < length; i++)
   {
     randN = rand() % length;
     temp = lines[i];
     lines[i] = lines[randN];
     lines[randN] = temp;
   }
 }
 
 void bogosort(char **lines)
 {
   while (!isSorted(lines))
     shuffle(lines);
 }