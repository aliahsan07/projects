     ###    1:  #include "card.h"
            2:  
            3:  #include "dominion_helpers.h"
            4:  #include "more_dominion_helpers.h"
            5:  
            6:  #include <stdio.h>
            7:  
            8:  
      ##    9:  int play_adventurer(struct gameState *state, int currentPlayer, int handPos)
           10:  {
           11:      int temphand[MAX_HAND];
      ##   12:      int drawntreasure=0;
           13:      int cardDrawn;
      ##   14:      int z = 0;// this is the counter for the temp hand
      ##   15:      while(drawntreasure<2){
      ##   16:          if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
     ###   17:              shuffle(currentPlayer, state);
           18:          }
      ##   19:          drawCard(currentPlayer, state);
      ##   20:          cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      ##   21:          if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
      ##   22:              drawntreasure++;
           23:          } else {
      ##   24:              temphand[z]=cardDrawn;
      ##   25:              state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      ##   26:              z++;
           27:          }
           28:      }
      ##   29:      while(z-1>=0){
      ##   30:          state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
      ##   31:          z=z-1;
           32:      }
           33:  
           34:      //discard card from hand
      ##   35:      discardCard(handPos, currentPlayer, state, 0);
      ##   36:      return 0;
           37:  }
           38:  
           39:  
      ##   40:  int play_council_room(struct gameState *state, int currentPlayer, int handPos)
           41:  {
           42:      int i;
           43:  
           44:      //+4 Cards
      ##   45:      for (i = 0; i < 4; i++)
           46:      {
      ##   47:          drawCard(currentPlayer, state);
           48:      }
           49:  
           50:      //+1 Buy
      ##   51:      state->numBuys++;
           52:  
           53:      //Each other player draws a card
      ##   54:      for (i = 0; i < state->numPlayers; i++)
           55:      {
      ##   56:          if ( i != currentPlayer )
           57:          {
      ##   58:              drawCard(i, state);
           59:          }
           60:      }
           61:  
           62:      //discard card from hand
      ##   63:      discardCard(handPos, currentPlayer, state, 0);
           64:  
      ##   65:      return 0;
           66:  }
           67:  
           68:  
      ##   69:  int play_feast(struct gameState *state, int currentPlayer, int choice1,
           70:          int handPos)
           71:  {
           72:      int i;
           73:      int x;
           74:      int temphand[MAX_HAND];
           75:  
           76:      //gain card with cost up to 5
           77:      //Backup hand
      ##   78:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
      ##   79:          temphand[i] = state->hand[currentPlayer][i];//Backup card
      ##   80:          state->hand[currentPlayer][i] = -1;//Set to nothing
           81:      }
           82:      //Backup hand
           83:  
           84:      //Update Coins for Buy
      ##   85:      updateCoins(currentPlayer, state, 5);
      ##   86:      x = 1;//Condition to loop on
      ##   87:      while( x == 1) {//Buy one card
      ##   88:          if (supplyCount(choice1, state) <= 0){
           89:              if (DEBUG)
           90:                  printf("None of that card left, sorry!\n");
           91:  
           92:              if (DEBUG){
           93:                  printf("Cards Left: %d\n", supplyCount(choice1, state));
           94:              }
           95:          }
      ##   96:          else if (state->coins < getCost(choice1)){
           97:              printf("That card is too expensive!\n");
           98:  
           99:              if (DEBUG){
          100:                  printf("Coins: %d < %d\n", state->coins, getCost(choice1));
          101:              }
          102:          }
          103:          else{
          104:  
          105:              if (DEBUG){
          106:                  printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
          107:              }
          108:  
      ##  109:              gainCard(choice1, state, 0, currentPlayer);//Gain the card
      ##  110:              x = 0;//No more buying cards
          111:  
          112:              if (DEBUG){
          113:                  printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
          114:              }
          115:  
          116:          }
          117:      }
          118:  
          119:      //Reset Hand
      ##  120:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
      ##  121:          state->hand[currentPlayer][i] = temphand[i];
      ##  122:          temphand[i] = -1;
          123:      }
          124:      //Reset Hand
          125:  
          126:      //discard card from hand
      ##  127:      discardCard(handPos, currentPlayer, state, 0);
          128:  
      ##  129:      return 0;
          130:  }
          131:  
          132:  
      ##  133:  int play_mine(struct gameState *state, int currentPlayer, int choice1,
          134:          int choice2, int handPos)
          135:  {
          136:      int i;
          137:      int j;
      ##  138:      j = state->hand[currentPlayer][choice1];  //store card we will trash
          139:  
      ##  140:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
          141:      {
          142:          return -1;
          143:      }
          144:  
      ##  145:      if (choice2 > treasure_map || choice2 < curse)
          146:      {
          147:          return -1;
          148:      }
          149:  
      ##  150:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
          151:      {
          152:          return -1;
          153:      }
          154:  
      ##  155:      gainCard(choice2, state, 2, currentPlayer);
          156:  
          157:      //discard card from hand
      ##  158:      discardCard(handPos, currentPlayer, state, 0);
          159:  
          160:      //discard trashed card
      ##  161:      for (i = 0; i < state->handCount[currentPlayer]; i++)
          162:      {
      ##  163:          if (state->hand[currentPlayer][i] == j) {
      ##  164:              discardCard(i, currentPlayer, state, 0);
      ##  165:              break;
          166:          }
          167:      }
          168:  
      ##  169:      return 0;
          170:  }
          171:  
          172:  
     ###  173:  int play_remodel(struct gameState *state, int currentPlayer, int choice1,
          174:          int choice2, int handPos)
          175:  {
          176:      int i;
          177:      int j;
          178:  
     ###  179:      j = state->hand[currentPlayer][choice1];  //store card we will trash
          180:  
     ###  181:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) < getCost(choice2) )
          182:      {
          183:          return -1;
          184:      }
          185:  
     ###  186:      gainCard(choice2, state, 0, currentPlayer);
          187:  
          188:      //discard card from hand
     ###  189:      discardCard(handPos, currentPlayer, state, 0);
          190:  
          191:      //discard trashed card
     ###  192:      for (i = 0; i < state->handCount[currentPlayer]; i++)
          193:      {
     ###  194:          if (state->hand[currentPlayer][i] == j)
          195:          {
     ###  196:              discardCard(i, currentPlayer, state, 0);
     ###  197:              break;
          198:          }
          199:      }
          200:  
          201:  
     ###  202:      return 0;
          203:  }
