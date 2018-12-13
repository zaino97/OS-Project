//Please edit the value assigned to the variable "size" in line #7 accordingly for time calculation

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

#define size 100000

void *bubbleSort()
{

	printf("\n\nBubble sort, sorts %d elements in descending order now..\n\n", size);
	int counter;
	srand((time(NULL)));
	int *theList = (int*)malloc(sizeof(int)*size);

        for(counter = 0; counter < size; counter++)
        {
              theList[counter] = (rand() % 900000)+1;

	}

	int temp_bubble;

	for (int counter = 0; counter < size; counter++)
	    {
		for (int count = counter + 1; count < size; count++)
		{
		    if (theList[count] > theList[counter])
		    {
		      temp_bubble = *(theList + count);
		      *(theList + count) = *(theList + counter);
		      *(theList + counter) = temp_bubble;
		    }
		}
	   }

free(theList);
}

void *shellSort()
{

	printf("\n\nShell sort, sorts %d elements in ascending order now..\n\n", size);
	int counter;
	srand((time(NULL)));
	int *theList = (int*)malloc(sizeof(int)*size);

        for(counter = 0; counter < size; counter++)
        {
              theList[counter] = (rand() % 9000000)+1;

	}

	int temp_shell;
	int count;
	int gap;

	for(gap = size / 2; gap > 0; gap /= 2)
        {

		for (counter = gap; counter < size; counter++)
        	    {

                temp_shell = *(theList + counter);
                count = counter - gap;

                    {

                    while (count >= 0 && *(theList + count) > temp_shell)
                    {

                       *(theList + (count+gap)) = *(theList + count);
                       count = count - gap;

                    }

                   *(theList + (count+gap)) = temp_shell;

                }

            }
        }
free(theList);
}


int main()
{
 	pthread_t shellThread;
	pthread_t bubbleThread;
	int counter;

	printf ("List being sorted in descending order...\n\n");

	double startShellTime = clock();

	pthread_create(&shellThread, NULL, &shellSort, (void *)NULL);
	pthread_join(shellThread, NULL);

	double endShellTime = clock();

	printf("Time taken by shell sort using pThreads: %lf milliseconds \n", (endShellTime - startShellTime) / 1000);

	double startBubbleTime = clock();

	pthread_create(&bubbleThread, NULL, &bubbleSort, (void *)NULL);
	pthread_join(bubbleThread, NULL);

	double endBubbleTime = clock();

	printf("Time taken by bubble sort using pThreads: %lf milliseconds \n", (endBubbleTime - startBubbleTime) / 1000);


}
