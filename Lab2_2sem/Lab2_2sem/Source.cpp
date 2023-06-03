#include <iostream>
#include <ctime>

using namespace std;
struct list
{
    int data;
    list* next;
    list* prev;
};
list* head;

void AddList(int value, int position)
{
    clock_t start = clock();
    list* node = new list;
    node->data = value;
    if (head == NULL)
    {
        node->next = node;
        node->prev = node;
        head = node;
    }
    else
    {
        list* p = head;
        for (int i = position; i > 1; i--)
            p = p->next;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;
    }
    cout << "\nЭлемент добавлен...\n" << endl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Время добалвения элементов " << seconds << endl;
}

int DeleteList(int position)
{
    clock_t start = clock();
    if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
    if (head == head->next)
    {
        delete head;
        head = NULL;
    }
    else
    {
        list* a = head;
        for (int i = position; i > 1; i--)
            a = a->next;
        if (a == head)
            head = a->next;
        a->prev->next = a->next;
        a->next->prev = a->prev;
        delete a;
    }
    cout << "\nЭлемент удален...\n\n" << endl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Время удаления элемента " << seconds << endl;
}

void CountList()
{
    int count = 0;
    if (head == NULL) cout << "\n0\n\n";
    else
    {
        list* a = head;
        do
        {
            a = a->next;
            count++;
        } while (a != head);
        cout << count << "\n";
    }
}

void PrintList()
{
    clock_t start = clock();
    if (head == NULL) cout << "\nСписок пуст\n\n";
    else
    {
        list* a = head;
        cout << "\nЭлемент: ";
        do
        {
            cout << a->data << " ";
            a = a->next;
        } while (a != head); cout << "\n\n";
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl << "Время получения элементов " << seconds << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int value, position, x;
    do
    {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Вывести список" << endl;
        cout << "4. Вывести размерность списка" << endl;
        cout << "5. Обменять элементы списка" << endl;
        cout << "0. Выйти" << endl;
        cout << "\nНомер операции > "; cin >> x;
        switch (x)
        {
        case 1:
            cout << "Значение > "; cin >> value;
            cout << "Позиция > "; cin >> position;
            AddList(value, position);
            break;
        case 2:
            cout << "Позиция > "; cin >> position;
            DeleteList(position); break;
        case 3:
            PrintList(); break;
        case 4:
            cout << "Размерность списка > ";
            CountList(); break;
        }
    } while (x != 0);
}