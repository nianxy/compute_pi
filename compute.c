#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const char* do_compute(int iteration, int precision) {
  const int r = iteration*1000/2;
  long s1 = 2, s2 = 2;
  int halfr = r/2;
  for (int i=-r+1; i<0; ++i) {
    int pow_i = pow(i, 2);
    for (int j=-r; j<r; ++j) {
      if (sqrt(pow_i+pow(j,2))<=r) {
        s1 += 2*(2*-j+1);
        s2 += 2*(2*-j+1+2);
        break;
      }
    }
  }
  s1+=2*r;
  s2+=2*r;
  char format[100];
  sprintf(format, "%%.%df ~ %%.%df", precision, precision);
  char* number = malloc(1000);
  sprintf(number, format, s1/pow(r,2), s2/pow(r,2));
  return number;
}

int main(int argc, char** argv) {
  if (argc!=3) {
    printf("usage: compute <iteration> <precision>\n");
    exit(1);
  }

  int iteration = atoi(argv[1]);
  int precision = atoi(argv[2]);

  const char* pi = do_compute(iteration, precision);
  printf("pi is %s\n", pi);

  return 0;
}
