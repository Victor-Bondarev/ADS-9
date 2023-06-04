// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::string w;
  std::ifstream file(filename);
  BST<std::string>* tree = new BST<std::string>;
  char str = ' ';
  while (!file.eof()) {
    while (str < 65 && (!file.eof())) {
      file.get(str);
    }
    while (str >= 65 && (!file.eof())) {
      if (str >= 65 && str <= 90) {
        w += str;
      }
      if (str >= 97 && str <= 122) {
        w += str;
      }
      file.get(str);
    }
    for (int i = 0; i < w.length(); i++) {
      if (w[i] >= 65 && w[i] <= 90)
        w[i] += 32;
    }
    (*tree).add(w);
    w = "";
  }
  return *tree;
}
