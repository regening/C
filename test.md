##  DAY1 内容

1. **理解并复习数据类型**：熟悉常见的数据类型，并能识别它们的使用场景。
2. **掌握数组与指针**：编写代码，使用指针访问数组元素，理解数组与指针的关系。
3. **结构体与动态内存**：理解如何使用结构体管理复杂数据，并实践动态内存分配与释放。
4. **函数使用**：编写函数并在程序中调用。
---
#### 今日任务：
---
1. **数组与指针**：创建一个整数数组，使用指针遍历数组中的元素。
```c
#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};            // 创建一个整数数组
    int *p = arr;                                 // 指针指向数组首元素
    for (int i = 0; i < 5; i++) {                 // 使用指针遍历数组
        printf("Element %d: %d\n", i, *(p + i));  // 通过指针访问数组元素
    }
    return 0;
}
```
---
2. **结构体**：定义一个结构体`Book`，包含书名、作者和出版年份。创建一个`Book`结构体实例，输出其信息。
```c
#include <stdio.h>
struct Book {                                     // 定义结构体
    char title[50];
    char author[50];
    int year;
};
int main() {                                     // 创建结构体实例并初始化
    struct Book book1 = {"C Programming", "Dennis Ritchie", 1978};   
    printf("Book Title: %s\n", book1.title);     // 输出结构体成员
    printf("Author: %s\n", book1.author);
    printf("Year of Publication: %d\n", book1.year);
    return 0;
}
```
---
3. **动态内存管理**：使用`malloc`分配一个整数数组，并让用户输入元素，最后输出数组内容并释放内存。
```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter the number of elements: ");// 获取用户输入的数组大小
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));// 使用malloc分配内存
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", n); // 输入数组元素
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are:\n"); // 输出数组内容
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);// 释放内存
    return 0;
}
```

---

##  DAY2 内容

1. **数组练习**：创建一个数组并进行遍历、修改操作，理解如何通过索引访问和修改元素。
2. **链表练习**：编写链表代码，实现链表的插入、删除和遍历功能。
3. **比较**：理解数组和链表的区别，并思考在实际应用中分别何时使用数组或链表。
---
#### 今日任务
---
1. **数组**：创建一个包含10个整数的数组，计算数组元素的总和并输出结果。
```c
#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 初始化一个长度为10的整数数组
    int sum = 0;

    for (int i = 0; i < 10; i++) {    // 使用循环遍历数组并求和
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);    // 输出数组元素的总和

    return 0;
}
// 输出：
// Sum of array elements: 55
```
---
2. **链表**：* 创建一个链表，插入3个节点，并编写一个函数删除链表中间的节点（非头尾节点）。
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {   // 定义节点结构体
    int data;
    struct Node* next;
};

struct Node* create(int data) {     // 创建一个新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {// 插入节点到链表头部
    struct Node* newNode = create(data);
    newNode->next = *head;
    *head = newNode;
}

void print(struct Node* head) {// 打印链表
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void delete(struct Node** head) {// 删除链表中间的节点
    if (*head == NULL || (*head)->next == NULL) {
        printf("No middle node to delete.\n");
        return;  // 链表为空或只有一个元素时没有中间节点
    }

    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {    // 使用快慢指针找到中间节点
        fast = fast->next->next;  // 快指针每次移动两步
        prev = slow;              // 慢指针每次移动一步
        slow = slow->next;
    }

    if (prev != NULL) {    // 删除中间节点
        prev->next = slow->next;
        free(slow);  // 释放中间节点的内存
    }
}

int main() {
    struct Node* head = NULL;

    insert(&head, 30);    // 插入3个节点
    insert(&head, 20);
    insert(&head, 10);

    printf("Original Linked List: ");    // 打印链表内容
    print(head);

    delete(&head);    // 删除中间节点
    printf("After deleting the middle node: ");
    print(head);

    return 0;
}
// 输出：
// Original Linked List: 10 -> 20 -> 30 -> NULL
// After deleting the middle node: 10 -> 30 -> NULL
```

---
