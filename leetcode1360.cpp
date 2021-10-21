#include<stdlib.h>
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        
        return abs (daysFrom1971(date2) - daysFrom1971(date1) );
        
    }
    
    bool isLeapYear(int year){ //判斷是否為閏年
        if( (year %4==0) && (year %100)!=0 || (year %400)==0 ) //可以被4整除 && 不可以被100整除 或 可以被400整除
            return true;
        return false;
    }
   
    //計算日期到1971所經過的天數
    int daysFrom1971(string date){
        
        int monthOfDays[13] = {0 ,31,28,31,30,31,30,31,31,30,31,30,31}; 
        
        int year=0,month=0,day=0;
        sscanf(date.c_str(),"%d-%d-%d",&year,&month,&day); //分割輸入的日期字串
        
        int totalDays = 0;
        for(int i=1971;i< year;i++){
            totalDays += 365;
            if(isLeapYear(i))
                totalDays +=1;
        }
        
        cout << month << endl;
        for(int i=1;i< month;i++){
            totalDays += monthOfDays[i];
            if(i==2 && isLeapYear(year)) //閏年2月是29天
                    totalDays +=1;
        }
        
        for(int i=1;i<=day;i++)
            totalDays +=1;
        
        return totalDays;
    }
    
};
