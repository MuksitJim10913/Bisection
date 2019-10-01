#include<stdio.h>

void bisection_function(float *mid_point, float interval_start, float interval_end, int *iteration_count);
double calc_function(double temp);

int main()
{
        int iteration_count, maximum_iteration_count;
        float mid_point, interval_start, interval_end, error_allowed, root;
        printf("Enter Interval Start Point:\t");
        scanf("%f", &interval_start);
        printf("Enter Interval End Point:\t");
        scanf("%f", &interval_end);
        printf("Enter Maximum Iterations To Allow:\t");
        scanf("%d", &maximum_iteration_count);
        printf("Enter Allowed Error Point:\t");
        scanf("%f", &error_allowed);
        bisection_function (&mid_point, interval_start, interval_end, &iteration_count);
        for(iteration_count = 0; iteration_count < maximum_iteration_count; mid_point = root)
        {
                if(calc_function(interval_start) * calc_function(mid_point) < 0)
                {
                        interval_end = mid_point;
                }
                else
                {
                        interval_start = mid_point;
                }
                bisection_function (&root, interval_start, interval_end, &iteration_count);
                if(fabs(root - mid_point) < error_allowed)
                {
                        printf("\nCalculated Root:\t%f\n", root);
                        return 0;
                }
        }
        printf("\nThe iterations are insufficient\n");
        return 0;
}

void bisection_function(float *mid_point, float interval_start, float interval_end, int *iteration_count)
{
        *mid_point = (interval_start + interval_end) / 2;
        ++(*iteration_count);
        printf("Iteration\t%d:\t%f\n", *iteration_count, *mid_point);
}

double calc_function(double temp)
{
        return (((9.8*68.1)/temp)*(1-pow(10,(-((temp/68.1)*10.0))))-40.0);
}
