#include <stdio.h>
#include <stdlib.h>

int h1 = 100000, h2 = 1000, h3 = 10, h4 = 1, h0 = 0;

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

data* input[610200];

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
	
	if(num > 0)
    	printf("1\n");
	else
		printf("0\n");
}

//쿼리 2
void QT2 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;


    printf("%d\n", num);
}

//쿼리 3
void QT3 (int qc1, int qc2, int qc3, int qc4, int tsa){
    int num = 0;



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
                    input[sc1*h1 + sc2*h2 + sc3*h3 + sc4*h4]->tsa = (int*)malloc(sizeof(int)*categoryNum[i][j][m][n]);
                    input[sc1*h1 + sc2*h2 + sc3*h3 + sc4*h4]->tsaNum = (int*)malloc(sizeof(int)*categoryNum[i][j][m][n]);
                    input[sc1*h1 + sc2*h2 + sc3*h3 + sc4*h4]->num = 0;
                }
            }
        }
    }

    // input에 옮기기



    free(temp);

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