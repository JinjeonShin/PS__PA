#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node* next;
} node;


typedef struct __list{
    struct __node* head; //필요한가??
    //node* tail; 
} linkedList;

linkedList* input[6][10][18][2]; //입력값, tsa 입력시 sort를 해야 할까??

//linked list 삽입(sort 안함)
void insertion (int sc1, int sc2, int sc3, int sc4, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(input[sc1][sc2][sc3][sc4]->head == NULL)
        input[sc1][sc2][sc3][sc4]->head = newnode;
    else{
        newnode->next = input[sc1][sc2][sc3][sc4]->head;
        input[sc1][sc2][sc3][sc4]->head = newnode;
    }
}

void QT1_count(int* num, int tsa, linkedList* l){
    node* n = l->head;
    while(n != NULL){
        if(n->data == tsa)
            (*num)++;

        n = n->next;
    }

    return;
}

void QT2_count(int* num, int tsa, linkedList* l){
    node* n = l->head;
    while(n != NULL){
        if(n->data >= tsa)
            (*num)++;

        n = n->next;
    }

    return;
}

void QT3_count(int* num, int tsa, linkedList* l){
    node* n = l->head;
    while(n != NULL){
        if(n->data <= tsa)
            (*num)++;

        n = n->next;
    }

    return;
}

//쿼리 1
void QT1 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;

    if(qc1 == 0 && qc2 == 0 && qc3 == 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j ++){
                for(int m = 0; m < 18; m++){
                    for(int n = 0; n < 2; n++){
                        QT1_count(&num, tsa, input[i][j][m][n]);
                    }
                }
            }
        }
    }
    if(qc1 == 0 && qc2 == 0 && qc3 == 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j ++){
                for(int m = 0; m < 18; m++){
                    QT1_count(&num, tsa, input[i][j][m][qc4-1]);
                }
            }
        }
    }
    if(qc1 == 0 && qc2 == 0 && qc3 != 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                for(int n = 0; n < 2; n++){
                    QT1_count(&num, tsa, input[i][j][qc3-1][n]);
                }
            }
        }

    }
    if(qc1 == 0 && qc2 == 0 && qc3 != 0 && qc4 != 0){
         for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                QT1_count(&num, tsa, input[i][j][qc3-1][qc4-1]);
            }
        }
    }
    if(qc1 == 0 && qc2 != 0 && qc3 == 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    QT1_count(&num, tsa, input[i][qc2-1][m][n]);
                }
            }
        }
    }
    if(qc1 == 0 && qc2 != 0 && qc3 == 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            for(int m = 0; m < 18; m++){
                QT1_count(&num, tsa, input[i][qc2-1][m][qc4-1]);
            }
        }

    }
    if(qc1 == 0 && qc2 != 0 && qc3 != 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int n = 0; n < 2; n++){
                QT1_count(&num, tsa, input[i][qc2-1][qc3-1][n]);
            }
        }

    }
    if(qc1 == 0 && qc2 != 0 && qc3 != 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            QT1_count(&num, tsa, input[i][qc2-1][qc3-1][qc4-1]);
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 == 0 && qc4 == 0){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    QT1_count(&num, tsa, input[qc1-1][j][m][n]);
                }
            }
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 == 0 && qc4 != 0){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                QT1_count(&num, tsa, input[qc1-1][j][m][qc4-1]);
            }
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 != 0 && qc4 == 0){
        for(int j = 0; j < 10; j++){
            for(int n = 0; n < 2; n++){
                QT1_count(&num, tsa, input[qc1-1][j][qc3-1][n]);
            }
        }
    }
    if(qc1 != 0 && qc2 == 0 && qc3 != 0 && qc4 != 0){
        for(int j = 0; j < 10; j++){
            QT1_count(&num, tsa, input[qc1-1][j][qc3-1][qc4-1]);
        }

    }
    if(qc1 != 0 && qc2 != 0 && qc3 == 0 && qc4 == 0){
        for(int m = 0; m < 18; m++){
            for(int n = 0; n < 2; n++){
                QT1_count(&num, tsa, input[qc1-1][qc2-1][m][n]);
            }
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 == 0 && qc4 != 0){
        for(int m = 0; m < 18; m++){
            QT1_count(&num, tsa, input[qc1-1][qc2-1][m][qc4-1]);
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 != 0 && qc4 == 0){
        for(int n = 0; n < 2; n++){
            QT1_count(&num, tsa, input[qc1-1][qc2-1][qc3-1][n]);
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 != 0 && qc4 != 0){
        QT1_count(&num, tsa, input[qc1-1][qc2-1][qc3-1][qc4-1]);
    }

    printf("%d\n", num);
}

//쿼리 2
void QT2 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;

    if(qc1 == 0 && qc2 == 0 && qc3 == 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j ++){
                for(int m = 0; m < 18; m++){
                    for(int n = 0; n < 2; n++){
                        QT2_count(&num, tsa, input[i][j][m][n]);
                    }
                }
            }
        }
    }
    if(qc1 == 0 && qc2 == 0 && qc3 == 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j ++){
                for(int m = 0; m < 18; m++){
                    QT2_count(&num, tsa, input[i][j][m][qc4-1]);
                }
            }
        }
    }
    if(qc1 == 0 && qc2 == 0 && qc3 != 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                for(int n = 0; n < 2; n++){
                    QT2_count(&num, tsa, input[i][j][qc3-1][n]);
                }
            }
        }

    }
    if(qc1 == 0 && qc2 == 0 && qc3 != 0 && qc4 != 0){
         for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                QT2_count(&num, tsa, input[i][j][qc3-1][qc4-1]);
            }
        }
    }
    if(qc1 == 0 && qc2 != 0 && qc3 == 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    QT2_count(&num, tsa, input[i][qc2-1][m][n]);
                }
            }
        }
    }
    if(qc1 == 0 && qc2 != 0 && qc3 == 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            for(int m = 0; m < 18; m++){
                QT2_count(&num, tsa, input[i][qc2-1][m][qc4-1]);
            }
        }

    }
    if(qc1 == 0 && qc2 != 0 && qc3 != 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int n = 0; n < 2; n++){
                QT2_count(&num, tsa, input[i][qc2-1][qc3-1][n]);
            }
        }

    }
    if(qc1 == 0 && qc2 != 0 && qc3 != 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            QT2_count(&num, tsa, input[i][qc2-1][qc3-1][qc4-1]);
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 == 0 && qc4 == 0){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    QT2_count(&num, tsa, input[qc1-1][j][m][n]);
                }
            }
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 == 0 && qc4 != 0){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                QT2_count(&num, tsa, input[qc1-1][j][m][qc4-1]);
            }
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 != 0 && qc4 == 0){
        for(int j = 0; j < 10; j++){
            for(int n = 0; n < 2; n++){
                QT2_count(&num, tsa, input[qc1-1][j][qc3-1][n]);
            }
        }
    }
    if(qc1 != 0 && qc2 == 0 && qc3 != 0 && qc4 != 0){
        for(int j = 0; j < 10; j++){
            QT2_count(&num, tsa, input[qc1-1][j][qc3-1][qc4-1]);
        }

    }
    if(qc1 != 0 && qc2 != 0 && qc3 == 0 && qc4 == 0){
        for(int m = 0; m < 18; m++){
            for(int n = 0; n < 2; n++){
                QT2_count(&num, tsa, input[qc1-1][qc2-1][m][n]);
            }
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 == 0 && qc4 != 0){
        for(int m = 0; m < 18; m++){
            QT2_count(&num, tsa, input[qc1-1][qc2-1][m][qc4-1]);
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 != 0 && qc4 == 0){
        for(int n = 0; n < 2; n++){
            QT2_count(&num, tsa, input[qc1-1][qc2-1][qc3-1][n]);
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 != 0 && qc4 != 0){
        QT2_count(&num, tsa, input[qc1-1][qc2-1][qc3-1][qc4-1]);
    }

    printf("%d\n", num);
}

//쿼리 3
void QT3 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;

    if(qc1 == 0 && qc2 == 0 && qc3 == 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j ++){
                for(int m = 0; m < 18; m++){
                    for(int n = 0; n < 2; n++){
                        QT3_count(&num, tsa, input[i][j][m][n]);
                    }
                }
            }
        }
    }
    if(qc1 == 0 && qc2 == 0 && qc3 == 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j ++){
                for(int m = 0; m < 18; m++){
                    QT3_count(&num, tsa, input[i][j][m][qc4-1]);
                }
            }
        }
    }
    if(qc1 == 0 && qc2 == 0 && qc3 != 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                for(int n = 0; n < 2; n++){
                    QT3_count(&num, tsa, input[i][j][qc3-1][n]);
                }
            }
        }

    }
    if(qc1 == 0 && qc2 == 0 && qc3 != 0 && qc4 != 0){
         for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                QT3_count(&num, tsa, input[i][j][qc3-1][qc4-1]);
            }
        }
    }
    if(qc1 == 0 && qc2 != 0 && qc3 == 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    QT3_count(&num, tsa, input[i][qc2-1][m][n]);
                }
            }
        }
    }
    if(qc1 == 0 && qc2 != 0 && qc3 == 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            for(int m = 0; m < 18; m++){
                QT3_count(&num, tsa, input[i][qc2-1][m][qc4-1]);
            }
        }

    }
    if(qc1 == 0 && qc2 != 0 && qc3 != 0 && qc4 == 0){
        for(int i = 0; i < 6; i++){
            for(int n = 0; n < 2; n++){
                QT3_count(&num, tsa, input[i][qc2-1][qc3-1][n]);
            }
        }

    }
    if(qc1 == 0 && qc2 != 0 && qc3 != 0 && qc4 != 0){
        for(int i = 0; i < 6; i++){
            QT3_count(&num, tsa, input[i][qc2-1][qc3-1][qc4-1]);
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 == 0 && qc4 == 0){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    QT3_count(&num, tsa, input[qc1-1][j][m][n]);
                }
            }
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 == 0 && qc4 != 0){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                QT3_count(&num, tsa, input[qc1-1][j][m][qc4-1]);
            }
        }

    }
    if(qc1 != 0 && qc2 == 0 && qc3 != 0 && qc4 == 0){
        for(int j = 0; j < 10; j++){
            for(int n = 0; n < 2; n++){
                QT3_count(&num, tsa, input[qc1-1][j][qc3-1][n]);
            }
        }
    }
    if(qc1 != 0 && qc2 == 0 && qc3 != 0 && qc4 != 0){
        for(int j = 0; j < 10; j++){
            QT3_count(&num, tsa, input[qc1-1][j][qc3-1][qc4-1]);
        }

    }
    if(qc1 != 0 && qc2 != 0 && qc3 == 0 && qc4 == 0){
        for(int m = 0; m < 18; m++){
            for(int n = 0; n < 2; n++){
                QT3_count(&num, tsa, input[qc1-1][qc2-1][m][n]);
            }
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 == 0 && qc4 != 0){
        for(int m = 0; m < 18; m++){
            QT3_count(&num, tsa, input[qc1-1][qc2-1][m][qc4-1]);
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 != 0 && qc4 == 0){
        for(int n = 0; n < 2; n++){
            QT3_count(&num, tsa, input[qc1-1][qc2-1][qc3-1][n]);
        }
    }
    if(qc1 != 0 && qc2 != 0 && qc3 != 0 && qc4 != 0){
        QT3_count(&num, tsa, input[qc1-1][qc2-1][qc3-1][qc4-1]);
    }


    printf("%d\n", num);
}

int main(){
    //input 배열 동적할당
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    input[i][j][m][n] = (linkedList*)malloc(sizeof(linkedList));
                    input[i][j][m][n]->head = NULL;
                    //input[i][j][m][n]->tail = NULL;
                }
            }
        }
    }

    int M, N;
    int sc1, sc2, sc3, sc4, tsa;

    //데이터 입력
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d %d %d", &sc1, &sc2, &sc3, &sc4, &tsa);
        
        //쿼리 형태로 변경
        if(sc4 < 3) //졸업 불가
            sc4 = 2;
        else        //졸업 가능
            sc4 = 1;

        //linked list에 tsa 저장
        insertion(sc1-1, sc2-1, sc3-1, sc4-1, tsa);
    }
    
    /*
    linkedList* l = input[0][5][11][1];
    node* n = l->head;
    printf("%d", n->data);
    while(n->next != NULL){
        n = n->next;
        printf("%d\n", n->data);
    }
    */

    //쿼리 입력
    int qt, qc1, qc2, qc3, qc4, Q_tsa;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
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