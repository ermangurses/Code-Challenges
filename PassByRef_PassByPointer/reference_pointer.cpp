#include <cstdlib>
#include <iostream>


/*******************************

*******************************/
void pass_by_pointer(int * var){

    printf("*var: %d\n", *var);
    printf(" var: %p\n", (void*)var);
    printf("&var: %p\n",(void*) &var);
}

/*******************************

*******************************/
void pass_by_reference(int & var){

    printf(" var:  %d\n", var);
    printf("&var:  %p\n",(void*)&var);
}

/*******************************

*******************************/
int main(int argc, char *argv[]){

  int x = 5;
  int * xptr = &x;
 
  printf("x    :  %d\n",x);
  printf("&x   :  %p\n",(void*)&x);  

  printf("\n\n\n");

  printf("pass_by_reference(x as & var)\n");
  pass_by_reference(x);

  printf("\n\n\n");

  printf("*xptr :  %d\n",*xptr);
  printf("xptr  :  %p\n",(void*)xptr);
  printf("&xptr :  %p\n",(void*)&xptr);

  printf("\n\n\n");
  printf("pass_by_pointer(xptr as * var)\n");
  pass_by_pointer(xptr);

 return 0;
}
