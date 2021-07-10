#include "parser.h"

void	change_var(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (i == 0)
		{
			split[i] = check_var(split[i]);
			split[i] = check_cmd(split[i]);
		}
		else if (ft_strncmp("<<", split[i - 1], 2))
		{
			split[i] = check_var(split[i]);
			split[i] = check_cmd(split[i]);
		}
		i++;
	}
}

t_list *lexer(char *line, int status)
{
	t_list	*node;
	char	**split;

	if (status != 0)
		return (NULL);
	node = NULL;
	split = ft_split_cmd_args(line);
	change_var(split);
	node = cmd_table(split);
	free_split(split);
	return (node);
}
