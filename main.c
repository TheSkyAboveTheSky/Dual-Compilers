#include <stdlib.h>
#include <stdio.h>

int main()
{
  int choice;
  printf("3ZZEL UR Launguage : `\n");
  printf("##1 : 1 = AR\n");
  printf("##2 : 2 = FR\n");
  printf("3ZEL :\t");
  scanf("%d", &choice);
  if (choice == 1)
  {
    int result;
    result = system("cd C:\\Users\\Geek Store\\Desktop\\New folder (5)\\compilateur-BL-MEGHRIBI\\projet_compilation\\AR && AR");
  }
  else if (choice == 2)
  {
    int result;
    result = system("cd C:\\Users\\Geek Store\\Desktop\\New folder (5)\\compilateur-BL-MEGHRIBI\\projet_compilation\\FR && FR");
  }
  return 0;
}
