#include <cmath>
#include <iostream>
using namespace std;

struct student {
    string name;
    int id;
    float cgpa;
    student() {}
    student(string __name, int __id, float __cgpa) {
        name = __name;
        id = __id;
        cgpa = __cgpa;
    }

    void setter(string __name, int __id, float __cgpa) {
        name = __name;
        id = __id;
        cgpa = __cgpa;
    }
};

int ceilDiv(int __number, int __divisor) {
    int temp;
    if (__number % 2 == 0) {
        temp = __number / 2;
        return temp;
    } else {
        temp = __number / 2;
        temp += 1;
        return (temp);
    }
}

void studentSwap(student &__s1, student &__s2) {
    student s = __s1;
    __s1 = __s2;
    __s2 = s;
}

class priority_queue {
   private:
    student *data;
    int size;
    int rear;

   public:
    priority_queue(int __size) {
        size = __size;
        data = new student[__size];
        rear = -1;
    }

    bool isFull() {
        if (rear + 1 == size) {
            return true;
        }
        return false;
    }

    void enque(student __obj) {
        if (isFull()) {
            return;
        }
        rear++;
        data[rear] = __obj;
        minHeap(rear);
    }

    void dequeue() {
        studentSwap(data[0], data[rear]);
        for (int i = rear - 1; i >= 0; i--) {
            miHeap(data, i, 0);
        }
        rear = rear - 1;
    }

    void miHeap(student __data[], int __i, int __n) {
        int smallest = __n;
        int leftChild = __n + 1;
        int rightChild = __n + 2;

        if (leftChild < __i && data[leftChild].cgpa < data[smallest].cgpa) {
            smallest = leftChild;
        }

        if (rightChild < __i && data[rightChild].cgpa < data[smallest].cgpa) {
            smallest = rightChild;
        }

        if (smallest != __n) {
            studentSwap(data[smallest], data[__n]);
            miHeap(data, __i, smallest);
        }
    }

    void maHeap(student __data[], int __i, int __n) {
        int highest = __n;
        int leftChild = __n + 1;
        int rightChild = __n + 2;

        if (leftChild < __i && data[leftChild].cgpa > data[highest].cgpa) {
            highest = leftChild;
        }

        if (rightChild < __i && data[rightChild].cgpa > data[highest].cgpa) {
            highest = rightChild;
        }

        if (highest != __n) {
            studentSwap(data[highest], data[__n]);
            miHeap(data, __i, highest);
        }
    }

    void minHeap(int __index) {
        int hole = __index;
        while (ceilDiv(hole, 2) - 1 >= 0) {
            if (data[hole].cgpa < data[ceilDiv(hole, 2) - 1].cgpa) {
                student s = data[ceilDiv(hole, 2) - 1];
                data[ceilDiv(hole, 2) - 1] = data[hole];
                data[hole] = s;
            }
            hole = ceilDiv(hole, 2) - 1;
        }
    }

    void maxHeap(int __index) {
        int hole = __index;
        while (ceilDiv(hole, 2) - 1 >= 0) {
            if (data[hole].cgpa > data[ceilDiv(hole, 2) - 1].cgpa) {
                student s = data[ceilDiv(hole, 2) - 1];
                data[ceilDiv(hole, 2) - 1] = data[hole];
                data[hole] = s;
            }
            hole = ceilDiv(hole, 2) - 1;
        }
    }

    bool isEmpty() {
        if (rear == -1) {
            return true;
        }
        return false;
    }

    student &peak() {
        if (isEmpty()) {
            exit(0);
        }
        return (data[0]);
    }

    void print() {
        for (int i = 0; i <= rear; i++) {
            cout << data[i].id << " " << data[i].name << " " << data[i].cgpa << '\n';
        }
        cout << '\n';
    }

    ~priority_queue() {
        delete[] data;
    }
};

int main(int argc, char const *argv[]) {
    priority_queue p(5);
    student s1("SAJJAD", 355, 3.2);
    student s2("HASSAN", 208, 2.67);
    student s3("RAFAY", 333, 3.1);
    p.enque(s1);
    p.enque(s2);
    p.enque(s3);
    p.print();
    p.dequeue();
    p.print();
    return 0;
}