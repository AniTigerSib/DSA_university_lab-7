#include "hash.h"

#include <algorithm>
#include <random>
#include <vector>

int hashCard(Card card, int M) {
  return ((card.Suit * 13) + card.Value) % M;
}

std::vector<Card> generateUniqueCards(int K) {
  std::vector<Card> cards;
  for (int suit = 0; suit < 4; ++suit) {
    for (int value = 0; value < 13; ++value) {
      cards.push_back({suit, value});
    }
  }

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(cards.begin(), cards.end(), g); // Перемешиваем карты в случайном порядке

  // Отбираем первые K уникальных карт
  std::vector<Card> uniqueCards(K);
  for (int i = 0; i < K; ++i) {
    uniqueCards[i] = cards[i];
  }

  return uniqueCards;
}

std::vector<std::vector<Card>> buildHashTable(int M, const std::vector<Card>& cards) {
  std::vector<std::vector<Card>> hash_table(M);
  for (const Card& card : cards) {
    int index = hashCard(card, M);
    hash_table[index].push_back(card);
  }
  return hash_table;
}