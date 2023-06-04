// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::string slovo;
  std::ifstream file(filename);
  BST<std::string>* tree = new BST<std::string>;
  char dlina = ' ';
  while (!file.eof()) {
    while (dlina < 65 && (!file.eof())) {
      file.get(str);
    }
    while (dlina >= 65 && (!file.eof())) {
      if (dlina >= 65 && dlina <= 90) {
        slovo += dlina;
      }
      if (dlina >= 97 && dlina <= 122) {
        slovo += dlina;
      }
      file.get(dlina);
    }
    for (int i = 0; i < slovo.length(); i++) {
      if (slovo[i] >= 65 && w[i] <= 90)
        slovo[i] += 32;
    }
    (*tree).add(slovo);
    slovo = "";
  }
  return *tree;
}
