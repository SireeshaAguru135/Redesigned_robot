#include <iostream>

using namespace std;

int main()
{
    int at[20],bt[20],ct[20],tat[20],wt[20],avg_tat=0,avg_wt=0;
    int p[20];
    int i;
    for(i=0;i<5;i++)
    {
        cout<<"Enter Arrival Time : ";
        cin>>at[i];
        cout<<"Enter Burst Time : ";
        cin>>bt[i];
    }
    ct[0]=bt[0];
    
    for(i=0;i<5;i++)
    {
        ct[i+1] = ct[i] + bt[i+1];
    }
    

    for(i=0;i<5;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    avg_tat/=5;
    avg_wt/=5;

    cout<<"Process ID Arrival Time  Burst Time  Complete Time  Turn Around Time  Waiting Time \n";

    for(i=0;i<5;i++)
    {
        cout<<"P"<<i<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<"\n"; 
    }
    cout<<"Average Turn Around Time :- "<<avg_tat<<"\n";
    cout<<"Average Waiting Time :- "<<avg_wt;
    return 0;
}