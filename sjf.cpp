#include <iostream>

using namespace std;

int main()
{
    int at[20],bt[20],ct[20],tat[20],wt[20],index[20];
    int i,c,d,temp;
    float avg_tat=0,avg_wt=0;
    for(i=0;i<5;i++)
    {
        cout<<"Enter Arrival Time : ";
        cin>>at[i];
        cout<<"Enter Burst Time : ";
        cin>>bt[i];
        index[i]=i;
    }

    for(i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(bt[i]>bt[j])
             {
                 temp=at[i];
                 at[i]=at[j];
                 at[j]=temp;

                 c=bt[i];
                 bt[i]=bt[j];
                 bt[j]=c;

                 d=index[i];
                 index[i]=index[j];
                 index[j]=d;

            }
        }
            
    }
    wt[0]=0;

   // for(i=0;i<5;i++)
   // {
    //    cout<<"Arrival Time"<<at[i]<<"\n";
    //    cout<<"Burst Time"<<bt[i]<<"\n";
   // }

    for(i=0;i<5;i++)
    {
        wt[i+1] = wt[i] + bt[i];
        tat[i] = wt[i] + bt[i];
        ct[i] = tat[i]+ at[i];
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