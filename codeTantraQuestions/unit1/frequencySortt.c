
#include <stdio.h>
typedef struct{
int value;
int frequency;
int firstIndex;
} info;

void bubbleSort(info used[],int count){
	for(int i=0;i<count-1;i++){
		for(int j=0;j<count-1-i;j++){
			if(used[j].frequency<used[j+1].frequency || (used[j].frequency==used[j+1].frequency && used[j].firstIndex>used[j+1].firstIndex)){
				info temp=used[j];
				used[j]=used[j+1];
				used[j+1]=temp;
			}
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	info total[m+1];
	for(int i=0;i<=m;i++){
		total[i].value=i;
		total[i].frequency=0;
		total[i].firstIndex=n+1;
	}
	for(int i=0;i<n;i++){
		int num=arr[i];
		total[num].frequency++;
		if(total[num].firstIndex==n+1)
			total[num].firstIndex=i;
	}
	
	info used[n];
	int count=0;
	for(int i=0;i<=m;i++){
		if(total[i].frequency>0)
			used[count++]=total[i];
	}

	bubbleSort(used,count);

	for(int i=0;i<count;i++){
		for(int j=0;j<used[i].frequency;j++){
			printf("%d ",used[i].value);
		}
	}
}