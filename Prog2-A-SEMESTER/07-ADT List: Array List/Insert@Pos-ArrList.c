int main() {
    ArrayList myList = {{}, 0};  // Empty list

    insertAtPos(&myList, 0, 10);  // [10]
    insertAtPos(&myList, 1, 30);  // [10, 30]
    insertAtPos(&myList, 1, 20);  // [10, 20, 30]

    printf("List: ");
    for (int i = 0; i < myList.size; i++) {
        printf("%d ", myList.items[i]);
    }

    return 0;
}
