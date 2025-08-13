#include <stdio.h>

int alg_nsd(int a, int b);
int alg_nsk(int a, int b);
int multiple_nsk(int arr_nums[], int len_arr);

int main(void)
{
	int min = 2, max = 20;
	int count;

	printf("Введіть кількість чисел в діапазоні від %d до %d: ", min, max);
	if (scanf("%d", &count) != 1) {
		printf("\nНекоректні дані\n");
		return 1;
	}

	if (count < min || count > max) {
		printf("\nКількість чисел не входить у діапазон\n");
		return 1;
	}

	int arr_nums[count];

	printf("Введіть числа для знаходження НСК через пробіл: ");
	for (int i = 0; i < count; i++) {
		if (scanf("%d", &arr_nums[i]) != 1) {
			printf("\nНекоректні дані\n");
			return 1;
		} else if (arr_nums[i] <= 0) {
			printf("\nЧисла мають бути більші за нуль\n");
			return 1;
		}
	}

	printf("\nНСК для цих чисел буде: %d\n", multiple_nsk(arr_nums, count));
	return 0;
}

int alg_nsd(int a, int b)
{
	int tmp;

	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int alg_nsk(int a, int b)
{
	return a * b / alg_nsd(a, b);
}

int multiple_nsk(int arr_nums[], int len_arr)
{
	int res = arr_nums[0];

	for (int i = 1; i < len_arr; i++) {
		res = alg_nsk(res, arr_nums[i]);
	}
	return res;
}
