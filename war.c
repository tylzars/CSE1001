/*
* Author: Tyler Zars, tzars2019@my.fit.edu
* Course: CSE 1001, Section 01 Fall 2019
* Filename: war.c
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

const int TOTAL_NUM_CARDS = 52;

/* Function Prototypes */
void shuffle(int *in_deck, int n);
int check_hand(int hand_size, int *hand);
void deal_hand(int *in_deck, int *hand1, int *hand2);
void draw_cards(int *hand1, int *hand2, int round);
void versus(int *hand1, int *hand2, int round, int *roundpointer);
void append_to_end(int *hand1, int *hand2, int round);
int total_number_cards(int *hand);
void shift_hand(int *in_hand, int hand_len);
void print_hand(int *in_hand_print);

int main(void){
  int full_card_deck[TOTAL_NUM_CARDS];
  int player_one_hand[TOTAL_NUM_CARDS*2];
  int player_two_hand[TOTAL_NUM_CARDS*2];
  char user_input = 'p';
  int round = 0;
  int *roundp = &round;
  //Testing Var
  int total_rounds_played = 1;

  printf("Welcome to War!\n");

  //Fill Full Deck
  for (int i = 0; i < TOTAL_NUM_CARDS; i++) {
    full_card_deck[i] = i;
  }
  //Shuffle Full Deck
  shuffle(full_card_deck, TOTAL_NUM_CARDS);
  //Deal Hands
  deal_hand(full_card_deck, player_one_hand, player_two_hand);

  printf("Would you like to play (p) or exit (e): ");
  scanf(" %c", &user_input);

  //Play Game
  while((user_input!='e')){
    printf("\n");

    /* Testing Purposes */
    /*
    printf("Player 1 Arr: ");
    print_hand(player_one_hand);
    printf("\nPlayer 2 Arr: ");
    print_hand(player_two_hand);
    printf("\n");
    */

    draw_cards(player_one_hand, player_two_hand, round);
    versus(player_one_hand, player_two_hand, round, roundp);

    printf("\n");

    /* Testing Purposes */
    /*
    printf("Num Elements Arr 1: %d \n", total_number_cards(player_one_hand));
    printf("Num Elements Arr 1: %d \n", total_number_cards(player_two_hand));
    printf("Round #%d \n \n", total_rounds_played);
    printf("Round Counter for Arr #%d \n \n", round);
    */

    /* Ending Game */
    if ((total_number_cards(player_one_hand)==0)) {
      printf("Player One Wins\n");
      break;
    } else if((total_number_cards(player_two_hand)==0)){
      printf("Player Two Wins\n");
      break;
    }

    /* Play Again */
    printf("Would you like to play (p) or exit (e): ");
    scanf(" %c", &user_input);
    round++;

    /* Reset round for arr[round] so it doesn't go past end of array && shuffle all cards to front so array doesn't overflow */
    if (round >= TOTAL_NUM_CARDS) {
      shift_hand(player_one_hand, total_number_cards(player_one_hand));
      shift_hand(player_two_hand, total_number_cards(player_two_hand));
      round = 0;
    }
    total_rounds_played++;
  }
  //Other Exit Case
  if ((total_number_cards(player_one_hand)!=0)&&(total_number_cards(player_two_hand)!=0)) {
    printf("\nThis game is a tie! \n");
  }

  printf("\nGoodbye! Thanks for playing War! \n");


}


void shuffle(int *in_deck, int n){
    srand((unsigned) time(NULL));
    if (n > 1) {
        int i, k, t;
        for (i = 0; i < (n - 1); i++) {
            k = i + rand() / (RAND_MAX / (n - i) + 1);
            t = in_deck[k];
            in_deck[k] = in_deck[i];
            in_deck[i] = t;
        }
    }
    printf("Shuffling deck... \n");
}

int check_hand(int hand_size, int *hand){
  //Please refer to append_to_end()
  return 0;
}

void deal_hand(int *in_deck, int *hand1, int *hand2){
  int counter = 0;
  for (int i = 0; i < TOTAL_NUM_CARDS; i+=2) {
    hand1[counter]=in_deck[i];
    hand2[counter]=in_deck[i+1];
    counter++;
  }
  for (int j = 26; j < TOTAL_NUM_CARDS*2; j++) {
    hand1[j]=-1;
    hand2[j]=-1;
  }
  printf("Dealing hands...\n");
}

void draw_cards(int *hand1, int *hand2, int round){
  int player_card;

 for(int i = round; i <= round+1; i++)
 {
   /* Set Card */
   if(i == round) {
     player_card = hand1[round];
   } else {
     player_card = hand2[round];
   }
   printf("Player %d's Card: ", (i-round+1));

   /* Print Card Number || Face */
   if((player_card % 13 < 9)&&(player_card!=-1)) {
     printf("%d", ((player_card % 13)+2));
   } else if(player_card % 13 == 12){
     printf("A");
   } else if(player_card % 13 >= 9) {
     switch (player_card % 13) {
       case 9:
         printf("J");
         break;
       case 10:
         printf("Q");
         break;
       case 11:
         printf("K");
         break;
     }
   }
   /* Check for Suit */
   if(player_card >= 39){
     printf("C \n");
   } else if(player_card >= 26) {
     printf("H \n");
   } else if(player_card >= 12) {
     printf("D \n");
   } else {
     printf("S \n");
   }
 }
}

void versus(int *hand1, int *hand2, int round, int *roundpointer){
   for (int i = round; i < round+1; i++) {
     if ((hand1[i]!=-1) && (hand2[i]!=-1)) {
       //War Code
       if ((hand1[i]%13)==(hand2[i]%13)) {
         printf("The cards match! It’s a battle!\n");
         printf("Drawing 3 cards from each player for battle...\n");
         draw_cards(hand1, hand2, round+3);
         if((hand1[i+3]%13)>(hand2[i+3]%13)){
           append_to_end(hand1, hand2, round);
           append_to_end(hand1, hand2, round+1);
           append_to_end(hand1, hand2, round+2);
           append_to_end(hand1, hand2, round+3);
           printf("Player 1 wins the round! Awarding played cards to Player 1...\n");
           *roundpointer+=3;
         } else if((hand1[i+3]%13)<(hand2[i+3]%13)) {
           append_to_end(hand2, hand1, round);
           append_to_end(hand2, hand1, round+1);
           append_to_end(hand2, hand1, round+2);
           append_to_end(hand2, hand1, round+3);
           printf("Player 2 wins the round! Awarding played cards to Player 2...\n");
           *roundpointer+=3;
         }
       } else if ((hand1[i]%13)>(hand2[i]%13)){
         /* Player 1 Wins */
         printf("\nPlayer 1 wins the round! Awarding played cards to Player 1... \n");
         append_to_end(hand1, hand2, round);
       } else {
         /* Player 2 Wins */
         printf("\nPlayer 2 wins the round! Awarding played cards to Player 2... \n");
         append_to_end(hand2, hand1, round);
       }
     }
   }
}

void append_to_end(int *hand_winner, int *hand_loser, int round) {
  int temp = hand_loser[round];
  hand_winner[round+total_number_cards(hand_winner)] = hand_winner[round];
  hand_winner[round+total_number_cards(hand_winner)] = temp;
  hand_loser[round] = -1;
  hand_winner[round] = -1;

}

int total_number_cards(int *hand){
  int counter = 0;
  for (int i = 0; i < TOTAL_NUM_CARDS*2; i++) {
    if(hand[i]!=-1){
      counter++;
    }
  }
  return counter;
}

void shift_hand(int *in_hand, int hand_len){
  for (int i = 0; i < hand_len; i++) {
    for (int j = i; j < TOTAL_NUM_CARDS*2; j++) {
      if(in_hand[j]!=(-1)){
        in_hand[i]=in_hand[j];
        //printf("i=%d j=%d ii=%d jj=%d\n", i, j, in_hand[i], in_hand[j]);
        in_hand[j]=-1;
        //printf("i=%d j=%d ii=%d jj=%d\n", i, j, in_hand[i], in_hand[j]);
        break;
      }
    }
  }
}

void print_hand(int *in_hand_print){
  for (int i = 0; i < TOTAL_NUM_CARDS*2; i++) {
    if(in_hand_print[i]!=-1){
      printf("%d ", in_hand_print[i]);
    }
  }
}
