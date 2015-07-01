#include "unity.h"
#include "Main.h"
#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>
#include <stdio.h>

void setUp(void){}

void tearDown(void){}

void test_doThings(void)
{
  ErrorObject *err;
  
 Try
 {
    doThings();
    TEST_FAIL_MESSAGE("Expect ERR_DUNNO_WHAT_HAPPEN to be thrown."  \
                      "But none throw.");
  } Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! Something is really wrong here.",   \
                               err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_DUNNO_WHAT_HAPPEN, err->errorCode);
    
    freeError(err);
  }
}

void test_specialAdd_given_minus_5_and_11_should_return_6(void)
{
	int result = specialAdd(-5, 11);
  TEST_ASSERT_EQUAL(6, result);
}

void test_specialAdd_given_7_and_18_should_throw_ERR_NUMBER_NOT_NEGATIVE(void)
{
  //printf("HELLO\n");
  ErrorObject *err;
  //int result;
  
  Try
  {
    specialAdd(7, 18);
  } Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! The first number must be negative.",  \
                               err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_NEGATIVE, err->errorCode);
    
    freeError(err);
  }
}


void test_specialAdd_given_minus_7_and_minus_8_should_throw_ERR_NUMBER_NOT_POSITIVE(void)
{
  //printf("HELLO\n");
  ErrorObject *err;
  //int result;
  
  Try
  {
    specialAdd(-7, -8);
  } Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! The second number must be positive.",  \
                               err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_POSITIVE, err->errorCode);
    
    freeError(err);
  }
}

void test_specialAdd_given_minus_7_and_88_should_throw_ERR_NUMBER_TOO_LARGE(void)
{
  //printf("HELLO\n");
  ErrorObject *err;
  //int result;
  
  Try
  {
    specialAdd(-7, 88);
  } Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! The second number must no more that 50.",  \
                               err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_TOO_LARGE, err->errorCode);
    
    freeError(err);
  }
}