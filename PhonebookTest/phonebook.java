package PhonebookTest;

import java.awt.List.*;
import java.util.*;
import java.util.Arrays;
import java.util.List;

public class phonebook {
int min_length = 3;
	
	public class phonebooks {
		String name = "�̴ٿ�";
		String phone= "010-3996-1401";
	}
	
    public boolean checkPhonebookLength(String phone){
        int length = phone.length();
        
        if (length<min_length)
           return false;
         return true;
     }
    public String search(String name) {
    	phonebooks Phonebook = new phonebooks();
        String notify="���� �̸��Դϴ�.";
        
        if(name == Phonebook.name){
           return Phonebook.phone;
        }
        return notify;
     }
}
