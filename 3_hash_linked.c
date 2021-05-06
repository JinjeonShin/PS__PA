#include <stdio.h>
#include <stdlib.h>

int h1 = 100000, h2 = 1000, h3 = 10, h4 = 1, h0 = 0;

typedef struct __node{
    int data;
    struct __node* next;
} node;


typedef struct __list{
    int node_Num;
    struct __node* head;
} linkedList;

linkedList* input[610200];

void insertion (int tsa, int key){

    input[key]->node_Num++;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = tsa;
    newnode->next = NULL;

    if(input[key]->head == NULL)
        input[key]->head = newnode;
    else{
        newnode->next = input[key]->head;
        input[key]->head = newnode;
    }
}

void set (int sc1, int sc2, int sc3, int sc4, int tsa){
    int key = 0;
    //
    key = sc1*h1 + sc2*h2 + sc3*h3 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h2 + sc3*h3 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h2 + sc3*h0 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h2 + sc3*h0 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h0 + sc3*h3 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h0 + sc3*h3 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h0 + sc3*h0 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h1 + sc2*h0 + sc3*h0 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h2 + sc3*h3 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h2 + sc3*h3 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h2 + sc3*h0 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h2 + sc3*h0 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h0 + sc3*h3 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h0 + sc3*h3 + sc4*h0;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h0 + sc3*h0 + sc4*h4;
    insertion(tsa, key);
    //
    key = sc1*h0 + sc2*h0 + sc3*h0 + sc4*h0;
    insertion(tsa, key);

}

void QT1_count(int* num, int tsa, linkedList* l){
    node* n = l->head;
    while(n != NULL){
        if(n->data == tsa)
            (*num)++;
        if(tsa > n->data)
            return;

        n = n->next;
    }

    return;
}

void QT2_count(int* num, int tsa, linkedList* l){
    node* n = l->head;
    while(n != NULL){
        if(n->data >= tsa)
            (*num)++;
        else
            return;

        n = n->next;
    }

    return;
}

void QT3_count(int* num, int tsa, linkedList* l){
    int k = 0;
    node* n = l->head;
    while(n != NULL){
        if(n->data > tsa)
            k++;
        else{
            (*num) += l->node_Num - k;
            break;
        }

        n = n->next;
    }

    return;

    /*
    node* n = l->head;
    while(n != NULL){  
        if(n->data <= tsa)
            (*num)++;

        n = n->next;
    }

    return;
    */
}

//쿼리 1
void QT1 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;
    int key = qc1*h1 + qc2*h2 + qc3*h3 + qc4*h4;
    QT1_count(&num, tsa, input[key]);

    if(num > 0)
        printf("1\n");
    else   
        printf("0\n");
}

//쿼리 2
void QT2 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;
    int key = qc1*h1 + qc2*h2 + qc3*h3 + qc4*h4;
    QT2_count(&num, tsa, input[key]);

    printf("%d\n", num);
}

//쿼리 3
void QT3 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;

    int key = qc1*h1 + qc2*h2 + qc3*h3 + qc4*h4;
    QT3_count(&num, tsa, input[key]);

    printf("%d\n", num);
}

int main(){
    int N, M;
    int sc1, sc2, sc3, sc4, tsa;

    // for(int i = 0; i < 610200; i++){
    //     input[i] = (linkedList*)malloc(sizeof(linkedList));
    //     input[i]->head = NULL;
    // }

    for(int i = 0; i <= 6; i++){
        for(int j = 0; j <= 10; j++){
            for(int m = 0; m <= 18; m++){
                for(int n = 0; n <= 2; n++){
                    int key = i*h1 + j*h2 + m*h3 + n*h4;
                    input[key] = (linkedList*)malloc(sizeof(linkedList));
                    input[key]->head = NULL;
                }
            }
        }
    }

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d %d", &sc1, &sc2, &sc3, &sc4, &tsa);

        if(sc4 > 2) sc4 = 1;
        else sc4 = 2;

        set(sc1, sc2, sc3, sc4, tsa);
    }

    //쿼리 입력
    int qt, qc1, qc2, qc3, qc4, Q_tsa;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d %d %d %d", &qt, &qc1, &qc2, &qc3, &qc4, &Q_tsa);

        switch (qt)
        {
        case 1 :
            QT1(qc1, qc2, qc3, qc4, Q_tsa);
            break;
        case 2 :
            QT2(qc1, qc2, qc3, qc4, Q_tsa);
            break;
        case 3 :
            QT3(qc1, qc2, qc3, qc4, Q_tsa);
            break;
        default :
            break;
        }
    }

    


    return 0;
}