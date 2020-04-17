#include <iostream>

using namespace std;

int gcd(long long a, long long b){
    int tmp,min,max;
    if(a < b) {min = a, max=b;}
    else {min = b; max = a;}
    while(min != 0){
        tmp = (max % min);
        max = min;
        min = tmp;
    }
    return max;
}

long long solution(int w,int h)
{
    long long w1=w,h1=h;
    return (w1 * h1) - (w1 + h1 - gcd(w1,h1));
}
