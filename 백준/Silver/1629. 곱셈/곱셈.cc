#include <iostream>
#include <vector>

using namespace std;

long long a, b, c;

long long sol(int n) {
   
   if (n == 1) {
      return a % c;
   }
   
   if (n % 2 == 1) {
      return (((a * sol(n / 2)) % c) * sol(n / 2)) % c;
   } else {
      return (sol(n / 2) * sol(n / 2)) % c;
   }
}

int main()
{
   
   scanf("%lld %lld %lld", &a, &b, &c);
   
   printf("%lld", sol(b));
   
   return 0;
}