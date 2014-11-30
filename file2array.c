#include<stdio.h>
#define MAX_ARRAY_SIZE(20);

int file2array(FILE *fp, int *array, int max){

  int count = 0;
  while(count < max && fscanf(fp, "%d", &array[count])){
    count++;
  }
}

int main() {
int array[MAX_ARRAY_SIZE]
  int count;

 count = file2array(stdin, array, MAX_ARRAY_SIZE);


return 0;
}

/*
//this is the concatinate opperator
cat num.txt | ./s2a
./s2a < num.txt
gdb./s2a
#start < ./s2a*/
