     ###     1:  #include "dominion.h"
             2:  #include "card.h"
             3:  #include "dominion_helpers.h"
             4:  #include "rngs.h"
             5:  
             6:  #include <stdio.h>
             7:  #include <math.h>
             8:  #include <stdlib.h>
             9:  
            10:  
            11:  int discardMultipleCards(int handPos[], int count, int currentPlayer,
            12:      struct gameState *state, int trashFlag);
            13:  
            14:  
     ###    15:  int compare(const void* a, const void* b) {
     ###    16:      if (*(int*)a > *(int*)b)
     ###    17:          return 1;
     ###    18:      if (*(int*)a < *(int*)b)
     ###    19:          return -1;
     ###    20:      return 0;
            21:  }
            22:  
            23:  
     ###    24:  struct gameState* newGame() {
     ###    25:      struct gameState* g = malloc(sizeof(struct gameState));
     ###    26:      return g;
            27:  }
            28:  
            29:  
            30:  int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
            31:          int k8, int k9, int k10) {
            32:      int* k = malloc(10 * sizeof(int));
            33:      k[0] = k1;
            34:      k[1] = k2;
            35:      k[2] = k3;
            36:      k[3] = k4;
            37:      k[4] = k5;
            38:      k[5] = k6;
            39:      k[6] = k7;
            40:      k[7] = k8;
            41:      k[8] = k9;
            42:      k[9] = k10;
            43:      return k;
            44:  }
            45:  
            46:  
     ###    47:  int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
            48:          struct gameState *state) {
            49:  
            50:      int i;
            51:      int j;
            52:      int it;
            53:      //set up random number generator
     ###    54:      SelectStream(1);
     ###    55:      PutSeed((long)randomSeed);
            56:  
            57:      //check number of players
     ###    58:      if (numPlayers > MAX_PLAYERS || numPlayers < 2)
            59:      {
            60:          return -1;
            61:      }
            62:  
            63:      //set number of players
     ###    64:      state->numPlayers = numPlayers;
            65:  
            66:      //check selected kingdom cards are different
     ###    67:      for (i = 0; i < 10; i++)
            68:      {
     ###    69:          for (j = 0; j < 10; j++)
            70:          {
     ###    71:              if (j != i && kingdomCards[j] == kingdomCards[i])
            72:              {
            73:                  return -1;
            74:              }
            75:          }
            76:      }
            77:  
            78:  
            79:      //initialize supply
            80:      ///////////////////////////////
            81:  
            82:      //set number of Curse cards
     ###    83:      if (numPlayers == 2)
            84:      {
     ###    85:          state->supplyCount[curse] = 10;
            86:      }
    ####    87:      else if (numPlayers == 3)
            88:      {
    ####    89:          state->supplyCount[curse] = 20;
            90:      }
            91:      else
            92:      {
    ####    93:          state->supplyCount[curse] = 30;
            94:      }
            95:  
            96:      //set number of Victory cards
     ###    97:      if (numPlayers == 2)
            98:      {
     ###    99:          state->supplyCount[estate] = 8;
     ###   100:          state->supplyCount[duchy] = 8;
     ###   101:          state->supplyCount[province] = 8;
           102:      }
           103:      else
           104:      {
    ####   105:          state->supplyCount[estate] = 12;
    ####   106:          state->supplyCount[duchy] = 12;
    ####   107:          state->supplyCount[province] = 12;
           108:      }
           109:  
           110:      //set number of Treasure cards
     ###   111:      state->supplyCount[copper] = 60 - (7 * numPlayers);
     ###   112:      state->supplyCount[silver] = 40;
     ###   113:      state->supplyCount[gold] = 30;
           114:  
           115:      //set number of Kingdom cards
     ###   116:      for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
           117:      {
     ###   118:          for (j = 0; j < 10; j++)           		//loop chosen cards
           119:          {
     ###   120:              if (kingdomCards[j] == i)
           121:              {
           122:                  //check if card is a 'Victory' Kingdom card
     ###   123:                  if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
           124:                  {
     ###   125:                      if (numPlayers == 2){
      ##   126:                          state->supplyCount[i] = 8;
           127:                      }
    ####   128:                      else{ state->supplyCount[i] = 12; }
           129:                  }
           130:                  else
           131:                  {
     ###   132:                      state->supplyCount[i] = 10;
           133:                  }
     ###   134:                  break;
           135:              }
           136:              else    //card is not in the set choosen for the game
           137:              {
     ###   138:                  state->supplyCount[i] = -1;
           139:              }
           140:          }
           141:  
           142:      }
           143:  
           144:      ////////////////////////
           145:      //supply intilization complete
           146:  
           147:      //set player decks
     ###   148:      for (i = 0; i < numPlayers; i++)
           149:      {
     ###   150:          state->deckCount[i] = 0;
     ###   151:          for (j = 0; j < 3; j++)
           152:          {
     ###   153:              state->deck[i][j] = estate;
     ###   154:              state->deckCount[i]++;
           155:          }
     ###   156:          for (j = 3; j < 10; j++)
           157:          {
     ###   158:              state->deck[i][j] = copper;
     ###   159:              state->deckCount[i]++;
           160:          }
           161:      }
           162:  
           163:      //shuffle player decks
     ###   164:      for (i = 0; i < numPlayers; i++)
           165:      {
     ###   166:          if ( shuffle(i, state) < 0 )
           167:          {
           168:              return -1;
           169:          }
           170:      }
           171:  
           172:      //draw player hands
     ###   173:      for (i = 0; i < numPlayers; i++)
           174:      {
           175:          //initialize hand size to zero
     ###   176:          state->handCount[i] = 0;
     ###   177:          state->discardCount[i] = 0;
           178:          //draw 5 cards
           179:          // for (j = 0; j < 5; j++)
           180:          //	{
           181:          //	  drawCard(i, state);
           182:          //	}
           183:      }
           184:  
           185:      //set embargo tokens to 0 for all supply piles
     ###   186:      for (i = 0; i <= treasure_map; i++)
           187:      {
     ###   188:          state->embargoTokens[i] = 0;
           189:      }
           190:  
           191:      //initialize first player's turn
     ###   192:      state->outpostPlayed = 0;
     ###   193:      state->phase = 0;
     ###   194:      state->numActions = 1;
     ###   195:      state->numBuys = 1;
     ###   196:      state->playedCardCount = 0;
     ###   197:      state->whoseTurn = 0;
     ###   198:      state->handCount[state->whoseTurn] = 0;
           199:      //int it; move to top
           200:  
           201:      //Moved draw cards to here, only drawing at the start of a turn
     ###   202:      for (it = 0; it < 5; it++){
     ###   203:          drawCard(state->whoseTurn, state);
           204:      }
           205:  
     ###   206:      updateCoins(state->whoseTurn, state, 0);
           207:  
     ###   208:      return 0;
           209:  }
           210:  
           211:  
     ###   212:  int shuffle(int player, struct gameState *state) {
           213:  
           214:  
           215:      int newDeck[MAX_DECK];
     ###   216:      int newDeckPos = 0;
           217:      int card;
           218:      int i;
           219:  
     ###   220:      if (state->deckCount[player] < 1)
  ######   221:          return -1;
     ###   222:      qsort ((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
           223:      /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
           224:  
     ###   225:      while (state->deckCount[player] > 0) {
     ###   226:          card = floor(Random() * state->deckCount[player]);
     ###   227:          newDeck[newDeckPos] = state->deck[player][card];
     ###   228:          newDeckPos++;
     ###   229:          for (i = card; i < state->deckCount[player]-1; i++) {
     ###   230:              state->deck[player][i] = state->deck[player][i+1];
           231:          }
     ###   232:          state->deckCount[player]--;
           233:      }
     ###   234:      for (i = 0; i < newDeckPos; i++) {
     ###   235:          state->deck[player][i] = newDeck[i];
     ###   236:          state->deckCount[player]++;
           237:      }
           238:  
     ###   239:      return 0;
           240:  }
           241:  
           242:  
     ###   243:  int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state)
           244:  {
           245:      int card;
     ###   246:      int coin_bonus = 0; 		//tracks coins gain from actions
           247:  
           248:      //check if it is the right phase
     ###   249:      if (state->phase != 0)
           250:      {
           251:          return -1;
           252:      }
           253:  
           254:      //check if player has enough actions
     ###   255:      if ( state->numActions < 1 )
           256:      {
           257:          return -1;
           258:      }
           259:  
           260:      //get card played
     ###   261:      card = handCard(handPos, state);
           262:  
           263:      //check if selected card is an action
     ###   264:      if ( card < adventurer || card > treasure_map )
           265:      {
           266:          return -1;
           267:      }
           268:  
           269:      //play card
     ###   270:      if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
           271:      {
           272:          return -1;
           273:      }
           274:  
           275:      //reduce number of actions
     ###   276:      state->numActions--;
           277:  
           278:      //update coins (Treasure cards may be added with card draws)
     ###   279:      updateCoins(state->whoseTurn, state, coin_bonus);
           280:  
     ###   281:      return 0;
           282:  }
           283:  
           284:  
     ###   285:  int buyCard(int supplyPos, struct gameState *state) {
           286:      int who;
           287:      if (DEBUG){
           288:          printf("Entering buyCard...\n");
           289:      }
           290:  
           291:      // I don't know what to do about the phase thing.
           292:  
     ###   293:      who = state->whoseTurn;
           294:  
     ###   295:      if (state->numBuys < 1){
           296:          if (DEBUG)
           297:              printf("You do not have any buys left\n");
           298:          return -1;
     ###   299:      } else if (supplyCount(supplyPos, state) <1){
           300:          if (DEBUG)
           301:              printf("There are not any of that type of card left\n");
           302:          return -1;
     ###   303:      } else if (state->coins < getCost(supplyPos)){
           304:          if (DEBUG)
           305:              printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
           306:          return -1;
           307:      } else {
     ###   308:          state->phase=1;
           309:          //state->supplyCount[supplyPos]--;
     ###   310:          gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
           311:  
     ###   312:          state->coins = (state->coins) - (getCost(supplyPos));
     ###   313:          state->numBuys--;
           314:          if (DEBUG)
           315:              printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
           316:      }
           317:  
           318:      //state->discard[who][state->discardCount[who]] = supplyPos;
           319:      //state->discardCount[who]++;
           320:  
     ###   321:      return 0;
           322:  }
           323:  
           324:  
     ###   325:  int numHandCards(struct gameState *state) {
     ###   326:      return state->handCount[ whoseTurn(state) ];
           327:  }
           328:  
           329:  
     ###   330:  int handCard(int handPos, struct gameState *state) {
     ###   331:      int currentPlayer = whoseTurn(state);
     ###   332:      return state->hand[currentPlayer][handPos];
           333:  }
           334:  
           335:  
     ###   336:  int supplyCount(int card, struct gameState *state) {
     ###   337:      return state->supplyCount[card];
           338:  }
           339:  
           340:  
     ###   341:  int fullDeckCount(int player, int card, struct gameState *state) {
           342:      int i;
     ###   343:      int count = 0;
           344:  
     ###   345:      for (i = 0; i < state->deckCount[player]; i++)
           346:      {
     ###   347:          if (state->deck[player][i] == card) count++;
           348:      }
           349:  
     ###   350:      for (i = 0; i < state->handCount[player]; i++)
           351:      {
     ###   352:          if (state->hand[player][i] == card) count++;
           353:      }
           354:  
     ###   355:      for (i = 0; i < state->discardCount[player]; i++)
           356:      {
     ###   357:          if (state->discard[player][i] == card) count++;
           358:      }
           359:  
     ###   360:      return count;
           361:  }
           362:  
           363:  
     ###   364:  int whoseTurn(struct gameState *state) {
     ###   365:      return state->whoseTurn;
           366:  }
           367:  
           368:  
     ###   369:  int endTurn(struct gameState *state) {
           370:      int k;
           371:      int i;
     ###   372:      int currentPlayer = whoseTurn(state);
           373:  
           374:      //Discard hand
     ###   375:      for (i = 0; i < state->handCount[currentPlayer]; i++){
     ###   376:          state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
     ###   377:          state->hand[currentPlayer][i] = -1;//Set card to -1
           378:      }
     ###   379:      state->handCount[currentPlayer] = 0;//Reset hand count
           380:  
           381:      //int k; move to top
           382:      //Current player draws hand
     ###   383:      for (k = 0; state->handCount[state->whoseTurn] < 5; k++) {
     ###   384:          drawCard(state->whoseTurn, state);//Draw a card
           385:      }
           386:  
           387:      //Code for determining the player
     ###   388:      if (currentPlayer < (state->numPlayers - 1)){
     ###   389:          state->whoseTurn = currentPlayer + 1;//Still safe to increment
           390:      }
           391:      else{
     ###   392:          state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
           393:      }
           394:  
     ###   395:      state->outpostPlayed = 0;
     ###   396:      state->phase = 0;
     ###   397:      state->numActions = 1;
     ###   398:      state->coins = 0;
     ###   399:      state->numBuys = 1;
     ###   400:      state->playedCardCount = 0;
           401:  
           402:      //Update money
     ###   403:      updateCoins(state->whoseTurn, state , 0);
           404:  
     ###   405:      return 0;
           406:  }
           407:  
           408:  
     ###   409:  int isGameOver(struct gameState *state) {
           410:      int i;
           411:      int j;
           412:  
           413:      //if stack of Province cards is empty, the game ends
     ###   414:      if (state->supplyCount[province] == 0)
           415:      {
           416:          return 1;
           417:      }
           418:  
           419:      //if three supply pile are at 0, the game ends
     ###   420:      j = 0;
     ###   421:      for (i = 0; i < 25; i++)
           422:      {
     ###   423:          if (state->supplyCount[i] == 0)
           424:          {
      ##   425:              j++;
           426:          }
           427:      }
     ###   428:      if ( j >= 3)
           429:      {
           430:          return 1;
           431:      }
           432:  
     ###   433:      return 0;
           434:  }
           435:  
           436:  
     ###   437:  int scoreFor (int player, struct gameState *state) {
           438:  
           439:      int i;
     ###   440:      int score = 0;
           441:      //score from hand
     ###   442:      for (i = 0; i < state->handCount[player]; i++)
           443:      {
     ###   444:          if (state->hand[player][i] == curse) { score = score - 1; };
     ###   445:          if (state->hand[player][i] == estate) { score = score + 1; };
     ###   446:          if (state->hand[player][i] == duchy) { score = score + 3; };
     ###   447:          if (state->hand[player][i] == province) { score = score + 6; };
     ###   448:          if (state->hand[player][i] == great_hall) { score = score + 1; };
     ###   449:          if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
           450:      }
           451:  
           452:      //score from discard
     ###   453:      for (i = 0; i < state->discardCount[player]; i++)
           454:      {
     ###   455:          if (state->discard[player][i] == curse) { score = score - 1; };
     ###   456:          if (state->discard[player][i] == estate) { score = score + 1; };
     ###   457:          if (state->discard[player][i] == duchy) { score = score + 3; };
     ###   458:          if (state->discard[player][i] == province) { score = score + 6; };
     ###   459:          if (state->discard[player][i] == great_hall) { score = score + 1; };
     ###   460:          if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
           461:      }
           462:  
           463:      //score from deck
     ###   464:      for (i = 0; i < state->deckCount[player]; i++)
           465:      {
     ###   466:          if (state->deck[player][i] == curse) { score = score - 1; };
     ###   467:          if (state->deck[player][i] == estate) { score = score + 1; };
     ###   468:          if (state->deck[player][i] == duchy) { score = score + 3; };
     ###   469:          if (state->deck[player][i] == province) { score = score + 6; };
     ###   470:          if (state->deck[player][i] == great_hall) { score = score + 1; };
     ###   471:          if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
           472:      }
           473:  
     ###   474:      return score;
           475:  }
           476:  
           477:  
           478:  int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
           479:      int i;
           480:      int j;
           481:      int highScore;
           482:      int currentPlayer;
           483:  
           484:      //get score for each player
           485:      for (i = 0; i < MAX_PLAYERS; i++)
           486:      {
           487:          //set unused player scores to -9999
           488:          if (i >= state->numPlayers)
           489:          {
           490:              players[i] = -9999;
           491:          }
           492:          else
           493:          {
           494:              players[i] = scoreFor (i, state);
           495:          }
           496:      }
           497:  
           498:      //find highest score
           499:      j = 0;
           500:      for (i = 0; i < MAX_PLAYERS; i++)
           501:      {
           502:          if (players[i] > players[j])
           503:          {
           504:              j = i;
           505:          }
           506:      }
           507:      highScore = players[j];
           508:  
           509:      //add 1 to players who had less turns
           510:      currentPlayer = whoseTurn(state);
           511:      for (i = 0; i < MAX_PLAYERS; i++)
           512:      {
           513:          if ( players[i] == highScore && i > currentPlayer )
           514:          {
           515:              players[i]++;
           516:          }
           517:      }
           518:  
           519:      //find new highest score
           520:      j = 0;
           521:      for (i = 0; i < MAX_PLAYERS; i++)
           522:      {
           523:          if ( players[i] > players[j] )
           524:          {
           525:              j = i;
           526:          }
           527:      }
           528:      highScore = players[j];
           529:  
           530:      //set winners in array to 1 and rest to 0
           531:      for (i = 0; i < MAX_PLAYERS; i++)
           532:      {
           533:          if ( players[i] == highScore )
           534:          {
           535:              players[i] = 1;
           536:          }
           537:          else
           538:          {
           539:              players[i] = 0;
           540:          }
           541:      }
           542:  
           543:      return 0;
           544:  }
           545:  
           546:  
     ###   547:  int drawCard(int player, struct gameState *state)
           548:  {	int count;
           549:      int deckCounter;
     ###   550:      if (state->deckCount[player] <= 0){//Deck is empty
           551:  
           552:          //Step 1 Shuffle the discard pile back into a deck
           553:          int i;
           554:          //Move discard to deck
     ###   555:          for (i = 0; i < state->discardCount[player];i++){
     ###   556:              state->deck[player][i] = state->discard[player][i];
     ###   557:              state->discard[player][i] = -1;
           558:          }
           559:  
     ###   560:          state->deckCount[player] = state->discardCount[player];
     ###   561:          state->discardCount[player] = 0;//Reset discard
           562:  
           563:          //Shufffle the deck
     ###   564:          shuffle(player, state);//Shuffle the deck up and make it so that we can draw
           565:  
           566:          if (DEBUG){//Debug statements
           567:              printf("Deck count now: %d\n", state->deckCount[player]);
           568:          }
           569:  
     ###   570:          state->discardCount[player] = 0;
           571:  
           572:          //Step 2 Draw Card
     ###   573:          count = state->handCount[player];//Get current player's hand count
           574:  
           575:          if (DEBUG){//Debug statements
           576:              printf("Current hand count: %d\n", count);
           577:          }
           578:  
     ###   579:          deckCounter = state->deckCount[player];//Create a holder for the deck count
           580:  
     ###   581:          if (deckCounter == 0)
 #######   582:              return -1;
           583:  
     ###   584:          state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
     ###   585:          state->deckCount[player]--;
     ###   586:          state->handCount[player]++;//Increment hand count
           587:      }
           588:  
           589:      else{
     ###   590:          int count = state->handCount[player];//Get current hand count for player
           591:          int deckCounter;
           592:          if (DEBUG){//Debug statements
           593:              printf("Current hand count: %d\n", count);
           594:          }
           595:  
     ###   596:          deckCounter = state->deckCount[player];//Create holder for the deck count
     ###   597:          state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
     ###   598:          state->deckCount[player]--;
     ###   599:          state->handCount[player]++;//Increment hand count
           600:      }
           601:  
     ###   602:      return 0;
           603:  }
           604:  
           605:  
     ###   606:  int getCost(int cardNumber)
           607:  {
     ###   608:      switch( cardNumber )
           609:      {
           610:          case curse:
           611:              return 0;
           612:          case estate:
     ###   613:              return 2;
           614:          case duchy:
     ###   615:              return 5;
           616:          case province:
     ###   617:              return 8;
           618:          case copper:
     ###   619:              return 0;
           620:          case silver:
     ###   621:              return 3;
           622:          case gold:
     ###   623:              return 6;
           624:          case adventurer:
     ###   625:              return 6;
           626:          case council_room:
     ###   627:              return 5;
           628:          case feast:
     ###   629:              return 4;
           630:          case gardens:
     ###   631:              return 4;
           632:          case mine:
     ###   633:              return 5;
           634:          case remodel:
     ###   635:              return 4;
           636:          case smithy:
     ###   637:              return 4;
           638:          case village:
     ###   639:              return 3;
           640:          case baron:
     ###   641:              return 4;
           642:          case great_hall:
     ###   643:              return 3;
           644:          case minion:
     ###   645:              return 5;
           646:          case steward:
     ###   647:              return 3;
           648:          case tribute:
    ####   649:              return 5;
           650:          case ambassador:
    ####   651:              return 3;
           652:          case cutpurse:
     ###   653:              return 4;
           654:          case embargo:
     ###   655:              return 2;
           656:          case outpost:
     ###   657:              return 5;
           658:          case salvager:
     ###   659:              return 4;
           660:          case sea_hag:
   #####   661:              return 4;
           662:          case treasure_map:
     ###   663:              return 4;
           664:      }
           665:  
           666:      return -1;
           667:  }
           668:  
           669:  
     ###   670:  int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
           671:  {
           672:      int i;
           673:      int j;
           674:      int k;
           675:      int x;
           676:      int index;
     ###   677:      int currentPlayer = whoseTurn(state);
     ###   678:      int nextPlayer = currentPlayer + 1;
           679:  
     ###   680:      int tributeRevealedCards[2] = {-1, -1};
     ###   681:      int drawntreasure=0;
           682:      int cardDrawn;
     ###   683:      int z = 0;// this is the counter for the temp hand
     ###   684:      if (nextPlayer > (state->numPlayers - 1)){
     ###   685:          nextPlayer = 0;
           686:      }
           687:  
           688:      int toDiscard[MAX_HAND];
     ###   689:      int toDiscardCount = 0;
           690:  
           691:      //uses switch to select card and perform actions
     ###   692:      switch( card )
           693:      {
           694:          case adventurer:
      ##   695:              return play_adventurer(state, currentPlayer, handPos);
           696:  
           697:          case council_room:
      ##   698:              return play_council_room(state, currentPlayer, handPos);
           699:  
           700:          case feast:
      ##   701:              return play_feast(state, currentPlayer, choice1, handPos);
           702:  
           703:          case gardens:
           704:              return -1;
           705:  
           706:          case mine:
      ##   707:              return play_mine(state, currentPlayer, choice1, choice2, handPos);
           708:  
           709:          case remodel:
     ###   710:              return play_remodel(state, currentPlayer, choice1, choice2,
           711:                  handPos);
           712:  
           713:          case smithy:
           714:              //+3 Cards
     ###   715:              for (i = 0; i < 3; i++)
           716:              {
     ###   717:                  drawCard(currentPlayer, state);
           718:              }
           719:  
           720:              //discard card from hand
     ###   721:              discardCard(handPos, currentPlayer, state, 0);
     ###   722:              return 0;
           723:  
           724:          case village:
           725:              //+1 Card
     ###   726:              drawCard(currentPlayer, state);
           727:  
           728:              //+2 Actions
     ###   729:              state->numActions = state->numActions + 2;
           730:  
           731:              //discard played card from hand
     ###   732:              discardCard(handPos, currentPlayer, state, 0);
     ###   733:              return 0;
           734:  
           735:          case baron:
           736:              //discard card from hand
     ###   737:              discardCard(handPos, currentPlayer, state, 0);
           738:  
     ###   739:              state->numBuys++;//Increase buys by 1!
     ###   740:              if (choice1 > 0){//Boolean true or going to discard an estate
     ###   741:                  int p = 0;//Iterator for hand!
     ###   742:                  int card_not_discarded = 1;//Flag for discard set!
     ###   743:                  while(card_not_discarded){
     ###   744:                      if (state->hand[currentPlayer][p] == estate){//Found an estate card!
     ###   745:                          state->coins += 4;//Add 4 coins to the amount of coins
     ###   746:                          discardCard(p, currentPlayer, state, 0);
     ###   747:                          card_not_discarded = 0;//Exit the loop
           748:                      }
      ##   749:                      else if (p > state->handCount[currentPlayer]){
           750:                          if(DEBUG) {
           751:                              printf("No estate cards in your hand, invalid choice\n");
           752:                              printf("Must gain an estate if there are any\n");
           753:                          }
           754:                          if (supplyCount(estate, state) > 0){
           755:                              gainCard(estate, state, 0, currentPlayer);
           756:                              state->supplyCount[estate]--;//Decrement estates
           757:                              if (supplyCount(estate, state) == 0){
           758:                                  isGameOver(state);
           759:                              }
           760:                          }
           761:                          card_not_discarded = 0;//Exit the loop
           762:                      }
           763:  
           764:                      else{
      ##   765:                          p++;//Next card
           766:                      }
           767:                  }
           768:              }
           769:  
           770:              else{
     ###   771:                  if (supplyCount(estate, state) > 0){
     ###   772:                      gainCard(estate, state, 0, currentPlayer);//Gain an estate
     ###   773:                      state->supplyCount[estate]--;//Decrement Estates
     ###   774:                      if (supplyCount(estate, state) == 0){
       #   775:                          isGameOver(state);
           776:                      }
           777:                  }
           778:              }
           779:  
     ###   780:              return 0;
           781:  
           782:          case great_hall:
           783:              //+1 Card
     ###   784:              drawCard(currentPlayer, state);
           785:  
           786:              //+1 Actions
     ###   787:              state->numActions++;
           788:  
           789:              //discard card from hand
     ###   790:              discardCard(handPos, currentPlayer, state, 0);
     ###   791:              return 0;
           792:  
           793:          case minion:
           794:              //+1 action
     ###   795:              state->numActions++;
           796:  
     ###   797:              if (choice1 == 1)		//+2 coins
           798:              {
     ###   799:                  state->coins = state->coins + 2;
     ###   800:                  discardCard(handPos, currentPlayer, state, 0);
           801:              }
           802:  
      ##   803:              else if (choice1 == 2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
           804:              {
           805:                  //discard hand
      ##   806:                  for (i = 0; i < state->handCount[currentPlayer]; i++)
      ##   807:                      toDiscard[toDiscardCount++] = i;
      ##   808:                  discardMultipleCards(toDiscard, toDiscardCount, currentPlayer,
           809:                      state, 0);
           810:  
           811:                  //draw 4
      ##   812:                  for (i = 0; i < 4; i++)
           813:                  {
      ##   814:                      drawCard(currentPlayer, state);
           815:                  }
           816:  
           817:                  //other players discard hand and redraw if hand size > 4
      ##   818:                  for (i = 0; i < state->numPlayers; i++)
           819:                  {
      ##   820:                      if (i != currentPlayer)
           821:                      {
      ##   822:                          if ( state->handCount[i] > 4 )
           823:                          {
      ##   824:                              toDiscardCount = 0;
           825:                              //discard hand
      ##   826:                              for (j = 0; j < state->handCount[i]; j++)
      ##   827:                                  toDiscard[toDiscardCount++] = j;
      ##   828:                              discardMultipleCards(toDiscard, toDiscardCount, i,
           829:                                  state, 0);
           830:  
           831:                              //draw 4
      ##   832:                              for (j = 0; j < 4; j++)
           833:                              {
      ##   834:                                  drawCard(i, state);
           835:                              }
           836:                          }
           837:                      }
           838:                  }
           839:  
           840:              }
     ###   841:              return 0;
           842:  
           843:          case steward:
     ###   844:              toDiscard[toDiscardCount++] = handPos;
           845:              //add card to discard
           846:              state->discard[currentPlayer][
     ###   847:                  state->discardCount[currentPlayer]++] = steward;
           848:  
     ###   849:              if (choice1 == 1)
           850:              {
           851:                  //+2 cards
      ##   852:                  drawCard(currentPlayer, state);
      ##   853:                  drawCard(currentPlayer, state);
           854:              }
     ###   855:              else if (choice1 == 2)
           856:              {
           857:                  //+2 coins
     ###   858:                  state->coins = state->coins + 2;
           859:              }
           860:              else
           861:              {
           862:                  //trash 2 cards in hand
     ###   863:                  toDiscard[toDiscardCount++] = choice2;
     ###   864:                  toDiscard[toDiscardCount++] = choice3;
           865:              }
           866:  
           867:              //trash cards
     ###   868:              discardMultipleCards(toDiscard, toDiscardCount, currentPlayer,
           869:                  state, 1);
     ###   870:              return 0;
           871:  
           872:          case tribute:
    ####   873:              if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
########   874:                  if (state->deckCount[nextPlayer] > 0){
########   875:                      tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
########   876:                      state->deckCount[nextPlayer]--;
           877:                  }
########   878:                  else if (state->discardCount[nextPlayer] > 0){
########   879:                      tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
########   880:                      state->discardCount[nextPlayer]--;
           881:                  }
           882:                  else{
           883:                      //No Card to Reveal
           884:                      if (DEBUG){
           885:                          printf("No cards to reveal\n");
           886:                      }
           887:                  }
           888:              }
           889:  
           890:              else{
    ####   891:                  if (state->deckCount[nextPlayer] == 0){
    ####   892:                      int discardCount = state->discardCount[nextPlayer];
    ####   893:                      for (i = 0; i < discardCount; i++){
    ####   894:                          state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
    ####   895:                          state->deckCount[nextPlayer]++;
    ####   896:                          state->discard[nextPlayer][i] = -1;
    ####   897:                          state->discardCount[nextPlayer]--;
           898:                      }
           899:  
    ####   900:                      shuffle(nextPlayer,state);//Shuffle the deck
           901:                  }
    ####   902:                  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    ####   903:                  state->deck[nextPlayer][state->deckCount[nextPlayer]-1] = -1;
    ####   904:                  state->deckCount[nextPlayer]--;
    ####   905:                  tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    ####   906:                  state->deck[nextPlayer][state->deckCount[nextPlayer]-1] = -1;
    ####   907:                  state->deckCount[nextPlayer]--;
           908:              }
           909:  
    ####   910:              state->discard[nextPlayer][state->discardCount[nextPlayer]++] =
    ####   911:                  tributeRevealedCards[0];
           912:  
           913:              //If we have a duplicate card, ignore one
    ####   914:              if (tributeRevealedCards[0] == tributeRevealedCards[1]){
    ####   915:                  tributeRevealedCards[1] = -1;
           916:              }
           917:              else{
    ####   918:                  state->discard[nextPlayer][state->discardCount[nextPlayer]++] =
    ####   919:                      tributeRevealedCards[1];
           920:              }
           921:  
    ####   922:              for (i = 0; i < 2; i ++){
    ####   923:                  if (tributeRevealedCards[i] == copper ||
    ####   924:                          tributeRevealedCards[i] == silver ||
    ####   925:                          tributeRevealedCards[i] == gold){
           926:                      //Treasure cards
    ####   927:                      state->coins += 2;
           928:                  }
    ####   929:                  else if (tributeRevealedCards[i] == estate ||
    ####   930:                          tributeRevealedCards[i] == duchy ||
    ####   931:                          tributeRevealedCards[i] == province ||
    ####   932:                          tributeRevealedCards[i] == gardens ||
    ####   933:                          tributeRevealedCards[i] == great_hall){
           934:                      //Victory Card Found
    ####   935:                      drawCard(currentPlayer, state);
    ####   936:                      drawCard(currentPlayer, state);
           937:                  }
           938:                  else{
           939:                      //Action Card
    ####   940:                      state->numActions = state->numActions + 2;
           941:                  }
           942:              }
           943:  
    ####   944:              discardCard(handPos, currentPlayer, state, 0);
           945:  
    ####   946:              return 0;
           947:  
           948:          case ambassador:
    ####   949:              j = 0;		//used to check if player has enough cards to discard
           950:  
    ####   951:              if (choice2 > 2 || choice2 < 0)
           952:              {
           953:                  return -1;
           954:              }
           955:  
    ####   956:              if (choice1 == handPos)
           957:              {
           958:                  return -1;
           959:              }
           960:  
    ####   961:              for (i = 0; i < state->handCount[currentPlayer]; i++)
           962:              {
    ####   963:                  if (i != handPos && state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
           964:                  {
    ####   965:                      j++;
           966:                  }
           967:              }
    ####   968:              if (j < choice2)
           969:              {
           970:                  return -1;
           971:              }
           972:  
           973:              if (DEBUG)
           974:                  printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
           975:  
           976:              //increase supply count for choosen card by amount being discarded
    ####   977:              state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
           978:  
           979:              //each other player gains a copy of revealed card
    ####   980:              for (i = 0; i < state->numPlayers; i++)
           981:              {
    ####   982:                  if (i != currentPlayer)
           983:                  {
    ####   984:                      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
           985:                  }
           986:              }
           987:  
           988:              //discard played card from hand
    ####   989:              discardCard(handPos, currentPlayer, state, 0);
           990:  
           991:              //trash copies of cards returned to supply
    ####   992:              for (j = 0; j < choice2; j++)
           993:              {
    ####   994:                  for (i = 0; i < state->handCount[currentPlayer]; i++)
           995:                  {
    ####   996:                      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
           997:                      {
    ####   998:                          toDiscard[toDiscardCount++] = i;
    ####   999:                          break;
          1000:                      }
          1001:                  }
          1002:              }
    ####  1003:              discardMultipleCards(toDiscard, toDiscardCount, currentPlayer,
          1004:                  state, 1);
          1005:  
    ####  1006:              return 0;
          1007:  
          1008:          case cutpurse:
          1009:  
     ###  1010:              updateCoins(currentPlayer, state, 2);
     ###  1011:              for (i = 0; i < state->numPlayers; i++)
          1012:              {
     ###  1013:                  if (i != currentPlayer)
          1014:                  {
     ###  1015:                      for (j = 0; j < state->handCount[i]; j++)
          1016:                      {
     ###  1017:                          if (state->hand[i][j] == copper)
          1018:                          {
     ###  1019:                              discardCard(j, i, state, 0);
     ###  1020:                              break;
          1021:                          }
     ###  1022:                          if (j == state->handCount[i])
          1023:                          {
          1024:                              for (k = 0; k < state->handCount[i]; k++)
          1025:                              {
          1026:                                  if (DEBUG)
          1027:                                      printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
          1028:                              }
          1029:                              break;
          1030:                          }
          1031:                      }
          1032:  
          1033:                  }
          1034:  
          1035:              }
          1036:  
          1037:              //discard played card from hand
     ###  1038:              discardCard(handPos, currentPlayer, state, 0);
          1039:  
     ###  1040:              return 0;
          1041:  
          1042:  
          1043:          case embargo:
          1044:              //+2 Coins
     ###  1045:              state->coins = state->coins + 2;
          1046:  
          1047:              //see if selected pile is in play
     ###  1048:              if ( state->supplyCount[choice1] == -1 )
          1049:              {
          1050:                  return -1;
          1051:              }
          1052:  
          1053:              //add embargo token to selected supply pile
     ###  1054:              state->embargoTokens[choice1]++;
          1055:  
          1056:              //trash card
     ###  1057:              discardCard(handPos, currentPlayer, state, 1);
     ###  1058:              return 0;
          1059:  
          1060:          case outpost:
          1061:              //set outpost flag
     ###  1062:              state->outpostPlayed++;
          1063:  
          1064:              //discard card
     ###  1065:              discardCard(handPos, currentPlayer, state, 0);
     ###  1066:              return 0;
          1067:  
          1068:          case salvager:
          1069:              //+1 buy
     ###  1070:              state->numBuys++;
          1071:  
     ###  1072:              toDiscard[toDiscardCount++] = handPos;
          1073:              //add card to discard
          1074:              state->discard[currentPlayer][
     ###  1075:                  state->discardCount[currentPlayer]++] = salvager;
          1076:  
     ###  1077:              if (choice1)
          1078:              {
          1079:                  //gain coins equal to trashed card
     ###  1080:                  state->coins = state->coins + getCost( handCard(choice1, state) );
          1081:                  //trash card
     ###  1082:                  toDiscard[toDiscardCount++] = choice1;
          1083:              }
          1084:  
          1085:              //trash cards
     ###  1086:              discardMultipleCards(toDiscard, toDiscardCount, currentPlayer,
          1087:                  state, 1);
     ###  1088:              return 0;
          1089:  
          1090:          case sea_hag:
   #####  1091:              for (i = 0; i < state->numPlayers; i++){
   #####  1092:                  if (i != currentPlayer){
   #####  1093:                      state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
   #####  1094:                      state->discardCount[i]++;
   #####  1095:                      state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
          1096:                  }
          1097:              }
   #####  1098:              return 0;
          1099:  
          1100:          case treasure_map:
          1101:              //search hand for another treasure_map
      ##  1102:              index = -1;
      ##  1103:              for (i = 0; i < state->handCount[currentPlayer]; i++)
          1104:              {
      ##  1105:                  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
          1106:                  {
      ##  1107:                      index = i;
      ##  1108:                      break;
          1109:                  }
          1110:              }
      ##  1111:              if (index > -1)
          1112:              {
          1113:                  //trash both treasure cards
      ##  1114:                  toDiscard[toDiscardCount++] = handPos;
      ##  1115:                  toDiscard[toDiscardCount++] = index;
      ##  1116:                  discardMultipleCards(toDiscard, toDiscardCount, currentPlayer,
          1117:                      state, 1);
          1118:  
          1119:                  //gain 4 Gold cards
      ##  1120:                  for (i = 0; i < 4; i++)
          1121:                  {
      ##  1122:                      gainCard(gold, state, 1, currentPlayer);
          1123:                  }
          1124:  
          1125:                  //return success
      ##  1126:                  return 1;
          1127:              }
          1128:  
          1129:              //no second treasure_map found in hand
          1130:              return -1;
          1131:      }
          1132:  
          1133:      return -1;
          1134:  }
          1135:  
          1136:  
     ###  1137:  int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
          1138:  {
          1139:  
          1140:      //if card is not trashed, add it to discard
     ###  1141:      if (trashFlag < 1)
          1142:      {
          1143:          //add card to discard
     ###  1144:          state->discard[currentPlayer][state->discardCount[currentPlayer]++] =
     ###  1145:              state->hand[currentPlayer][handPos];
          1146:      }
          1147:  
          1148:      //set played card to -1
     ###  1149:      state->hand[currentPlayer][handPos] = -1;
          1150:  
          1151:      //remove card from player's hand
     ###  1152:      if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
          1153:      {
          1154:          //reduce number of cards in hand
     ###  1155:          state->handCount[currentPlayer]--;
          1156:      }
     ###  1157:      else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
          1158:      {
          1159:          //reduce number of cards in hand
  ######  1160:          state->handCount[currentPlayer]--;
          1161:      }
          1162:      else
          1163:      {
          1164:          //replace discarded card with last card in hand
     ###  1165:          state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
          1166:          //set last card to -1
     ###  1167:          state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
          1168:          //reduce number of cards in hand
     ###  1169:          state->handCount[currentPlayer]--;
          1170:      }
          1171:  
     ###  1172:      return 0;
          1173:  }
          1174:  
          1175:  
     ###  1176:  int discardMultipleCards(int handPos[], int count, int currentPlayer,
          1177:          struct gameState *state, int trashFlag)
          1178:  {
     ###  1179:      int *hand = state->hand[currentPlayer];
          1180:  
     ###  1181:      for (int i = 0; i < count; i++) {
     ###  1182:          if (trashFlag < 1)
          1183:              state->discard[currentPlayer][
      ##  1184:                  state->discardCount[currentPlayer]++] =
      ##  1185:                  hand[handPos[i]];
     ###  1186:          hand[handPos[i]] = -1;
          1187:      }
          1188:  
     ###  1189:      int left = 0;
     ###  1190:      int right = state->handCount[currentPlayer] - 1;
     ###  1191:      for (int i = 0; i < count; i++) {
          1192:          //replace discarded card with last card in hand
     ###  1193:          while (hand[left] != -1)
     ###  1194:              left++;
     ###  1195:          while (hand[right] == -1)
     ###  1196:              right--;
     ###  1197:          hand[left] = hand[right];
     ###  1198:          left++;
     ###  1199:          right--;
          1200:      }
          1201:  
     ###  1202:      state->handCount[currentPlayer] -= count;
          1203:  
     ###  1204:      return 0;
          1205:  }
          1206:  
          1207:  
     ###  1208:  int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
          1209:  {
          1210:      //Note: supplyPos is enum of choosen card
          1211:  
          1212:      //check if supply pile is empty (0) or card is not used in game (-1)
     ###  1213:      if ( supplyCount(supplyPos, state) < 1 )
          1214:      {
          1215:          return -1;
          1216:      }
          1217:  
          1218:      //added card for [whoseTurn] current player:
          1219:      // toFlag = 0 : add to discard
          1220:      // toFlag = 1 : add to deck
          1221:      // toFlag = 2 : add to hand
          1222:  
     ###  1223:      if (toFlag == 1)
          1224:      {
      ##  1225:          state->deck[ player ][ state->deckCount[player] ] = supplyPos;
      ##  1226:          state->deckCount[player]++;
          1227:      }
     ###  1228:      else if (toFlag == 2)
          1229:      {
      ##  1230:          state->hand[ player ][ state->handCount[player] ] = supplyPos;
      ##  1231:          state->handCount[player]++;
          1232:      }
          1233:      else
          1234:      {
     ###  1235:          state->discard[player][ state->discardCount[player] ] = supplyPos;
     ###  1236:          state->discardCount[player]++;
          1237:      }
          1238:  
          1239:      //decrease number in supply pile
     ###  1240:      state->supplyCount[supplyPos]--;
          1241:  
     ###  1242:      return 0;
          1243:  }
          1244:  
          1245:  
     ###  1246:  int updateCoins(int player, struct gameState *state, int bonus)
          1247:  {
          1248:      int i;
          1249:  
          1250:      //reset coin count
     ###  1251:      state->coins = 0;
          1252:  
          1253:      //add coins for each Treasure card in player's hand
     ###  1254:      for (i = 0; i < state->handCount[player]; i++)
          1255:      {
     ###  1256:          if (state->hand[player][i] == copper)
          1257:          {
     ###  1258:              state->coins += 1;
          1259:          }
     ###  1260:          else if (state->hand[player][i] == silver)
          1261:          {
     ###  1262:              state->coins += 2;
          1263:          }
     ###  1264:          else if (state->hand[player][i] == gold)
          1265:          {
     ###  1266:              state->coins += 3;
          1267:          }
          1268:      }
          1269:  
          1270:      //add bonus
     ###  1271:      state->coins += bonus;
          1272:  
     ###  1273:      return 0;
          1274:  }
          1275:  
          1276:  
          1277:  //end of dominion.c
          1278:  
