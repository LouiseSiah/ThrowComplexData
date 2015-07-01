#include "Main.h"
#include "ErrorObject.h"
#include "malloc.h"
#include "CException.h"

int shouldFail = 1;

void doThings()
{
  //ErrorObject *err; //CEXCEPTION_T err is same

//  Try
//  {
    doSomething();
  // } Catch(err)
  // {
    // printf("Error: %s\n", err->errorMsg);
    // freeError(err);
  // }
}

int doSomething()
{
  //ErrorObject *errorObj = malloc(sizeof(ErrorObject)); //throwError will malloc there
    
  if(shouldFail)
  {
    throwError("Hey! Something is really wrong here.",  \
               ERR_DUNNO_WHAT_HAPPEN);
  }
  
  return 1;
}

/**
 * Add two numbers. The first number must be negative.
 * The second number must be positive no more that 50.
 */
int specialAdd(int negVal, int posVal)
{
  if(negVal > 0)
  {  
    throwError("Hey! The first number must be negative.",  \
                ERR_NUMBER_NOT_NEGATIVE);
  }
  
  if(posVal < 0)
  {  
    throwError("Hey! The second number must be positive.",  \
                ERR_NUMBER_NOT_POSITIVE);
  }
  
  if(posVal > 50)
  {  
    throwError("Hey! The second number must no more that 50.",  \
                ERR_NUMBER_TOO_LARGE);
  }
  
  return(negVal + posVal);
  
}
