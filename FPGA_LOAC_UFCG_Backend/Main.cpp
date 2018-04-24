#include <iostream>

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
                  vmain->SWI[0] = a;
                  vmain->SWI[1] = b;
                  vmain->SWI[2] = c;
                  vmain->SWI[3] = d;
                  vmain->SWI[4] = e;
                  vmain->SWI[5] = f;
                  vmain->SWI[6] = g;
                  vmain->SWI[7] = h;

                  vmain->eval();

                  for (int i = 0; i < 8; i++) {
                    cout << (int)vmain->SWI[i];
                  }
                  cout << ":";
                  for (int i = 0; i < 8; i++) {
                    cout << (int)vmain->LED[i];
                  }
                  for (int i = 0; i < 8; i++) {
                    cout << (int)vmain->SEG[i];
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
}
