# Практикум 7

### Дървета

#### Задача 1
Напишете функция, която обхожда дърво по следния начин - 
ляво - корен - дясно(Inorder Traversal)

#### Задача 2 
Напишете функция, която приема указател към корена на дърво и цяло число n и принтира елементите, които се намират на ниво n.

#### Задача 3
Напишете функция, която приема указател към корена на дърво и цяло число n и принтира сумата на елементите, които се намират на ниво n.

#### Задача 4
Напишете функция, която приема указател към корена на дърво и низ, съставен само от символите 'l', 'r', и принтира елемента, към който сочи низът
(като 'l' означава дa търсим в текущото ляво поддърво, а 'r' - в дясното).

#### Задача 5 
Напишете фунцкия, която приема указател към корена на дърво и цяло число x и връща низа, който сочи към него(като използваме условието от горната задача).

#### Задача 6
Напишете фунцкия, която приема указател към корена на дърво и променя дървото в неговата огледална форма.

#### Задача 7
Напишете фунцкия, която приема указател към корена на дърво и проверява дали то е двоично дърво за търсене(BST).

#### Забележка : Използвайте следната структура: 

```c++
template <typename T>
struct Node {
  T data;
  Node<T>* left, *right;

  Node() {
    left = nullptr;
    right = nullptr;
  }

  Node(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};
```
  