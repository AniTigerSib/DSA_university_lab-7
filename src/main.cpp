#include <cmath>
#include <exception>
#include <iostream>

#include "hash.h"

#define M 17
#define K 50

std::vector<double> calculateChiSquared(const std::vector<std::vector<Card>>& hash_table);
double chi(const std::vector<std::vector<Card>>& hash_table, int count, int size);

int main() {
  std::vector<Card> cards = generateUniqueCards(K);
  std::vector<std::vector<Card>> hash_table = buildHashTable(M, cards);
  for (int i = 0; i < M; i++) {
    bool flag = false;
    for (int j = 0; j < M; j++) {
      try {
        if (hash_table.at(i).at(j).Suit != -1) {
          flag = true;
          std::cout << "1 ";
        }
      } catch(std::exception e) {
        std::cout << "0 ";
      }
    }
    std::cout << "\n";
  }
  // double sigma = 0;
  // int count = 0;
  // for (int i=0;i<M;i++) {
  //   count = 0;
  //   try {
  //     while (hash_table.at(i).at(count).Suit != -1) {
  //       count++;
  //     }
  //   } catch (std::exception e) {}
  //   sigma += pow((count - 10000 / M), 2);
  // }
  // std::cout << sigma * ((double)M/(double)10000);

  std::cout << chi(hash_table, M, K) << "\n";
}

double chi(const std::vector<std::vector<Card>>& hash_table, int count, int size) {
  double sum = 0;
  double koef = (double) size / (double) count;
  for (int i = 0; i < count; i++) {
    sum += pow((hash_table.at(i).size() - koef), 2);
    std::cout << sum << "\n";
  }
  std::cout << (1/koef) << "\n";
  return (1 / koef) * sum;
}

std::vector<double> calculateChiSquared(const std::vector<std::vector<Card>>& hash_table) {
  int size = hash_table.size(); // Number of buckets
  int N = 0; // Total number of elements (initialize to 0)

  // Calculate total number of elements
  for (const auto& bucket : hash_table) {
    N += bucket.size();
  }

  // Choose expected distribution (uniform or pre-computed)
  std::vector<double> expected(size, N / static_cast<double>(size));  // Uniform distribution

  // Calculate chi-squared for each bucket
  std::vector<double> chi_squared(size, 0.0);
  for (int i = 0; i < size; ++i) {
    int observed = hash_table[i].size();
    chi_squared[i] = std::pow(observed - expected[i], 2) / expected[i];
  }

  return chi_squared;
}
