//#include<stdio.h>
//#include<stdlib.h>
//#include<unistd.h>
//#define T_F 10
//#define W_S 4
//
//int main()
//{
//	int sentup=0, ackup=0 , i;
//	
//	printf("\nsliding window protocol simulation\n");
//	printf("\nTotal Frames: %d | window size %d\n\n",T_F,W_S);
//	
//	while(ackup < T_F)
//	{
//		for(i=0;i<W_S && sentup < T_F; i++)
//		{
//			printf("\nSender : sending frame %d \n",sentup+1);
//			sentup++;
//		}
//		sleep(1);
//		int ack=(rand() % W_S) + 1;
//		
//		if(ackup+ack > T_F)
//			ack=T_F-ackup;
//		ackup+=ack;
//		printf("Receiver : Acknoweledge up to Frame %d \n\n",ackup);
//		sleep(1);
//	}
//	printf("\nAll %d frames transmitted Successfully!\n",T_F);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define T_F 10
#define W_S 4
int main()
{
	int sent_up=0, ack_up=0,i;
	printf("\ Sliding window protocol simulation\n");
	printf("\nTotal Frames %d | Window Frames %d ",T_F, W_S);
	while(ack_up < T_F){
		for(i=0;i<W_S && sent_up<T_F;i++)
		{
			printf("\nSender : sending frame %d \n",sent_up+1);
			sent_up++;
		}
		sleep(1);
		int ack = rand() % W_S +1;
		if(ack_up + ack > T_F) 
			ack = T_F - ack_up;
		ack_up += ack;
		printf("Reciever : Acknoweledge upto Frame %d \n\n",ack_up);
		sleep(1);
	}	
		printf("All %d frames transmitted successfully!\n",T_F);
		return 0;	
}
