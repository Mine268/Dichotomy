#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define y(x) x * x - 1.0
#define exp "x * x - 1.0"

const float accuracy = .00001;

void calc(float start, float end) {
	float y1 = y(start);
	float y2 = y(end);
	float tmp = .0;
	float tmp2 = .0;

	if (y1 * y2 >= .0) { //y1 y2Í¬ºÅÅÐ¶¨ 
		printf("Can not find the solution.");
		return;
	}
	else {
		if ((end - start) / 2.0 >= accuracy) {
			tmp2 = (start + end) / 2.0;
			tmp = y(tmp2);

			if (tmp * y1 < 0) {
				calc(start, tmp2);
			}
			else if (tmp * y2 < 0) {
				calc(tmp2, end);
			}
			else if (tmp * y1 == 0 || tmp * y2 == 0) {
				printf("The solution is %f.", (start + end) / 2.0);
			}
			return;

		}
		else {
			printf("The solution is %f.", (start + end) / 2.0);
			return;
		}
	}

	return;
}

int main() {
	float start = .0, end = .0;

	printf("Expression: %s\nEnter the starting value and the ending value:\n", exp);
	scanf("%f %f", &start, &end);

	//	printf("%f, %f\n", start, end);

	if (start < end)
		calc(start, end);
	else
		printf("Invalid input has been given.");

	getchar(); getchar();
	return 0;
}

