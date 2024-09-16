#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int countBomb(char** arr,int i, int j,int size) {
  int count = 0;
  if (i == 0 && j == 0) {
    for (int l = 0; l < 2; l++) {
      for (int z = 0; z < 2; z++) {
        if (l == 0 && z == 0) {
          continue;
        }
        if (arr[l][z] == '*') {
          count++;
        }
        
      }
      
     
    }
    
  } else if (i != 0 && j == 0 && i < size - 1) {
    if (arr[i][j+1] == '*') {
      count++;
    }
    if (arr[i+1][j] == '*') {
      count++;
    }
    if (arr[i+1][j+1] == '*') {
      count++;
    }
     if (arr[i-1][j] == '*') {
      count++;
    }
    if (arr[i-1][j+1] == '*') {
      count++;
    }
    
    
  } else if (i == size - 1 && j == 0) {
    if (arr[i][j + 1] == '*') {
      count++;
    }
       if (arr[i - 1][j] == '*') {
      count++;
    }
    if (arr[i - 1][j + 1] == '*') {
      count++;
    }
  } else if (i == 0 && j != 0 && j < size - 1) {
    if (arr[i][j + 1] == '*') {
      count++;
    }
    if (arr[i][j - 1] == '*') {
      count++;
    }
    if (arr[i + 1][j - 1] == '*') {
      count++;
    }
    if (arr[i + 1][j] == '*') {
      count++;
    }
    if (arr[i + 1][j + 1] == '*') {
      count++;
    }
     
  } else if (i == 0 && j == size - 1) {
    if (arr[i][j - 1] == '*') {
      count++;
    }
    if (arr[i + 1][j - 1] == '*') {
      count++;
    }
     if (arr[i + 1][j] == '*') {
      count++;
    }
  } else if (i != 0 && j == size - 1 && i != size - 1) {
    if (arr[i][j - 1] == '*') {
      count++;
    }
    if (arr[i + 1][j - 1] == '*') {
      count++;
    }
    if (arr[i + 1][j] == '*') {
      count++;
    }
    if (arr[i - 1][j - 1] == '*') {
      count++;
    }
    if (arr[i - 1][j] == '*') {
      count++;
    }
  } else if (i == size - 1 && j == size - 1) {
     if (arr[i][j - 1] == '*') {
      count++;
    }
     if (arr[i - 1][j - 1] == '*') {
      count++;
    }
    if (arr[i - 1][j] == '*') {
      count++;
    }
  } else if (i == size - 1 && j != 0 && j < size - 1) {
    if (arr[i][j - 1] == '*') {
      count++;
    }
     if (arr[i - 1][j - 1] == '*') {
      count++;
    }
    if (arr[i - 1][j] == '*') {
      count++;
    }
    if (arr[i - 1][j + 1] == '*') {
      count++;
    }
    if (arr[i][j + 1] == '*') {
      count++;
    }
  } else {
    if (arr[i][j - 1] == '*') {
      count++;
    }
    if (arr[i][j + 1] == '*') {
      count++;
    }
    if (arr[i - 1][j - 1] == '*') {
      count++;
    }
    if (arr[i - 1][j] == '*') {
      count++;
    }
    if (arr[i - 1][j + 1] == '*') {
      count++;
    }
    if (arr[i + 1][j - 1] == '*') {
      count++;
    }
    if (arr[i + 1][j] == '*') {
      count++;
    }
    if (arr[i + 1][j + 1] == '*') {
      count++;
    }
  }
  return count;
}

void print(char** arr,int n) {
     printf("   ");
   for(int i = 0; i < n;i++) {
    printf("\x1b[32m%d\x1b[0m  ",i);
   }
 
   for (int i = 0; i < n; i++) {
    printf("\n\n\x1b[32m%d\x1b[0m ",i);
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == '1') {
        printf(" \x1b[33m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '2') {
        printf(" \x1b[34m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '0') {
        printf(" \x1b[28m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '*') {
        printf(" \x1b[31m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '3'){
        printf(" \x1b[35m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '4'){
        printf(" \x1b[36m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '5'){
        printf(" \x1b[37m%c\x1b[0m ", arr[i][j]);
      } else if (arr[i][j] == '6'){
        printf(" \x1b[90m%c\x1b[0m ", arr[i][j]);
      } else {
      printf(" %c ", arr[i][j]);
      }
      
    }
      printf(" \x1b[32m%d\x1b[0m ",i);
   }
    printf("   \n\n   \x1b[32m0\x1b[0m  ");
   for(int i = 1; i < n;i++) {
    printf("\x1b[32m%d\x1b[0m  ",i);
   }
   printf("\n\n");
}


void sattingBombs(char** arr,bool** mFlag, int size,int n) {
  int i = 0;
  int j = 0;
     srand(time(NULL)) ;
  for (int l = 0; l < n; ) {
    
   
    i = rand() % (size - 1);
    j = rand() % (size - 1);
    if (mFlag[i][j] == true) {
    continue;
   }
   
    arr[i][j] = '*'; 
    mFlag[i][j] = true;
    l++;
  }
  
}

void understandingCountOfBombs(char** arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == '*') {
        continue;
      }
      arr[i][j] = countBomb(arr,i,j,n) + '0';
    }
    
  }
  
}


void openZeroes(char** arr, char** arr2, bool** mFlag, int i, int j, int n) {
    if (i < 0 || j < 0 || i >= n || j >= n || mFlag[i][j]) {
        return;
    }
    if (arr[i][j] == '0') {
      arr2[i][j] = ' ';
      mFlag[i][j] = true;
    } else {
     arr2[i][j] = arr[i][j];
     mFlag[i][j] = true;
    }     
    if (arr[i][j] == '0') {
      if (i < n-1 && j < n-1 && arr[i+1][j+1] != '0') {
        arr2[i+1][j+1] = arr[i+1][j+1];
        mFlag[i+1][j+1] = true;
      } 
      if (i > 0 && j > 0 && arr[i-1][j-1] != '0' ) {
        arr2[i-1][j-1] = arr[i-1][j-1];
        mFlag[i-1][j-1] = true;
      }
      if (i > 0 && j < n-1 && arr[i-1][j+1] != '0') {
        arr2[i-1][j+1] = arr[i-1][j+1];
        mFlag[i-1][j+1] = true;
      }
      if (i < n-1 && j > 0 && arr[i+1][j-1] != '0') {
        arr2[i+1][j-1] = arr[i+1][j-1];
        mFlag[i+1][j-1] = true;
      }
        openZeroes(arr, arr2, mFlag, i + 1, j, n);
        openZeroes(arr, arr2, mFlag, i - 1, j, n);
        openZeroes(arr, arr2, mFlag, i, j + 1, n);
        openZeroes(arr, arr2, mFlag, i, j - 1, n);
        openZeroes(arr, arr2, mFlag, i + 1, j + 1, n);
        openZeroes(arr, arr2, mFlag, i + 1, j + 1, n);
    } 
}

 int pid;
 void handler(int sig) {
  kill(pid,SIGKILL);
  exit(0);
 }

int main() {
  signal(SIGINT,handler);
  int n = 0;
  pid = fork();
  char complexity[6]; 
  if (pid == 0) {
    while(1){
    system("mpg123 ./sounds/'pixel-fight-8-bit-arcade-music-background-music-for-video-36-second-208771 (mp3cut.net).mp3' >/dev/null 2>&1");
    }
  }
  
  printf("please input size you can input bigger 2 and less 11\n");
  while (n < 3 || n > 10 ) {
  scanf("%d", &n);
   if (n >= 3 && n <= 10) {break;}
  printf("wrong size please input again you can input bigger 2 and less 11\n");
  } 
  
  printf("please input complexity you can input easy,normal or hard\n");
  while (strcmp(complexity,"hard") && strcmp(complexity,"easy") && strcmp(complexity,"normal")) {
    scanf("%s", complexity);
    printf("wrong complexity please input again you can input easy,normal or hard\n");
  }
  

  char** matrix =(char**)malloc(n * sizeof(char*) );
  for (int i = 0; i < n; i++) {
    matrix[i] = (char*)malloc(n * sizeof(char));
  }
     for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n; j++) {
      matrix[i][j] = '_';
    }
    
   }
   

   
    char** matrix2 =(char**)malloc(n * sizeof(char*) );
  for (int i = 0; i < n; i++) {
    matrix2[i] = (char*)malloc(n * sizeof(char));
  }
     for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n; j++) {
      matrix2[i][j] = 'x';
    }
    
   }


  bool** mFlag =(bool**)malloc(n * sizeof(bool*) );
  for (int i = 0; i < n; i++) {
    mFlag[i] = (bool*)malloc(n * sizeof(bool));
  }
     for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n; j++) {
      mFlag[i][j] = false;
    }
    
   }

  if (!strcmp(complexity,"easy")) {
   sattingBombs(matrix,mFlag,n,n);
  } else if (!strcmp(complexity,"normal")) {
   sattingBombs(matrix,mFlag,n,n+(n/2));
  } else if (!strcmp(complexity,"hard")) {
   sattingBombs(matrix,mFlag,n,n+n);
  }
  
   understandingCountOfBombs(matrix,n);
  for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n; j++) {
      mFlag[i][j] = false;
    }
    
   }

   int i = 0;
   int j = 0;
   int loseFlag = 0;
   int winFlag = 0;

   
   system("clear");
   printf("\tWelcome to the simple min game\n\n");
   printf("    for exit please input i = -1, j = -1\n\n");
   while (1) {

    
    
  //      for (int i = 0; i < n; i++) {
  //   printf("\n\n");
  //   for (int j = 0; j < n; j++) {     Steps for win
  //     if (matrix[i][j] == '*') {
  //       continue;
  //     } else {
  //       printf("%d%d ",i,j);
  //     }
  //   }
  //  }

   printf("\n\n");
   
   print(matrix2,n);
   printf("please input the i and j kordinats\n");
   scanf("%d %d", &i ,&j);
   if(i == -1 && j == -1) {
    raise(SIGINT);
    break;
   } else if (i < 0 || j < 0 || i >= n || j >= n || mFlag[i][j] == true) {
    system("clear");
     printf("wrong answer please input again\n\n");
     continue;
   }
   if (matrix[i][j] == '*') {
    loseFlag = 1;
    break;
   } else if(matrix[i][j] == '0') {
    openZeroes(matrix,matrix2,mFlag,i,j,n);
    system("aplay ./sounds/'mixkit-unlock-game-notification-253 (mp3cut.net).wav' >/dev/null 2>&1");
   } else {
   matrix2[i][j] = matrix[i][j];
   mFlag[i][j] = true;
   system("aplay ./sounds/'mixkit-unlock-game-notification-253 (mp3cut.net).wav' >/dev/null 2>&1");
   }
   int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mFlag[i][j] == true){
        count++;
      }
    } 
    if (count == n * n - n) {
      winFlag = 1;
    }
    
  }
   if (winFlag) {
    usleep(10);
    kill(pid,SIGKILL);
    printf("\t congratulations \n\t   you are won\n\n");
    print(matrix2,n);
    system("mpg123 ./sounds/'crowd-cheer-ii-6263 (mp3cut.net).mp3' >/dev/null 2>&1");
    break;
   }
  print(matrix2,n);
  system("clear");
   

   }


  if (loseFlag) {
    kill(pid,SIGKILL);
    
    printf("\tyou lose\n\n");
    print(matrix,n);
    system("aplay ./sounds/mixkit-8-bit-bomb-explosion-2811.wav >/dev/null 2>&1");
    exit(0);
  }
  exit(EXIT_SUCCESS);
  kill(pid,SIGKILL);
  
}