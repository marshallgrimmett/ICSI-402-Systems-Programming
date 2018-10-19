#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char *str1, char *str2){
    char string1[20];
    strcpy(string1,str1);
    char string2[20];
    strcpy(string2,str2);
    char *temp= strtok(string1," ");
    
    char *time1= strtok(NULL," ");
     char *year1= strtok(temp, "-");
     char *month1=strtok(NULL,"-");
     char *date1= strtok(NULL,"-");
     char *hour1= strtok(time1,"-");
     char *min1=strtok(NULL,"-");
    char *temp1= strtok(string2," ");
    char *time2= strtok(NULL," ");
     char *year2= strtok(temp1, "-");
     char *month2=strtok(NULL,"-");
     char *date2= strtok(NULL,"-");
     char *hour2= strtok(time2,"-");
     char *min2=strtok(NULL,"-");
    
    if(atoi(year1)<atoi(year2)){
        return 0;
    }else if(atoi(year1)>atoi(year2)){
        return 1;
    }else{
        if(atoi(month1)<atoi(month2)){
            return 0;
        }else if(atoi(month1)>atoi(month2)){
            return 1;
        }else{
            if(atoi(date1)<atoi(date2)){
             return 0;
            }else if(atoi(date1)>atoi(date2)){
             return 1;
            }else{
                if(atoi(hour1)<atoi(hour2)){
                    return 0;
                }else if(atoi(hour1)>atoi(hour2)){
                    return 1;
                }else{
                    if(atoi(min1)<atoi(min2)){
                        return 0;
                    }else if(atoi(min1)>atoi(min2)){
                        return 1;
                    }
                }
            }
        }
    }
  
    return 0;

}
// void swap(char *xp, char *yp) 
// { 
//     char *temp;
    
    
// }

void bubbleSort(char **arr, const int n) 
{
    char record[50],record1[50];
    char *temp,*temprecord;
    char *date1,*date2;
   int i, j; 
   for (i = 0; i < n-1; i++){  

       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  {
        strcpy(record,arr[j]);
        
        temp= strtok(record," ");
        strtok(NULL," ");
        strtok(NULL," ");
        date1=strtok(NULL,"");
        strcpy(record1,arr[j+1]);
        temp= strtok(record1," ");
        strtok(NULL," ");
        strtok(NULL," ");
        date2=strtok(NULL,"");
        //printf("date1:%s\tdate2:%s\there 1:%d\n",date1,date2,compare(date1,date2));
           if (compare(date1,date2)==1){
                strcpy(temprecord,arr[j]); 
                strcpy(arr[j],arr[j+1]);
                 //printf("here :%s",date2);
                strcpy(arr[j+1],temprecord); 
            }
       } 
}
} 



void sort(){

}



int main(){
char **flights;
flights = (char **) malloc(10 * sizeof(char*));
for (int j = 0; j < 10; j++) {
    flights[j] = (char *) malloc(50 * sizeof(char*));
}

strcpy(flights[0],"AA43 DFW DTW 2016-01-06 11:00");
strcpy(flights[1],"AA43 DFW DTW 2016-01-17 11:00");
strcpy(flights[2],"AA44 SEA JFK 2015-02-05 7:45");
strcpy(flights[3],"AA197 ORD BOS 2012-03-12 11:50");
strcpy(flights[4],"AA197 ORD BOS 2012-03-12 11:50");
strcpy(flights[5],"AA1 JFK LAX 2016-07-02 9:00");
strcpy(flights[6],"OO7435 DTW PLN 2016-11-22 21:55");
strcpy(flights[7],"F9612 DEN MIA 2014-12-19 22:15");
strcpy(flights[8],"DL801 GEG MSP 2016-08-31 9:00");
strcpy(flights[9],"DL1087 ATL DAB 2016-04-10 12:05");
    // for(int i=0;i<10;i++){
    //     printf("\n%s",flights[i]);
    // }

    char str1[20]=" 2016-01-06 11:00";
    char str2[20]=" 2018-01-06 1:00";
    // char *temp= strtok(str1," ");
    // char *time1= strtok(NULL," ");
    //  char *year1= strtok(temp, "-");
    //  char month1=strtok(NULL,"-");
    //  char date1= strtok(NULL,"-");
    //  char hour1= strtok(time1,"-");
    //  char min1=strtok(NULL,"-");
    // char arr[50];
    // strcpy(arr,"AA43 DFW DTW 2016-01-06 11:00");
    // char *temp= strtok(arr," ");
    // printf("%s",temp);
    // strtok(NULL," ");
    // strtok(NULL," ");
    // char *date=strtok(NULL,"");
    
    int val=compare("2016-01-06 1:00","2016-01-06 11:00");
    bubbleSort(flights,10);
    
    for(int i=0;i<10;i++){
        printf("\n%s",flights[i]);
    }

}