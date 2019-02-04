#include <stdio.h> //printf(), scanf()
#include <string.h> //strcpy(), strlen()

// deklaracje zmiennych
#define MAX 16
char *options[4] = {"Add a task", "Take a task", "Show all tasks", "Exit"};
char tasks[MAX][256] = {};
int ix = 0;

// deklaracje funkcji
void show_options();
int choose_option();
void add_task();
void take_task();
void show_all_tasks();

int main() {
  int choose;

  while (choose != 3)
  {
    show_options();
    choose = choose_option();
  }

  return 0;
}

void show_options() {
  int i;

  printf("What do you want to do?\n");

  for (i = 0; i < 4; i++) {
    printf("%d. %s\n", i+1, options[i]);
  }
}

int choose_option() {
  int choose;

  printf("Choose an option by typing proper number: ");
  scanf("%d", &choose);
  getchar();

  if(choose == 1) {
    add_task();
  } else if(choose == 2) {
    take_task();
  } else if(choose == 3) {
    show_all_tasks();
  }

  return choose - 1;
}

void add_task() {
  char s[512];
  char *pos;

  if (ix < MAX) {
    printf("Enter your task: ");
    // scanf("%s", tasks[ix]);
    fgets(s, 512, stdin);
    strtok(s, "\n");

    if (strcmp(s, "\n") && strlen(s)<256) {
      strcpy(tasks[ix], s);
      printf("\n\nTask %d. %s\n\n", ix+1, tasks[ix]);
      ix ++;
    } else {
      printf("Wrong length of task! Type a task which length is between 1 and 256 characters.\n\n");
    }

  } else {
    printf("You can't add more than %d tasks!\n\n", MAX);
  }

}

void take_task() {
  int i;

  if (strlen(tasks[0]) > 0) {
    printf("Task for you to do:\n%s\n\n", tasks[0]);
    ix --;
  } else {
    printf("You don't have any tasks to do :)\n\n");
  }

  for (i = 1; i < ix+1; i++) {
    strcpy(tasks[i-1], tasks[i]);
  }

}

void show_all_tasks() {
  int i;

  printf("\nYour tasks:\n");

  for (i = 0; i < ix; i++) {
    printf("Task %d. %s\n", i+1, tasks[i] );
  }

  printf("\n");
}
