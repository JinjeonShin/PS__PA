#include <stdio.h>
#include <stdlib.h>

typedef struct __student{
    int sc1;
    int sc2;
    int sc3;
    int sc4; // 1 or 2
    int tsa;
}student;

int compare(const void* m, const void*n){
    student *a, *b;
    a = (student*) m;
    b = (student*) n;

    if(a->tsa < b->tsa) return -1;
    if(a->tsa > b->tsa) return 1;

    return 0;
}

typedef struct __node{
    int data;
    struct __node* next;
} node;


typedef struct __list{
    int node_Num;
    struct __node* head; //필요한가??
    //node* tail; 
} linkedList;

linkedList* input[6][10][18][2]; //입력값, tsa 입력시 sort를 해야 할까??

//linked list 삽입(sort 안함)
void insertion (int sc1, int sc2, int sc3, int sc4, int data){
    input[sc1][sc2][sc3][sc4]->node_Num++;
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
	
		if(num > 0)
    	printf("1\n");
		else
			printf("0\n");
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
    int N, M;
    int sc1, sc2, sc3, sc4, tsa;

    //input 배열 동적할당
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    input[i][j][m][n] = (linkedList*)malloc(sizeof(linkedList));
                    input[i][j][m][n]->head = NULL;
                    input[i][j][m][n]->node_Num = 0;
                    //input[i][j][m][n]->tail = NULL;
                }
            }
        }
    }

    scanf("%d", &N);
    // student* temp = (student*)malloc(sizeof(student)*N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d %d", &sc1, &sc2, &sc3, &sc4, &tsa);
        // temp[i].sc1 = sc1;
        // temp[i].sc2 = sc2;
        // temp[i].sc3 = sc3;

        if(sc4 > 2) sc4 = 1;
        else sc4 = 2;

        insertion(sc1 - 1, sc2-1, sc3-1, sc4-1, tsa);
        // temp[i].sc4 = sc4;
        // temp[i].tsa = tsa;
    }

    //sort
    // qsort(temp, N, sizeof(student), compare);

    // free(temp);

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