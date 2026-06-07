#include<stdio.h>
int main(){
int n, i;
int at[20],bt[20],ct[20],tat[20],wt[20];
float avg_tat=0,avg_wt=0;
printf("Enter no. processes:");
scanf("%d",&n);
printf("Enter AT and BT:");
for(i=0;i<n;i++){
    scanf("%d%d", &at[i], &bt[i]);
}
ct[0]=bt[0];
for(i=1;i<n;i++){
    ct[i]=ct[i-1]+bt[i];
}
for(i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    avg_tat+=tat[i];
    avg_wt+=wt[i];
}
avg_tat/=n;
avg_wt/=n;
printf("Avg TAT=%.2f",avg_tat);
printf("Avg WT =%.2f",avg_wt);

printf("\nGantt Chart:\n");
for(i=0;i<n;i++){
    printf("|P%d",i+1);
}
printf("\n");
printf("0");
for(i=0;i<n;i++){
    printf(" %d",ct[i]);
}
return 0;
}
