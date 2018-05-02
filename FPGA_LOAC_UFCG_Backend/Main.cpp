#include <iostream>
#include <cmath>

#include "VMain.h"

VMain * vmain;

int main() {
  vmain = new VMain;

  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      for (int c = 0; c < 2; c++) {
        for (int d = 0; d < 2; d++) {
          for (int e = 0; e < 2; e++) {
            for (int f = 0; f < 2; f++) {
              for (int g = 0; g < 2; g++) {
                for (int h = 0; h < 2; h++) {
                  int value = a * pow(2, 0) + b * pow(2, 1) + c * pow(2, 2) + d * pow(2, 3)
                   + e * pow(2, 4) + f * pow(2, 5) + g * pow(2, 6) + h * pow(2, 7);
                  vmain->SWI = value;

                  vmain->eval();

                  for (int i = 0; i < 8; i++) {
                    cout << value % 2;
                    value /= 2;
                  }
                  cout << ":";
                  value = (int)vmain->LED;
                  for (int i = 0; i < 8; i++) {
                    cout << value % 2;
                    value /= 2;
                  }
                  value = (int)vmain->SEG;
                  for (int i = 0; i < 8; i++) {
                    cout << value % 2;
                    value /= 2;
                  }
                  cout << endl;
                }
              }
            }
          }
        }
      }
    }
  }

  exit(0);
}
