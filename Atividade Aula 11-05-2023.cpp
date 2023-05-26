#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
    T data;

public:
    bool isEmpty() {
        return data.empty();
    }

    void push(const typename T::value_type& value) {
        data.push_back(value);
    }

    typename T::value_type pop() {
        if (isEmpty()) {
            cerr << "A pilha está vazia." << endl;
            return typename T::value_type();
        }
        typename T::value_type value = data.back();
        data.pop_back();
        return value;
    }
};

int main() {
    Stack<list<int>> oddStack, evenStack;
    Stack<vector<int>> oddVectorStack, evenVectorStack;
    int previous = INT32_MIN;
    int count = 0;

    while (count < 30) {
        int num;
        cout << "Digite o número " << count + 1 << ": ";
        cin >> num;

        if (num > previous) {
            if (num % 2 == 0) {
                evenStack.push(num);
                evenVectorStack.push(num);
            } else {
                oddStack.push(num);
                oddVectorStack.push(num);
            }
            previous = num;
            count++;
        } else {
            cout << "O número digitado deve ser maior do que o anterior." << endl;
        }
    }

    cout << "Desempilhando os números pares (lista encadeada):" << endl;
    while (!evenStack.isEmpty()) {
        cout << evenStack.pop() << " ";
    }
    cout << endl;

    cout << "Desempilhando os números pares (vetor):" << endl;
    while (!evenVectorStack.isEmpty()) {
        cout << evenVectorStack.pop() << " ";
    }
    cout << endl;

    cout << "Desempilhando os números ímpares (lista encadeada):" << endl;
    while (!oddStack.isEmpty()) {
        cout << oddStack.pop() << " ";
    }
    cout << endl;

    cout << "Desempilhando os números ímpares (vetor):" << endl;
    while (!oddVectorStack.isEmpty()) {
        cout << oddVectorStack.pop() << " ";
    }
    cout << endl;

    return 0;
}
