Difference between linkedlist and array and where one is more usefull:

so while counting the nodes the time complexity of linkedlist is O(n) while in 
arrays it O(1)

as for counting no of nodes u just wrote the code in "countingNodes.c" while in 
arrays it just "int n=sizeof(arr)/sizeof(arr[0]);

for printing the data both have same O(n) time complexity.

*time complexity for deleting node at the end in LL and Array*
in case of linkedlist the time complexity will be O(n) cause we will traverse the list
to the end to find the last node and then delete that node but in case of array it would be O(1) as we just do there *int size=sizeof(arr)/sizeof(arr[0])* and then we do *size=size-1* so now we say that the array is not arr[20] but its arr[19] , i.e we just now print the values for n=size; i.e for(int i=0;i<n;i++>) we dont have to update anything 
so *NOTE: deleting node at end for LinkedList- O(n) & for array O(1)*

*and this is opposite for deleting node at starting*
i.e for LL we have O(1) for deleting node at beginning whereas in array we first replace the arr[i]=arr[i+1]; and then we do size=size-1 so here O(n)
so *NOTE: deleting node at begin for LinkedList- O(1) & for array O(n)*
