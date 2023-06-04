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
    char slovoobukva = file.get();
    if (slovoobukva >= 'A' && slovoobukva <= 'Z')
        slovoobukva = slovoobukva + ('a' - 'A');
    if (slovoobukva >= 'a' && slovoobukva <= 'z') {
      otvet = otvet + slovoobukva;
    } else {
      BSTtree.add(result);
      otvet.clear();
    }
  }
  return BSTtree;
}
