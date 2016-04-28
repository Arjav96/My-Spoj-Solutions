/*** To solve equation like A*x + B*sin(x) = C.
 
Do the following steps :
1.  A * x  +  B * sin(x) - C = 0 = (say it) f(x)
2.  Apply Newton - Ralphson approximation.
 
***/
 
#include<stdio.h>
#include<math.h>
 
int main()
{
    int t,six;  double a,b,c,x1,x2;
 
    scanf("%i",&t);
 
    while(t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
 
        x1 = -1;
 
        x2 = c/a;
        
        six = 6;
 
        while(x2!=x1 && six--)
        {
            x1 = x2;
            x2 = x1 - ( a*x1 + b*sin(x1) - c )/ ( a + b*cos(x1) );	// x2 = x1 - f(x)/f'(x):(general form => xn+1 = xn - f(x)/f'(x))
        }
 
        printf("%lf\n",x2);
    }
 
    return 0;
}
 
