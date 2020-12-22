#include<iostream>

using namespace std;

int CountingMinutesI(string str) { 

  // code goes here 
  // First create two substrings from the original string by finding the position
  // of the hyphen
  int hyphen = str.find('-');
  string time1 = str.substr(0,hyphen);
  string time2 = str.substr(hyphen+1);
  
  int hour1 = 0;
  int hour2 = 0;
  int minutes1 = 0;
  int minutes2 = 0;
  int totalMinutes = 0;
  
  //Traverse through the first substring to find the total number of minutes that
  //have passed for time #1
  for(int i = 0; i < time1.length(); i++){
    //The number that appears after the colon is the number of minutes
    if(time1[i] == ':'){
      minutes1 = time1[i+1];
    }
    
    //If time is in pm, then the number of hours is increased by 12
    if(time1[i] == 'p'){
      if(time1[0] < 12){
        hour1 = (12 + time1[0]);
      }
      else{
        hour1 = 12;
      }
    }
    
    //If time is in am, then the number of hours remains the same
    else if(time1[i] == 'a'){
      if(time1[0] < 12){
        hour1 = time1[0];
      }
      else{
        hour1 = 0; //12:00 am = 0 minutes (starting point)
      }
    }
  }
  
  
  //Doing exactly the same thing we did with time #1 for time #2
  for(int i = 0 ; i < time2.length(); i++){
    if(time1[i] == ':'){
      minutes2 = time2[i+1];
    }
    
    if(time2[i] == 'p'){
      if(time2[0] < 12){
        hour2 = (12 + time2[0]);
      }
      else{
        hour2 = 12;
      }
    }
    
    else if(time2[i] == 'a'){
      if(time2[0] < 12){
        hour2 = time2[0];
      }
      else{
        hour2 = 0;
      }
    }
  }
  
  //Now that we have collected the amount 
  totalMinutes = (hour2 * 60 + minutes2) - (hour1 * 60 + minutes1);
  if(totalMinutes < 0)
    totalMinutes += 1440;
  return totalMinutes; 
            
}
