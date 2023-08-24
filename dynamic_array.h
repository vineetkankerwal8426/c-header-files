#include <iostream>
using namespace std;

template <typename t>
class array
{
    t *arr;
    int capacity;
    int current;

public:
    array()
    {
        arr = new t[1];
        capacity = 1;
        current = 0;
    }
    ~array()
    {
        delete[] arr;
    }

    void push(t data)
    {
        if (current == capacity)
        {
            t *temp = new t[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void push(t data, int index)
    {
        if (current == capacity)
        {
            push(data);
        }
        else
            arr[index] = data;
    }

    void print()
    {
        for (int i = 0; i < current; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void insert(t data, int index)
    {
        int i = 0;
        int j = 0;
        if (index > current || index <0)
        {
            cout << "invalid";
        }
        else if (current == capacity)
        {
            t *temp = new t[2 * capacity];

            while (i != current + 1)
            {
                if (i == index)
                {
                    temp[i] = data;
                    i++;
                }
                else
                {
                    temp[i] = arr[j];
                    i++;
                    j++;
                }
            }
            delete[] arr;
            arr = temp;
            current++;
        }
        else
        {
            for (int i = current; i >= index; i--)
            {
                t temp = arr[i];
                arr[i + 1] = temp;
            }
            arr[index] = data;
            current++;

        }
    }
};



