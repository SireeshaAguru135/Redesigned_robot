#include<iostream>

using namespace std;
 
int main()
{
  int wt,tat,at[10],bt[10],rt[10];
  int k=10,i,j,time,condition=0,time_quantum;
  float avg_wt,avg_tat;
  
  for(i=0;i<10;i++)
  {
    cout<<"Enter Arrival Time and Burst Time for Process Process Number :",i+1;
    cin>>at[i];
    cin>>bt[i];
    rt[i]=bt[i];
  }
  cout<<"Enter Time Quantum: ";
  cin>>time_quantum;
  cout<<"Process   Turnaround Time   Waiting Time\n";
  for(time=0,i=0;k!=0;)
  {
    if(rt[i]<=time_quantum && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      condition=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[i]==0 && condition==1)
    {
      k--;
      wt+=time-at[i]-bt[i];
      tat+=time-at[i];
      condition=0;
      cout<<"P"<<i+1<<"\t\t"<<tat<<"\t\t"<<wt<<"\n";;
    }
    if(i==10-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }
  avg_wt=avg_wt/10;
  avg_tat=avg_tat/10; 

  cout<<"Average Turn Around Time :- "<<avg_tat<<"\n";
  cout<<"Average Waiting Time :- "<<avg_wt;
    
  
  return 0;
}