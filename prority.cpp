#include<iostream>
 
using namespace std;
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20];
    int i,j,n,total=0,c,temp;
    float avg_wt,avg_tat;
    
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;          
    }
 
    for(i=0;i<n;i++)
    {
        c=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[c])
                c=j;
        }
 
        temp=pr[i];
        pr[i]=pr[c];
        pr[c]=temp;
 
        temp=bt[i];
        bt[i]=bt[c];
        bt[c]=temp;
 
        temp=p[i];
        p[i]=p[c];
        p[c]=temp;
    }
 
    wt[0]=0;            
 
    for(i=1;i<10;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        avg_wt+=wt[i];
    }
       
    cout<<"Process    Burst Time    Turnaround Time   Waiting Time\n";
    for(i=0;i<10;i++)
    {
        tat[i]=bt[i]+wt[i];     
        avg_tat+=tat[i];
        cout<<"P["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<tat[i]<<"\t\t\t"<<wt[i]<<endl;
    }
    avg_wt=avg_wt/10;
    avg_tat=avg_tat/n; 

    cout<<"Average Turn Around Time :- "<<avg_tat<<"\n";
    cout<<"Average Waiting Time :- "<<avg_wt;   
    
    return 0;
}