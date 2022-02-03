#include "checker.h"

int	main(int argc, char	**argv)
{
	t_main		main_struct;	

	if (argc > 1)
	{
		ft_initial_struct(&main_struct);
		ft_fill_vector(&main_struct, ++argv);
		if (!ft_validation(main_struct.vector, &main_struct.sorted_vector))
			ft_error(&main_struct, "Error");
		ft_fill_stack(&main_struct);
		ft_fill_operations(&main_struct);
		if (ft_check(&main_struct))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_success(&main_struct);
	}
	exit(EXIT_SUCCESS);
}
