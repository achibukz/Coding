#include <stdio.h>
#include <string.h>

int getTotalLikes(VideoList list, String3000 accountName){
    int i,j;
    int totLikes = 0;
      
    for (i = 0; i < 100; i++){
        Video video = list[i];

        if (strcmp(video.postedBy -> accountName, accountName) == 0){

            for (j = 0; j < video.comments[j].numThumbsUp;j++){
                totLikes += video.comments[j].numThumbsUp;
            }

        }
    }

    return totLikes;
}