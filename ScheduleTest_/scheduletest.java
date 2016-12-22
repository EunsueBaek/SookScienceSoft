package ScheduleTest_;

import static org.junit.Assert.*;

import org.junit.Test;

public class scheduletest {
   @Test
      public void testadd() {
      SchedulefuncTest addtest = new SchedulefuncTest();
          assertTrue(addtest.addfunc("161225"));
      }
   
   @Test
    public void testsearch() {
       String description = null;
       SchedulefuncTest searchtest = new SchedulefuncTest();
       description = searchtest.search("161225");
       assertEquals("크리스마스", description);
 }
}
