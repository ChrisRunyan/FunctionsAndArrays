#include <iostream>
#include <stdlib.h>
#include <time.h>

void assignRandomValues(int a[], int size){
  srand(time(NULL));
  for(int i=0; i<size; i++){
    a[i]=rand()%10;
    std::cout<<"Array Index "<<i<<": "<<a[i]<<"\n";
  }
}

double getAverage(int a[], int size){
  int sum=0;
  double avg=0;

  for(int i=0; i<size; i++){
    sum+=a[i];
  }

  avg=(double)sum/size;

  return avg;
}

int getMode(int a[], int size){
  int possibilities[10][2];
  int tempHighest=0;
  int mode=0;
  int counter=0;

  //set first dimension equal to each possibility
  for(int i=0; i<10; i++){
    possibilities[i][0]=i;
  }

  //set second dimension equal to 0
  for(int i=0; i<10; i++){
    possibilities[i][1]=0;
  }

  //set second dimension equal to frequency of each number in imported array
  for(int i=0; i<10; i++){
    for(int j=0; j<size; j++){
      if(a[j]==possibilities[i][0]){
	possibilities[i][1]++;
      }
    }
  }

  //find most occurring number
  tempHighest=possibilities[0][1];
  mode=possibilities[0][0];
  for(int i=0; i<10; i++){
    if(possibilities[i][1]>tempHighest){
      tempHighest=possibilities[i][1];
      mode=possibilities[i][0];
    }
  }

  //catch if more than one
  for(int i=0; i<10; i++){
    if(possibilities[i][1]==possibilities[mode][1]&&i!=mode){
      counter++;
    }
  }
  if(counter>0){
    mode=11;
  }

  //catch if none occur more than once
  if(mode!=11){
    if(possibilities[mode][1]==1){
      mode=11;
    }
  }

  return mode;
}

int getLowest(int a[], int size){
  int tempLowest=a[0];

  for(int i=0; i<size; i++){
    if(a[i]<tempLowest){
      tempLowest=a[i];
    }
  }

  return tempLowest;
}

int getHighest(int a[], int size){
  int tempHighest=a[0];

  for(int i=0; i<size; i++){
    if(a[i]>tempHighest){
      tempHighest=a[i];
    }
  }

  return tempHighest;
}		

int main(){
  int array[15];
  int mode=0;

  assignRandomValues(array, 15);
  mode=getMode(array, 15);

  std::cout<<"Average: "<<getAverage(array, 15)<<"\n";

  if(mode==11){
    std::cout<<"Mode: No Mode\n";
  }
  else{
    std::cout<<"Mode: "<<mode<<"\n";		\
  }

  std::cout<<"Lowest Value: "<<getLowest(array, 15)<<"\n";
  std::cout<<"Highest Value: "<<getHighest(array, 15)<<"\n";
}
