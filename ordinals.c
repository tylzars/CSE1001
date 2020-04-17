/*
* Author: Tyler Zars, tzars2019@my.fit.edu
* Course: CSE 1001, Section 01 Fall 2019
* Project: ordinal.c
* Print the ordinals from 1 to the user input
*/


#include <math.h>
#include <stdio.h>

int main(void){
  int in_num = 0;
  long sum_entered_nums = 0;
  int loop_iter = 0;
  printf("Enter a value between 0 and 65535 (negative value to quit): ");
  scanf("%d", &in_num);
  while (in_num>=0) {
    if((in_num>=0) && (in_num<=65535)){
          while((loop_iter<=in_num)){
            if(loop_iter==11){
              printf("11th\n");
            } else if(loop_iter==12){
              printf("12th\n");
            } else if(loop_iter==13){
              printf("13th\n");
            } else {
              switch (loop_iter%10) {
                case 1:
                  printf("%dst\n", loop_iter);
                  break;
                case 2:
                  printf("%dnd\n", loop_iter);
                  break;
                case 3:
                  printf("%drd\n", loop_iter);
                  break;
                default:
                  printf("%dth\n", loop_iter);
                  break;
              }
            }
            loop_iter++;
        }
      loop_iter = 0;
      sum_entered_nums+=in_num;
    } else if(in_num>65535) {
      printf("Input not allowed. Try again.\n");
    }
    printf("Enter a value between 0 and 65535 (negative value to quit): ");
    scanf("%d", &in_num);
  }
  printf("The sum of all your entered numbers is %ld. \nGoodbye! Thanks for playing!\n", sum_entered_nums);

  return 0;
}
