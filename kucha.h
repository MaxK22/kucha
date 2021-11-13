//
// Created by korotkov.ma on 13.11.2021.
//

#ifndef KUCHA_KUCHA_H
#define KUCHA_KUCHA_H

#include "vector"

template<typename T>
class Kucha
{
public:
    std::vector <T> src;
    int size;
    Kucha(std::vector<T> a, bool need_sort);
    Kucha();
    void sift_up(int i);
    void sift_down(int i);
    void delete_(int i);
    void plus_x(int i, int x);
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
void Kucha<T>::sift_up(int i) {
    int prev = (i-1)/2, now = i;
    while(now != 0 && src[now] > src[prev])
    {
        swap(src[now], src[prev]);
        now = prev;
        prev = (now - 1)/2;
    }
}

template<typename T>
void Kucha<T>::sift_down(int i) {
    int next1 = i*2 +1, next2 = i*2 +2, now = i;
    while(next1 < size)
    {
        if(next2 < size)
        {
            if(src[next1] > src[next2] && src[next1] > src[now])
            {
                swap(src[next1] , src[now]);
                now = next1;
            }
            else if(src[next2] > src[next1] && src[next2] > src[now])
            {
                swap(src[next2] , src[now]);
                now = next2;
            }
        }
        else
        {
            if(src[next1] > src[now])
            {
                swap(src[next1] , src[now]);
                now = next1;
            }
        }
        next1 = 2*now+1;
        next2 = 2*now+2;
    }
}

template<typename T>
void Kucha<T>::delete_(int i) {
    swap(src[i], src[size - 1]);
    src.pop_back();
    size--;
    sift_down(i);
}


template<typename T>
void Kucha<T>::plus_x(int i, int x){
    src[i] += x;
    sift_up(i);
}

#endif //KUCHA_KUCHA_H
