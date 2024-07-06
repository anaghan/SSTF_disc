#include<stdio.h>
int main(){
    int tracks,i,start,curr,min,j,hm_comp,next,ind,nextInd,head_movement=0;
    printf("Enter no. of tracks:");
    scanf("%d",&tracks);
    tracks+=1;
    int track[tracks],done[tracks];
    printf("Enter tracks:");
    for (i=1;i<tracks;i++){
        scanf("%d",&track[i]);
    }
    printf("Enter starting read/write head position:");
    scanf("%d",&start);
    track[0]=start;
    for (i=0;i<tracks;i++){
        done[i]=0;
    }
    curr=start;
    done[0]=1;
    j=1;
    while (j<=tracks){
        min=9999;
        for (i=0;i<tracks;i++){
            if (done[i]!=1){
                if (track[i]>curr){
                    hm_comp=track[i]-curr;
                }
                else{
                    hm_comp=curr-track[i];
                }
                if (min>hm_comp){
                    min=hm_comp;
                    next=track[i];
                    ind=i;
                }
            }
        }    
        if (j==tracks){
            printf("%d",curr);
        }
        else{
            printf("%d->",curr);
            head_movement+=min;
        }
        j++;
        curr=next;
        done[ind]=1;
    }
    printf("\nTotal head movement=%d",head_movement);
    return 0;
}
