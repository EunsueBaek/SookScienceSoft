package ScheduleTest_;

import java.awt.List.*;
import java.util.*;
import java.util.Arrays;
import java.util.List;

public class SchedulefuncTest{

   public boolean addfunc(String date) {
        int length = date.length();
        
        if (length < 6) 
            return false;
              
        return true;
    }
   
    
   public String search(String date) {
      String existingdate="161225";
      String existingdescription="ũ��������";
      String notify="�ٽ��Է��ϼ���.";
              
        if(date == existingdate){
           return existingdescription;
        }
        return notify;
     }
}