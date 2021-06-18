#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    double std_cost, std_distance, cost_per_m, per_distance;
    int n;
    scanf("%lf %lf %lf %lf %d",&std_cost,&std_distance,&cost_per_m,&per_distance,&n);
    
    if(n == 0) printf("0\n");
    
    int i;
    
    char time[n];
    double dis[n];
    for(i = 0; i < n; i++){
        scanf("%s %lf",time,&dis[i]);
    }
    
    double cost[n];
    for(i = 0; i < n; i++){
        cost[i] = 0.0;
        if(std_distance >= dis[i] && strchr(time, '22:' | '23:' | '00:') == NULL){
            cost[i] = std_cost;
            printf("%i 人目%f\n",i + 1,cost[i]);
        }
        else if(std_distance >= dis[i] && strchr(time, '22:' | '23:' | '00:') != NULL){
            cost[i] = 1.2 * std_cost;
            printf("%i人 目%f\n",i + 1,cost[i]);
        }
        else if(std_distance < dis[i] && strchr(time, '22:' | '23:' | '00:') == NULL){
            cost[i] = std_cost + cost_per_m * (dis[i] - std_distance) / per_distance;
            printf("%i人目 %f\n",i + 1,cost[i]);
        }
        else if(std_distance < dis[i] && strchr(time, '22:' | '23:' | '00:') != NULL){
            cost[i] = 1.2 * (std_cost + cost_per_m * (dis[i] - std_distance) / per_distance);
            printf(" %i人目%f\n",i + 1,cost[i]);
        }
    }
    return 0;
}
