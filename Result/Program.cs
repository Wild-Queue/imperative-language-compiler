using System;using int_return = __unnamed_struct_number_0__;
main(1);
int fib(int n,int_return return_variable){var a = 0;var b = 1;for (int i=1; i < n; i++){int temp = a;a=b;b=temp + b;};return_variable.ans=a;Console.WriteLine(a);return a;}
struct __unnamed_struct_number_0__{public int ans;};
