#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > vec(128, vector<int>(128));
int white_paper, blue_paper;

void num_paper(int x, int y, int n) {
   
   int current = vec[x][y];
   
   for (int xx = x; xx < x + n; xx++) {
      for (int yy = y; yy < y + n; yy++) {
         if (vec[xx][yy] != current) {
            num_paper(x, y, n / 2);
            num_paper(x + n / 2, y, n / 2);
            num_paper(x, y + n / 2, n / 2);
            num_paper(x + n / 2, y + n / 2, n / 2);
            return;
         }
      }
   }
   
   if (current == 1) {
      blue_paper++;
   } else {
      white_paper++;
   }
   
}

int main()
{
   int n;
   
   scanf("%d", &n);
   
   for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
         scanf("%d", &vec[x][y]);
      }
   }
   
   num_paper(0, 0, n);
   
   printf("%d\n%d", white_paper, blue_paper);
   
   return 0;
}