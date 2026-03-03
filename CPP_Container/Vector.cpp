#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class MyVector {
private:
    T* data;
    int size;
    int capacity;

public:
    MyVector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    MyVector(const MyVector& other) {
        size = other.size;
        capacity = other.capacity;

        if (capacity > 0) 
        {
            data = new T[capacity];

            for (int i = 0 ; i < size ; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
            data = nullptr;
    }

    ~MyVector() {
        delete[] data;
    }

    void printStatus() {
        cout << "Size: " << size << ", Capacity: " << capacity << '\n';
    }

    void push_back(T value) {
    if (size == capacity) 
    {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;

        T* new_data = new T[new_capacity];

        for (int i = 0; i < size; i++) 
        {
            new_data[i] = data[i];
        }

        if (data != nullptr)
        {
            delete[] data;
        }

        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    size++;
    }

    void pop_back() {
        if (size == 0)
            throw std::out_of_range("Size is already Zero");
        else
            size--;
    }

    T& operator[](int index) {
        if (index >= 0 && index < size)
            return data[index];
        else
            throw std::out_of_range("Index Error");
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other)
        {
            return *this;
        }

        delete[] this->data;

        size = other.size;
        capacity = other.capacity;

        if (capacity > 0)
        {
            data = new T[capacity];
            for (int i = 0 ; i < size ; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
            data = nullptr;

        return *this;
    }

    T* begin(){
        return data;
    }

    T* end() {
        return data + size;
    }
};

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    // 범위 기반 for문 (Range-based for loop) 테스트
    for (int x : vec) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}