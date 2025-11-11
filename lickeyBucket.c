//Leacky Bucket Program 
//#include<stdio.h>
//int main(){
//	int bs,opr,n,ips,str=0,i;
//	
//	printf("Enter the bucket size: ");
//	scanf("%d",&bs);
//	printf("\nEnter the output rate: ");
//	scanf("%d",&opr);
//	printf("\nEnter the number of input Packet: ");
//	scanf("%d",&n);
//	
//	for(i=1;i<=n;i++)
//	{
//		printf("\nEnter the size of input packet (%d): ",i);
//		scanf("%d",&ips);
//		printf("Incomming packet size = %d KB\n",ips);
//	
//		if((ips+str)>bs){
//			printf("\nBucket is overflow! packet size %d is discarded.",(ips+str)-bs);
//			str = bs;
//		}
//		else{
//			str=str+ips;
//			printf("Buffer packet in bucket %d KB",str);
//		}
//		str=str-opr;
//	
//		if(str < 0)
//			str = 0;
//		printf("\nAter sending packets left in bucket %d: ",str);
//	}
//	
//	while(str > 0)
//	{
//		printf("\nsending remaining packets  %dKB left.",str);
//		str=str-opr;
//		if(str < 0)
//			str = 0;
//		printf("\nAfter sending packet left = %dKB",str);
//	}
//	printf("\nAll packets sent Bucket is now empty\n");
//	return 0;
//}

#include<stdio.h>
int main()
{
	int bs,opr,ips,n,str=0,i;
	
	printf("\nEnter the Bucket size: ");
	scanf("%d",&bs);
	printf("\nEnter the output rate: ");
	scanf("%d",&opr);
	printf("\nEnter the number of size of input value: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the size of packet %d (in KB): ",i);
		scanf("%d",&ips);
		printf("\nIncomming packet size = %d KB",ips);
		
		if((ips+str)>bs)
		{
			printf("\nBucket is overflow! , %d packets are diascarded!",(ips+str)-bs);
			str=bs;
		}else{
			str=ips+str;
			printf("\nbuffered in the bucket = %d",str);
		}
		
		str=str-opr;
		if(str<0)
			str=0;
		printf("\nAfter sending   packets, %d packets are left.",str);
		
	}
	while(str>0)
	{
		printf("\nRemaining packets are %d KB",str);
		str=str-opr;
		if(str<0)
			str=0;
		printf("\nAfter sending all packets, %d packets are left.",str);
		
	}
	printf("\nAfter sending all packets, bucket is empty now.");
	return 0;
}
