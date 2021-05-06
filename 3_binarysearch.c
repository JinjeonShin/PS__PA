#include <stdio.h>
#include <stdlib.h>

typedef struct __student{
    int sc1;
    int sc2;
    int sc3;
    int sc4; // 1 or 2
    int tsa;
}student;

typedef struct __data{
    int num; // tsa의 수, 중복 X, index 
    int* tsa;
    int* tsaNum;
}data;

data input[6][10][18][2];

void QT1_count(int* num, int tsa, data d){
    if(d.num == 0)
        return;
    //binary search 구현, 존재 여부
    int low = 0;
    int high = d.num - 1;
    int mid;

    if(high == 0){
        if(d.tsa[0] == tsa)
            (*num) += d.tsaNum[0];
        return;
    }
    if(tsa == d.tsa[0]){
        (*num)++;
        return;
    }
    if(tsa == d.tsa[d.num - 1]){
        (*num)++;
        return;
    }

    while(low <= high){
        mid = (low + high) / 2;

        if(d.tsa[mid] == tsa){
            (*num)++;
            return;
        }
        else if(d.tsa[mid] > tsa)
            high = mid - 1;
        else
            low = mid + 1;
    }
    

    return;
}


void QT2_count(int* num, int tsa, data d){
    if(d.num == 0)
        return;
    //binary search 구현, 개수!!
    int low = 0;
    int high = d.num - 1;
    int mid;

    if(tsa <= d.tsa[0]){
        *num += d.tsaNum[d.num - 1];
        return;
    }
    if(tsa > d.tsa[d.num - 1]){
        return;
    }
    if(tsa == d.tsa[d.num - 1]){
        *num += d.tsaNum[d.num - 1] - d.tsaNum[d.num - 2];
        return;
    }

    if(high == 0){
        if(d.tsa[0] >= tsa)
            *num += d.tsaNum[0];
        return;
    }

    while(low <= high){
        mid = (low + high) / 2;

        if(d.tsa[mid] == tsa){
            *num += d.tsaNum[d.num - 1] - d.tsaNum[mid - 1];
            return;
        }
        else if(d.tsa[mid] > tsa)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(low == high + 1)
        *num += d.tsaNum[d.num - 1] - d.tsaNum[high];


    return;
}

void QT3_count(int* num, int tsa, data d){
    if(d.num == 0)
        return;
    //binary search 구현, 개수!!
    int low = 0;
    int high = d.num - 1;
    int mid;

    if(tsa < d.tsa[0])
        return;
    if(tsa == d.tsa[0]){
        *num += d.tsaNum[0];
        return;
    }
    if(tsa >= d.tsa[d.num - 1]){
        *num += d.tsaNum[d.num - 1];
        return;
    }

    if(high == 0){
        if(d.tsa[0] <= tsa)
            *num += d.tsaNum[0];
        return;
    }


    while(low <= high){
        mid = (low + high) / 2;

        if(d.tsa[mid] == tsa){
            *num += d.tsaNum[mid];
            return;
        }
        else if(d.tsa[mid] > tsa)
            high = mid - 1;
        else
            low = mid + 1;

    }
    
    if(low == high + 1)
        *num += d.tsaNum[high];

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

//복붙하기

int main(){
    int N, M;
    int sc1, sc2, sc3, sc4, tsa;

    scanf("%d", &N);
    student* temp = (student*)malloc(sizeof(student)*N);
    int categoryNum[6][10][18][2] = { 0 };
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d %d", &sc1, &sc2, &sc3, &sc4, &tsa);
        temp[i].sc1 = sc1;
        temp[i].sc2 = sc2;
        temp[i].sc3 = sc3;

        if(sc4 > 2) sc4 = 1;
        else sc4 = 2;
        temp[i].sc4 = sc4;
        temp[i].tsa = tsa;
        categoryNum[sc1 - 1][sc2 - 1][sc3 - 1][sc4 - 1]++;
    }

    // input 배열 초기화
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){
            for(int m = 0; m < 18; m++){
                for(int n = 0; n < 2; n++){
                    input[i][j][m][n].tsa = (int*)malloc(sizeof(int)*categoryNum[i][j][m][n]);
                    input[i][j][m][n].tsaNum = (int*)malloc(sizeof(int)*categoryNum[i][j][m][n]);
                    input[i][j][m][n].num = 0;
                }
            }
        }
    }

    // input에 옮기기
    for(int i = 0; i < N; i++){
        if(input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].num == 0){
            input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].num++;
            input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsa[0] = temp[i].tsa;
            input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsaNum[0] = 1;
        }
        else{
            int index = input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].num;
            if(input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsa[index - 1] == temp[i].tsa){
                input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsaNum[index - 1] += 1;
            }
            else{
                input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsa[index] = temp[i].tsa;
                input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsaNum[index] = 
                        input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].tsaNum[index-1] + 1;
                input[temp[i].sc1 - 1][temp[i].sc2 - 1][temp[i].sc3 - 1][temp[i].sc4 - 1].num++;
            }
        }
    }

    free(temp);

    // printf("--------------\n");
    // for(int i = 0; i < 6; i++){
    //     for(int j = 0; j < 10; j++){
    //         for(int m = 0; m < 18; m++){
    //             for(int n = 0; n < 2; n++){
    //                 if(input[i][j][m][n].num != 0){
    //                     printf("%d\n", input[i][j][m][n].num);
    //                     for(int x = 0; x < input[i][j][m][n].num; x++)
    //                     {
    //                         // printf("%d %d %d %d %d\n", i, j, m, n, input[i][j][m][n].tsa[x]);
    //                         printf("%d %d %d %d %d    %d\n", i, j, m, n, input[i][j][m][n].tsa[x], input[i][j][m][n].tsaNum[x]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }


        // for(int m = 0; m < 18; m++){
        //     printf("%d\n", input[4][4][m][0].num);
        //     for(int x = 0; x < input[4][4][m][0].num; x++)
        //     {
        //         // printf("%d %d %d %d %d\n", i, j, m, n, input[i][j][m][n].tsa[x]);
        //         printf("%d %d %d %d %d    %d\n", 4, 4, m, 0, input[4][4][m][0].tsa[x], input[4][4][m][0].tsaNum[x]);
        //     }
        // }

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