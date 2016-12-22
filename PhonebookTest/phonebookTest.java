package PhonebookTest;

import static org.junit.Assert.*;

import org.junit.Test;

public class phonebookTest {

	@Test
	public void testCheckLength() {
		phonebook phonebook = new phonebook();
		 assertTrue(phonebook.checkPhonebookLength("031)238-4154"));

	}
	
	@Test
    public void testSearch() {
       String phone = null;
       phonebook ts = new phonebook();
       phone = ts.search("ÀÌ´Ù¿µ");
       assertEquals("010-3996-1401", phone);
	}

}
