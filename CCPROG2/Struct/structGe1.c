#include <stdio.h>
#include <string.h>

typedef char String[101];
typedef char String3000[3001];

struct DateTag{
    int year;
    int month;
    int day;
};

struct AccountTag{
    String accountName;
    struct DateTag creationDate;
};

struct CommentTag{
    struct AccountTag *postedBy;
    struct DateTag postDate;
    String commentText;
    int numThumbsUp;
    int numThumbsDown;
};

struct VideoTag{
    String videoID;
    struct AccountTag *postedBy;
    struct DateTag postDate;
    int numComments;
    struct CommentTag comments[100];
};

typedef struct DateTag Date;
typedef struct VideoTag Video;
typedef struct AccountTag Account;
typedef struct CommentTag Comment;
typedef Video VideoList[100];


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


int main(){
    VideoList vids;
    Video video1;
    Account account1;

    printf("%s", vids->videoID);


    return 0;
}