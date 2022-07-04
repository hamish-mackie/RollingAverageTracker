//
// Created by postonlylosses on 1/07/22.
//
#pragma once

#include <list>
#include <iostream>

template<class T>
class RollingAverageTracker {
public:
    explicit RollingAverageTracker(int list_size);

    void add_node(T n);
    T get_average();

private:
    T total_;
    int list_size_;
    T average_;
    std::list<T> nodes_;
};

template<class T>
RollingAverageTracker<T>::RollingAverageTracker(int list_size):
        list_size_(list_size),
        total_(0),
        average_(0){
            if(list_size_ < 1){
               std::cerr << "List size invalid number: " << list_size <<
                            " Make it 1 so things still work. \n"
                            "But its not really an average now is it?" << std::endl;
               list_size_ = 1;
            }
}

template<class T>
void RollingAverageTracker<T>::add_node(T n) {
    nodes_.push_back(n);
    total_ += n;

    if(nodes_.size() > list_size_){
        int t = nodes_.front();
        total_ -= t;
        nodes_.pop_back();
    }
    average_ = total_ / int(nodes_.size());
}

template<class T>
T RollingAverageTracker<T>::get_average() {
    return average_;
}

