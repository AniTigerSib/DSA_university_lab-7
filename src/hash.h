#ifndef HASH_H
#define HASH_H

#include <vector>
struct Card {
  int Suit;
  int Value;

  Card(int suit, int value) : Suit(suit), Value(value) {}
  Card() : Suit(-1), Value(-1) {}
  int hash(int M) {
    return ((Suit * 13) + Value) % M;
  }
  bool equals(const Card& other) {
    return Suit == other.Suit && Value == other.Value;
  }
};

std::vector<Card> generateUniqueCards(int K);
std::vector<std::vector<Card>> buildHashTable(int M, const std::vector<Card>& cards);

#endif