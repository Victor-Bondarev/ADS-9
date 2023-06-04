// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTtree;
  std::ifstream file(filename);
  std::string otvet;
  while (!file.eof()) {
    char slovooobukva = file.get();
    if (slovooobukva >= 'A' && slovooobukva <= 'Z')
        slovooobukva = slovooobukva + ('a' - 'A');
    if (slovooobukva >= 'a' && slovooobukva <= 'z') {
      otvet = otvet + slovooobukva;
    } else {
      BSTtree.add(result);
      otvet.clear();
    }
  }
  return BSTtree;
}
