/*
# Name: Franklin Colton Parry
# Course: CS3260 - 001
# Assignment:  #6
# File: Assn6.c

Promise of originality
I promise that this source code file, in it's entirety, been
written by myself and by no other person or persons.  If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/



#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE  100
#define MAX_QUEUE_SIZE  10

int file2array(FILE *fp, int *processArray, int max)
{

  int count = 0;
  	  while(count < max && fscanf(fp, "%d", &processArray[count]) == 1)
	  {
		count++;
	  }
	  return count;
 
}

int fcfs(int * processArray, int time, int count)
{
int i;
	
	for(i = 1; i < count; i++)
	{
		time +=  abs(processArray[i] - processArray[i-1]);
	}	

	return time;
}


int sstf(int * processArray, int time, int count)
{
int i;
int j;

int index = 0;
int tempTime1 = 0;
int tempTime2 = -1;
int loc = -1;
int p = 0; 
time = 0;
int indexArray[MAX_ARRAY_SIZE];

for(; p < count; p++)
{
	indexArray[p] = 0;
}


indexArray[0] = 1;
	
	for(i = 1; i < count; i++)
	{
	
		for(j = 1; j < count; j++)
			{

				if(indexArray[j] == 0)
				{
				
					tempTime1 = abs(processArray[index]-processArray[j]);
				
					if(tempTime2 == -1)
					{
						tempTime2 = tempTime1;
					}
					
					if(tempTime1 < tempTime2)
					{
						tempTime2 = tempTime1;
						loc = j;
					}
					
					if (tempTime1 == tempTime2)
					{
						if(loc < j)
							loc = loc;
						else
							loc = j;
					}

				}
			}

		time += tempTime2;
		tempTime2 = -1;
		index = loc;
		indexArray[index] = 1;
	}

return time;
}

int look(int * processArray, int time, int count)
{
int i;
int j;

int index = 0;
int tempTime1 = 0;
int tempTime2 = -1;
int loc = -1;
int p = 0; 
int max = 0;
time = 0;
int reachedMax = 0;

int indexArray[MAX_ARRAY_SIZE];

for(; p < count; p++)
{
	indexArray[p] = 0;
}


indexArray[0] = 1;
	
	for(i = 1; i < count; i++)
	{
		for(p = 0; p < count; p++)
		{
			if(processArray[p] > max)
			{
				max = processArray[p];
			}
		}
	
		for(j = 1; j < count; j++)
			{
				if(max != processArray[index] && reachedMax < 1)
				{
					if(indexArray[j] == 0)
					{
						if(processArray[index] < processArray[j])
						{
							tempTime1 = abs(processArray[index]-processArray[j]);
						
							if(tempTime2 == -1)
							{
								tempTime2 = tempTime1;
								loc = j;
							}
							
							if (tempTime1 < tempTime2)
							{
								tempTime2 = tempTime1;
								loc = j;
							}
						}
					}
				}
				
				else
				{				
				reachedMax = 1;
				
					if(indexArray[j] == 0)
						{
							if(processArray[index] > processArray[j])
							{
								tempTime1 = abs(processArray[index]-processArray[j]);
							
								if(tempTime2 == -1)
								{
									tempTime2 = tempTime1;
									loc = j;
								}
								
								if (tempTime1 < tempTime2)
								{
									tempTime2 = tempTime1;
									loc = j;
								}
							}
						}
				
				}
			}

			time += tempTime2;
		tempTime2 = -1;
		index = loc;
		indexArray[index] = 1;
	}

return time;
}


int clook(int * processArray, int time, int count)
{

int i;
int j;

int index = 0;
int tempTime1 = 0;
int tempTime2 = 0;
int loc = -1;
int p = 0; 
int max = 0;
time = 0;
int min = -1;
int minIndex = -1;


int indexArray[MAX_ARRAY_SIZE];

for(; p < count; p++)
{
	indexArray[p] = 0;
}


indexArray[0] = 1;
	
	for(i = 1; i < count; i++)
	{
		for(p = 0; p < count; p++)
		{
			if(processArray[p] > max)
			{
				max = processArray[p];
			}
			
			if(min == -1)
			{
				min = processArray[p];
				minIndex = p;
			}
			else 	if(processArray[p] < min)
			{
				min = processArray[p];
				minIndex = p;
			}
		}
	
		for(j = 1; j < count; j++)
			{
				if(max != processArray[index])
				{
					
					if(indexArray[j] == 0)
					{
						if(processArray[index] < processArray[j])
						{
							tempTime1 = abs(processArray[index]-processArray[j]);
						
							if(tempTime2 == 0)
							{
								tempTime2 = tempTime1;
								loc = j;
							}
							
							if (tempTime1 < tempTime2)
							{
								tempTime2 = tempTime1;
								loc = j;
							}
						}
					}
				}
				else
				{
				index = minIndex;
				time += abs(max - processArray[index]);
				}
			}

		time += tempTime2;
		tempTime2 = 0;
		index = loc;
		indexArray[index] = 1;

	}

return time;
}


int main()
{
int processArray[MAX_ARRAY_SIZE];
int count = 500;
int time = 0;

count = file2array(stdin, processArray, MAX_ARRAY_SIZE);

printf("Assignment 6: Block Access Algorithm\n");
printf("By:  Franklin Colton Parry\n"); 

printf("_________________________________________________________________\n");
time = fcfs(processArray, time, count);
printf("FCFS Total Seek: %d\n", time);

time = sstf(processArray,time,count);
printf("SSTF Total Seek: %d\n", time);

time = look(processArray,time,count);
printf("Look Total Seek: %d\n", time);

time = clook(processArray,time,count);
printf("C-Look Total Seek: %d\n\n", time);


return 0;
}
