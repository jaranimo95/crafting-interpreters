#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup_c(const char *s) {
    size_t len = strlen(s) + 1;
    char *p = malloc(len);
    if (p) {
        memcpy(p, s, len);
    }
    return p;
}

struct Node {
    struct Node *prev;
    char *value;
    struct Node *next;
};

void insert(struct Node *curr, struct Node *new) {
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;
    new->prev = curr;
    return;
}

void delete(struct Node *curr, struct Node *to_delete) {
    while (curr != NULL) {
        if(strcmp(curr->value, to_delete->value) == 0) {
            printf("Found delete match: %s\n", curr->value);
            
            struct Node *prev;
            struct Node *next;
            if (to_delete->prev != NULL) {
                prev = to_delete->prev;
            }
            if (to_delete->next != NULL) {
                next = to_delete->next;
            }
            prev->next = next;
            next->prev = prev;
            
            free(to_delete->value);
            break;
        }
        curr = curr->next;
    } 
    return;
}

int main() {
    struct Node first = { NULL, strdup_c("abcde"), NULL};
    struct Node second = { NULL, strdup_c("bcdef"), NULL};
    struct Node third = { NULL, strdup_c("cdefg"), NULL};
    struct Node four = { NULL, strdup_c("defgh"), NULL};

    insert(&first, &second);
    insert(&first, &third);
    insert(&second, &four);
    delete(&first, &second);

    struct Node *curr = &first;
    while(curr != NULL) {
        printf("%s\n", curr->value);
        curr = curr->next;
    }

    return 0;
}
