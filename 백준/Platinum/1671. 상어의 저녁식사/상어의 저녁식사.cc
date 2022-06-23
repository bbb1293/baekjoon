#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct shark {
   int size, speed, iq;
   
   shark(int _size, int _speed, int _iq) {
      size = _size;
      speed = _speed;
      iq = _iq;
   }
} shark;

int n;
bool visited[50];
int who_eat[50];
vector<shark> sharks;
vector< vector<int> > edges(50, vector<int>());

bool can_eat(int prey_idx, int predator_idx) {
   
   shark &prey = sharks[prey_idx];
   shark &predator = sharks[predator_idx];
   
   return predator.size >= prey.size && predator.speed >= prey.speed &&
   predator.iq >= prey.iq;
}

bool does_eat(int cur) {
   
   for (auto prey: edges[cur]) {
      if (visited[prey]) {
         continue;
      }
      
      visited[prey] = true;
      
      if (who_eat[prey] == -1 || does_eat(who_eat[prey])) {
         who_eat[prey] = cur;
         return true;
      }
   }
   
   return false;
   
}

int main()
{
   scanf("%d", &n);
   
   int a, b, c;
   for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &a, &b, &c);
      sharks.push_back(shark(a, b, c));
   }
   
   for (int i = 0; i < n; i++) {
      
      for (int j = 0; j < i; j++) {
         
         if (can_eat(j, i)) {
            edges[i].push_back(j);
            
         } else if (can_eat(i, j)) {
            edges[j].push_back(i);
         }
            
      }
   }
   
   memset(who_eat, -1, sizeof who_eat);
   
   int ret = 0;
   for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n; i++) {
         
         memset(visited, 0, sizeof visited);
         if (does_eat(i)) {
            ret++;
         }
      }
   }
   
   ret = n - ret;
   
   printf("%d", ret);
   
   return 0;
}