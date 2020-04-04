#include<stdio.h>
#include<conio.h>
int no_of_resources;
int no_of_processes;
int current_instances[3][3];
int maximum_instances[3][3];;
int avail[3];
int resource_allocation[3]={0,0,0};
int maximum_resources[5];
int processing[5];
int safe=0;
int count=0;
int i,j;
int proc;
int main()
{
printf("\nenter processes available: ");
scanf("processes are %d", &no_of_processes);
for (i = 0; i < no_of_processes; i++) 
{
processing[i] = 1;
count++;
}
printf("\nEnter resources available: ");
scanf("resources are %d ", &no_of_resources);
printf("\n :");
for (i = 0; i<no_of_resources; i++) 
{ 
scanf("%d", &maximum_resources[i]);
}
prinf("\n allocate the resources to processes");
for (i = 0; i < no_of_processes; i++) 
{
for (i = 0; i < no_of_resources; i++)
{
scanf("%d",&current_instances[i][j]);
}
}

printf("\n maximun no of instances available is:\n");
for (i = 0; i<no_of_processes; i++) 
{
for(j = 0; j< no_of_resources; j++) 
{
scanf("%d", &maximum_instances[i][j]);
}
}

printf("\n resources required is: ");
for(i=0;i<no_of_resources;i++)
{
printf("\t %d",maximum_resources[i]);
}


printf("\n resources allocated to the processes p0,p1, and p2 are :\n);
for (i = 0; i <no_of_processes; i++) 
{
for (j = 0; j <no_of_resources; j++) 
{
printf("\t%d", current_instances[i][j]);
}
printf("\n");
}


printf("\n table for maximun no of instances available is:\n");
for (i = 0; i<no_of_processes; i++) 
{
for(j = 0; j< no_of_resources; j++) 
{
printf("\t%d", maximum_instances[i][j]);

}
printf("\n");
}


for (i = 0; i<no_of_processes; i++) 
{
for(j = 0; j< no_of_resources; j++) 
{
resource_allocation[j] +=current_instances[i][j];
}
}
printf("\nallocation of resources");
for(i= 0; i< no_of_resources; i++) 
{
printf("\t%d",resource_allocation[i]);
}
for(i= 0; i< no_of_resources; i++) 
{
avail[i]=maximum_resources[i]-resource_allocation[i];
}
printf("\n resources available is :");
for(i=0;i<no_of_resources;i++);
{
printf("\t%d",avail[i]);
}
printf("\n");
while(count!=0)
{
safe=0;
for (i = 0; i<no_of_processes; i++) 
{
if(processing[i])
{
proc=1;
for(j = 0; j< no_of_resources; j++) 
{
if(maximum_instances[i][j]-current_instances[i][j]>avail[j])
{
proc=0;
break;
}
if(proc)
{
printf("\n process %d is excecuting \n",i+1);
processing[i]=0;
count--;
safe=1;
for(j = 0; j< no_of_resources; j++)
{
avail[j]+=current_instances[i][j];
}
break;
}
}
}
if(!safe)
{
printf("\n processes are unsafe");
break;
}
else
{
printf("\n processes 
are safe");
printf("\n available :");
for (i = 0; i<no_of_resources; i++) 
{
printf("\t%d",avail[i]);
}
printf("\n");
}
}
return 0;
}
