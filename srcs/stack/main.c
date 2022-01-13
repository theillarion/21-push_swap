#include "stack.h"
#include <stdio.h>

int main()
{
	t_stack	*stack = NULL;
	int		array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	ft_push_array(&stack, array, 10);
	/*ft_push(&stack, 1);
	ft_push(&stack, 2);
	ft_push(&stack, 3);
	ft_push(&stack, 4);*/
	printf("Size stack: %ld\n", ft_size(&stack));
	if (!ft_empty(&stack))
		printf("Elements:\n");
	while (!ft_empty(&stack))
	{
		printf("%d\n", ft_top(&stack));
		ft_pop(&stack);
	}
	printf("Stack empty: ");
	if (ft_empty(&stack))
		printf("True\n");
	else
		printf("False\n");
	/*t_stack	*backup = stack;
	while (backup != NULL)
	{
		printf("%d\n", backup->data);
		backup = backup->next;
	}*/
	exit(EXIT_SUCCESS);
}