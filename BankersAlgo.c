/*
    Name: Arpan Manna
    Dept.: Data Science
    Banker's Algorithm
*/
#include<stdio.h>

void main(){
    int i;
    int j;
    int k = 0;
    int flag;
    int flag1 = 0;
    int processNo;
    int resourceNo;
    printf("Enter the number of processes: ");
    scanf("%d", &processNo);
    printf("\n");
    printf("Enter the number of resources: ");
    scanf("%d", &resourceNo);
    printf("\n");
    int process[processNo][resourceNo];
    int resource[resourceNo];
    int alloc[processNo][resourceNo];
    int need[processNo][resourceNo];
    int safeProcess[processNo];
    int f[processNo];
    for(i = 0; i < processNo; i++){
        f[i] = 0;
    }
    printf("Enter the max alloc of the processes:\n");
    for(i = 0; i < processNo; i++){
        printf("Enter the max alloc of P[%d]:\n", i);
        for(j = 0; j < resourceNo; j++){
            printf("resource %d : ", j);
            scanf("%d", &process[i][j]);
            printf("\n");
        }
    }
    printf("Enter the already allocated resources of the processes:\n");
    for(i = 0; i < processNo; i++){
        printf("Enter the alloc of P[%d]:\n", i);
        for(j = 0; j < resourceNo; j++){
            printf("resource %d : ", j);
            scanf("%d", &alloc[i][j]);
            printf("\n");
        }
    }
    printf("Enter the max resources of the system:\n");
    for(i = 0; i < resourceNo; i++){
        printf("resource %d : ", i);
        scanf("%d", &resource[i]);
        printf("\n");
    }
    for(i = 0; i < processNo; i++){
        for(j = 0; j < resourceNo; j++){
            need[i][j] = process[i][j] - alloc[i][j];
        }
    }
    for(j = 0; j < resourceNo; j++){
        for(i = 0; i < processNo; i++){
            resource[j] =  resource[j] - alloc[i][j];
        }
    }
    printf("Available resource: \n");
    for(i = 0; i < resourceNo; i++){
        printf("R[%d]: %d\n", i, resource[i]);
    }
    printf("\t|Max allocation|\t|Already allocated|\t|Remaining need|\n");
    for(i = 0; i < processNo; i++){
        printf("P[%d]:", i);
        printf("\t\t");
        for(j = 0; j < resourceNo; j++){
            printf("%d ", process[i][j]);
        }
        printf("\t\t\t");
        for(j = 0; j < resourceNo; j++){
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t\t");
        for(j = 0; j < resourceNo; j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for(int r = 0; r < processNo; r++){
        for(i = 0; i < processNo; i++){
            if(f[i] == 0){
                flag = 0;
                for(j = 0; j < resourceNo; j++){
                    if(need[i][j] > resource[j]){
                        flag++;
                    }
                }
                if(flag == 0){
                    safeProcess[k] = i;
                    k++;
                    for(j = 0; j < resourceNo; j++){
                        resource[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    
    for(i = 0; i < processNo; i++){
        if(f[i] == 0){
            flag1++;
        }
    }
    if(flag1 > 0){
        printf("The system is in unsafe state!!!\n");
    }
    else{
        printf("The system is in safe state\n");
        printf("The safety sequence is: \n");
        for(i = 0; i < processNo; i++){
            printf("P[%d]->", safeProcess[i]);
        }
        printf("End\n");
    }
}