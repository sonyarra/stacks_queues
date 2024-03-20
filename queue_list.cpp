#include <iostream>
#include <list>
#include <ctime>

const int array_size = 10000;

template <typename T>
struct queue_list {
    std::list<T> storage;

    void add_element(T element) {
        if (storage.size() >= array_size) {
            // Если размер очереди достиг предела, то не добавляем новый элемент
            std::cout << "Очередь переполнена, нельзя добавить элемент" << std::endl;
        } else {
            storage.push_back(element);
        }
    }

    T get_element() {
        if (storage.empty()) {
            // Если очередь пуста, сообщаем об этом и возвращаем дефолтное значение элемента
            std::cout << "Очередь пуста, нельзя извлечь элементы" << std::endl;
            return T();
        } else {
            // Извлекаем элемент из начала очереди и возвращаем его
            T front_element = storage.front();
            storage.pop_front();
            return front_element;
        }
    }
};

int main() {    
    queue_list<int> my_queue;

    // Добавляем элементы в очередь
    my_queue.add_element(50);
    my_queue.add_element(9);
    my_queue.add_element(15);

    // Извлекаем элементы из очереди
    std::cout << my_queue.get_element() << std::endl;
    std::cout << my_queue.get_element() << std::endl;
    std::cout << my_queue.get_element() << std::endl;

    return 0;
}

