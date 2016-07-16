#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5

bool straight, flush, four, three, royal;
int pairs;

void read_cards(int hand[][2]);
void analyze_hand(int hand[][2]);
void print_result(void);
void sort_hand(int hand[][2], int n);
bool is_flush(int hand[][2], int n);
bool card_exists(int rank, int suit, int hand[][2], int n);

int main(void) {
    int hand[NUM_CARDS][2] = {{0}};

    while (1) {
        read_cards(hand);
        analyze_hand(hand);
        print_result();
    }
}

void read_cards(int hand[][2]) {
    bool bad_card;
    int  ch,
         rank_ch,
         suit_ch,
         rank = 0,
         suit = 0,
         cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
        case '0':           exit(EXIT_SUCCESS);
        case '2':           rank = 0; break;
        case '3':           rank = 1; break;
        case '4':           rank = 2; break;
        case '5':           rank = 3; break;
        case '6':           rank = 4; break;
        case '7':           rank = 5; break;
        case '8':           rank = 6; break;
        case '9':           rank = 7; break;
        case 't': case 'T': rank = 8; break;
        case 'j': case 'J': rank = 9; break;
        case 'q': case 'Q': rank = 10; break;
        case 'k': case 'K': rank = 11; break;
        case 'a': case 'A': rank = 12; break;
        default:            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
        case 'c': case 'C': suit = 0; break;
        case 'd': case 'D': suit = 1; break;
        case 'h': case 'H': suit = 2; break;
        case 's': case 'S': suit = 3; break;
        default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists(rank, suit, hand, cards_read))
            printf("Duplicate card; ignored.\n");
        else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

void analyze_hand(int hand[][2]) {
    // sort the hand by rank
    sort_hand(hand, NUM_CARDS);

    flush = is_flush(hand, NUM_CARDS);
    royal = flush && hand[0][0] == 8;

    for (int i = 1; i < NUM_CARDS; i++) {
        if (hand[i][0] - hand[i-1][0] != 1)
            straight = false;
    }

    // check for ace low straight
    straight = hand[0][0] == 0 && hand[NUM_CARDS - 1][0] == 12;

    for (int i = 0; i < NUM_CARDS; i++) {
        int matches = 0;
        for (int j = i + 1; j < NUM_CARDS; j++)
            if (hand[i][0] == hand[j][0])
                matches++;
            else break;

        if (matches == 3) four = true;
        else if (matches == 2) three = true;
        else if (matches == 1) pairs++;
        i += matches; // skip matches
    }
}

void print_result(void) {
    if (royal && flush)    printf("Royal flush.");
    else if (straight &&
            flush)         printf("Straight flush.");
    else if (four)         printf("Four of a kind.");
    else if (three &&
             pairs == 1)   printf("Full house");
    else if (flush)        printf("Flush.");
    else if (straight)     printf("Straight.");
    else if (three)        printf("Three of a kind.");
    else if (pairs == 2)   printf("Two pairs");
    else if (pairs == 1)   printf("Pair");
    else                   printf("High card");

    printf("\n\n");
}

bool card_exists(int rank, int suit, int hand[][2], int n) {
    for (int i = 0; i < n; i++)
        if (rank == hand[i][0] && suit == hand[i][1])
            return true;
    return false;
}

bool is_flush(int hand[][2], int n) {
    for (int card = 0; card < n; card++)
        if (hand[card][1] != hand[0][1])
            return false;
    return true;
}

void sort_hand(int hand[][2], int n) {
    if (n == 0)
        return;

    int maxrank = 0;
    for (int i = 0; i < n; i++)
        maxrank = (hand[i][0] > hand[maxrank][0]) ? i : maxrank;

    int temp_rank = hand[maxrank][0];
    int temp_suit = hand[maxrank][1];

    hand[maxrank][0] = hand[n - 1][0];
    hand[maxrank][1] = hand[n - 1][1];

    hand[n - 1][0] = temp_rank;
    hand[n - 1][1] = temp_suit;

    sort_hand(hand, --n);
}
