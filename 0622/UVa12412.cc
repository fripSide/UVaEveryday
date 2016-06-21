#include <cstdio>

void add() {

}

void DQ(int t) {

}

void stat() {
    
}

int main() {
    for (;;) {
        int choice;
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 0: break;
            case 1:
                add();
                break;
            case 2:
                DQ(0);
                break;
            case 3:
                DQ(1);
                break;
            case 4:
                printf("\n");
                break;
            case 5:
                stat();
                break;

        }
    }
    return 0;
}
