#include <iostream>
//#include "kucha.h"

#include "vector"

template<typename T>
class Kucha
{
public:
    std::vector <T> src;
    int size;
    Kucha(std::vector<T> a, bool need_sort);
    Kucha();
    int sift_up(int i);
    int sift_down(int i);
    void delete_(int i);
    int plus_x(int i, int x);
    int minus_x(int i, int x);
};

template<typename T>
Kucha<T>::Kucha(std::vector<T> a, bool need_sort) {
    src = a;
    size = a.size();
    for(int i = size-1; i >= 0 && need_sort; i++)
        sift_down(i);
}

template<typename T>
Kucha<T>::Kucha() {
    size = 0;
}

template<typename T>
int Kucha<T>::sift_up(int i) {
    int prev = (i-1)/2, now = i;
    while(now != 0 && src[now] > src[prev])
    {
        std::swap(src[now], src[prev]);
        now = prev;
        prev = (now - 1)/2;
    }
    return now;
}

template<typename T>
int Kucha<T>::sift_down(int i) {
    int next1 = i*2 +1, next2 = i*2 +2, now = i;
    while(next1 < size)
    {
        std::cout << "ok";//infinitive problem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(next2 < size)
        {
            if(src[next1] > src[next2] && src[next1] > src[now])
            {
                std::swap(src[next1] , src[now]);
                now = next1;
            }
            else if(src[next2] > src[next1] && src[next2] > src[now])
            {
                std::swap(src[next2] , src[now]);
                now = next2;
            }
        }
        else
        {
            if(src[next1] > src[now])
            {
                std::swap(src[next1] , src[now]);
                now = next1;
            }
        }
        next1 = 2*now+1;
        next2 = 2*now+2;
    }
    return now;
}

template<typename T>
void Kucha<T>::delete_(int i) {
    swap(src[i], src[size - 1]);
    src.pop_back();
    size--;
    sift_down(i);
}

template<typename T>
int Kucha<T>::plus_x(int i, int x){
    src[i] += x;
    return sift_up(i);
}

template<typename T>
int Kucha<T>::minus_x(int i, int x){
    src[i] -= x;
    return sift_down(i);
}

int main() {
    Kucha<int> kucha;
    int n,x, id;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        kucha.src.push_back(x);
    }
    kucha.size = kucha.src.size();
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> id >> x;
        std::cout << kucha.minus_x(id-1, x)+1 << " ";
    }
    for(int i = 0; i < kucha.size; i++)
        std::cout << kucha.src[i] << " ";

    return 0;
}
