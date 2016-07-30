#include <cstdio>
#include <cstring>

const int max1 = 10000;
int n;
bool removed[max1];
int cid[max1];
int score[max1][10];
char sid[max1][100], name[max1][100];

void print_menu() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n");   
}

int rank(int t) {
    int rk = 0;
        for (int i = 0; i < n; i++) {
            if (score[t][4] < score[i][4]) rk++;
        }
    return rk;
}

void add() {
    char s[max1];
    for (;;) {
        memset(s, 0, sizeof s);
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
        scanf("%s", s);
        if (strcmp(s, "0") == 0) break;
        bool dup = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(s, sid[i]) == 0 && !removed[i]) {
                dup = true;
                printf("Duplicated SID.\n"); 
                break;
            }
        }
        if (dup) {
            int drop;
            char drops[max1];
            scanf("%d%s%d%d%d%d", &drop, drops, &drop, &drop, &drop, &drop);
        }
        removed[n] = false;
        strcpy(sid[n], s);
        scanf("%d", &cid[n]);
        scanf("%s", name[n]);
        scanf("%d%d%d%d", &score[n][0], &score[n][1], &score[n][2], &score[n][3]);
        for (int i = 0; i < 4; ++i) score[n][4] += score[n][i];
        n++;
    }
}

void DQ(int t) {
    char s[max1];
    for (;;) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0) break;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                if (strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0) {
                    if (t == 1) printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank(i), 
                            sid[i], cid[i], name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], score[i][4] / 4.0);
                    else {
                        removed[i] = true;
                        r++;
                    }
                }
            }
        }
        if (t == 0) printf("%d student(s) removed.\n", r);
    }
}

void stat() {
    char course[10][30] = {"Chinese","Mathematics","English","Programming"};  
    int c, passed, total = 0, sum[9], pc[9], pass[9], fc[9];
    scanf("%d", &c);
    memset(sum, 0, sizeof sum);
    memset(pc, 0, sizeof pc);
    memset(pass, 0, sizeof pass);
    memset(fc, 0, sizeof fc);
    for (int i = 0; i < n; ++i) {
        if (!removed[i]) {
            if (cid[i] == c || c == 0) {
                passed = 4;
                for (int j = 0; j < 4; j++) {
                    sum[j] += score[i][j];
                    if (score[i][j] >= 60) pc[j]++;
                    else passed--, fc[j]++;
                }
            }
            if (passed == 0) pass[0]++;
            else {
                for (int k = 1; k <= passed; k++) pass[k]++;
            }
            total += 1;
        }
    }
    if (total > 0) {
        for (int i = 0; i < 4; i++) {
            double avg = sum[i] / (double) total;
            printf("%s\nAverage Score: %.2f\n", course[i], avg);
            printf("Number of passed students: %d\n", pc[i]);
            printf("Number of failed students: %d\n\n", fc[i]);
        }
        printf("Overall:\nNumber of students who passed all subjects: %d\n", pass[4]);
        printf("Number of students who passed 3 or more subjects: %d\n",pass[3]); 
        printf("Number of students who passed 2 or more subjects: %d\n",pass[2]); 
        printf("Number of students who passed 1 or more subjects: %d\n",pass[1]); 
        printf("Number of students who failed all subjects: %d\n\n",pass[0]); 
    }
}

int main() {
    for (;;) {
        int choice;
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 0: return 0;
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
