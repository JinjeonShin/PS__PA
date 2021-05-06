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
    int* arr;
    int* arrNum;
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

void search(int key){
    linkedList* l = input[key];
    if(l->node_Num == 0)
        return;

    l->arr = (int*)malloc(sizeof(int)*l->node_Num);
    l->arrNum = (int*)malloc(sizeof(int)*l->node_Num);

    int index = 0;
    node* n = l->head;
    l->arr[index] = n->data;
    l->arrNum[index] = 1;
    index++;
    n = n->next;
    while(n != NULL){
        if(n->data == l->arr[index - 1])
            l->arrNum[index - 1] += 1;
        else{
            l->arr[index] = n->data;
            l->arrNum[index] = 1;
            index++;
        }

        n = n->next;
    }

    l->node_Num = index;
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

void QT1_count(int* num, int tsa, linkedList* d){
    if(d->node_Num == 0)
        return;
    //binary search 구현, 존재 여부
    int low = 0;
    int high = d->node_Num - 1;
    int mid;

    if(high == 0){
        if(d->arr[0] == tsa)
            (*num) += d->arrNum[0];
        return;
    }
    if(tsa == d->arr[0]){
        (*num)++;
        return;
    }
    if(tsa == d->arr[d->node_Num- 1]){
        (*num)++;
        return;
    }

    while(low <= high){
        mid = (low + high) / 2;

        if(d->arr[mid] == tsa){
            (*num)++;
            return;
        }
        else if(d->arr[mid] > tsa)
            high = mid - 1;
        else
            low = mid + 1;
    }
    

    return;
}

void QT2_count(int* num, int tsa, linkedList* d){
    if(d->node_Num == 0)
        return;
    //binary search 구현, 개수!!
    int low = 0;
    int high = d->node_Num - 1;
    int mid;

    if(tsa <= d->arr[0]){
        *num += d->arrNum[d->node_Num - 1];
        return;
    }
    if(tsa > d->arr[d->node_Num - 1]){
        return;
    }
    if(tsa == d->arr[d->node_Num - 1]){
        *num += d->arrNum[d->node_Num - 1] - d->arrNum[d->node_Num - 2];
        return;
    }

    if(high == 0){
        if(d->arr[0] >= tsa)
            *num += d->arrNum[0];
        return;
    }

    while(low <= high){
        mid = (low + high) / 2;

        if(d->arr[mid] == tsa){
            *num += d->arrNum[d->node_Num - 1] - d->arrNum[mid - 1];
            return;
        }
        else if(d->arr[mid] > tsa)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(low == high + 1)
        *num += d->arrNum[d->node_Num - 1] - d->arrNum[high];


    return;
}

void QT3_count(int* num, int tsa, linkedList* d){
    if(d->node_Num == 0)
        return;
    //binary search 구현, 개수!!
    int low = 0;
    int high = d->node_Num - 1;
    int mid;

    if(tsa < d->arr[0])
        return;
    if(tsa == d->arr[0]){
        *num += d->arrNum[0];
        return;
    }
    if(tsa >= d->arr[d->node_Num - 1]){
        *num += d->arrNum[d->node_Num - 1];
        return;
    }

    if(high == 0){
        if(d->arr[0] <= tsa)
            *num += d->arrNum[0];
        return;
    }


    while(low <= high){
        mid = (low + high) / 2;

        if(d->arr[mid] == tsa){
            *num += d->arrNum[mid];
            return;
        }
        else if(d->arr[mid] > tsa)
            high = mid - 1;
        else
            low = mid + 1;

    }
    
    if(low == high + 1)
        *num += d->arrNum[high];

    return;
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

    for(int i = 0; i <= 6; i++){
        for(int j = 0; j <= 10; j++){
            for(int m = 0; m <= 18; m++){
                for(int n = 0; n <= 2; n++){
                    search(i*h1 + j*h2 + m*h3 + n*h4);
                }
            }
        }
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