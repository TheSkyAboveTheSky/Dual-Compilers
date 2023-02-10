#include <stdlib.h>
#include <stdio.h>

int main()
{
  int choice;
  printf("Selectionner un langage : `\n");
  printf("##1 : 1 = AR\n");
  printf("##2 : 2 = FR\n");
  
  scanf("%d", &choice);
  if (choice == 1)
  {
    int result;
    result = system("cd ./AR && AR");
  }
  else if (choice == 2)
  {
    int result;
    result = system("cd ./FR && FR");
  }
  else {
    exit(1);
  }
  return 0;
}
